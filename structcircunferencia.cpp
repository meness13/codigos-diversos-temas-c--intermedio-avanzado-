#include <cstdio>
#include <iostream>
using namespace std;

typedef  struct {
    int x;
    int y;
} Coordenada;

typedef struct {
    Coordenada centro;
    int radio;
} Circunferencia;

int main() {
    Circunferencia circunferencia;
    circunferencia.centro.x = 1;
    circunferencia.centro.y = 2;
    circunferencia.radio = 5;
    cout << "La ecuacion de la circunferencia: (x-" << circunferencia.centro.x
            << ")² + (y-" << circunferencia.centro.y << ")² = "
            <<circunferencia.radio<<"²" << endl;
}
