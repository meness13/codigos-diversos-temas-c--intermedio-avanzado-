#include<iostream>
using namespace std;
typedef struct{
	char nombre[6];
	char cantante[4];
	int  preferencia;
} Cancion;
const int M = 5;

void sort(int nCan, Cancion **can){
	Cancion *p;
	int i, j;
	for(i=0; i<nCan-1; i++) 
		for(j=i+1; j<nCan; j++)
			if(can[i]->preferencia < can[j]->preferencia){
				p = can[i];
				can[i] = can[j];;
				can[j] = p;
			}
}
void cantar(int nCan, Cancion **can){
	cout << "Mis canciones favoritos" << endl;
	cout << "Rep. Canción  Cantante" << endl;
	for(int i=0; i<nCan; i++, can++)
		for (int j=0; j< (*can)->preferencia; j++) 
			cout << (j+1)<<"    "<<(*can)->nombre<<"      "<<(*can)->cantante<< "       "<< endl;
	cout << endl;
}
int main(){
	Cancion can [M] = {"Nelly", "El ", 1,
							 "Fiore", "Tu ", 2,
							 "Nena ", "   ", 0,
							 "Ana  ", "Yo ", 3,
							 "Mila ", "   ", 0};
	int nc=0, i, inc=0;
	for(i=0; i<M; i++) if(can[i].preferencia >0) nc++;							// calcula nc
	Cancion *pcan[nc];
	for(i=0; i<M; i++) if(can[i].preferencia >0) pcan[inc++] = &can[i];	// Apunta a las caniones
	sort  (nc, pcan);
	cantar(nc, pcan);
}
