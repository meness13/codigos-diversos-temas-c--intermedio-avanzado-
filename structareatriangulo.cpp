#include <iostream>
#include <iomanip>
#include<math.h>
using namespace std;

struct punto{
	float x;
	float y; 
}puntos[2];

int main(){
	float l1,m,l2,l3,sp;
	for(int i=0;i<2;i++){
		cout<<"ingrese la cordenada x del punto:"<<i+1<<endl;
		cin>>puntos[i].x;
		cout<<"ingrese la cordenada y del punto:"<<i+1<<endl;
		cin>>puntos[i].y;
	}
		l1=sqrt((puntos[0].x-puntos[1].x)*(puntos[0].x-puntos[1].x)+(puntos[0].y-puntos[1].y)*(puntos[0].y-puntos[1].y));
		m=((puntos[0].y-puntos[1].y)/(puntos[0].x-puntos[1].x));
		cout<<"La distancia entre los puntos es :"<<l1<<endl;
	cout<<"\n La ecuacion es:"<<endl;
	cout<<"Y="<<1.0*((-m)*puntos[0].x+puntos[0].y)<<" "<<1.0*m<<"x";
	l2=sqrt((puntos[0].x)*(puntos[0].x)+(puntos[0].y)*(puntos[0].y));
	l3=sqrt((puntos[1].x)*(puntos[1].x)+(puntos[1].y)*(puntos[1].y));
	sp=(l1+l2+l3)/2;
	cout<<"\nEl area es: "<<sqrt(sp*(sp-l1)*(sp-l2)*(sp-l3));

	return 0;
}
