%{
    int lines=0;
%}

LINE \n

%%
{LINE} {ECHO;printf("%d", ++lines);}
%%

main()
{
    printf("%d", ++lines);
    yylex();
}
