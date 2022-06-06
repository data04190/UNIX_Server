#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXLINE 256

main() {
    int fd1, fd2, n, pid;
    char cmsg[MAXLINE],smsg[MAXLINE];

    if(mkfifo("./chatfifo1", 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }
    if(mkfifo("./chatfifo2", 0666) == -1) {
        perror("mkfifo");
        exit(2);
    }

    chmod("./chatfifo1", 0666);
    chmod("./chatfifo2", 0666);

    fd1 = open("./chatfifo1", O_WRONLY);
    fd2 = open("./chatfifo2", O_RDONLY);

    if(fd1 == -1 || fd2 == -1) {
        perror("open");
        exit(3);
    }

    printf("서버 시작 \n");

    pid = fork(); 

    while(1) {

        if (pid == 0) {  //자식 프로세스 
              n = read(fd2, cmsg, MAXLINE);
              printf("클라이언트 :  %s\n", cmsg); 

        } else{       // 부모 프로세스

            fgets(smsg, MAXLINE, stdin);
            if ( (strlen(smsg) > 1)  ) {
           	      printf("서버 : %s", smsg);
	      n = write(fd1, smsg, strlen(smsg)+1);
                  if (n == -1) {
                     perror("write");
                     exit(1);
                   }
	
            }

       }
    }     
}
