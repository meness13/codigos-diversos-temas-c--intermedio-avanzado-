#include<iostream>
#include<conio.h>
#include<string>
#include<cstdio>
using namespace std;
struct paciente{
   int codpac;
   int codenf;
   int codmed;
};
void display(paciente p);
paciente ingresar();
int menu();

int main(){
   paciente pac1, *eptr;
   int resp,codp,codm;
   paciente arr_pac[10];
   resp=menu();
   int c=0;
   while (resp!=4){
	   if ( resp==1 ){
	       arr_pac[c]=ingresar();
	       display( arr_pac[c] );
	       c++;
	   }
	   else if (resp==2){
	   	   cout<<"codigo del paciente= ";
	   	   cin>>codp;
	   	   for (int i=0;i<c;i++){
	   	      if (arr_pac[i].codpac==codp){
	   	      	cout<<"cod enf= "<<arr_pac[i].codenf<<endl;
	   	      	cout<<"cod med= "<<arr_pac[i].codmed;
	   	      }
	       }          
	   }
	   else if (resp==3){
	   	   cout<<"codigo del medico= ";
	   	   cin>>codm;
	   	   for (int i=0;i<c;i++){
	   	      if (arr_pac[i].codmed==codm){
	   	      	cout<<"cod pac= "<<arr_pac[i].codpac<<endl;
	   	      }
	       }          
	   }	   
	   
	   resp=menu();
	}
   getch();
}
paciente ingresar(){
	paciente pac1;
   cout<<"codigo paciente: ";
   cin>>pac1.codpac;
   cout<<"codigo enfermedad: ";
   cin>>pac1.codenf;
   cout<<"codigo medico: ";
   cin>>pac1.codmed;
   return pac1;
}

void display(paciente p)
{
   cout<<"Paciente code: "<<p.codpac;
   cout<<"\tEnfermedad: "<<p.codenf;
   cout<<"\tMedico: "<<p.codmed;
}

int menu(){
	int opc;
	cout<<"\n1.Ingreso de paciente"<<endl;
	cout<<"2.Consulta de paciente"<<endl;
	cout<<"3.Dar de alta a paciente"<<endl;
	cout<<"4.Salir"<<endl;
	cout<<"Opcion= "	;
	cin>>opc;
	return opc;
}

