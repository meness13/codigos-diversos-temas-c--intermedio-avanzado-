#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

struct restaurante{
	string nombre;
	int rpositiva;
	int rnegativa;
}valores[10];

void generarestaurante(int n){
	srand(time(0));
	for(int i=0;i<n;i++){
		fflush(stdin);
		cout<<"["<<i<<"]"<<"Nombre:";getline(cin,valores[i].nombre);
		valores[i].rpositiva=rand()%1000+1;
		valores[i].rnegativa=rand()%1000+1;

	}
}

void imprimeresultado(int n){
	cout<<"\n\n Los restautantes y sus referenvias"<<endl;
	int max=0,posma,min=99999,posmi;
	for(int i=0;i<n;i++){
		cout<<"["<<i<<"]Nombre:"<<valores[i].nombre<<"\tRpositiva"<<valores[i].rpositiva<<"\tRnegativa"<<valores[i].rnegativa<<endl;
		if(valores[i].rpositiva>max){
			max=valores[i].rpositiva;
			posma=i;
		}else if(valores[i].rpositiva<min){
			min=valores[i].rpositiva;
			posmi=i;
		}
	}
	cout<<"\n\n El mejor"<<"Nombre: "<<valores[posma].nombre<<"	Rpositiva"<<valores[posma].rpositiva<<"	Rnegativa"<<valores[posma].rnegativa<<endl;
	cout<<"\n\n El peor"<<"Nombre: "<<valores[posmi].nombre<<"	Rpositiva"<<valores[posmi].rpositiva<<"	Rnegativa"<<valores[posmi].rnegativa<<endl;
}

int main(){
	int n;
	cout<<"ingrese la cantidad de restaurantes"<<endl;cin>>n;
	generarestaurante(n);
	imprimeresultado(n);
	
	
	
	getch();
	return 0;
}
