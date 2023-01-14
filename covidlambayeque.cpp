#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

struct pide{
	string Nombre;
	string Apellido;
	int dni;
	bool covi;
}persona[5];

void pregunta(){
	for(int i=0;i<5;i++){
		fflush(stdin);
	cout<<i+1<<"Ingrese su nombre: "<<endl;getline(cin,persona[i].Nombre);
	cout<<i+1<<"Ingrese su apellido: "<<endl;getline(cin,persona[i].Apellido);
	cout<<i+1<<"ingresa tu dni: "<<endl;cin>>persona[i].dni;
	cout<<i+1<<"usted tuvo covid 19 (1/0) ingrese 1 si tuvo covid de lo contrario ingrese 0"<<endl;cin>>persona[i].covi;	
	}
}

int main(){
	pregunta();
	
for(int i=0;i<5;i++){
	cout<<i+1<<"nombre: ";cout<<persona[i].Nombre<<endl;
	cout<<i+1<<"apellido: ";cout<<persona[i].Apellido<<endl;
	cout<<i+1<<"dni: ";cout<<persona[i].dni<<endl;
	if(persona[i].covi==1){
		cout<<i+1<<"usted tuvo covid"<<endl;
	}else{cout<<"usted no tuvo covid"<<endl;};
}
	
	getch();
	return 0;
}
