#include<iostream>
#include<conio.h>
using namespace std;

void M_insercion(int lista[],int TAM){
int temp,j,i,cont=0;
for (i=1; i<TAM; i++)
{
temp = lista[i];
j = i - 1;
while ( (lista[j] > temp) && (j >= 0) )
{
lista[j+1] = lista[j];
j--;
}
lista[j+1] = temp;
cont++;
for(int k=0;k<TAM;k++){
	cout<<lista[k]<<"	";
}cout<<endl;
}
cout<<"Se realizaron :"<<cont<<"movimientos"<<endl;
}

void imprime(int a[],int N){
	for(int i=0;i<N;i++){
		cout<<a[i]<<"	";
	}
}

int main(){
	int arr[]={12,50,68,30,46,5,92,38};
	M_insercion(arr,8);
	
	getch();
	return 0;
}
