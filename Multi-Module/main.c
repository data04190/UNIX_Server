#include <stdio.h>
#include <string.h>
#include "string_tokenize.h"
#include "len_str.h"
#include "copy.h"


/* 입력된 줄 가운데 가장 긴 줄을 프린트한다. */
main()
{
    char line[MAXLINE]="";
    char longest[MAXLINE] = "";
    char *sArr[MAXLINE] = {NULL,};

    int len;
    int max;
    int count = 0;
    max = 0;

    while (gets(line) != NULL) {
        len = strlen(line);
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }

    if (max > 0)   // 입력 줄이 있었다면
       printf("length=%d, %s\n", max, longest);
       count = string_tokenize(longest, sArr);
       len_str(count,sArr);

   return 0;
}
