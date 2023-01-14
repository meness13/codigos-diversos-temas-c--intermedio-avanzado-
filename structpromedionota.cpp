#include <string>
#include <iostream>
#include<conio.h>
using namespace std;
struct Estudiante{
    Student() //Constructor por defecto
              //Inicializa los miembros
	{
		for (int n = 0; n < 5; ++n)
		notas[n] = 0.00;
		promedio = 0.00;
        nombre="Nombre por definir";
	}
	string id;
	string nombre;
	double notas[5];
	double promedio;
};

int main()
{
    int numest =0;
    double sumnotas =0.0;
    cout << "Ingrese el numero de estudiantes: "; cin >> numest;    
	Estudiante* e1 = new Estudiante[numest];
        // Mostrar arreglo inicializado
		for (int n = 0; n < numest; ++n){
            cout << n << " Nombre: " << e1[n].nombre << "\t Notas:"; 
            for(int m=0; m<5; ++m){
                cout<< " "<< e1[n].notas[m];
            }
            cout << "\t Promedio: " << e1[n].promedio << endl;
        }
		// Ingresar Informacion de estudiantes
        for (int n = 0; n < numest; ++n){
            cin.ignore(1);
            cout << " Nombre: " ;
            getline(cin,e1[n].nombre);
            cout<< " ingrese " << 5 << " Notas por estudiante "<< endl;
            sumnotas=0.0; 
            for(int m=0; m<5; ++m){
                cin >> e1[n].notas[m];
                sumnotas += e1[n].notas[m];
            }
            e1[n].promedio=sumnotas/5;
            cout << "\t Promedio: " << e1[n].promedio << endl;
        }
        // Mostrar arreglo final
		for (int n = 0; n < numest; ++n){
            cout << n << " Nombre: " << e1[n].nombre << "\t Notas:"; 
            for(int m=0; m<5; ++m){
                cout<< " "<< e1[n].notas[m];
            }
            cout << "\t Promedio: " << e1[n].promedio << endl;
        }

	delete[] e1;
	getch();
	return 0;
}
