#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
#include "DBFunction.h"


void dblist( char *argv[])
{
    int fd, id, size,i;
    char buf[BUFSIZE];
    struct student rec;
    ssize_t nread;
    int total = 0;
    struct flock lock;


   if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(2);
    }

   while((nread = read(fd,buf, BUFSIZE))>0)
   {
    total += nread;
   }

   size = total / sizeof(rec);
   //printf("파일 크기 : %ld\n ", total);

   lock.l_whence = SEEK_SET;
   lock.l_len = sizeof(rec);

   for(i = 0; i<size ; i++){


      lock.l_type = F_RDLCK;
      lock.l_start =  i*sizeof(rec);

      if(fcntl(fd, F_SETLKW, &lock) == -1) {
         perror(argv[1]);
         exit(3);
       }

      lseek(fd, i*sizeof(rec), SEEK_SET);
      if (( read(fd, &rec, sizeof(rec)) >0) && (rec.id !=0) && (rec.name[0] !='$')){

        printf("\n%d\t %s\t %d\n", rec.id, rec.name, rec.score);

     }
   lock.l_type = F_UNLCK;
   fcntl(fd, F_SETLK, &lock);
   }

   close(fd);
}
