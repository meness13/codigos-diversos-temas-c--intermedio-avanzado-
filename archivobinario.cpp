#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>

using namespace std;

struct lista{
	char nombre[20];
	char apellido[20];
};

void escribir(){
	ofstream archivo;
	char letra[20];
	archivo.open("pbinario.dat",ios::out | ios::binary);
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo"<<endl;
		exit(1);
	}
		lista milista1;
		cout<<"Ingresando datos:"<<endl;
		cout<<"ingresa un nombre"<<endl;cin.getline(milista1.nombre,20,'\n');
		cout<<"ingresa un apellido"<<endl;cin.getline(milista1.apellido,20,'\n');
	archivo.write((char *)&milista1,sizeof(lista));

	archivo.close();
	
}

void leer(){
	ifstream archivo1;
	char letra[20];
	archivo1.open("pbinario.dat",ios::in | ios::binary);
	if(archivo1.fail()){
		cout<<"No se pudo crear el archivo"<<endl;
		exit(1);
	}
	lista milista1;
			archivo1.read((char *)&milista1,sizeof(lista));
	cout<<"\nMostrar datos"<<endl;
	cout<<"Nombre: "<<milista1.nombre<<endl;
	cout<<"Apellido: "<<milista1.apellido<<endl;
	archivo1.close();
}

int main(){
	escribir();
	leer();
	
}

