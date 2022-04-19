#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
#include "dbDelete.h"

/* 학번을 입력받아 해당 학생 레코드를 삭제한다. */
void dbdelete (char *argv[])
{
    int fd, id;
    char c;
    struct student rec;

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

     printf("삭제할 학생의 학번 입력: ");
      if (scanf("%d", &id) == 1) {
            lseek(fd,  (long) (id-START_ID)*sizeof(rec), SEEK_SET);
            if ((read(fd, &rec, sizeof(rec)) > 0) && (rec.id != 0)) {
                //printf("%s\n", rec.name);
                //printf("%c\n", rec.name[0]);
                rec.name[0] = '$';
                //printf("%s\n", rec.name);
                lseek(fd, (long) -sizeof(rec), SEEK_CUR);
                write(fd, &rec, sizeof(rec));
            }
            else printf("레코드 %d 없음\n", id);
        }
       else printf("입력오류\n");


    close(fd);
}
