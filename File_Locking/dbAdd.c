
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
#include "DBFunction.h"


void dbadd( char *argv[])
{
    int fd;
    struct student rec, new;
    struct flock lock;


    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

     printf("%-9s %-8s %-4s\n", "학번",  "이름",  "점수");

     if(scanf("%d %s %d", &new.id, new.name, &new.score) == 3){

         lock.l_type = F_RDLCK;  
         lock.l_whence = SEEK_SET;
         lock.l_start = (new.id - START_ID) * sizeof(rec);
         lock.l_len = sizeof(rec);

         if(fcntl(fd, F_SETLKW, &lock) == -1){
             perror(argv[1]);
             exit(3);
         }

         lseek(fd, (new.id - START_ID) * sizeof(new), SEEK_SET);

         read(fd, &rec, sizeof(rec));


        // printf("%d", rec.id);

         if (rec.id == NULL){
             lseek(fd, -sizeof(rec), SEEK_CUR);
             write(fd, &new, sizeof(rec));
         }
         else printf("이미 저장된 학생 정보 있음\n");


        lock.l_type = F_UNLCK;   // 잠금 설정 해제.
        fcntl(fd, F_SETLK, &lock);
     }

    close(fd);
}
