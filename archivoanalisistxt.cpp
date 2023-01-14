#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
// Prototipos de función
void OpenFiles(ifstream&, ofstream&);
void IncrementCounter(char, int&, int&, int&, int&, int&, int&);
void Printtabla(ofstream& table, int, int, int, int, int, int);
int main(){
// Preparar los archivos para lectura y escritura
ifstream texto;
ofstream tabla;
char caracter;
// Declarar e inicializar contadores
int mayuscula = 0; // Número de letras mayúsculas
int minuscula = 0; // Número de letras minúsculas
int espacio = 0; // Número de espacios
int digito = 0; // Número de dígitos
int signos = 0; // Número de caracteres de fin de enunciado '.', '?', '!'
int otroscaracteres = 0; // Caracteres restantes

OpenFiles(texto, tabla);
if ( !texto || !tabla){
cout << "Los archivos no se abrieron de manera exitosa." << endl;
return 1;
}
texto.get(caracter); // Introducir un carácter
do{ // Procesar cada carácter
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

tabla << fixed << setprecision(3) << "Porcentaje de mayúsculas: " << mayuscula /
total * 100 << endl;
tabla << fixed << setprecision(3) << "Porcentaje de minúsculas: "<< minuscula /
total * 100 << endl;
tabla << fixed << setprecision(3) << "Porcentaje de espacios: " << espacio / total
* 100 << endl;
tabla << fixed << setprecision(3) << "Porcentaje de dígitos: " << digito / total *
100 << endl;

tabla << fixed << setprecision(3) << "Porcentaje de signos de fin del enunciado "
<< "Puntuación " << signos / total * 100 << endl;
}

void OpenFiles(ifstream& texto, ofstream& tabla ){
string inFileName; // Nombre de archivo de entrada especifi cado por el usuario
string outFileName; // Nombre de archivo de salida especifi cado por elusuario
cout << "Introducir el nombre del archivo de entrada que será procesado" <<
endl;
cin >> inFileName;
texto.open(inFileName.c_str());
cout << "Introducir el nombre del archivo de salida" << endl;
cin >> outFileName;
tabla.open(outFileName.c_str());
tabla << "Análisis de caracteres en el archivo de salida " << inFileName << endl;
}
