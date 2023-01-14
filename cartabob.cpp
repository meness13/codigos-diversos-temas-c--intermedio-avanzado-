#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>

using namespace std;
struct diccionario{
	char clave;
	char letra;
};

void genera_diccionario(diccionario* dic);
void guardar_diccionario(diccionario* dic);
void cifrar(diccionario* dic);

int main (){
    struct diccionario dic[27];

    int i = 0;
    genera_diccionario(dic);
    guardar_diccionario(dic);
    cifrar(dic);
    
    return 0;
}

void genera_diccionario(diccionario* dic) {
    int n;
    char t;
    srand(time(NULL));
    for(int i=0; i<26; i++){	
    	dic[i].letra=char(i+97);
    	dic[i].clave=char(i+97);
    }
    for (int i = 25; i >= 0; i--){
        int j = rand() % (i + 1);
    	t = dic[i].clave;
    	dic[i].clave=dic[j].clave;
    	dic[j].clave= t;	
    }
}

void guardar_diccionario(diccionario* dic) {
	ofstream fsalida("diccionario.dat",ios::out | ios::binary);
	for(int i=0; i<26; i++){	
    	fsalida.write(reinterpret_cast<char *>(&dic[i]),sizeof(struct diccionario));
    }	
	fsalida.close();
}

void cifrar(diccionario* dic){
	char letra;
	int i;
	ifstream ficheroEntrada("carta.txt");
	ofstream ficheroSalida("cifrado.txt");
	if (ficheroEntrada.is_open()) {
		while (! ficheroEntrada.eof() ) {
 			ficheroEntrada >> letra;
 			cout << letra << " ";
 			i = 0;
 			while(dic[i].letra != letra){
 				++i;
			}
			ficheroSalida << dic[i].clave;
			
 		}
 		ficheroEntrada.close();
 		ficheroSalida.close();
	}
 	else cout << "Fichero no existe" << endl;
}
