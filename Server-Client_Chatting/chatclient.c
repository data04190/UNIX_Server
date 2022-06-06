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
    int fd1, fd2, n,pid;
    char smsg[MAXLINE], cmsg[MAXLINE];

    fd1 = open("/home/users/22-1/kmk04190/hw05/chatfifo1", O_RDONLY);
    fd2 = open("/home/users/22-1/kmk04190/hw05/chatfifo2", O_WRONLY);
    if(fd1 == -1 || fd2 == -1) {
        perror("open");
        exit(1);
    }  

   printf("클라이언트 시작 \n");

   pid = fork(); 

    while(1) { 

        if (pid == 0) {    //자식 프로세스 

	     n = read(fd1, smsg, MAXLINE);
             if ( n > 0) 
                 printf("서버 :  %s\n", smsg);

        } else{           // 부모 프로세스

	      fgets(cmsg, MAXLINE, stdin);
	      if ( (strlen(cmsg) > 1)  ) {
                   printf("클라이언트 : %s", cmsg);
	           write(fd2, cmsg, strlen(cmsg)+1);
               }
       }
   }
}
