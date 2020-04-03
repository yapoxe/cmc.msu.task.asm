all: main_prog
main_prog: main.o functions.o
		gcc -m32 main.o functions.o -o main_prog

main.o: main.c
		gcc -m32 -c -g -std=c99 main.c

functions.o: functions.asm
		nasm -f elf functions.asm -F dwarf -g

clean:
		rm -rf *.o main_prog