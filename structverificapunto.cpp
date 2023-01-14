#include <iostream>
#include <math.h>
using namespace std;

struct PUNTO {
	float x;
	float y;
	void imprimir() {
		cout << "Punto (" << x << ", " << y << ")\n";
	}
};

int verificaPertenecia(PUNTO *punto, int a, int b, int r) {
	//De la definición de pertenencia f(x,y) < 0; > 0; == 0
	return pow(punto->x - a, 2) + pow(punto->y - b, 2) - r * r;
}
int main() {
	int n, a, b, r;
	cout << "Ingrese los valores a, b y r de la circunferencia: ";
	cin >> a >> b >> r;
	cout << "Ingrese la cantidad de puntos: ";
	cin >> n;
	PUNTO *puntos = new PUNTO[n];
	for (int i = 0; i < n; i++) {
		cin >> puntos[i].x >> puntos[i].y;
	}
	int val;
	for (int i = 0; i < n; i++) {
		val = verificaPertenecia(&puntos[i], a, b, r);
		if (val < 0)
			cout << "Dentro ";
		else if (val > 0)
			cout << "Fuera ";
		else
			cout << "Borde ";
		puntos[i].imprimir();
	}

	return 0;
}
