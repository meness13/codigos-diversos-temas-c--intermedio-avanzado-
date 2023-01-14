#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main(){
	int **notas,n,min;
	float *prom,sum;
	do{
		cout<<"ingrese el tamanio del arr"<<endl;cin>>n;	
	}while(n<0);
	notas = new int*[n];
	prom = new float[n];
	srand(time(0));
	for(int i=0;i<n;i++){
		cout<<"El arr de notas nro"<<i+1<<"es:"<<endl;
		notas[i]=new int[6];
		sum=0;
		min=999999;
		for(int j=0;j<6;j++){
		cout<<"["<<i<<"]["<<j<<"]";
		notas[i][j]=rand()%20+1;
		sum+=notas[i][j];
		if(notas[i][j]<min){
			min=notas[i][j];
		}
		cout<<notas[i][j]<<"	"<<endl;	
		}
		cout<<"La nota minima es"<<min<<endl;
		sum=sum-min;
		cout<<"\nEl promedio de"<<i+1<<"es"<<1.00*sum/5<<endl;
	}
	
	
	for(int i=0;i<n;i++){
		delete notas[i];
	}
	delete notas;
	getch();
	return 0;
}
