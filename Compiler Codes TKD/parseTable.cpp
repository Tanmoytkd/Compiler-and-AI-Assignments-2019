#include<bits/stdc++.h>
using namespace std;

int main()
     {
       char tmp[15];
       char str[15], csf[15];
       int ssm=0, i, j, v, k, pos=0, a;


       char pt[6][5][4]={"" , "i" , "+" , "*" , "/",
             "E", "TX", "n" , "n" , "n",
             "X", "n" , "+TX", "n" , "" ,
             "T", "VY", "n" , "n" , "n",
             "Y", "n" , ""  , "*VY", "" ,
             "V", "i" , "n" , "n" , "n"};
     cout<<"\n Enter An Expression: "<<endl;
     cin>>str;
     strcpy(csf,"E");
     while(1)
    {
      pos=0;
      while(csf[pos]!='E' &&         //find leftmost NT from csf
        csf[pos]!='X' &&
        csf[pos]!='T' &&
        csf[pos]!='Y' &&
        csf[pos]!='V' && csf[pos]!='\0')
        pos++;
      ssm=pos;
    if (csf[pos]=='\0')             // if csf contains all terminals then exitbreak;

    for(i=1; i<6; i++)              // find left most NT into parser table into first column
      {
        if(csf[pos]==pt[i][0][0])
           break;
      }
       for(j=1; j<5; j++)            // find the ssm character from source string into parser table into first row
      {
         if(str[ssm]==pt[0][j][0])
        break;
      }

       if(strcmp(pt[i][j],"n")==0)     // if entry is not there in parser table, error and exit.
       {
          cout<<"\n Production does not exist: "<<endl;
          cout<<pt[i][j];
          exit(0);
       }

       for(k=0; k<pos; k++)              // replace NT into csf with its parser table entry
       tmp[k]=csf[k];
       tmp[k]='\0';
       strcat(tmp, pt[i][j]);
       int l=strlen(tmp);

       for(a=pos+1; csf[a]!='\0'; a++, l++)
       tmp[l]=csf[a];
       tmp[l]='\0';
       strcpy(csf, tmp);
       cout<<"\n"<<str[ssm]<<"\t"<<csf;

 }
       strcat(csf, "/");

       cout<<"\t\tcsf ::"<<csf;

     if(strcmp(csf, str)==0)
         {
         cout<<"\n Valid Expression: "<<endl;
         }
     else
         {
          cout<<"\n Invalid Expression:"<<endl;
         }

      return 0;
}
