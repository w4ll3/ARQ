%option noyywrap
%{
	#include <stdio.h>
	#include "inter.tab.h"
%}

%%

"ARQUITETURA"				{ 					return ARCH;					}
"somador"					{					return A_SUM;					}
"multiplicador"				{					return A_MUL;					}
"divisor"					{					return A_DIV;					}
"busca_de_instrucoes"		{					return A_BIN;					}
"buffer_de_carga"			{					return A_BCH;					}
"buffer_de_escrita"			{					return A_BES;					}
"re_sum"					{					return RE_SUM;					}
"re_sub"					{					return RE_SUB;					}
"re_div"					{					return RE_DIV;					}
"re_mul"					{					return RE_MUL;					}

"TEXTO"                     {					return TEXTO;					}
".data"						{					return DDATA;					}
".int"						{					return TYPE;					}
".text"						{					return DTEXT;					}

"CICLOS"					{					return CICLOS;					}
"b"							{	yylval.opp = "110000";			return LAB;		}
"beqz"						{	yylval.opp = "010001";			return REG_I;	}
"bgtz"						{	yylval.opp = "010011";			return REG_I;	}
"blez"						{	yylval.opp = "010100";			return REG_I;	}
"bnez"						{	yylval.opp = "010010";			return REG_I;	}
"li"						{	yylval.opp = "010000";			return REG_I;	}
"addi"						{	yylval.opp = "100000";			return REG2_I;	}
"andi"						{	yylval.opp = "100100";			return REG2_I;	}
"divi"						{	yylval.opp = "100011";			return REG2_I;	}
"multi"						{	yylval.opp = "100010";			return REG2_I;	}
"ori"						{	yylval.opp = "100101";			return REG2_I;	}
"sll"						{	yylval.opp = "001011";			return REG2_I;	}
"subi"						{	yylval.opp = "100001";			return REG2_I;	}
"beq"						{	yylval.opp = "100110";			return REG2_L;	}
"bge"						{	yylval.opp = "101001";			return REG2_L;	}
"bgt"						{	yylval.opp = "101000";			return REG2_L;	}
"ble"						{	yylval.opp = "101011";			return REG2_L;	}
"blt"						{	yylval.opp = "101010";			return REG2_L;	}
"bne"						{	yylval.opp = "100111";			return REG2_L;	}
"add"						{	yylval.opp = "000101";			return REG3;	}
"and"						{	yylval.opp = "001001";			return REG3;	}
"div"						{	yylval.opp = "001000";			return REG3;	}
"ld"						{	yylval.opp = "000000";			return REG2;	}
"move"						{	yylval.opp = "000010";			return REG2;	}
"mult"						{	yylval.opp = "000111";			return REG3;	}
"neg"						{	yylval.opp = "000011";			return REG2;	}
"not"						{	yylval.opp = "000100";			return REG2;	}
"or"						{	yylval.opp = "001010";			return REG3;	}
"slr"						{	yylval.opp = "001100";			return REG3;	}
"st"						{	yylval.opp = "000001";			return REG3;	}
"sub"						{	yylval.opp = "000110";			return REG3;	}

[[:alpha:]]+				{	yylval.label = strdup(yytext);	return LABEL;	}
[rR][0-9]+					{	yylval.reg = strdup(yytext);	return REG;		}
"$"							{					return CIFRAO;					}
\-?[0-9]+					{	yylval.value = atoi(yytext);	return VALUE;	}
","							{					return COMMA;					}
":"							{					return COLLON;					}
"="							{					return EQUAL;					}
[\r?\n]+					{					return EOL;						}
[ \t]						{					/*spaces*/						}
.							{	printf("'%s' is not a valid entry.\n", yytext);	}

%%
