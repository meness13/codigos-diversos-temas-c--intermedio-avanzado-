#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string apellidos, nombre, cadena, apeMax="", nomMax="";
	int n, i, num, indMax=0;
	float* prom, promMax=0;
	float nota1, nota2;
	ifstream ar;
	ar.open("C:/UNI/baseUNI.txt");
	n = 0;
	while (!ar.eof())
	{
		getline(ar, cadena);
		n++;
	}
	ar.close();
	n = n - 1;
	prom = new float[n];
	cout << "Num\tApellidos\tNombre\tNota1\tNota2\tPromedio" << endl;
	ar.open("C:/UNI/baseUNI.txt");
	for (i = 0; i < n; i++)
	{
		getline(ar, cadena, '.');
		num = stoi(cadena);
		getline(ar, cadena, ',');
		apellidos = cadena;
		getline(ar, cadena, '-');
		nombre = cadena;
		getline(ar, cadena, '-');
		nota1 = stof(cadena);
		getline(ar, cadena);
		nota2 = stof(cadena);
		prom[num - 1] = (nota1 + nota2) / 2;
		if (prom[num - 1] > promMax)
		{
			promMax = prom[num - 1];
			indMax = num - 1;
			apeMax = apellidos;
			nomMax = nombre;
		}
		cout << num << "\t" << apellidos << "\t" << nombre
			<< "\t" << nota1 << "\t" << nota2 << "\t" << prom[num - 1] << endl;
	}
	ar.close();
	cout << "\nEl promedio maximo: " << promMax << endl;
	cout << "Alumno: " << nomMax << " " << apeMax << endl;
	
	
	delete[] prom;
	return 0;
}
