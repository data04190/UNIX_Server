#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXLINE 256

main()
{
    int fd1, fd2, n;
    char inmsg[MAXLINE];

    fd1 = open("/home/users/22-1/kmk04190/hw05/chatfifo1", O_RDONLY);   // 절대경로
    fd2 = open("/home/users/22-1/kmk04190/hw05/chatfifo2", O_WRONLY);   //절대경로
    if(fd1 == -1 || fd2 == -1) {
        perror("open");
        exit(1);
    }

    printf("클라이언트 시작 \n");
    while(1) {
        n = read(fd1, inmsg, MAXLINE);
        printf("서버 -> %s\n", inmsg);
        printf("클라이언트 : ");
        fgets(inmsg, MAXLINE, stdin);
        write(fd2, inmsg, strlen(inmsg)+1);
    }
}
