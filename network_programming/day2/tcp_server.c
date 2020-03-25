#include <stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<ctype.h>
#include<sys/types.h>
#include<stdlib.h>//exit()
#include<unistd.h>

#define LISTEN_BACKLOG 50
#define SERV_PORT 9527

void handle_error(const char *str)
{
    perror(str);
    exit(1);
}

int main()
{
    //创建一个socket    
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd == -1)
    {
        handle_error("socket error\n");
    }
    //绑定服务器的地址结构
    struct sockaddr_in addr_serv;
    addr_serv.sin_family = AF_INET;
    addr_serv.sin_port = htons(SERV_PORT);
    addr_serv.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(sfd, (struct sockaddr*)&addr_serv, sizeof(addr_serv))==-1)
    {
        handle_error("bind error\n");
    }
    //设置同时连接的客户端数量上限
    if(listen(sfd, LISTEN_BACKLOG)==-1)
    {
        handle_error("listen error\n");
    }
    //阻塞等待客户端连接
    struct sockaddr_in addr_client;
    socklen_t client_addr_len;
    client_addr_len = sizeof(addr_client);//传入传出参数，所以需要先给它赋值
    int cfd = accept(sfd, (struct sockaddr*)&addr_client, &client_addr_len);
     if(cfd == -1)
    {
        handle_error("accept error\n");
    }
    char client_IP[1024];
    printf("client ip:%s, port:%d\n",
           inet_ntop(AF_INET, &addr_client.sin_addr.s_addr, client_IP, sizeof(client_IP)),
           ntohs(addr_client.sin_port));
    //读数据
    char buf[BUFSIZ];//系统自带的宏 4096
    int ret;
    while(1)
    {
        ret = read(cfd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, ret);
        for(int i = 0; i<ret; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        //写数据
        write(cfd, buf, ret);
    }
    //关闭连接
    close(cfd);
    close(sfd);
    return 0;
}

