#include <iostream>
#include <fstream>
using namespace std;

const int Capacidad = 100;
const char Salir = 's';
const char Agregar = 'a';
const char Ver = 'v';
const char Remove = 'r';
const int NotFound = -1;

struct Libro{
int codigo;
string titulo;
string descripcion;
double precio;
};

char getComando(){
char ch;
cout << "Por favor, elija un libro,\n (A)gregar libro,\n (V)er la informacion de unlibro,\n"<< " (R)emover un libro \n (S)alir:\n";
cin >> ch;
return tolower(ch);
}

int getId(){
int x;
cout << "Por favor, introduzca la Id. del libro: ";
cin >> x;

while (x <= 0) {
cout << "Número positivo como Id: ";
cin >> x;
}

string garbage;
getline(cin, garbage);

return x;
}

double getprecio(){
double x;

cout << "Ingrese el precio del libro: ";
cin >> x;

while (x <= 0) {
cout << "El precio del libro es positivo: ";
cin >> x;
}

string garbage;
getline(cin, garbage);

return x;
}

void getInfoLibro(Libro& alibro){
cout << "Ingrese el título del libro: ";
getline(cin, alibro.titulo);
cout << "Ingrese la descripcion del libro: ";
getline(cin, alibro.descripcion);
alibro.precio = getprecio();
}

int buscar(Libro arr[] , int size, int id){
for(int i = 0; i < size; ++i) {
if (arr[i].codigo == id)
return i;
}
return 0;
}

void imprimir(const Libro& alibro){
cout << "Libro id: " << alibro.codigo << endl;
cout << "Titulo: " << alibro.titulo << endl;
cout << "Descripcion: " << alibro.descripcion << endl;
cout << "Precio: " << alibro.precio << endl;
cout << "------------------------------\n";
}

void ver(Libro arr[], int size){
int id = getId();

int index = buscar(arr, size, id);

if (index == NotFound) {
cout << "No se ecuentra el libro.\n";
cout << "-------------\n";
} else {
imprimir(arr[index]);
}

}

void agregar(Libro arr[], int& size){
if (size >= Capacidad) {
cout << "No hay espacio. No se pueden agregar más libros al inventario.\n";
cout << "-------------\n";
return;
}

int id = getId();
cout << size << "--" << id << ".\n";
int index = buscar(arr, size, id);
if (index != NotFound) { // duplicate
cout << "El Libro ya esta en el inventario.\n";
cout << "-------------\n";
} else { // insert into unsorted array
arr[size].codigo = id;
getInfoLibro(arr[size]);
++size;
cout << "El Libro se agrego al inventario.\n";
cout << "-------------\n";
}
}

void remove(Libro arr[], int & size) {
int id = getId();

int index = buscar(arr, size, id);

if (index == NotFound) {
cout << "El libro no se encuentra en la biblioteca.\n";
cout << "-------------\n";
} else {
cout << "El libro se removio: \n";
imprimir(arr[index]);
--size;
arr[index].codigo = arr[size].codigo;
arr[index].titulo = arr[size].titulo;
arr[index].descripcion = arr[size].descripcion;
arr[index].precio = arr[size].precio;
}
}

int cargarLibros(string filename, Libro arr[]){
ifstream fin;
int size = 0;
string garbage;
fin.open(filename.c_str());
if (fin.good()) {
fin >> size;
for(int i = 0; i < size; i++) {
fin >> arr[i].codigo;
getline(fin, garbage);
getline(fin, arr[i].titulo);
getline(fin, arr[i].descripcion);
fin >> arr[i].precio;
getline(fin, garbage);

}
cout << "Se ha cargado con exito " << size << " Libros.\n";
} else {
cout << "No se puede abrir el archivo \n"
<< "Iniciar el programa con 0 libros en la coleccion.\n";
}
fin.close();
return size;
}

void guardarLibros(string filename, Libro arr[], int size){
ofstream fout;
fout.open(filename.c_str());
if (fout.good()) {
fout << size << endl;
for(int i = 0; i < size; i++) {
fout << arr[i].codigo << endl
<< arr[i].titulo << endl
<< arr[i].descripcion << endl
<< arr[i].precio << endl;
}
cout << "Se ha exportado con exito " << size << " registros.\n";
} else {
cout << "No puede abrir el " << filename << " para escribir.\n"
<< "termina el programa sin guardar.\n";
}
}

int main(){
const string filename = "Libros.txt";
char cmd;
Libro libros[Capacidad];
int size = 0;
int id;

size = cargarLibros(filename, libros);

cmd = getComando();

while (cmd != Salir) {
switch (cmd) {
case Agregar: agregar(libros, size);
break;
case Ver: ver(libros, size);
break;
case Remove: remove(libros, size);
break;
default: cout << "Comando Invalido.\n";
}
cmd = getComando();
}
guardarLibros(filename, libros, size);
cout << "Saliendo ...\n";
return 0;
}
