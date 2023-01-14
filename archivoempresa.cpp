#include<iostream>
#include<fstream>
#define TAM 20
using namespace std;
struct tFecha{
   int dd,mm,aa;
};
struct tipoTrabajador{
   int codigo;
   string nombre;
   string categoria;
   double sueldo;
   tFecha fing; 
};
int menu();
void leerTrabajador(tipoTrabajador trab[],int n);
void buscarxCodigo(tipoTrabajador trab[],int n);
void buscarxSalario(tipoTrabajador trab[],int n);
void buscarxFechas(tipoTrabajador trab[],int n);
int main() {
    tipoTrabajador trab[TAM];
    int n,opc;
    cout<<"Numero de trabajadores: ";
    cin>>n;
    leerTrabajador(trab,n);    
    do{
    	opc=menu();
    	switch (opc){
	    	case 1:
			    buscarxCodigo(trab,n);break;
			case 2:
	    		buscarxSalario(trab,n);break;
	    	case 3:
				buscarxFechas(trab,n);break;	
	    } 
    }while (opc!=4);
	return 0;
}
int menu(){
	int resp;
	cout<<"\tMenu\n";
	cout<<"(1) Buscar por Codigo\n";
	cout<<"(2) Buscar por Salario\n";
	cout<<"(3) Buscar por rango de Fechas\n";
	cout<<"(4) Salir\n";	
	cout<<"Elija la opcion: ";
	cin>>resp;
	return resp;
}
void buscarxFechas(tipoTrabajador trab[],int n){
	tFecha f1,f2;
	cout<<"\nFecha Inicial"<<endl;
	cout<<"dia: ";cin>>f1.dd;
	cout<<"mes: ";cin>>f1.mm;
	cout<<"año: ";cin>>f1.aa;
	
	cout<<"\nFecha Final"<<endl;
	cout<<"dia: ";cin>>f2.dd;
	cout<<"mes: ";cin>>f2.mm;
	cout<<"año: ";cin>>f2.aa;
	cout<<"Relacion de Trabajadores que ingresaron entre ambas fechas\n";
	for (int i=0;i<n;i++)
	    if ( (trab[i].fing.dd>=f1.dd and trab[i].fing.mm>=f1.mm and trab[i].fing.aa>=f1.aa) and 
	         (trab[i].fing.dd<=f2.dd and trab[i].fing.mm<=f2.mm and trab[i].fing.aa<=f2.aa) )
	    {
	       cout<<"Codigo: "<<trab[i].codigo<<endl;
	       cout<<"Nombre: "<<trab[i].nombre<<endl; 
	       cout<<"Categoria: "<<trab[i].categoria<<endl; 
	       cout<<"Sueldo: "<<trab[i].sueldo;
	    }					    
}
void buscarxSalario(tipoTrabajador trab[],int n){		
	double salary;
	cout<<"\nIngrese un salario= ";
	cin>>salary;
	
	for (int i=0;i<n;i++)
	    if (trab[i].sueldo>salary ){
	       cout<<"Codigo: "<<trab[i].codigo<<endl;
	       cout<<"Nombre: "<<trab[i].nombre<<endl; 
	       cout<<"Categoria: "<<trab[i].categoria<<endl; 
	       cout<<"Sueldo: "<<trab[i].sueldo;
	    }
}
void buscarxCodigo(tipoTrabajador trab[],int n){
	int code;
	cout<<"\nIngrese un codigo= ";
	cin>>code;
	for (int i=0;i<n;i++)
	    if (code == trab[i].codigo ){
	       cout<<"Nombre: "<<trab[i].nombre<<endl; 
	       cout<<"Categoria: "<<trab[i].categoria<<endl; 
	       cout<<"Sueldo: "<<trab[i].sueldo;
	    }
}
void leerTrabajador(tipoTrabajador trab[],int n){
    for (int i=0;i<n;i++){
	    cout<<"Trabajador "<<i+1<<": ";
	    cout<<"Codigo: ";cin>>trab[i].codigo;
	    cin.ignore();
	    cout<<"Nombre: ";getline(cin, trab[i].nombre); 
	    cout<<"Categoria: ";getline(cin, trab[i].categoria); 
	    cout<<"Sueldo: ";cin>>trab[i].sueldo;
	    cout<<"Fecha de Ingreso\n";
	    cout<<"Dia: ";cin>>trab[i].fing.dd;
	    cout<<"Mes: ";cin>>trab[i].fing.mm;
	    cout<<"Año: ";cin>>trab[i].fing.aa;
	}
}
