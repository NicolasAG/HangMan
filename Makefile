HangMan: main.o menu.o functions.o
	gcc -o HangMan main.o menu.o functions.o
main.o: main.c
	gcc -c -Wall main.c
menu.o: menu.c
	gcc -c -Wall menu.c
functions.o: functions.c
	gcc -c -Wall functions.c
clean:
	rm -f HangMan main.o menu.o functions.o

