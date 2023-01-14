#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>

using namespace std;

void aniadir(){
	ofstream archivo;
	archivo.open("alejandro1.txt",ios::app);
	string frase;
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	cout<<"ingrese el texto que desa agregar"<<endl;
	getline(cin,frase);
	archivo<<frase;
	archivo.close();
}

int main(){
	aniadir();
	
	
	return 0;
}
