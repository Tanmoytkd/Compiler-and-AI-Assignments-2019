%option yylineno
%option noyywrap
%%
^\n fprintf(yyout,"%4d\n", yylineno-1);
(.*) fprintf(yyout,"%4d\t%s", yylineno, yytext);
\n ECHO;
%%
int main(int argc, char *argv[]) {
 yyin = fopen(argv[1], "r");
 yyout = fopen(argv[2], "w");
 yylex();
 fclose(yyin);
 fclose(yyout);
}