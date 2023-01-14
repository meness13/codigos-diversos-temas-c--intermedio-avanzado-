#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i, j, n = 0, max = 0;
	string codigo, nota;
	string** base = new string * [1];
	//Lectura de datos
	cout << "Ingreso de datos UNI:\n";
		while (true)
		{
			cout << "Ingrese un codigo: ";
			cin >> codigo;
			if (codigo == "fin")
				break;
			n++;
			cout << "Ingrese una nota: ";
			cin >> nota;
			//Comprueba la maxima nota
			if (stoi(nota) > max)
				max = stoi(nota);
			//Crea nueva base con nuevo tamaño
			string** base2 = new string * [n];
			for (i = 0; i < n; i++)
				base2[i] = new string[2];
			//Copia Base, uno menos porque el original tiene un elemento menos
			for (i = 0; i < n - 1; i++)
				for (j = 0; j < 2; j++)
					base2[i][j] = base[i][j];
			//Borra base original y copia la base	
			delete[] base;
			base = base2;
			//Ingresa los nuevos datos
			base[n - 1][0] = codigo;
			base[n - 1][1] = nota;
		}
	//Imprime aquellos que tiene la maxima nota
		cout << "Alumnos con la maxima nota:\n";
		for (i = 0; i < n; i++)
		{
			if (max == stoi(base[i][1]))
			{
				for (j = 0; j < 2; j++)
					cout << base[i][j] << " ";
				cout << endl;
			}
		}
	return 0;
}
