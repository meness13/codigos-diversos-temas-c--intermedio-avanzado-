#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>

using namespace std;

void lectura(){
	ifstream archivo;
	string texto;
	archivo.open("LePetitPrince.txt",ios::in);//abriendo el archivo para leer
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
