C_FLAGS=-Wall
all: main.o str2int.o
	gcc $(C_FLAGS) out/obj/* -o out/str2int
main.o:
	gcc -c $(C_FLAGS) main.c -o out/obj/main.o
str2int.o: str2int.h
	gcc -c $(C_FLAGS) -fPIC str2int.c -o out/obj/str2int.o
libstr2int.so: str2int.o
	gcc -shared out/obj/str2int.o -o libstr2int.so
