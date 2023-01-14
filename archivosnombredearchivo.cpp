#include<iostream>
#include<stdlib.h>
#include<fstream>


using namespace std;

void datos(){
	ofstream archivo;
	string letra,frase;
	cout<<"ingrese el nombre de su archivo\n";
	getline(cin,letra);
	
	archivo.open(letra.c_str(),ios::out);
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo"<<endl;
		exit(1);
	}
	cout<<"ingrese la frase que desea guardar en el archivo"<<endl;
	getline(cin,frase);
	archivo<<frase;	
	archivo.close();//cerrando el archivo	
}

int main(){
	datos();
	
	
	return 0;
}
