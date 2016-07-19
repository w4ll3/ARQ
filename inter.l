%{
#include "inter.tab.h"
%}

%%
[ \t] {}
[a-z"_"]* { return ARCHITECTURE; }
"=" { return EQUALS; }
[0-9]+ { return VALUE; }
"r""R"^[0-9]* { printf("%s\n", yytext); }
["$"0-9]* { return INSTANT; }
. { }
%%

main(int argc, char **argv) {
    while(1)
        yylex();
}
