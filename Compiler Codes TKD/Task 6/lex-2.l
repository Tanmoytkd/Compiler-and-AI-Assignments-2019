/*a Flex Program [Lex2.l] that will print line no # and the line*/

%option yylineno
%option main
%%
^\n printf("%4d\n", yylineno-1);
(.*) printf("%4d\t%s", yylineno, yytext);
\n ECHO;
%%