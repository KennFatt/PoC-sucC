all: main.o str2int.o
	gcc out/obj/* -o out/str2int

main.o:
	gcc -c main.c -o out/obj/main.o

str2int.o: str2int.h
	gcc -c str2int.c -o out/obj/str2int.o