// 6.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
void llenarMatriz(int **ptr,int nfil,int ncol);
void mostrarMatriz(int **ptr,int nfil,int ncol);
void liberaMemoria(int **ptr,int nfil);
int main(void){
  int cnt=0;
  int nfil,ncol;
  int **ptr;
  int **D;
  cout<<"Dimension de la matriz: ";
  cin>>nfil>>ncol;
//iii.Reservar memoria dinamicamente para ptr
  ptr= new int*[nfil];
  for (int f=0;f<nfil;f++)
     ptr[f]= new int[ncol]; 
  llenarMatriz(ptr,nfil,ncol);
  cout<<"Matriz ingresada\n";
  mostrarMatriz(ptr,nfil,ncol);
  //cantidad de ceros
  for (int i=0;i<nfil;i++){
     for (int j=0;j<ncol;j++)
	if (ptr[i][j]!=0)
           cnt++;
  }
  float pceros=(float)(nfil*ncol-cnt)/(nfil*ncol);
  cout<<"porc. ceros "<<pceros<<endl;
  if (pceros<0.75)
     cout<<"no es conveniente reducir\n";	
  else{
          cout<<"es conveniente reducir\n";	
          //iii.Reservar memoria dinamicamente para D
          D= new int*[cnt+1];
          for (int f=0;f<cnt+1;f++)
             D[f]= new int[3]; 
	  D[0][0]=nfil;
	  D[0][1]=ncol;
	  D[0][2]=cnt;
	  int k=1;
	  for (int i=0;i<nfil;i++)
	     for (int j=0;j<ncol;j++)
		if (ptr[i][j]!=0){
		   D[k][0]=i;
		   D[k][1]=j;
		   D[k][2]=ptr[i][j];
		   k++;
		}    
	  cout<<endl;
	  cout<<"Matriz reducida\n";
	  for (int i=0;i<k;i++){
	     for (int j=0;j<3;j++)
		cout<<D[i][j]<<" ";
	     cout<<endl;
	  }
      }
  liberaMemoria(ptr,nfil);
}

void mostrarMatriz(int **ptr,int nfil,int ncol){
  for (int i=0;i<nfil;i++){
    for (int j=0;j<ncol;j++)
      cout<<setw(3)<<ptr[i][j]; 
    cout<<endl;
  }
}
void llenarMatriz(int **ptr,int nfil,int ncol){
  cout<<"Ingrese valores a la matriz\n";
  for (int i=0;i<nfil;i++){
    cout<<"Ingrese "<<ncol<<" datos para la fila "<<i+1<<": "; 
    for (int j=0;j<ncol;j++)
      cin>>ptr[i][j];
 }
}

void liberaMemoria(int **ptr,int nfil){
  for (int i=0;i<nfil;i++)
     delete[] ptr[i];
  delete[] ptr;   
}
 
