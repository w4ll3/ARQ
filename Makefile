all: clean windows

windows: clean
	bison -d inter.y
	flex inter.l
	gcc -Wno-implicit -o $@ inter.tab.c lex.yy.c memory.c line.c register.c utils.c -lfl
	./windows.exe < entrada

linux: clean
	bison -d inter.y
	flex inter.l
	gcc -Wno-implicit -o $@ inter.tab.c lex.yy.c memory.c line.c register.c utils.c -lfl
	./linux < entrada

clean:
	rm -f *.o *.gch *.stackdump *.exe inter.tab.c inter.tab.h interpreter
