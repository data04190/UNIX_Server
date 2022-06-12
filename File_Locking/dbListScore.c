#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
#include "DBFunction.h"


void  list_score ( char *argv[])
{
    int fd,size,i,j, count=0;
    char buf[BUFSIZE];
    student rec, next , tmp;
    ssize_t nread;
    int total = 0;
    student data[16];
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

    for(i = 0; i<size; i++){

        lock.l_type = F_RDLCK;
        lock.l_start =  i*sizeof(rec);

        lseek(fd, i*sizeof(rec), SEEK_SET);
        if (( read(fd, &rec, sizeof(rec)) >0) && (rec.id !=0) && (rec.name[0] !='$')){

        memcpy(&data[count], &rec, sizeof(student));
        count++;

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);

        }
   }

   for (i = 0 ; i<count; i++){
         for(j=0; j<count; j++){
             if( data[j].score < data[j+1].score) {
                    tmp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = tmp;
              }
             else if (data[j].score == data[j+1].score){
                    if(data[j].id > data[j+1].id){
                tmp = data[j];
                data[j] = data[j+1];
                        data[j+1] = tmp;
                   }
              }
         }
     }

     for (i = 0; i<count; i++)
                printf("\n%d\t %s\t %d\n", data[i].id, data[i].name, data[i].score);

   //printf("\n%d\n", count);
   //printf("%s", data[0].name);

   close(fd);

}
