#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
    

int revisaRed(int k,int *coorX,int *coorY,int left,int right,int buttom,int top)
{
int resp,i;

resp = 0;
for(i = 0; i < k; i++)
   {
   if( left <= coorX[i] && coorX[i] <= right && buttom <= coorY[i] && coorY[i] <= top )
    { resp++; }
   }
return resp;
}

int revisaPez(int n,int m,int k,int *coorX,int *coorY,int index)
{
int i,max,temp;

max = 0;
for(i = 0; i < n; i++)
  {
  temp = revisaRed(k,coorX,coorY,coorX[index],coorX[index]+m,coorY[index]-i,coorY[index]+n-i);
  if( temp > max )
    max = temp;
  }

return max;
}


int main(void)
{
    
   ofstream salida;
   ifstream entrada;   
   int i,*coorX,*coorY,max,temp,n,m,k;

   // Abrimos el archivo de entrada.
   entrada.open("input.txt", ios ::in);
   if(entrada.is_open())
      {
       // Leemos los valores de n y m y damos memoria a los arreglos mientras leemos.
       entrada>>n;
       entrada>>m;
       entrada>>k;
      }
    else
      {
       cout<<"Error al abrir el archivo.."<<endl;
       return 0;
      }

   coorX = new int[k];
   coorY = new int[k];

   for(i = 0; i < k; i++)
       entrada>>coorX[i];
       entrada>>coorY[i];
  
   // Cerramos el archivo de entrada.
   entrada.close();
   max = 0;
  for(i = 0; i < k; i++)
      {
          temp = revisaPez(n,m,k,coorX,coorY,i);
          if(temp > max)
              max = temp;
      }

      // Abrimos el archivo de salida.
      salida.open("output.txt", ios ::out);
      salida<<max;
      // Cerramos el archivo de salida y liberamos memoria.
      salida.close();

      delete[] coorX;
      delete[] coorY;

      return 0;
}

