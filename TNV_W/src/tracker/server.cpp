// 跟踪服务器
// 实现服务器类
//
#include <unistd.h>
#include "proto.h"
#include "util.h"
#include "globals.h"
#include "service.h"
#include "server.h"
  
// 在进程启动时被调用
void server_c::proc_on_init(void) {
    // 应用ID表
	if (!cfg_appids || !strlen(cfg_appids))
        logger_fatal("application ids is null");
    split(cfg_appids, g_appids);
	if (g_appids.empty()) 
        logger_fatal("application ids is empty");

	// MySQL地址表
	if (!cfg_maddrs || !strlen(cfg_maddrs))
		logger_fatal("mysql addresses is null");
	split(cfg_maddrs, g_maddrs);
	if (g_maddrs.empty())
		logger_fatal("mysql addresses is empty");

	// Redis地址表
	if (!cfg_raddrs || !strlen(cfg_raddrs))
		logger_error("redis addresses is null");
	else {
		split(cfg_raddrs, g_raddrs);
		if (g_raddrs.empty())
			logger_error("redis addresses is empty");
		else {
			// 遍历Redis地址表，尝试创建连接池
			for (std::vector<std::string>::const_iterator raddr =
				g_raddrs.begin(); raddr != g_raddrs.end(); ++raddr)
				if ((g_rconns = new acl::redis_client_pool(
					raddr->c_str(), cfg_maxconns))) {
					// 设置Redis连接超时和读写超时
					g_rconns->set_timeout(cfg_ctimeout, cfg_rtimeout);
					break;
				}
			if (!g_rconns)
				logger_error("create redis connection pool fail, cfg_raddrs: %s",
					cfg_raddrs);
		}
	}

	// 主机名
	char hostname[256+1] = {};
	if (gethostname(hostname, sizeof(hostname) - 1))
		logger_error("call gethostname fail: %s", strerror(errno));
	g_hostname = hostname;

    // 创建并开启存储服务器状态检查线程
    if((m_status = new status_c)) {
        m_status->set_detachable(false);
        m_status->start();
    }

	// 打印配置信息
	logger("cfg_appids: %s, cfg_maddrs: %s, cfg_raddrs: %s, "
		"cfg_interval: %d, cfg_mtimeout: %d, cfg_maxconns: %d, "
		"cfg_ctimeout: %d, cfg_rtimeout: %d, cfg_ktimeout: %d",
		cfg_appids, cfg_maddrs, cfg_raddrs,
		cfg_interval, cfg_mtimeout, cfg_maxconns,
		cfg_ctimeout, cfg_rtimeout, cfg_ktimeout);
}

// 在进程意图退出时被调用
// 返回true, 进程立即退出，否则
// 若配置项ioctl_quick_abort非0，进程立即退出， 否则
// 待所有客户机连接都关闭后， 进程再退出
bool server_c::proc_exit_timer(size_t nclients, size_t nthreads) {
    // 终止存储服务器状态检查线程
    m_status->stop();

    if (!nclients || !nthreads) {
        logger("nclients: %lu, nthreads: %lu", nclients, nthreads);
        return true;
    }
    
    return false;
}

// 在进程即将退出时被调用
void server_c::proc_on_exit(void) {
    // 回收存储服务器状态检查线程
    if (!m_status->wait(NULL))
        logger_error("wait thread #%lu fail", m_status->thread_id());

    // 销毁存储服务器状态检查线程
    if (m_status) {
        delete m_status;
        m_status = NULL;
    }

    // 销毁Redis连接池
    if (g_rconns) {
        delete g_rconns;
        g_rconns  = NULL;
    }
}

// 线程获得连接时被调用
bool server_c::thread_on_accept(acl::socket_stream* conn) {
    logger("connect, from: %s", conn->get_peer());
    return true;
}

// 与线程绑定的连接可读时被调用
bool server_c::thread_on_read(acl::socket_stream* conn) {
	// 接收包头
	char head[HEADLEN];
	if (conn->read(head, HEADLEN) < 0) {
		if (conn->eof())
			logger("connection has been closed, from: %s",
				conn->get_peer());
		else
			logger_error("read fail: %s, from: %s",
				acl::last_serror(), conn->get_peer());
		return false;
	}

    // 业务处理
    service_c service;
    return service.business(conn, head);
}

// 当连接发生读写超时时被调用
bool server_c::thread_on_timeout(acl::socket_stream* conn) {
    logger("read timeout, from: %s", conn->get_peer());
    return true;
}
// 以上三个函数返回true，连接继续，否则关闭

// 当连接被关闭时调用
void server_c::thread_on_close(acl::socket_stream* conn) {
    logger("client disconnect, from: %s", conn->get_peer());
}

