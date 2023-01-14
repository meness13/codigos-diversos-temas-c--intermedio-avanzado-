#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

void genera(int *m,int n){
	for(int i=0;i<n;i++){
		m[i]=rand()%20+1;
		cout<<m[i]<<"	";
	}
}

int b_binariarecursiva(int a[],int clave,int p,int u){
	int central=(p+u)/2;
	if(p>u){
		return -1;
	}else{
		if(clave==a[central]){
			return central;
		}else if(clave>a[central]){
			return b_binariarecursiva(a,clave,central+1,u);
		}else{
			return b_binariarecursiva(a,clave,p,central-1);
		}
	}
}

void m_burbuja(int v[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(v[j]>v[j+1])
			{
            swap(v[j+1],v[j]);
			}	
		}
	}		
}

int main(){
	int *m,n,clave,resultado;
	cout<<"ingrese la cantidad dde noras"<<endl;cin>>n;
	m=new int[n];
	srand(time(0));
genera(m,n);cout<<endl;
m_burbuja(m,n);//ordena el arr
for(int i=0;i<n;i++){
	cout<<m[i]<<"	";
}
cout<<"\nque numero desea buscar en el arr";cin>>clave;
resultado=b_binariarecursiva(m,clave,0,n);
cout<<resultado;
if(resultado ==-1){
	cout<<"El nro no esta en el arr"<<endl;
}else{cout<<"El nro esta en el arr en la posicion"<<resultado;};


	delete m;
	getch();
	return 0;
}
