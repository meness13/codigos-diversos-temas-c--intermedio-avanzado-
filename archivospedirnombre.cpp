#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>

using namespace std;

void lectura(){
	ifstream archivo;
	string texto,letra;
	cout<<"ingrese el nombre de su archivo\n";
	getline(cin,letra);
	archivo.open(letra.c_str(),ios::in);//abriendo el archivo para leer
	if(archivo.fail()){
		cout<<"Error abriendo el archivo\n";
		exit(1);		
	}
	while(!archivo.eof()){//mientras no sea el final del archivo
	getline(archivo,texto);
	cout<<texto<<endl;		
	}
	archivo.close();
}

int main(){
	
	 lectura();
	
	
	return 0;
}
