
#include <stdio.h>
#include <string.h>
#include "string_tokenize.h"

int string_tokenize(char longest[], char *sArr[])
{

  int j = 0;
  int i;

  char *ptr = strtok(longest," ");
  while (ptr != NULL)
  {
    sArr[j] = ptr;
    j++;
    ptr = strtok(NULL, " ");
  }

  for (i = 0; i<MAXLINE; i++)
  {
     if(sArr[i] != NULL)
        printf("%s\n", sArr[i]);
  }
  printf("단어의 개수 : %d\n", j);
  return j;
}
