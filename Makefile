all: clean assembly

clean:
	rm -f *.o *.gch *.stackdump *.exe inter.tab.c inter.tab.h interpreter

assembly: clean inter.y inter.l
	bison -d inter.y
	flex inter.l
	cc -o $@ inter.tab.c lex.yy.c -lfl
	./assembly < entrada
