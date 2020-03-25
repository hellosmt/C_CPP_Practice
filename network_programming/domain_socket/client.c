#include <stdio.h>
#include <ctype.h>
#include <arpa/inet.h>
#include "wrap.h"
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stddef.h>
#include <unistd.h>

/* domain socket的客户端要初始化两个地址结构，一个自己的用于bind，一个服务端的用于connet */

#define CLIENT_ADDR "client.socket"
#define SERV_ADDR "serv.socket"
int main()
{
    int cfd = 0, len = 0; 

    char buf[BUFSIZ];

    struct sockaddr_un client_addr, serv_addr;

    cfd = Socket(AF_UNIX, SOCK_STREAM, 0);

    client_addr.sun_family = AF_UNIX;
    strcpy(client_addr.sun_path, CLIENT_ADDR);

    len = offsetof(struct sockaddr_un, sun_path) + strlen(CLIENT_ADDR);

    unlink(CLIENT_ADDR);
    Bind(cfd, (struct sockaddr*)&client_addr, len);
    
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, SERV_ADDR);

    len = offsetof(struct sockaddr_un, sun_path) + strlen(SERV_ADDR);

    Connect(cfd, (struct sockaddr*)&serv_addr, len);

    while(fgets(buf, sizeof(buf), stdin)!=NULL)
    {
        write(cfd, buf, strlen(buf));
        len = read(cfd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, len);
    }
    
    close(cfd);
    return 0;
}
