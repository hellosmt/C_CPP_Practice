/*
 * @Author       : Cement
 * @Date         : 2020-03-26 00:03:14
 * @LastEditors  : Cement
 * @LastEditTime : 2020-03-26 00:03:15
 * @Description  : 
 */
#include <stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<ctype.h>
#include<sys/types.h>
#include<stdlib.h>//exit()
#include<unistd.h>

#define SERV_PORT 9527
char SERV_IP[]="127.0.0.1";

void handle_error(const char* str)
{
    perror(str);
    exit(1);
}

int main(int arg, char *argv[])
{
    //创建socket
    int cfd = socket(AF_INET, SOCK_STREAM, 0);
    if(cfd == -1)
    {
        handle_error("socket error\n");
    }

    //建立连接
    struct sockaddr_in addr_serv;//服务器地址结构
    addr_serv.sin_family = AF_INET;
    addr_serv.sin_port = htons(SERV_PORT);//要传进网络中，所以要转换
    void* server_ip;
    inet_pton(AF_INET, SERV_IP, &addr_serv.sin_addr.s_addr); // 已经 转成了网络字节序
    int ret = connect(cfd, (struct sockaddr*)&addr_serv, sizeof(addr_serv));
    if(ret != 0)
    {
        handle_error("connet error\n");
    }

    char buf[BUFSIZ];
    //写数据
    while(1)
    {
        write(cfd, "hello\n", 6);
        ret = read(cfd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, ret);
        sleep(1);
    }

    close(cfd);
    return 0;
}
