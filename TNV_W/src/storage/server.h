// 存储服务器
// 声明服务器类
// 
#pragma once

#include <list>
#include <lib_acl.hpp>
#include "tracker.h"

// 服务器类
// 
class server_c: public acl::master_threads {
protected:
    // 在进程启动时被调用
    void proc_on_init(void);
    // 在进程意图退出时被调用
    // 返回true, 进程立即退出，否则
    // 若配置项ioctl_quick_abort非0，进程立即退出， 否则
    // 待所有客户机连接都关闭后， 进程再退出
    bool proc_exit_timer(size_t nclients, size_t nthreads);
    // 在进程即将退出时被调用
    void proc_on_exit(void);

    // 线程获得连接时被调用
    bool thread_on_accept(acl::socket_stream* conn);
    // 与线程绑定的连接可读书时被调用
    bool thread_on_read(acl::socket_stream* conn);
    // 当连接发生读写超时时被调用
    bool thread_on_timeout(acl::socket_stream* conn);
    // 以上三个函数返回true，连接继续，否则关闭
    // 当连接被关闭时调用
    void thread_on_close(acl::socket_stream* conn);

private:
    std::list<tracker_c*> m_trackers;   // 跟踪客户机线程集
};
