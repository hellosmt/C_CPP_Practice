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
#include <fcntl.h>

#define SERV_ADDR "serv.socket"

int main()
{
    int lfd = 0 , len = 0, cfd = 0, n = 0;

    char buf[BUFSIZ];

    lfd = Socket(AF_UNIX, SOCK_STREAM, 0);

    struct sockaddr_un serv_addr, client_addr;
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, SERV_ADDR);
    len =  offsetof(struct sockaddr_un, sun_path) + strlen(SERV_ADDR); // 不使用硬编码，而是offsetof函数 
    
    unlink(SERV_ADDR);  // 保证没有该同名文件，确保bind成功

    Bind(lfd, (struct sockaddr*)&serv_addr, len);
    
    Listen(lfd, 50);   //其实没有必要，只是两个进程间进行通信

    printf("Accepting...\n");

    while(1)
    {
        len = sizeof(client_addr);
        
        cfd = Accept(lfd, (struct sockaddr*)&client_addr,(socklen_t*)&len) ;
        
        //下面两行纯粹是为了练习使用offsetof函数
        len -= offsetof(struct sockaddr_un, sun_path);  //得到文件名的长度
        client_addr.sun_path[len] = '\0';              //防止打印的时候乱码

        printf("client bind filename: %s\n", client_addr.sun_path);

        while((n = read(cfd, buf, BUFSIZ)) > 0 )
        {
            for(int  i = 0; i < n ; i++)
            {
                buf[i] = toupper(buf[i]); 
            }
            write(cfd, buf, n);
        }

        Close(cfd);
    }

    Close(lfd);

    return 0;
}

