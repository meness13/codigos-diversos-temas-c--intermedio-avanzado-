#include <iostream>
#include <fstream>
using namespace std;

void backtracking(int n, int k, char *runas, char *palabra, int posicion, ofstream &salida, int r, char *puesta);

int main(void)
{
   ofstream salida;
   ifstream entrada;
   
   int n,k;
   char *runas;
   char *palabra;
   char *puesta;

   entrada.open("input.txt", ios ::in);
   
   if(entrada.is_open())
     {
       entrada>>n;
       entrada>>k;
     }
    else
     {
       cout<<"Error al abrir el archivo.."<<endl;
       return 0;
     }

   
   runas = new char[n];
   puesta = new char[n];
   palabra = new char[k+1];

   palabra[0] = 0;
   palabra[k] = 0;

   for(int i=0; i<n; i++)
      {
        entrada>> runas[i]; 
   
      puesta[i] = 0;
      }

   entrada.close();
   

   salida.open("output.txt", ios ::out);
   

   backtracking(n,k,runas,palabra,0,salida,-1, puesta);
    
   salida.close();
   

   return 0;
}


void backtracking(int n, int k, char *runas, char *palabra, int posicion, ofstream &salida, int r, char *puesta)
   {
   if(posicion == k)
      {
      salida<<palabra<<endl;
      
      }
   else
      {
      for(int i=0; i<n; i++)
         {
         if(puestas[i] == 0)
            {
            palabra[posicion] = runas[i];
            puestas[i] = 1;
            backtracking(n,k,runas,palabra,posicion+1,salida,i,puestas);
            puestas[i] = 0;
            }
         }
      }
   }
