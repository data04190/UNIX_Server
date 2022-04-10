
main: main.o dbCreate.o dbQuery.o dbUpdate.o dbList.o dbAdd.o dbDelete.o dbListScore.o
        gcc -o main main.o dbCreate.o dbQuery.o dbUpdate.o dbList.o dbAdd.o dbDelete.o dbListScore.o
main.o: main.c dbCreate.h dbQuery.h dbUpdate.h dbList.h dbAdd.h dbDelete.h dbListScore.h
        gcc -c main.c
dbCreate.o :dbCreate.c
        gcc -c dbCreate.c
dbQuery.o : dbQuery.c
        gcc -c dbQuery.c
dbUpdate.o : dbUpdate.c
        gcc -c dbUpdate.c
dbList.o : dbList.c
        gcc -c dbList.c
dbAdd.o : dbAdd.c
        gcc -c dbAdd.c
dbDelete.o : dbDelete.c
        gcc -c dbDelete.c
dbListScore.o : dbListScore.c
        gcc -c dbListScore.c
