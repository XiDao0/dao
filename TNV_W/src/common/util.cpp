// 公共模块
// 声明实用函数


#include <string.h>
#include "types.h"
#include "util.h"

// long long类型整数主机序转网络序
void llton(long long ll, char* n) {
    for(size_t i = 0; i < sizeof(ll); ++i)
        n[i] = ll >> (sizeof(ll) - i - 1) * 8;
}

// long long类型整数网络序转主机序
long long ntoll(char const* n) {
    long long ll = 0;
    for(size_t i = 0; i < sizeof(ll); ++i)
        ll |= (long long)(unsigned char)n[i] << (sizeof(ll) - i - 1) * 8;
    return ll;
}

// long类型整数主机序转网络序
void lton(long l, char* n) {
    for(size_t i = 0; i < sizeof(l); ++i)
        n[i] = l >> (sizeof(l) - i - 1) * 8;
}

// long类型整数网络序转主机序
long ntol(char const* n) {
    long l = 0;
    for(size_t i = 0; i < sizeof(l); ++i)
        l |= (long)(unsigned char)n[i] << (sizeof(l) - i - 1) * 8;
    return l;
}

// short类型整数主机序转网络序
void ston(short s, char* n) {
    for(size_t i = 0; i < sizeof(s); ++i)
        n[i] = s >> (sizeof(s) - i - 1) * 8;
}

// short类型整数网络序转主机序
short ntos(char const* n) {
    short s = 0;
    for(size_t i = 0; i < sizeof(s); ++i)
        s |= (short)(unsigned char)n[i] << (sizeof(s) - i - 1) * 8;
    return s;
}

// 字符串是否合法，即是否只包含26个英文字母大小写和0 到 9十个阿拉伯数字
int valid(char const* str) {
    if(!str)
        return ERROR;
    
    size_t len = strlen(str);
    if(!len)
        return ERROR;

    for (size_t i = 0; i < len; ++i){
        if(!(('a' <= str[i] && str[i] <= 'z') || 
             ('A' <= str[i] && str[i] <= 'Z') ||
             ('0' <= str[i] && str[i] <= '9') )) 
            return ERROR;
    }

    return OK;
}

// 以分号为分隔符将一个字符串拆分为多个字符串
int split(char const* str, std::vector<std::string>& substrs) {
    if(!str)
        return ERROR;
    
    size_t len = strlen(str);
    if(!len)
        return ERROR;
    
    char* buf = new char[len+1];
    strcpy(buf, str);
    
    char const* sep = ";";
    for(char* substr = strtok(buf, sep); substr; substr = strtok(NULL, sep))
        substrs.push_back(substr);

    delete[] buf;

    return OK;
}















