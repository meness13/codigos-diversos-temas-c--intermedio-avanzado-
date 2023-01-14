#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int i=0,j,n=0;
	string sum;
	string codigo,monto,*dir_sum;
	string** base = new string * [1];
while(true){
	cout<<"ingrese el codigo del vendedor"<<endl;getline(cin,codigo);
    if(monto=="-1") break;
			n++;
	cout<<"ingrese el monto del vendedor"<<endl;getline(cin,monto);
	//Crea nueva base con nuevo tamaño
	string** base2 = new string * [n];
	for (i = 0; i < n; i++)
	base2[i] = new string[2];
	//Copia Base, uno menos porque el original tiene un elemento menos
	for (i=0;i<n-1;i++)
	for (j=0;j<2;j++)
			base2[i][j] = base[i][j];
	//Borra base original y copia la base	
			delete[] base;
			base = base2;
	//Ingresa los nuevos datos
			base[n-1][0]=codigo;
			base[n-1][1]=monto;			
}
int k;
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		if(j==1){
		*(dir_sum+k)=base[i][j];
		k++;
		}
	}
}

for(int i=0;i<n;i++){
		*(dir_sum+i)+=*(dir_sum+i+1);
	}
cout<<(int*)dir_sum;


	getch();
	return 0;
}
