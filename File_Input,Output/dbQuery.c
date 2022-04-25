#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
#include "dbQuery.h"

/* 학번을 입력받아 해당 학생의 레코드를 파일에서 읽어 출력한다. */
void dbquery (char *argv[])
{
    int fd, id;
    char c;
    struct student rec;


   if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    do {
        printf("\n검색할 학생의 학번 입력:");
        if (scanf("%d", &id) == 1) {
            lseek(fd, (id-START_ID)*sizeof(rec), SEEK_SET);
            if ((read(fd, &rec, sizeof(rec)) > 0) && (rec.id != 0))
                printf("학번:%d\t 이름:%s\t 점수:%d\n",
                        rec.id, rec.name, rec.score);
            else printf("검색할 레코드 %d 없음, rec.id=%d\n", id, rec.id);
        }
        else printf("입력 오류");

        printf("계속하겠습니까?(Y/N)");
        scanf(" %c", &c);
    } while (c == 'Y');

    close(fd);
}
