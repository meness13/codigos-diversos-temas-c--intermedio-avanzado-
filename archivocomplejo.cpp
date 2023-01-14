#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
using namespace std;
struct Complejo{
    int re;
    int im;
} ;

Complejo c1 = {1,2}, c2 = {3,5}, producto;
char nombre[20]="complejo.bin";


void multiplicar(Complejo* ptr1, Complejo* ptr2, Complejo* ptr_producto){
    ptr_producto->re = ptr1->re * ptr2->re - ptr1->im * ptr2->im;
    ptr_producto->im = ptr1->re * ptr2->im + ptr1->im * ptr2->re;
}

int main(){
	ofstream a1;//archivo modo escritura
	a1.open(nombre,ios::out | ios::binary);
	
	if(a1.fail()){
		cout<<"No se pudo crear el archivo"<<endl;
		exit(1);
	}
	
	multiplicar(&c1, &c2, &producto);
	
	a1.write((char *)&producto,sizeof(producto));
	
	a1.close();
	
	ifstream a2;//archivo modo lectura
 	a2.open(nombre,ios::in | ios::binary);
 	
 	if(a2.fail()){
		cout<<"No se pudo crear el archivo"<<endl;
		exit(1);
	}
	
	a2.read((char*)&c1,sizeof(c1));
	
	cout<<"El producto es :"<<endl;
	cout<<"\n :("<<c1.re<<") + ("<<c1.im<<")i";
	a2.close();

	getch();
	return 0;
}
