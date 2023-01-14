#include<iostream>
#include<conio.h>

using namespace std;

void genera(int *m,int n){
	cout<<"ingrese los datos del arr";
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	cout<<"\nDAtos del arr";
	for(int i=0;i<n;i++){
		cout<<i+1<<"["<<m[i]<<"]"<<endl;
	}
}



int main(){
	int *a1,*a2,t1,t2,*sum;
	cout<<"ingrese el tamanio del arr 1"<<endl;cin>>t1;
		cout<<"ingrese el tamanio del arr 2"<<endl;cin>>t2;
	a1=new int [t1];
	a2=new int [t2];
	sum= new int[t1+t2];
	genera(a1,t1);cout<<endl;
	genera(a2,t2);
	cout<<"\n";
	for(int i=0;i<min(t1,t2);i++){
		sum[i]=a1[i]+a2[i];
		cout<<"["<<i<<"]"<<sum[i]<<"	";
	}
	
	
	delete a1;
	delete a2;
	delete sum;
	getch();
	return 0;
}
