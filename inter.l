%option noyywrap
%{
	#include <stdio.h>
	#include "inter.tab.h"
%}

%%

"ARQUITETURA"				{ 					return arch;					}
"somador"					{					return a_sum;					}
"multiplicador"				{					return a_mul;					}
"divisor"					{					return a_div;					}
"busca_de_instrucoes"		{					return a_bin;					}
"buffer_de_carga"			{					return a_bch;					}
"buffer_de_escrita"			{					return a_bes;					}

"TEXTO"                     {					return texto;					}
".data"						{					return data;					}
".text"						{					return text;					}

"CICLOS"					{					return ciclos;					}
"addi"						{	yylval.opp = "100000";			return reg2_i;	}
"add"						{	yylval.opp = "000101";			return reg3;	}
"andi"						{	yylval.opp = "100100";			return reg2_i;	}
"and"						{	yylval.opp = "001001";			return reg3;	}
"beqz"						{	yylval.opp = "010001";			return reg_i;	}
"beq"						{	yylval.opp = "100110";			return reg2_l;	}
"bgtz"						{	yylval.opp = "010011";			return reg_i;	}
"bge"						{	yylval.opp = "101001";			return reg2_l;	}
"bgt"						{	yylval.opp = "101000";			return reg2_l;	}
"blez"						{	yylval.opp = "010100";			return reg_i;	}
"ble"						{	yylval.opp = "101011";			return reg2_l;	}
"blt"						{	yylval.opp = "101010";			return reg2_l;	}
"bnez"						{	yylval.opp = "010010";			return reg_i;	}
"bne"						{	yylval.opp = "100111";			return reg2_l;	}
"b"							{	yylval.opp = "110000";			return lab;		}
"divi"						{	yylval.opp = "100011";			return reg2_i;	}
"div"						{	yylval.opp = "001000";			return reg3;	}
"ld"						{	yylval.opp = "000000";			return reg2;	}
"li"						{	yylval.opp = "010000";			return reg_i;	}
"move"						{	yylval.opp = "000010";			return reg2;	}
"multi"						{	yylval.opp = "100010";			return reg2_i;	}
"mult"						{	yylval.opp = "000111";			return reg3;	}
"neg"						{	yylval.opp = "000011";			return reg2;	}
"not"						{	yylval.opp = "000100";			return reg2;	}
"ori"						{	yylval.opp = "100101";			return reg2_i;	}
"or"						{	yylval.opp = "001010";			return reg3;	}
"slr"						{	yylval.opp = "001100";			return reg3;	}
"sll"						{	yylval.opp = "001011";			return reg2_i;	}
"st"						{	yylval.opp = "000001";			return reg3;	}
"subi"						{	yylval.opp = "100001";			return reg2_i;	}
"sub"						{	yylval.opp = "000110";			return reg3;	}

[0-9]+						{	yylval.value = atoi(yytext);	return a_param;	}
[rR][0-9]+					{	yylval.reg = yytext;			return reg;		}
"$"\-?[0-9]					{	yylval.value = atoi(yytext);	return imed;	}
[[:alpha:]]					{	yylval.label = yytext;			return label;	}
".int"						{					return type;					}
","							{					return comma;					}
":"							{					return collon;					}
"="							{					return equal;					}
[\r?\n]*					{					return eol;						}
[ \t]*						{					/*spaces*/						}
.							{					/*others*/						}

%%
