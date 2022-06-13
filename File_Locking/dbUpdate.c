
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
#include "DBFunction.h"

/* 학번을 입력받아 해당 학생 레코드를 수정한다. */
void dbupdate( char *argv[])
{
    int fd, id;
    char c;
    struct student rec;
    struct flock lock;


    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    do {
        printf("수정할 학생의 학번 입력: ");
        if (scanf("%d", &id) == 1) {

        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = (id-START_ID)*sizeof(rec);
            lock.l_len = sizeof(rec);

            if(fcntl (fd, F_SETLKW, &lock) == -1) {
             perror(argv[1]);
             exit(3);
            }

            lseek(fd,  (long) (id-START_ID)*sizeof(rec), SEEK_SET);
            if ((read(fd, &rec, sizeof(rec)) > 0) && (rec.id != 0)) {
                printf("학번:%8d\t 이름:%4s\t 점수:%4d\n",
                       rec.id, rec.name, rec.score);
                printf("새로운 점수: ");
                scanf("%d", &rec.score);
                lseek(fd, (long) -sizeof(rec), SEEK_CUR);
                write(fd, &rec, sizeof(rec));
            }
            else printf("레코드 %d 없음\n", id);
        }
        else printf("입력오류\n");

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);

        printf("계속하겠습니까?(Y/N)");
        scanf(" %c",&c);
    } while (c == 'Y');


    close(fd);
}
