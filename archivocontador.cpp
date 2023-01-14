#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main () {
    ifstream file("input.txt");
    if (!file.good()) {
        cout << "Error, no se pudo abrir el archivo!" << endl;
        return 1;
    }
    char word[31];
    int len_max, len;
    
    len_max = 0;
    int cont = 0;
    while( file >> word ) {
        len = strlen(word);
        if (len > len_max)
            len_max = len;
        cont++;
    }
    file.clear();
    file.seekg(0);
    
    int *statist = new int[len_max + 1];
    
    for(int i = 0; i <= len_max; i++)
        statist[i] = 0; 
    
    while(file >> word) {
        statist[strlen(word)]++;
    }
    
    cout << "Número de palabras del texto: " << cont << endl;
    
    for(int i = 0; i <= len_max; i++)
        if (statist[i] > 0)
            cout << "Número de palabras con " << i << " caracteres de longitud: " << statist[i] << endl; 
        
    file.close();
    return 0;
}
