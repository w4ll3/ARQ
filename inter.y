%{
	#include "memory.h"
	#include "utils.h"
	#include "register.h"
	#include "processor.h"
	#include "line.h"
	#include "rs.h"
	#include "functional_unit.h"
	#include <stdio.h>
	#include <stdlib.h>

	memory *mem;
	list *llist, *olist;
	line *iline;
	fu_unit *fu;
	reserve_station *rs;
	reg_bank *regi;


	int ic = 0;
	int vcount = 0;
	int lcount = 0;
	int ocount = 0;
%}

%union {
	char *opp, *reg, *label;
	int value;
};

%token ARCH A_SUM A_MUL A_DIV A_BIN A_BCH A_BES VALUE RE_SUM RE_SUB RE_DIV RE_MUL MEM_SIZE
%token TEXTO DDATA DTEXT
%token CICLOS REG_I REG2 REG2_L REG2_I REG3 LAB CIFRAO
%token REG LABEL COMMA COLLON EQUAL EOL TYPE

%type <opp> REG3 REG2_I REG2_L REG2 REG_I LAB A_SUM A_MUL A_DIV A_BIN A_BCH A_BES
%type <value> VALUE
%type <reg> REG COMMA COLLON DTEXT
%type <label> LABEL

%%
	all:
		ARCH EOL set_arch
		CICLOS EOL set_cicles
		TEXTO EOL
		DDATA EOL dados
		DTEXT EOL program {
			printf("Text\t\t[OK]\n");
		}
	;

	set_arch:
		A_SUM EQUAL VALUE EOL
		A_MUL EQUAL VALUE EOL
		A_DIV EQUAL VALUE EOL
		A_BIN EQUAL VALUE EOL
		A_BCH EQUAL VALUE EOL
		A_BES EQUAL VALUE EOL
		RE_SUM EQUAL VALUE EOL
		RE_SUB EQUAL VALUE EOL
		RE_DIV EQUAL VALUE EOL
		RE_MUL EQUAL VALUE EOL
		MEM_SIZE EQUAL VALUE EOL {
			mem = initiate_mem($43);
			fu = initiate_fu($7, $11, $15);
			rs = initiate_rs($27, $31, $35, $39);
			regi = initiate_breg();
			search = $15;
			printf("Architecture\t[OK]\n");
		}
	;

	set_cicles:
		REG3 EQUAL VALUE EOL set_cicles {
			cicles[binary_to_decimal($1, 0, 5)] = $3;
		}
		| REG2 EQUAL VALUE EOL set_cicles {
			cicles[binary_to_decimal($1, 0, 5)] = $3;
		}
		| REG2_I EQUAL VALUE EOL set_cicles {
			cicles[binary_to_decimal($1, 0, 5)] = $3;
		}
		| REG2_L EQUAL VALUE EOL set_cicles {
			cicles[binary_to_decimal($1, 0, 5)] = $3;
		}
		| REG_I EQUAL VALUE EOL set_cicles {
			cicles[binary_to_decimal($1, 0, 5)] = $3;
		}
		| LAB EQUAL VALUE EOL set_cicles {
			cicles[binary_to_decimal($1, 0, 5)] = $3;
		}
		| {
			printf("Cicles\t\t[OK]\n");
		}
	;

	dados:
		TYPE VALUE EOL dados {
			copy(mem, decimal_to_binary($2), 0, 31, vcount, 0);
			vcount++;
		}
		|
	;

	text_in:
		REG3 REG COMMA REG COMMA REG EOL {
			copy(mem, $1, 0, 5, mem -> size - ic - 1, 0);
			copy(mem, decimal_to_binary(atoi(get_register($2)) - 1), 6, 10, mem -> size - ic - 1, 27);
			copy(mem, decimal_to_binary(atoi(get_register($4)) - 1), 11, 15, mem -> size - ic - 1, 27);
			copy(mem, decimal_to_binary(atoi(get_register($6)) - 1), 16, 21, mem -> size - ic - 1, 27);
			ic++;
		}
		| REG2 REG COMMA REG EOL {
			copy(mem, $1, 0, 5, mem -> size - ic - 1, 0);
			copy(mem, decimal_to_binary(atoi(get_register($2)) - 1), 6, 10, mem -> size - ic - 1, 27);
			copy(mem, decimal_to_binary(atoi(get_register($4)) - 1), 11, 15, mem -> size - ic - 1, 27);
			ic++;
		}
		| REG2_I REG COMMA REG COMMA CIFRAO VALUE EOL {
			copy(mem, $1, 0, 5, mem -> size - ic - 1, 0);
			copy(mem, decimal_to_binary(atoi(get_register($2)) - 1), 6, 10, mem -> size - ic - 1, 27);
			copy(mem, decimal_to_binary(atoi(get_register($4)) - 1), 11, 15, mem -> size - ic - 1, 27);
			copy(mem, decimal_to_binary($7), 16, 31, mem -> size - ic - 1, 16);
			ic++;
		}
		| REG_I REG COMMA CIFRAO VALUE EOL {
			copy(mem, $1, 0, 5, mem -> size - ic - 1, 0);
			copy(mem, decimal_to_binary(atoi(get_register($2)) - 1), 6, 10, mem -> size - ic - 1, 27);
			copy(mem, decimal_to_binary($5), 11, 31, mem -> size - ic - 1, 11);
			ic++;
		}
		| REG2_L REG COMMA REG COMMA LABEL EOL {
			copy(mem, $1, 0, 5, mem -> size - ic - 1, 0);
			copy(mem, decimal_to_binary(atoi(get_register($2)) - 1), 6, 10, mem -> size - ic - 1, 27);
			copy(mem, decimal_to_binary(atoi(get_register($4)) - 1), 11, 15, mem -> size - ic - 1, 27);
			insert_list(olist, $6, mem -> size - ic - 1, &ocount);
			ic++;
		}
		| REG_I REG COMMA LABEL EOL {
			copy(mem, $1, 0, 5, mem -> size - ic - 1, 0);
			copy(mem, decimal_to_binary(atoi(get_register($2)) - 1), 6, 10, mem -> size - ic - 1, 27);
			insert_list(olist, $4, mem -> size - ic - 1, &ocount);
			ic++;
		}
		| LAB LABEL EOL {
			copy(mem, $1, 0, 5, mem -> size - ic - 1, 0);
			insert_list(olist, $2, mem -> size - ic - 1, &ocount);
			ic++;
		}
	;

	l:
		LABEL COLLON EOL {
			insert_list(llist, $1, mem -> size - ic - 1, &lcount);
		}
	;

	program:
		| l text_in program
		| text_in program
	;

%%

int yyerror(const char *ptr) {
	printf("%s\n\n", ptr);
	exit(EXIT_FAILURE);
};

int main(int argc, char **argv) {
	FILE *input = fopen(argv[1], "r");
	yyrestart(input);
	llist = initialize_list();
	olist = initialize_list();
	yyparse();
	set_address(llist, olist, lcount, ocount, mem);
	iline = initiate();
	print_mem(*mem);
	printf("Press ENTER to continue...");
	getchar();
	int clock = 0;
	do {
		printf("\n\nClock #%d\n\n", clock);
		execute(&pc, rs, fu);
		issue(&pc, iline, rs, regi);
		fetch(mem, iline, &pc, &ic);
		showLine(iline);
		show_rs(rs);
		printf("Press ENTER to continue...");
		getchar();
		clock++;
	} while(1);
	return 0;
}
