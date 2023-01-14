#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ofstream salida;
   ifstream entrada;
   int q,m,t,c=0,tmp;
   
    entrada.open("input.txt", ios ::in);
    salida.open("output.txt", ios ::out);
   
   if(entrada.is_open())
     {
       entrada>>q;
       entrada>>m;
       entrada>>t;
     }
    else
     {
       cout<<"Error al abrir el archivo.."<<endl;
       return 0;
     }



   //medios
   c+=(m/2);
   m=(m%2);

   //tres q con un q

   while(t && q)
   {
      c++;t--;q--;
   }
   c+=t;


   if(m && q==1)
   {
      c++;q--;
   }
   if(m && q>1)
   {
      c++;q-=2;
   }

   c+=(q/4);

   if( q%4 != 0 )
   	c++;

   salida<<c<<endl;
   entrada.close();
   salida.close();

   return 0;
}
