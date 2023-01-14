#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;

struct Dato{
	string codigo,nombre,cantidad,precio;
}datos;

void crear(){
	char rpt;
	ofstream archivo;
	archivo.open("Agendatelefono.txt",ios::out);
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	cout<<"\tIngreso de datos\n";
	do{
		fflush(stdin);
		cout<<"ingrese du codigo"<<endl;
		getline(cin,datos.codigo);
		cout<<"Ingrese su nombre"<<endl;
		getline(cin,datos.nombre);
		cout<<"Ingrese su cantidad"<<endl;
		getline(cin,datos.cantidad);
		cout<<"Ingrese su precio"<<endl;
		getline(cin,datos.precio);
		cout<<"\n";
		archivo<<"Codigo: "<<datos.codigo<<endl;	
		archivo<<"Nombre:"<<datos.nombre<<endl;
		archivo<<"Apellido:"<<datos.cantidad<<endl;
		archivo<<"Nro de telefono"<<datos.precio<<endl;
		cout<<"Desea ingresar otro articulo"<<endl;
		cin>>rpt;
	}while(rpt=='S' || rpt=='s');
	archivo.close();
}

void agregar(){
	char rpt;
	ofstream archivo;
	archivo.open("Agendatelefono.txt",ios::out);
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	do{
		fflush(stdin);
		cout<<"ingrese du codigo"<<endl;
		getline(cin,datos.codigo);
		cout<<"Ingrese su nombre"<<endl;
		getline(cin,datos.nombre);
		cout<<"Ingrese su cantidad"<<endl;
		getline(cin,datos.cantidad);
		cout<<"Ingrese su precio"<<endl;
		getline(cin,datos.precio);
		cout<<"\n";
		archivo<<"Codigo: "<<datos.codigo<<endl;	
		archivo<<"Nombre:"<<datos.nombre<<endl;
		archivo<<"Apellido:"<<datos.cantidad<<endl;
		archivo<<"Nro de telefono"<<datos.precio<<endl;
		cout<<"Desea ingresar otro articulo"<<endl;
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

void comprar(){
	
	
	
}

void menu(){
	int op;
	do{
		cout<<"\tMENU"<<endl;
		cout<<"1. Ingreso de un artículo"<<endl;
		cout<<"2. Agregar un nuevo articulo"<<endl;
		cout<<"3. Listar artículo"<<endl;
		cout<<"4. Comprar articulo"<<endl;
		cout<<"5. Vender articulo"<<endl;
		cout<<"6. SALIR (6)"<<endl;
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
			case 4:
			
				break;
			case 5:
			
				break;			
		}		
		system("cls");
	}while(op!=6);	
}

int main(){
	menu();
	
	return 0;
}
