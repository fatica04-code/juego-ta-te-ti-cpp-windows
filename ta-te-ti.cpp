#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;


void gotoxy(int x, int y) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
void imprimir();
int main()
{
char mat[3][3],jp,pj;
int i,j,fil,col,num;
for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
{
    mat[i][j]=' ';
}
}
imprimir();
gotoxy(1,11);cout<<"Elija la ficha para inicial el juego (X)/(O): ";
jp=getch();
pj=toupper(jp);
if(pj=='X'||pj=='O')
{
gotoxy(1,11);cout<<"......Ingresa un numero del 1 al 9 para seguir: ";
cin>>num;
system("cls");
imprimir();
while(num!=0)
{
while (true)
{	
if(num==1||num==2||num==3)
{fil=0;}
else if(num==4||num==5||num==6)
{fil=1;}
else if(num==7||num==8||num==9)
{fil=2;}
if(num==1||num==4||num==7)
{col=0;}
else if(num==2||num==5||num==8)
{col=1;}
else if(num==3||num==6||num==9)
{col=2;}
if (mat[fil][col]!=' ')
{
gotoxy(1,11);cout<<"................Ya existe la jugada, ingresa otro numero: ";
cin>>num;
if(num==0)break;
}
else{
mat[fil][col]=pj;gotoxy(1,10);cout<<"                                       ";
break;
}
}
if(num==0) break;
mat[fil][col]=pj;
gotoxy(20,14);cout<<" "<<mat[0][0]<<" | "<<mat[0][1]<<" | "<<mat[0][2];
gotoxy(20,15);cout<<"------------";
gotoxy(20,16);cout<<" "<<mat[1][0]<<" | "<<mat[1][1]<<" | "<<mat[1][2];
gotoxy(20,17);cout<<"------------";
gotoxy(20,18);cout<<" "<<mat[2][0]<<" | "<<mat[2][1]<<" | "<<mat[2][2];
if((mat[0][0]==pj&&mat[0][1]==pj&&mat[0][2]==pj)||
   (mat[1][0]==pj&&mat[1][1]==pj&&mat[1][2]==pj)||
   (mat[2][0]==pj&&mat[2][1]==pj&&mat[2][2]==pj)||
   (mat[0][0]==pj&&mat[1][0]==pj&&mat[2][0]==pj)||
   (mat[0][1]==pj&&mat[1][1]==pj&&mat[2][1]==pj)||
   (mat[0][2]==pj&&mat[1][2]==pj&&mat[2][2]==pj)||
   (mat[0][0]==pj&&mat[1][1]==pj&&mat[2][2]==pj)||
   (mat[2][0]==pj&&mat[1][1]==pj&&mat[0][2]==pj))
   {
gotoxy(1,11);cout<<"......................GANA LA FICHA: "<<pj<<"......................";
num=0;
break;
}
if (pj == 'X') {
pj = 'O';
} else {
pj = 'X';
}
imprimir();
gotoxy(1,11);cout<<"......Es el turno de: "<<pj<<" .Ingresa del 1 al 9 para seguir: ";
cin>>num;
        }           
}
else{
gotoxy(1,11);cout<<"....Elige una ficha valida (X)/(O) y vuelve al programa: ";

}
getch();
return 0;
}
void imprimir(){
gotoxy(20,2);cout<<"|1  |2  |3  |";
gotoxy(20,3);cout<<"------------";
gotoxy(20,4);cout<<"|4  |5  |6  |";
gotoxy(20,5);cout<<"------------";
gotoxy(20,6);cout<<"|7  |8  |9  |";

}