#include<iostream>
#include<conio.h>
#include<sstream>
#include<string>
using namespace std;
void calculadora(){
	cout<<"Que operacion va a realizar"<<" + "<<" - "<<" * "<<" / "<<endl;
	string operacion;
	getline(cin,operacion);
	if(operacion=="+"||operacion=="-"||operacion=="*"||operacion=="/"){
		cout<<"ingresa el primer nro"<<endl;
		string n1;getline(cin,n1);
		cout<<"ingresa el segundo nro"<<endl;
		string n2;getline(cin,n2);
		float num1,num2;
		if(istringstream(n1)>>num1 && istringstream(n2)>>num2){
			if(operacion=="+"){cout<<"La suma es: "<<num1+num2;}
			else if(operacion=="-"){cout<<"La diferencia es: "<<num1-num2;}
			else if(operacion=="*"){cout<<"El producto es: "<<num1*num2;}
			else{cout<<"La division es:"<<num1/num2;}
			cout<<"Deseas continuar? si-no"<<endl;
			string pr;getline(cin,pr);
			if(pr=="si"){calculadora();}
			else{};
		}
	}
}

int main(){
	string cad;
	calculadora();
	getch();
	return 0;
}
