
#include <fstream>                      // ifstream, ofstream
#include <cassert>                      // assert()
#include <iostream>
#include <cstring>
using namespace std;

int obtener_ocurrencias(char* cad1, char* cad2);

int main() {
    char bufer_de_lectura[255];         // memoria temporal para la lectura del archivo
    char palabra[20];                    // cadena a buscar en el archivo
    int ocurrencias = 0;

    cout << "Ingrese la palabra a buscar: ";
    cin >> palabra;

    ifstream fin("input.txt");       // estableciendo coneccion con el disco duro,
    assert( fin.is_open() );            // y verificando si la operacion se realizo satisfactoriamente

    while (fin.getline(bufer_de_lectura,255)) {
        ocurrencias += obtener_ocurrencias(bufer_de_lectura, palabra);
    }
    cout << "Número de ocurrencias: " << ocurrencias << endl;
    fin.close();                        // cerrando la conexion con el disco duro

    return 0;
}

// contador de ocurrencias de cad2 en cad1
int obtener_ocurrencias(char* cad1, char* cad2) {
    int M = strlen(cad1);
    int N = strlen(cad2);
    int contador = 0;
    int k = 0;
    for (int j = 0; j <= M - N; ++j) {
        // verificacion para el indice actual j
        for (k = 0; k < N; ++k)
            if (cad1[j+k] != cad2[k]) break;

        if (k == N) ++contador; // si cad1[j, j+1, ...j+M-1] = cad2[0...M-1]
    }
    return contador;
}
