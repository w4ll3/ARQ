%{
	int yylex();
	void yyerror(const char *s);

	#include "memory.h"

	typedef struct llist {
		char *label, *address;
	} llist;

	memory *mem;
	llist *list = (llist*) malloc(sizeof(llist*));
	list -> label = (char*) malloc(sizeof(char*));
	list -> address = (char*) malloc(sizeof(char*));

	int pc = 0;
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
			printf("EndP\n");
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
		mem = initialize_mem($43);
		printf("Architecture\t[OK]\n");
	};

	inst:
	REG3 | REG2 | REG2_I | REG2_L | REG_I | LAB
	;

	set_cicles:
	inst
	EQUAL VALUE EOL
	set_cicles {

	}
	| {
		printf("Cicles\t\t[OK]\n");
	};

	dados:
	TYPE VALUE EOL dados {

	}
	| {
		printf(".data\t\t[OK]\n");
	};

	text_in:
	REG3 REG COMMA REG COMMA REG EOL {
		printf("[%.3d]  %s %s, %s, %s \n", pc, $1, $2, $4, $6);
		set_opcode($1, mem, pc);
		pc++;
	}
	| REG2 REG COMMA REG COMMA EOL {
		printf("[%.3d]  %s %s, %s \n", pc, $1, $2, $4);
		set_opcode($1, mem, pc);
		pc++;
	}
	| REG2_I REG COMMA REG COMMA CIFRAO VALUE EOL {
		printf("[%.3d]  %s %s, %s, %d\n", pc, $1, $2, $4, $7);
		set_opcode($1, mem, pc);
		pc++;
	}
	| REG2_L REG COMMA REG COMMA LABEL EOL {
		printf("[%.3d]  %s %s, %s, %s \n", pc, $1, $2, $4, $6);
		set_opcode($1, mem, pc);
		pc++;
	}
	| REG_I REG COMMA CIFRAO VALUE EOL {
		printf("[%.3d]  %s %s, %d\n", pc, $1, $2, $5);
		set_opcode($1, mem, pc);
		pc++;
	}
	| REG_I REG COMMA LABEL EOL {
		printf("[%.3d]  %s %s, %s \n", pc, $1, $2, $4);
		set_opcode($1, mem, pc);
		pc++;
	}
	| LAB LABEL EOL {
		printf("[%.3d]  %s %s \n", pc, $1, $2);
		set_opcode($1, mem, pc);
		pc++;
	};

	l:
	LABEL COLLON EOL {
		printf("[%.3d]  %s:\n", pc, $1);
		list -> label = $1;
		list -> address = mem -> data[pos];
		list = realloc(list, sizeof(list * 2));
		pc++;
	};

	program:
	| l text_in program
	| text_in program;

%%

void yyerror(const char *s){};

int main(int argc, char **argv) {
	yyparse();
}

/*
	.text
		add		Rd, Rs, Rt					Rd = Rs + Rt
		addi	Rt, Rs, Imed				Rt = Rs + Imed
		and		Rd, Rs, Rt					Rd = Rs AND Rt
		andi	Rt, Rs, Imed				Rt = Rs NOT Imed
		b		label						pc = label
		beq		Rs, Rt, label				Rs == Rt -> pc <- label
		beqz	Rs, label					Rs == 0 -> pc <- label
		bgt		Rs, Rt, label				Rs > Rt -> pc <- label
		bge		Rs, Rt, label				Rs >= Rt -> pc <- label
		bgtz	Rs, label					Rs > 0 -> pc <- label
		blt		Rs, Rt, label				Rs < Rt -> pc <- label
		ble		Rs, Rt, label				Rs <= Rt -> pc <- label
		blez	Rs, label					Rs <= 0 -> pc <- label
		bne		Rs, Rt, label				Rs != Rt -> pc <- label
		bnez	Rs, label					Rs != 0 -> pc <- label
		div		Rd, Rs, Rt					Rd = Rs / Rt
		divi	Rt, Rs, Imed				Rt = Rs / Imed
		ld		Rb, Ra						Rb = Ra
		li		Rb, Imed					Rb = Imed
		move	Ra, Rb						Ra = Rb
		mult	Rd, Rs, Rt					Rd = Rs * Rt
		multi	Rd, Rs, Imed				Rd = Rs - Imed
		neg		Rd, Rs						Rd = -Rs
		not		Rd, Rs						Rd = NOT Rs
		or		Rd, Rs, Rt					Rd = Rs OR Rt
		ori		Rd, Rs, Imed				Rd = Rs OR Imed
		sll		Rd, Rs, Num					Rd = Rs << Num(times)
		slr		Rd, Rs, Num					Rd = Rs >> Num(times)
		st		Rb, Ra						Ra = Rb
		sub		Rd, Rs, Rt					Rd = Rs - Rt
		subi	Rt, Rs, Imed				Rt = Rs - Imed
*/
