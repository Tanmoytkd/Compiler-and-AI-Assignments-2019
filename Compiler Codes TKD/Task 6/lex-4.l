
%%
^\n fprintf(yyout,"%4d\n", yylineno-1);
a countA++;
b countB++;
c countC++;
. ;
\n {fprintf(yyout,"%4d\tA:%4d\tB:%4d\tC:%4d\n", yylineno-1,countA,countB,countC); countA=0; countB=0; countC=0;}
<<EOF>> {fprintf(yyout,"%4d\tA:%4d\tB:%4d\tC:%4d", yylineno,countA,countB,countC); yyterminate();}
%%