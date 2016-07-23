%{
    #include <stdio.h>
%}

%union {
	char *opp, *reg, *label;
	int value;
};

%token ARCH A_SUM A_MUL A_DIV A_BIN A_BCH A_BES VALUE
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
			printf("Error\n");
		}
	;

	set_arch:
	A_SUM EQUAL VALUE EOL
	A_MUL EQUAL VALUE EOL
	A_DIV EQUAL VALUE EOL
	A_BIN EQUAL VALUE EOL
	A_BCH EQUAL VALUE EOL
	A_BES EQUAL VALUE EOL {
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
		printf("%s %s, %s, %s \n", $1, $2, $4, $6);
	}
	| REG2 REG COMMA REG COMMA EOL {
		printf("%s %s, %s, %s \n", $1, $2, $4);
	}
	| REG2_I REG COMMA REG COMMA CIFRAO VALUE EOL {
		printf("%s %s, %s, %d \n", $1, $2, $4, $7);
	}
	| REG2_L REG COMMA REG COMMA LABEL EOL {
		printf("%s %s, %s, %s \n", $1, $2, $4, $6);
	}
	| REG_I REG COMMA CIFRAO VALUE EOL {
		printf("%s %s, %d \n", $1, $2, $5);
	}
	| REG_I REG COMMA LABEL EOL {
		printf("%s %s, %d \n", $1, $2, $4);
	}
	| LAB LABEL EOL {
		printf("%s %s \n", $1, $2);
	};

	l:
	LABEL COLLON EOL {
		printf("%s:\n", $1);
	};

	program:
	l text_in program
	| text_in program
	| {
		printf(".text\t\t[OK]\n");
	};

%%

yyerror(){}

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


000101
100000
001001
100100
110000
100110
010001
101001
101000
010011
101011
010100
101010
100111
010010
001000
100011
000000
010000
000010
000111
100010
000011
000100
001010
100101
001011
001100
000001
000110
100001
*/
