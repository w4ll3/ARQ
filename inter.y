%{
    #include <stdio.h>
%}

%union {
	char *opp, *reg, *label;
	int value;
};

%token arch a_sum a_mul a_div a_bch a_bes a_param a_bin
%token texto data text
%token ciclos reg_l reg_i reg2 reg2_l reg2_i reg3 lab
%token reg label imed comma collon equal eol

%type <opp> reg3 reg2_i reg2_l reg2 reg_l reg_i lab a_sum a_mul a_div a_bin a_bch a_bes
%type <value> a_param imed
%type <reg> reg

%%
	all:
		arch eol set_arch
		ciclos eol set_cicles
		texto eol assembly
	;
	set_arch:
	a_sum equal a_param eol
	a_mul equal a_param eol
	a_div equal a_param eol
	a_bin equal a_param eol
	a_bch equal a_param eol
	a_bes equal a_param eol
	{
	printf("Architecture\t[OK]\n\
	--Somador\t\t\t[%5d]\n\
	--Multiplicador\t\t\t[%5d]\n\
	--Divisor\t\t\t[%5d]\n\
	--Busca de instrucoes\t\t[%5d]\n\
	--Buffer de carga\t\t[%5d]\n\
	--Buffer de escrita\t\t[%5d]\n\n",
		$3, $7, $11, $15, $19, $23);
	};

	inst:
	reg3 | reg2 | reg2_i | reg2_l | reg_i | lab
	;

	set_cicles:
	inst
	equal a_param eol
	set_cicles
	{

	}
	| {
		printf("Cicles\t\t[OK]\n");
	};

	assembly:
	;

	dados:
	data

%%

yyerror(){}

int main(int argc, char **argv) {
	yyparse();
}
