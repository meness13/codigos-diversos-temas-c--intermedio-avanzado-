#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

int fib(int n){
	if((n<2)){
		return n;
	}
	else{
		return fib(n-1)+fib(n-2);
	}
}

void imprimir(int n,int arr[]){
	for(int i=0;i<n;i++){
		cout<<fib(i)<<"	";
	}cout<<endl;
	cout<<"LAs matrices"<<endl;
	int t=0;
	string **l;
	do{	
	l=new string*[fib(t+1)];
	for(int h=0;h<fib(t+1);h++){
		l[h]=new string[fib(t+1)];
	}
	for(int i=0;i<fib(t);i++){
		for(int j=0;j<fib(t);j++){
			l[i][j]="#";
			cout<<l[i][j]<<" ";
		}cout<<endl;
	}
	t++;

	}while(t<n);
	for(int h=0;h<fib(t+1);h++){
		delete l[h];
	}
delete l;
}

void generar(){
	int *aux,l=0,n=1;
	aux = new int[n];
	cout<<"ingrese la dimension"<<endl;cin>>l;
	
	imprimir(l,aux);
	delete aux;
}


int main(){
	generar();
	
	cout<<"\n\n";
	
	getch();
	return 0;
}
