#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

void escribir(){
	ofstream archivo;
	
	archivo.open("prueba.txt",ios::out);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	archivo<<"Hola que tal mi nombre es alejandro"<<endl;
	
	archivo.close();//cerrar el archivo
}

int main(){
	
	
	
	
	
	return 0;
}
