
/* copy: from을 to에 복사, to가 충분히 크다*/
void copy(char *from, char *to)
{
   int i;

   for(i=0; *(from+i)!='\0'; i++){
        *(to+i) = *(from+i);
   }
   *(to+i) = '\0';

}
