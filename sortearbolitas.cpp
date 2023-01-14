#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
using namespace std;
void sortear(int* p, int poblacion, int muestra);

int main() {
    int capacidad = 0, *bolillas = 0;

    cout << "ingrese la cantidad de bolillas: ";
    cin >> capacidad;
    bolillas = new int[capacidad];

    for (int j = 0; j < capacidad; ++j)
        bolillas[j] = j + 1;
    sortear(bolillas, capacidad, 5);

    delete[] bolillas; // liberando espacio
}

void sortear(int* p, int poblacion, int muestra) {
    int aux, k;
    cout << "Bolillas sorteadas:";
    srand(time(0));
    for (int j = 0; j < muestra; ++j) {
        k = rand() % (poblacion - j); // sorteando bolilla
        cout << setw(5) << p[k];
        // a continuacion intercambiamos la bolilla sorteada con la de mayor denominacion
        aux = p[poblacion - j - 1];
        p[poblacion - j - 1] = p[k];
        p[k] = aux;
    }
    cout << endl;
}
