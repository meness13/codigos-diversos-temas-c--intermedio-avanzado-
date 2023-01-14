
#include <iostream>
using namespace std;

class Imagin{
	public:

	double x,y;

	Imagin(double nx, double ny){

	x=nx;y=ny;}
};

int main(){

	double nu1,nu2;
	cout << "Primer número \n";
	cout<< "Ingrese la parte real:";
	cin>> nu1;
	cout<< "Ingrese la parte imaginaria:";
	cin>> nu2;
	Imagin number1(nu1,nu2);
	cout << "Segundo número \n";
    double nu3,nu4;
	cout<< "Ingrese la parte real:";
	cin>> nu3;
	cout<< "Ingrese la parte imaginaria:";
	cin>> nu4;
	
	Imagin number2(nu3,nu4);

	double real;

    real = number1.x +number2.x;

    double imagin;

    imagin = number2.y + number1.y;

    cout << "La suma de la parte real es "<< real << "\n";
    cout << "La suma de la parte imaginaria es "<<imagin;

    return 0;
}
