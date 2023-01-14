#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

typedef struct {
char nombre[50];
int nota;
} Alumno;

void mostrar(Alumno* ptr, int cap);
void ordenar_por_nota(Alumno* ptr, int cap);

int main() {
Alumno lista[4] = {{"Juan",18},{"Elena",20},{"Pedro",17},{"Javier",19}};
mostrar(lista, 4);
ordenar_por_nota(lista,4);
mostrar(lista, 4);
return 0;
}
void mostrar(Alumno* ptr, int cap) {
cout << "\t\t\t\tNombre\t\tNota de sustitutorio\n";
	for (int j = 0; j < cap; ++j) {
		cout << "alumno\t" << j << "\t:\t" << setw(10) << ptr[j].nombre << setw(16) <<
		ptr[j].nota << endl;
	}
}

void ordenar_por_nota(Alumno* ptr, int cap) {
char nombre_[50] = "";
int nota_ = 0;
for (int k = cap-1; k > 0; --k) {
	for (int j = 0; j < k; ++j) {
		if (ptr[j].nota > ptr[j+1].nota) {
		strcpy(nombre_,ptr[j].nombre);
		nota_ = ptr[j].nota;
		strcpy(ptr[j].nombre, ptr[j+1].nombre);
		ptr[j].nota = ptr[j+1].nota;
		strcpy(ptr[j+1].nombre, nombre_);
		ptr[j+1].nota = nota_;
		}
	}
}
}
