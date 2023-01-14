#include<iostream>
#include<conio.h>

using namespace std;

void agregar(int n, int *p, int valor){
int i;
for(i = n; valor < p[i-1] && i > 0; i--) 
p[i] = p[i-1];
p[i] = valor;
}

void quitar(int n, int *p, int valor){
int i;
for(i = n; valor < p[i-1] && i > 0; i--) 
p[i] = p[i+1];
p[i] = valor;
}

int main(){
	int a[10],n=0,ele;
	a[0]=2;a[1]=4;a[2]=7;a[3]=10;
	cout<<"ingresa el elmento en la pos 2"<<endl;cin>>ele;
	agregar(3,a,ele);
		quitar(2,a,7);
	cout<<"\n\n";
	quitar(4,a,12);
	cout<<"El arr final es "<<endl;
		for(int i=0;i<5;i++){
		cout<<a[i]<<"	";
	}

	getch();
	return 0;
}
