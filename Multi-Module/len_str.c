#include <stdio.h>
#include <string.h>
#include "len_str.h"

void len_str(int count, char *sArr[])
{
 int i;
 int max=0;
 int min = 100;
 int len;

 for(i=0;i<count;i++) {
   len = strlen(sArr[i]);
   if( len> max)
      max = len;
   if ( len <min)
      min = len;
 }
 for (i = 0; i<count; i++){
   len = strlen(sArr[i]);
   if ( len == max)
     printf("가장 긴 단어 길이  : %d, 가장 긴 단어 : %s\n",max, sArr[i]);
  }
 for (i = 0; i <count; i++){
   len = strlen(sArr[i]);
   if (len == min)
      printf("가장 짧은 단어 길이  : %d, 가장 짧은 단어 : %s\n",min, sArr[i]);
 }
}
