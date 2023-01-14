#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int mm=60, n=0, nn=81, i, j, imin;
	char tex[mm][81], min[nn];
	cout << "Ordenamiento de líneas de caracteres por longitud.  Para terminar tipea enter\n";
	do{ 
		cout << "Ingrese la linea " << n+1 << ": ";
		cin.getline(tex[n], nn);
		if(strlen(tex[n])==0) break;
		n++;
	} while(n<mm); 
// ordenar tex[ ]
	for(i=0; i<n-1; i++){
		imin = i;
		for(j=i+1; j<n; j++) 
		if(strlen(tex[imin])>strlen(tex[j])) imin = j;
		if(imin>i){
			strcpy(min,tex[imin]);
			strcpy(tex[imin],tex[i]);
			strcpy(tex[i], min);
		}
	}
	cout << "\nLíneas ordenadas por longitud\n";
	for(i=0; i<n; i++) cout << tex[i] << endl;
}
