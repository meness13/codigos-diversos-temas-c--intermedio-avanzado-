#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

struct datos{
	string nombre;
	int nota[10];
	double prom;
}notas[10];

void leer(int n){
	int k;
	for(int i=0;i<n;i++){
			cout<<i+1<<"ingrese su nombre"<<endl;
			fflush(stdin);
			getline(cin,notas[i].nombre);
			cout<<"cuantas notas tiene el alumno"<<i+1<<endl;cin>>k;
			for(int j=0;j<k;j++){
					cout<<"ingrese las notas";
					cin>>notas[i].nota[j];
					notas[i].prom+=notas[i].nota[j];
			}
			notas[i].prom/=k;
	}
}

void promedio(int n){
	cout<<"............................."<<endl;
	for(int i=0;i<n;i++){
			cout<<i+1<<"nombre:"<<notas[i].nombre<<endl;
			cout<<"Promedio"<<1.0*notas[i].prom<<endl;
	}
}

int main(){
	int n;
	cout<<"ingrese la cantidad de alumnos"<<endl;cin>>n;
	leer(n);
	promedio(n);
	
	getch();
	return 0;
}
