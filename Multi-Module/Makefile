
main: main.o copy.o len_str.o string_tokenize.o
        gcc -o main main.o copy.o len_str.o string_tokenize.o
main.o: main.c copy.h len_str.h string_tokenize.h
        gcc -c main.c
copy.o: copy.c
        gcc -c copy.c
len_str.o : len_str.c
        gcc -c len_str.c
string_tokenize.o : string_tokenize.c
        gcc -c string_tokenize.c
