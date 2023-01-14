#include <iostream>
#include <cstring>
using namespace std;

int main () {
    int n;
    cout << "Ingrese el número de caracteres máximos y luego la cadena: ";cin >> n;
    cin.ignore();
    char *cadena = new char[n + 1];
    cin.getline(cadena, n + 1);
    cin.clear();
    int size = strlen(cadena);
    int nespacios = 0;    
    for(int i = 0; i < size; i++) {
        if (cadena[i] == ' ') 
            nespacios++;
    }
    char *nueva_cadena = new char[size - nespacios + 1];
    
    int j = 0;
    for( int i = 0; i < size; i++ ) {
        if (cadena[i] != ' ')
            nueva_cadena[j++] = cadena[i];
    }
    nueva_cadena[j] = 0;  
    cout << "Cadena transformada: " << nueva_cadena << endl;

    delete [] cadena;
    delete [] nueva_cadena;

    return 0;
}
