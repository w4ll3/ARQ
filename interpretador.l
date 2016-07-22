%option noyywrap
%{
    #include <stdio.h>
    #include <string.h>
    #include "interpretador.tab.h"
%}

%%
"ARQUITETURA"         {return ARQUITETURA;      }
"somador"             {return SOMADOR;      }
"multiplicador"       {return MULTIPLICADOR;      }
"divisor"             {return DIVISOR;      }
"busca_de_instrucoes" {return BUSCA_DE_INSTRUCOES;      }
"buffer_de_carga"     {return BUFFER_DE_CARGA;      }
"buffer_de_escrita"   {return BUFFER_DE_ESCRITA;      }

"CICLOS"              {return CICLOS;       }


"TEXTO"               { return TEXTO;                     }
".data"               { return DOTDATA;                    }
".text"               { return DOTTEXT;                     }

"ld"                  { yylval.op = strdup(yytext);  return OPERATION_2R;                   }
"st"                  { yylval.op = strdup(yytext);  return OPERATION_2R;                   }
"li"                  { yylval.op = strdup(yytext);  return OPERATION_R_I;                   }
"move"                { yylval.op = strdup(yytext);  return OPERATION_2R;                   }

"beq"                 { yylval.op = strdup(yytext);  return OPERATION_2R_L;                   }
"beqz"                { yylval.op = strdup(yytext);  return OPERATION_R_L;                   }
"bne"                 { yylval.op = strdup(yytext);  return OPERATION_2R_L;                   }
"bnez"                { yylval.op = strdup(yytext);  return OPERATION_R_L;                   }
"bgt"                 { yylval.op = strdup(yytext);  return OPERATION_2R_L;                   }
"bge"                 { yylval.op = strdup(yytext);  return OPERATION_2R_L;                   }
"bgtz"                { yylval.op = strdup(yytext);  return OPERATION_R_L;                   }
"blt"                 { yylval.op = strdup(yytext);  return OPERATION_2R_L;                   }
"ble"                 { yylval.op = strdup(yytext);  return OPERATION_2R_L;                   }
"blez"                { yylval.op = strdup(yytext);  return OPERATION_R_L;                   }
"b"                   { yylval.op = strdup(yytext);  return OPERATION_L;                   }

"add"                 { yylval.op = strdup(yytext);  return OPERATION_3R;                   }
"addi"                { yylval.op = strdup(yytext);  return OPERATION_2R_I;                   }
"sub"                 { yylval.op = strdup(yytext);  return OPERATION_3R;                   }
"subi"                { yylval.op = strdup(yytext);  return OPERATION_2R_I;                   }
"mult"                { yylval.op = strdup(yytext);  return OPERATION_3R;                   }
"multi"               { yylval.op = strdup(yytext);  return OPERATION_2R_I;                   }
"div"                 { yylval.op = strdup(yytext);  return OPERATION_3R;                   }
"divi"                { yylval.op = strdup(yytext);  return OPERATION_2R_I;                   }

"and"                 { yylval.op = strdup(yytext);  return OPERATION_3R;                   }
"andi"                { yylval.op = strdup(yytext);  return OPERATION_2R_I;                   }
"or"                  { yylval.op = strdup(yytext);  return OPERATION_3R;                   }
"ori"                 { yylval.op = strdup(yytext);  return OPERATION_2R_I;                   }
"neg"                 { yylval.op = strdup(yytext);  return OPERATION_2R;                   }
"not"                 { yylval.op = strdup(yytext);  return OPERATION_2R;                   }
"sll"                 { yylval.op = strdup(yytext);  return OPERATION_3R;                   }
"slr"                 { yylval.op = strdup(yytext);  return OPERATION_3R;                   }

[rR][0-9]+             { yylval.r = strdup(yytext); return R;              }

"$"             {return DOLLAR;              }


\-?[0-9]+                { yylval.value = atoi(yytext); return VALUE;                  }

[a-zA-Z]+             { yylval.l = strdup(yytext); return L;              }


[ \t]                 { /* ignore white space */                   }

":"                  {return COLON;}

\n                   { return EOL;                                }

","                   { return COMMA;                                }

"="                   { return EQUAL;                                }

".int"                 {return DATATYPE ;                            }

.                     { printf("invalid character %c\n", *yytext); }
%%

/* int main(int argc, char **argv){
    yylex();
} */
