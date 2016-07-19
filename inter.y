%{
    #include <stdio.h>
%}

%token OPCODE
%token REGISTER
%token LABEL
%token INSTANT
%token ARCHITECTURE
%token VALUE
%token EQUALS

%%
    nothing: ARCHITECTURE EQUALS VALUE { printf("%s = %d", $1, $2); }
%%

yyerror(){}
