%{
    int counta=0,countb=0,countc=0;	
%}
%option main
%option yylineno
%%
CSE {printf("Match Found\n");} 
EEE {printf("Match Found\n");} 
PHY {printf("Match Found\n");} 
MAT {printf("Match Found\n");} 
GEB {printf("Match Found\n");} 
STA {printf("Match Found\n");} 
SOC {printf("Match Found\n");} 
SCW {printf("Match Found\n");} 
BMB {printf("Match Found\n");} 
IPE {printf("Match Found\n");} 
... {printf("Match Not Found\n");} 
\n ;
%%