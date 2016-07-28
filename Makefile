all: clean assembly

clean:
	rm -f *.o *.gch *.stackdump *.exe inter.tab.c inter.tab.h interpreter

assembly: clean inter.y inter.l memory.c
	bison -d inter.y
	flex inter.l
	cc -o $@ inter.tab.c lex.yy.c memory.c line.c register.c -lfl
	./assembly < entrada
