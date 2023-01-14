#include<iostream>
using namespace std;
void leer_matriz(int n, int *p);
void escribir_matriz(int f, int c, int *p);
void promediofila(int f, int c, int *p, float *pm);
void ordenar(int f, float *p);
int main(){
	int f=4, c=3;
	int mat[4][3]={ { 12, 3, 11 },{ 17, 9, 6} ,{ 4, 20, 13} ,{ 12, 16, 1} }; 
	float prom[4];
	int *p = mat[0];
	float *pm = prom;
	escribir_matriz(f, c, p);
	cout<< "Promedio de fila\n";
	promediofila(f,c ,p ,pm);
	cout<< "Ordenado \n";
	ordenar(f, pm);
	return 0;
}
void escribir_matriz(int f, int c, int *p){
	int i, j;
	for(i = 0; i < f; i++){
		for(j = 0; j < c; j++) cout<< *p++ <<" ";
		cout<< "\n";
	}
}
void promediofila(int f,int c, int *p, float *pm){
	int i ,j;
	float auxp;
	int *q;
	q = p;
	for(i = 0; i < f; i ++){
		j = 0;
		auxp = 0.0;
		for(j = 0; j < c; j ++){
			auxp = auxp + *(q + i * c + j) ;
		}
		auxp = auxp/c;
		*(pm + i * sizeof(float) ) = auxp;
		cout<< *(pm + i * sizeof(float) ) << "\n";
	}
}
void ordenar(int f,float *pm){
	float aux;
	int i, j;
	for(i = 0; i < f - 1; i ++){
		for(j = 0; j < f - 1; j ++){
			if( *( pm + j* sizeof(float) ) <= *( pm + j* sizeof(float) + sizeof(float) ) ){
				aux = *( pm + j* sizeof(float) );
				*( pm + j* sizeof(float) ) = *( pm + j* sizeof(float) + sizeof(float) );
				*( pm + j* sizeof(float) + sizeof(float) ) = aux;	
			}
		}
	}
	for(i = 0; i < f; i ++){
		cout<< "::--::" << *(pm + i * sizeof(float) ) << "\n";
	}
}
