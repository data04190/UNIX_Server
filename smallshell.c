
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define MAXARG 7

main()
{
    char buf[256];
    char *arg[MAXARG];
    char *s;
    char *save;
    int argi;
    /* °ø¹é, ÅÇ, °³ÇàÀ¸·Î ÀÌ·ç¾îÁø ±¸ºÐÀÚ ¼±¾ð */
    static const char delim[] = " \t\n";
    int pid, status;

    /* ¹«ÇÑ ¹Ýº¹ */
    while(1) {
       /* ÇÁ·ÒÇÁÆ® Ãâ·Â */
       printf("myshell$ ");
       gets(buf);
       argi = 0;
       /* ¹®ÀÚ¿­¿¡¼­ delimÀ» ±âÁØÀ¸·Î ´Ü¾î¸¦ Àß¶ó³¿ */
       s = strtok_r(buf, delim, &save);
       while(s) {
          arg[argi++] = s;
          s = strtok_r(NULL, delim, &save);
       }
       /* ÀÎ¼ö°¡ ´õ ¾øÀ½À» ÀÇ¹ÌÇÏ´Â ¹®ÀÚ Ãß°¡ */
       arg[argi] = (char *)0;

       /* ÇÁ·ÒÇÁÆ®·Î ÀÔ·Â ¹ÞÀº Ã¹ ¹øÂ° ´Ü¾î°¡ ¡®quit¡¯ÀÌ¸é while ¹® ¹þ¾î³² */
       if (!strcmp(arg[0], "quit"))
           break;

       if ((pid=fork()) == -1)   /* fork È£Ãâ¿¡ ½ÇÆÐÇÏ¸é */
          perror("fork failed");
       /* ºÎ¸ð ÇÁ·Î¼¼½º´Â ÀÚ½Ä ÇÁ·Î¼¼½º°¡ Á¾·áµÇ±â¸¦ ±â´Ù¸² */
       else if (pid != 0) {
          pid = wait(&status);
       /* ÀÚ½Ä ÇÁ·Î¼¼½º´Â execvp¸¦ ÀÌ¿ëÇÏ¿© arg[0] ½ÇÇà */
       } else {
          execvp(arg[0], arg);
       }
    }
    exit(0);
}
