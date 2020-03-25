#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "wrap.h"
#include <arpa/inet.h>
#include <string.h>   //bzero

#define SERV_PORT 9000
int main()
{
    //创建套接字
    int sock_fd = 0, ret = 0;    

    sock_fd = Socket(AF_INET, SOCK_DGRAM, 0);   //SOCK_DGRAM指报式传输
    
    char buf[BUFSIZ] = {0}, str_ip[INET_ADDRSTRLEN] = {0};
    struct sockaddr_in serv_addr , client_addr;
    socklen_t client_len = sizeof(client_addr);//传入传出参数，一定要先赋初值，这里找死我了

    bzero(&serv_addr, sizeof(serv_addr));
    bzero(&client_addr, sizeof(client_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    //绑定服务器地址结构
    Bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    //因为不用连接，所以不需要listen来设置监听上限
    
    printf("Accepting connections...\n");

    while(1)
    {
        ret = recvfrom(sock_fd, buf, BUFSIZ, 0, (struct sockaddr*)&client_addr, &client_len );
        if(ret == -1)
        {
            perr_exit("recvfrom error\n");
        }

        printf("recieved from %s at PORT %d\n",
               inet_ntop(AF_INET, &client_addr.sin_addr, str_ip, sizeof(str_ip)),
               ntohs(client_addr.sin_port));

        for(int i = 0; i<ret; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        ret = sendto(sock_fd, buf, ret, 0 , (struct sockaddr*)&client_addr, sizeof(client_addr));
        if(ret == -1)
        {
            perr_exit("sendto error\n");
        }
    }
    Close(sock_fd);
    return 0;
}

