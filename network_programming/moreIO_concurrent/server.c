#include <stdio.h>
#include<unistd.h> //STDOUT_FILENO
#include <ctype.h>  //toupper
#include <sys/types.h>
#include <sys/socket.h>
#include "wrap.h"
#include <arpa/inet.h>//sockaddr_in
#include <stdlib.h>
#include <string.h>//memset
#include <sys/epoll.h>

#define  SERV_PORT 9723
#define LISTEN_BACKLOG 50
#define OPEN_MAX 5000 
#define MAX_LINE 8192
int main()
{
    int lfd, efd, res, nready, cfd, sockfd, n;

    //创建一个套接字
    lfd = Socket(AF_INET, SOCK_STREAM,0 );

    struct sockaddr_in addr_serv, addr_client;

    struct epoll_event tep, ep[OPEN_MAX];

    socklen_t len_client;

    char client_IP[INET_ADDRSTRLEN], buf[MAX_LINE];
    //设置端口复用
    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    memset(&addr_serv, 0, sizeof(struct sockaddr_in));
    addr_serv.sin_family = AF_INET;
    addr_serv.sin_port = SERV_PORT;
    addr_serv.sin_addr.s_addr = htonl(INADDR_ANY);
    //绑定服务器地址结构
    Bind(lfd, (struct sockaddr*)&addr_serv, sizeof(addr_serv));

    //设置同时连接的客户端数量上限
    Listen(lfd, LISTEN_BACKLOG);
        
    efd = epoll_create(OPEN_MAX);  //创建epoll模型，efd指向红黑树根节点
    if(efd == -1)
    {
        perr_exit("epoll_create error\n");
    }

    tep.events = EPOLLIN; //指定lfd的监听事件为读事件
    tep.data.fd = lfd;
    res = epoll_ctl(efd, EPOLL_CTL_ADD, lfd, &tep);   //将lfd挂在树上
    if(res == -1)
    {
        perr_exit("epoll_ctl error\n");
    }

    while(1)
    {
       nready =  epoll_wait(efd, ep, OPEN_MAX, -1);//-1表示阻塞等待
       if(nready==-1)
       {
           perr_exit("epoll_wait error\n");
       }

       for(int i = 0; i<nready; i++)
       {
            if(ep[i].data.fd == lfd)
            {
                memset(&addr_client, 0, sizeof(struct sockaddr_in));
                len_client = sizeof(addr_client);//传入传出参数
                cfd = Accept(lfd, (struct sockaddr*)&addr_client, &len_client);//接受连接

                printf("receive from %s at Port %d\n", 
                       inet_ntop(AF_INET, &addr_client.sin_addr.s_addr, client_IP, sizeof(client_IP)), 
                       ntohs(addr_client.sin_port));
                
                tep.events = EPOLLIN;
                tep.data.fd = cfd;

                res = epoll_ctl(efd, EPOLL_CTL_ADD, cfd, &tep);//将新客户端挂在监听树上
                if(res == -1)
                {
                    perr_exit("epoll_ctl error\n");
                }
           }

            else
            {
                sockfd = ep[i].data.fd;
                n = Read(sockfd, buf, MAX_LINE);
                if(n==0)//读到0， 说明客户端关闭连接
                {
                    res = epoll_ctl(efd, EPOLL_CTL_DEL, sockfd, NULL);  //从监听树上摘下
                    if(res == -1)
                    {
                        perr_exit("epoll_ctl error\n");
                    }
                    Close(sockfd);  //关闭与客户端的连接
                    printf("client[%d] closed connection\n", sockfd);
                }
                if(n > 0)
                {
                    for(int i =0; i<n; i++)
                    {
                        buf[i] = toupper(buf[i]);  //小写转大写 
                    }
                    Write(STDOUT_FILENO, buf, n);
                    Write(sockfd, buf, n);

                }
            }
        }
    }
    Close(lfd);
    Close(efd);
}
