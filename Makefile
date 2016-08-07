all: clean
	bison -d inter.y
	flex inter.l
	gcc -o $@.exe *.c -lfl -Wno-implicit-function-declaration
	./$@.exe < entrada

clean:
	rm -f *.o *.gch *.stackdump *.exe inter.tab.c inter.tab.h interpreter
