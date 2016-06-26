#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
using namespace std;

int gra(int mspf);

int main()
{
    char poziom='0';
    int mspf,a;
    cout<<" __________ "<<endl
        <<"|          |"<<endl
        <<"|          |"<<endl
        <<"|          |"<<endl
        <<"|KONSOLOWY |"<<endl
        <<"|          |"<<endl
        <<"|  ARKANOID|"<<endl
        <<"|          |"<<endl
        <<"|          |"<<endl
        <<"|          |"<<endl
        <<"|by        |"<<endl
        <<"|    Michal|"<<endl
        <<"|  Szewczak|"<<endl
        <<"|__________|";
    getch();
    
    system("CLS");
    cout<<" __________ "<<endl
        <<"|          |"<<endl
        <<"|          |"<<endl
        <<"|          |"<<endl
        <<"|wybierz   |"<<endl
        <<"| poziom   |"<<endl
        <<"| trudnosci|"<<endl
        <<"|          |"<<endl
        <<"|          |"<<endl
        <<"|1 = easy  |"<<endl
        <<"|2 = medium|"<<endl
        <<"|3 = hard  |"<<endl
        <<"|          |"<<endl
        <<"|__________|";
    while(poziom!='1'&&poziom!='2'&&poziom!='3')
    {
     poziom=getch();
     switch(poziom)
     {
      case '1': {mspf=1000; break;}  //mspf dla EASY
      case '2': {mspf=500;  break;}  //mspf dla MEDIUM
      case '3': {mspf=200;  break;}  //mspf dla HARD
     }
    }
    a=gra(mspf);
    switch(a)
    {
     case 0:{ 
     system("CLS");
     cout<<" __________ "<<endl
        <<"|          |"<<endl
        <<"|PRZEGRANA |"<<endl
        <<"|          |"<<endl
        <<"| PRZEGRANA|"<<endl
        <<"|          |"<<endl
        <<"|PRZEGRANA |"<<endl
        <<"|          |"<<endl
        <<"| PRZEGRANA|"<<endl
        <<"|          |"<<endl
        <<"|PRZEGRANA |"<<endl
        <<"|          |"<<endl
        <<"| PRZEGRANA|"<<endl
        <<"|__________|";
     break;}
    
     case 1:{ 
     system("CLS");
     cout<<" __________ "<<endl
        <<"|          |"<<endl
        <<"|WYGRANA   |"<<endl
        <<"|          |"<<endl
        <<"|   WYGRANA|"<<endl
        <<"|          |"<<endl
        <<"|WYGRANA   |"<<endl
        <<"|          |"<<endl
        <<"|   WYGRANA|"<<endl
        <<"|          |"<<endl
        <<"|WYGRANA   |"<<endl
        <<"|          |"<<endl
        <<"|   WYGRANA|"<<endl
        <<"|__________|";
     break;}
    }

    getch();
    return 0;
}


int gra(int mspf)
{
    char board[14][13]={' ','_','_','_','_','_','_','_','_','_','_',' ','\0',
                        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','\0',
                        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','\0',
                        '|','X','X','X','X','X','X','X','X','X','X','|','\0',
                        '|','X','X','X','X','X','X','X','X','X','X','|','\0',
                        '|','X','X','X','X','X','X','X','X','X','X','|','\0',
                        '|','X','X','X','X','X','X','X','X','X','X','|','\0',
                        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','\0',
                        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','\0',
                        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','\0',
                        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','\0',
                        '|',' ',' ',' ','*','*','*',' ',' ',' ',' ','|','\0',
                        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','\0',
                        '|','_','_','_','_','_','_','_','_','_','_','|','\0',};
    int bar=5, yball=8, xball, kierX=-1, kierY=-1,klocki=20,i=0,ii=0;
    long int timer;                    
    srand(time(0));
    xball=rand()%8+2;
    board[yball][xball]='O';
    timer=GetTickCount();
    system("CLS");
    while(1)
    {
           if(GetTickCount()-timer>=mspf)         //poczatek ruchu pilki
           {
            timer=GetTickCount();
            if(board[yball--][xball]=='_'||board[yball--][xball]=='X'||board[yball++][xball]=='X'||board[yball++][xball]=='*')
            kierY=-kierY;
            if(board[yball][xball++]=='|'||board[yball][xball++]=='X'||board[yball][xball--]=='|'||board[yball][xball--]=='X')
            kierX=-kierX;
     
            if(board[yball--][xball]=='X')  //niszczenie klockow
            {
             board[yball--][xball]=' ';
             if(xball&2==1)
             board[yball--][xball++]=' ';
             else
             board[yball--][xball--]=' ';
             klocki--;
            }
            if(board[yball++][xball]=='X')
            {
             board[yball++][xball]=' ';
             if(xball&2==1)
             board[yball++][xball++]=' ';
             else
             board[yball++][xball--]=' ';
             klocki--;
            }
            if(board[yball][xball++]=='X')
            {
             board[yball][xball++]=' ';
             if(xball++&2==1)
             board[yball][xball+2]=' ';
             else
             board[yball][xball++]=' ';
             klocki--;
            }
            if(board[yball][xball--]=='X')
            {
             board[yball][xball--]=' ';
             if(xball--&2==1)
             board[yball][xball]=' ';
             else
             board[yball][xball-2]=' ';
             klocki--;
            }
     
            board[yball][xball]=' ';
            board[yball+kierY][xball+kierX]='O';
            xball+=kierX;
            yball+=kierY;
            system("CLS");
            while(i<14)
            {
             while(ii<12)
             {
              cout<<board[i][ii];
              ii++;
             }
             cout<<endl;
             ii=0;
             i++;
            }
            i=0;
           }                                    //koniec ruchu pilki
           
           
           if(kbhit()!=0)
           {
            if(getch()==',')
            {
             if(bar-2!='|'||bar-2!='O')
             {
              board[11][bar-2]='*';
              board[11][bar+1]=' ';
              bar--;
             }
             system("CLS");
             while(i<14)
             {
              while(ii<12)
              {
               cout<<board[i][ii];
               ii++;
              }
              cout<<endl;
              ii=0;
              i++;
             }
             i=0;
            }
            if(getch()=='.')
            {
             if(bar+2!='|'||bar+2!='O')
             {
              board[11][bar+2]='*';
              board[11][bar-1]=' ';
              bar++;
             }
             system("CLS");
             while(i<14)
             {
              while(ii<12)
              {
               cout<<board[i][ii];
               ii++;
              }
              cout<<endl;
              ii=0;
              i++;
             }
             i=0;
            } 
           }
           if(klocki==0)
           return 1;
           if(board[yball+1][xball]=='_')
           return 0;
    }
}

