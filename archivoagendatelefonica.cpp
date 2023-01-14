#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;

struct Dato{
	string nombre,apellido,telefono;
}datos;

void crear(){
	char rpt;
	ofstream archivo;
	archivo.open("Agendatelefono.txt",ios::out);
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	cout<<"\tAgenda telefonica\n";
	do{
		fflush(stdin);
		cout<<"Ingrese su nombre"<<endl;
		getline(cin,datos.nombre);
		cout<<"Ingrese su apellido"<<endl;
		getline(cin,datos.apellido);
		cout<<"Ingrese su nro telefono"<<endl;
		getline(cin,datos.telefono);
		cout<<"\n";	
		archivo<<"Nombre:"<<datos.nombre<<endl;
		archivo<<"Apellido:"<<datos.apellido<<endl;
		archivo<<"Nro de telefono"<<datos.telefono<<endl;
		cout<<"Desea ingresar otro contacto"<<endl;
		cin>>rpt;
	}while(rpt=='S' || rpt=='s');
	archivo.close();
}

void agregar(){
	char rpt;
	ofstream archivo;
	archivo.open("Agendatelefono.txt",ios::app);
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	do{
		fflush(stdin);
		cout<<"Ingrese su nombre"<<endl;
		getline(cin,datos.nombre);
		cout<<"Ingrese su apellido"<<endl;
		getline(cin,datos.apellido);
		cout<<"Ingrese su nro telefono"<<endl;
		getline(cin,datos.telefono);
		cout<<"\n";	
		archivo<<"\nNombre:"<<datos.nombre<<endl;
		archivo<<"\nApellido:"<<datos.apellido<<endl;
		archivo<<"\nNro de telefono"<<datos.telefono<<endl;
		cout<<"Desea ingresar otro contacto"<<endl;
		cin>>rpt;
	}while(rpt=='S' || rpt=='s');
	archivo.close();
}

void visualizar(){
	ifstream archivo;
	string texto;
	archivo.open("Agendatelefono.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	while(!archivo.eof()){
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close();
}

void menu(){
	int op;
	do{
		cout<<"\tMENU"<<endl;
		cout<<"1. Crear (nombre,apellido,nrotelefono)"<<endl;
		cout<<"2. Agregar un nuevo nro telefonico"<<endl;
		cout<<"3. Visualizar contactos agregados"<<endl;
		cout<<"4. SALIR (s/n)"<<endl;
		cin>>op;
		switch(op){		
			case 1:
				crear();
				system("PAUSE");
				break;
			case 2:
				agregar();
				system("pause");
				break;	
			case 3:
				visualizar();
				system("pause");
				break;	
		}		
		system("cls");
	}while(op!=4);	
}

int main(){
	menu();
	
	return 0;
}
