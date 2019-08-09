app: intlen.o main.o
	gcc out/obj/*.o -o out/$@

intlen.o: intlen.c intlen.h
	gcc -c $< -o out/obj/$@

main.o: main.c intlen.o
	gcc -c $< -o out/obj/$@