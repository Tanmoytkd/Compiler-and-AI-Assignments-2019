%{
    int counta=0,countb=0,countc=0;	
%}
%option main
%option yylineno
%%
A {printf("%4d",counta);
      counta++; } 
B {printf("%4d",countb);
      countb++; } 
%%