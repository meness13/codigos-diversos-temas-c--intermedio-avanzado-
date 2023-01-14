#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;

struct santa{
    int estatura[10];
    int peso[10];
}personas;

void m_burbuja(int v[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(v[j]>v[j+1])
			{
            swap(v[j+1],v[j]);
			}	
		}
	}		
}


int main(){
	ofstream a1;
	a1.open("ayudantes.txt",ios::out);
	int n,t=0;
	if(a1.fail()){
		cout<<"No se pudo crear el archivo"<<endl;
		exit(1);
	}
	cout<<"ingrese el tamanio de los arr"<<endl;cin>>n;
	
do{
	cout<<"ingrese la estatura de los ayudantes de santa"<<endl;
	cin>>personas.estatura[t];
	a1<<"Estatura: "<<personas.estatura[t]<<endl;
	t++;
}while(t<n);
int l=0;
do{
	cout<<"ingrese el peso de los regalos de los reagalos"<<endl;
	cin>>personas.peso[l];
	a1<<"Peso: "<<personas.peso[l]<<endl;
	l++;
}while(l<n);
    
	a1.close();
	
	m_burbuja(personas.estatura,n);
	m_burbuja(personas.peso,n);
	
ifstream a2;
	a2.open("ayudantes.txt",ios::in);
	if(a2.fail()){
		cout<<"No se pudo crear el archivo"<<endl;
		exit(1);
	}
	cout<<"\n Salida"<<endl;
	for(int i=0;i<n;i++){
		cout<<personas.estatura[i]<<"	"<<personas.peso[i]<<endl;
	}
	a2.close();
	
	getch();
	return 0;
}
