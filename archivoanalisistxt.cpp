#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
// Prototipos de funci�n
void OpenFiles(ifstream&, ofstream&);
void IncrementCounter(char, int&, int&, int&, int&, int&, int&);
void Printtabla(ofstream& table, int, int, int, int, int, int);
int main(){
// Preparar los archivos para lectura y escritura
ifstream texto;
ofstream tabla;
char caracter;
// Declarar e inicializar contadores
int mayuscula = 0; // N�mero de letras may�sculas
int minuscula = 0; // N�mero de letras min�sculas
int espacio = 0; // N�mero de espacios
int digito = 0; // N�mero de d�gitos
int signos = 0; // N�mero de caracteres de fin de enunciado '.', '?', '!'
int otroscaracteres = 0; // Caracteres restantes

OpenFiles(texto, tabla);
if ( !texto || !tabla){
cout << "Los archivos no se abrieron de manera exitosa." << endl;
return 1;
}
texto.get(caracter); // Introducir un car�cter
do{ // Procesar cada car�cter
IncrementCounter(caracter, mayuscula, minuscula, espacio, digito, signos,otroscaracteres);
texto.get(caracter);
} while (texto);

Printtabla(tabla, mayuscula, minuscula, espacio, digito, signos, otroscaracteres);
texto.close();
tabla.close();
return 0;
}

void IncrementCounter(char caracter, int &mayuscula, int &minuscula, int&espacio, int &digito, int &signos, int &otroscaracteres){
if (isupper(caracter))
mayuscula++;
else if (islower(caracter))
minuscula++;
else if (caracter == ' ')
espacio++;
else if (isdigit(caracter))
digito++;
else if ((caracter == '.') || (caracter == '?') || (caracter == '!'))
signos++;
else
otroscaracteres++;
}

void Printtabla(ofstream &tabla, int mayuscula, int minuscula, int espacio, int
digito, int signos, int otroscaracteres ) {
float total = mayuscula + minuscula + espacio + digito + signos + otroscaracteres;

tabla << fixed << setprecision(3) << "Porcentaje de may�sculas: " << mayuscula /
total * 100 << endl;
tabla << fixed << setprecision(3) << "Porcentaje de min�sculas: "<< minuscula /
total * 100 << endl;
tabla << fixed << setprecision(3) << "Porcentaje de espacios: " << espacio / total
* 100 << endl;
tabla << fixed << setprecision(3) << "Porcentaje de d�gitos: " << digito / total *
100 << endl;

tabla << fixed << setprecision(3) << "Porcentaje de signos de fin del enunciado "
<< "Puntuaci�n " << signos / total * 100 << endl;
}

void OpenFiles(ifstream& texto, ofstream& tabla ){
string inFileName; // Nombre de archivo de entrada especifi cado por el usuario
string outFileName; // Nombre de archivo de salida especifi cado por elusuario
cout << "Introducir el nombre del archivo de entrada que ser� procesado" <<
endl;
cin >> inFileName;
texto.open(inFileName.c_str());
cout << "Introducir el nombre del archivo de salida" << endl;
cin >> outFileName;
tabla.open(outFileName.c_str());
tabla << "An�lisis de caracteres en el archivo de salida " << inFileName << endl;
}
