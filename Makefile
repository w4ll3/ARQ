all: clean
	bison -d inter.y
	flex inter.l
	gcc -o $@.exe *.c -lfl
	./$@.exe < entrada

clean:
	rm -f *.o *.gch *.stackdump *.exe inter.tab.c inter.tab.h interpreter
