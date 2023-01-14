#include<iostream>
#include<conio.h>
using namespace std;

void qsort2(int a[],int p,int u){
	int central=(p+u)/2,pivot=a[central],i=p,j=u;
	do{
		while(a[i]<pivot)i++;
		while(a[j]>pivot)j--;
		if(i<=j){
		swap(a[i],a[j]);
		i++;
		j--;		
		}
	}while(i<=j);
	if(p<j)
	qsort2(a,p,j);
	if(i<u)
	qsort2(a,i,u);
}


int main(){
	int n;cout<<"ingrese ek tamanio del arr";cin>>n;
	int a1[n],aux[n],max=0;
	for(int i=0;i<n;i++){
		cout<<"["<<i+1<<"]";
		cin>>a1[i];
		aux[i]=a1[i];
		if(a1[i]>max){
			max=a1[i];
		}
	}
	qsort2(a1,0,n-1);qsort2(aux,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a1[i]<<"	";
	}cout<<"\n\n";int i=0,j=0;
	while(i<n){
		swap(aux[i],a1[j+1]);
		swap(aux[i+1],a1[j]);
		i=i+2;j=j+2;
		if(i==n){
			aux[n-1]=a1[n-1];
			break;
		}
	}cout<<"\n\n";

	for(int i=0;i<n;i++){
		if(i<n-1){
			cout<<aux[i]<<"	";
		}else{
			cout<<max;
		}
	}
	
	getch();
	return 0;
}
