#include<iostream>
#include<conio.h>
using namespace std;

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

int redimensionar(int *&dir_v, int n)
{
    n+=1;
    int *aux = new int[n];
    for(int i = 0; i < n ; i++)
    {
        aux[i] = dir_v[i];
    }
    m_burbuja(aux,n-1);
    delete[] dir_v;
    dir_v = aux;
}


int main(){
	int n=1,*vector,i=0,*dir_ultimo,nd;
	vector=new int[n];//reserva memoria para n enteros
	cout<<"ingrese datos para el arr"<<endl;
	while(1){
		cout<<"ingrese datos termina con 0:"<<endl;
		cout<<"["<<i<<"]";cin>>vector[i];
		if(vector[i]==0){
			dir_ultimo=&vector[0];
			for(int k=0;k<i;k++){
				cout<<*dir_ultimo++<<"	";
			}
			break;
		}
		if(i==n-1){//rediemnsiona el vector
			redimensionar(vector,n);
		}
	i++;n++;
	}	
	
	delete[] vector;
	getch();
	return 0;
}
