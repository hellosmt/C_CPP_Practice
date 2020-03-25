#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "wrap.h"
#include <arpa/inet.h>
#include <string.h>

#define SERV_PORT 9000

int main()
{
    int sock_fd = 0, ret = 0;
    struct sockaddr_in serv_addr;
    char buf[BUFSIZ];
    //创建套接字
    sock_fd = Socket(AF_INET, SOCK_DGRAM, 0);
    
    bzero(&serv_addr, sizeof(serv_addr));    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);


    while(fgets(buf, BUFSIZ, stdin) != NULL)
    {
        ret = sendto(sock_fd, buf, strlen(buf), 0,(struct sockaddr*)&serv_addr, sizeof(serv_addr));
        
        if(ret == -1)
        {
            perr_exit("sendto error\n");
        }

        ret = recvfrom(sock_fd, buf, BUFSIZ, 0, NULL, 0);  //NULL表示不关心对端信息，因为只可能是该服务器发过来的
        
        if(ret == -1)
        {
            perr_exit("recvfrom error\n");
        }
        
        write(STDOUT_FILENO, buf, ret);

    }

    Close(sock_fd);
    return 0;
}

