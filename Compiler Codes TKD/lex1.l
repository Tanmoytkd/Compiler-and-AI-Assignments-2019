%%
"+" {printf("PLUS ");}

%%
main(int argc, char** argv)
{
yylex();
}
//lex lex1.l
//gcc lex.yy.c -lfl
//./a.out
