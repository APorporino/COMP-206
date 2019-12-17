bank: main.o linked.o ssv.o
	gcc -o bank linked.o ssv.o main.o 

linked.o: src/linked.c
	gcc -c src/linked.c

ssv.o: src/ssv.c
	gcc -c src/ssv.c

main.o: src/main.c
	gcc -c src/main.c

