#include <cstdlib>
#include <iostream>
#include<string.h>
#include<conio.h>
using namespace std;

void sbl( char *cad, int &i)
{
    while (cad[i] == ' ' && i <= strlen(cad))
    i++;
} 
  
void spl(char *cad, int &i)
{
    while (cad[i] != ' ' && i <= strlen(cad))   
    i++;
} 

int main() 
{
   char cad[81];
   int cont,total=0; 
   cout << " Introduzca lineas, separando las palabras con blancos.\n";
   cin.getline (cad,80);
   while (*cad!=0)			  
   {
     cont = 0;  	
     for(int i=0; i<=strlen(cad);i++)
      {
        spl(cad,i);
        sbl(cad,i);
        cont++;					
      }     
     cout <<  " \t\t\"" <<cad << "\" :" << cont << endl;
     cin.getline(cad,80);
     total += cont;				   
  }
  cout << " total de palabras del texto " << total << endl;
   
  getch();
  return 0;
}

