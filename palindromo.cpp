#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

void eliminar_espacios(char * des, char * ori) {
    int k = 0;
    int iFinal = strlen(ori) - 1;
    for (int j = 0; j <= iFinal; j++) {
        if (ori[j] != ' ') {
            des[k] = ori[j];
            k++;
        }
    }
    des[k] = 0;
}

int main(){
	char palabra[40],letra[40];int cont,res=0;
	char *dir_i,*dir_u;
	cout<<"ingrese la palabra:"<<endl;cin.getline(palabra,40);
	eliminar_espacios(letra,palabra);
	dir_i=letra;
	cont=strlen(letra);
	dir_u=&letra[cont-1];
	for(int i=0;i<cont;i++){
		cout<<*(dir_u-i);
	}cout<<"\n\n";
	for(int i=0;i<cont;i++){
		if(*dir_i++==*(dir_u-i)){
			res++;
		}
	}
	if(cont==res){
		cout<<"Las cadenas son palindromos"<<endl;
	}
	
	getch();
	return 0;
}


