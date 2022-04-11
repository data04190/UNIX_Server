#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
#include "dbCreate.h"
#include "dbQuery.h"
#include "dbUpdate.h"
#include "dbList.h"
#include "dbAdd.h"
#include "dbDelete.h"
#include "dbListScore.h"

int main(int argc, char *argv[])
{
   char c = 'x';
   int fd, id;
   student rec,search;


    if (argc < 2) {
        fprintf(stderr,  "사용법 : %s file\n", argv[0]);
        exit(1);
    }

   while(1){

        printf("무슨 기능을 수행할까요(c/q/u/l/a/d/s/e)? ");
        scanf("%c", &c);
        fflush(stdin);
        //if(( scanf("%c", &c)== 1) && ( c!= NULL)){


             if(c == 'c')
                 dbcreate(argv);

             else if( c== 'q')
                 dbquery(argv);

             else if (c == 'u')
                 dbupdate(argv);

             else if (c == 'l')
                 dblist(argv);

             else if (c == 'a')
                 dbadd(argv);

             else if (c == 'd')
                 dbdelete(argv);

             else if (c == 's')
                 list_score(argv);

             else if (c == 'e')
                 break;
      // }

     }

   //close(fd);
    exit(0);
}
