DEFINES=
all: microsecond.o
	gcc -c main.c -o out/obj/main.o \
	&& gcc $(DEFINES) out/obj/* -o out/app

microsecond.o: microsecond.h
	gcc -c microsecond.c -o out/obj/microsecond.o

watch:
	watch -n1 './out/app'