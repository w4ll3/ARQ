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

"TEXTO"                     {					return TEXTO;					}
".data"						{					return DDATA;					}
".int"						{					return TYPE;					}
".text"						{					return DTEXT;					}

"CICLOS"					{					return CICLOS;					}
"addi"						{	yylval.opp = "100000";			return REG2_I;	}
"add"						{	yylval.opp = "000101";			return REG3;	}
"andi"						{	yylval.opp = "100100";			return REG2_I;	}
"and"						{	yylval.opp = "001001";			return REG3;	}
"beqz"						{	yylval.opp = "010001";			return REG_I;	}
"beq"						{	yylval.opp = "100110";			return REG2_L;	}
"bgtz"						{	yylval.opp = "010011";			return REG_I;	}
"bge"						{	yylval.opp = "101001";			return REG2_L;	}
"bgt"						{	yylval.opp = "101000";			return REG2_L;	}
"blez"						{	yylval.opp = "010100";			return REG_I;	}
"ble"						{	yylval.opp = "101011";			return REG2_L;	}
"blt"						{	yylval.opp = "101010";			return REG2_L;	}
"bnez"						{	yylval.opp = "010010";			return REG_I;	}
"bne"						{	yylval.opp = "100111";			return REG2_L;	}
"b"							{	yylval.opp = "110000";			return LAB;		}
"divi"						{	yylval.opp = "100011";			return REG2_I;	}
"div"						{	yylval.opp = "001000";			return REG3;	}
"ld"						{	yylval.opp = "000000";			return REG2;	}
"li"						{	yylval.opp = "010000";			return REG_I;	}
"move"						{	yylval.opp = "000010";			return REG2;	}
"multi"						{	yylval.opp = "100010";			return REG2_I;	}
"mult"						{	yylval.opp = "000111";			return REG3;	}
"neg"						{	yylval.opp = "000011";			return REG2;	}
"not"						{	yylval.opp = "000100";			return REG2;	}
"ori"						{	yylval.opp = "100101";			return REG2_I;	}
"or"						{	yylval.opp = "001010";			return REG3;	}
"slr"						{	yylval.opp = "001100";			return REG3;	}
"sll"						{	yylval.opp = "001011";			return REG2_I;	}
"st"						{	yylval.opp = "000001";			return REG3;	}
"subi"						{	yylval.opp = "100001";			return REG2_I;	}
"sub"						{	yylval.opp = "000110";			return REG3;	}

[rR][0-9]+					{	yylval.reg = strdup(yytext);	return REG;		}
"$"							{					return CIFRAO;					}
\-?[0-9]+					{	yylval.value = atoi(yytext);	return VALUE;	}
[[:alpha:]]+				{	yylval.label = strdup(yytext);	return LABEL;	}
","							{					return COMMA;					}
":"							{					return COLLON;					}
"="							{					return EQUAL;					}
[\r?\n]+					{					return EOL;						}
[ \t]						{					/*spaces*/						}
.							{					printf("coisa\n");				}

%%
