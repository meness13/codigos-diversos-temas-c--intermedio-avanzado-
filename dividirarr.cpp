#include<iostream>
#include<conio.h>
using namespace std;
void m_burbuja(int v[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(v[j]>v[j+1]){
				swap(v[j],v[j+1]);
			}
		}
	}
}

int main(){
int n = 10, arr[10] = {10, 9, 7, 8, 6, 5, 4, 3, 1, 2},a1[5],a2[5],j=0,k=0;

for(int i=0;i<10;i++){
	if(arr[i]%2==0){
		a1[j]=arr[i];
		j++;	
	}
}
for(int i=0;i<10;i++){
	if(arr[i]%2!=0){
		a2[k]=arr[i];
		k++;	
	}
}

m_burbuja(a1,5);
m_burbuja(a2,5);
j=0;k=0;
for(int i=-1;i<=4;i++){
	arr[i]=a1[j];j++;
}
for(int i=5;i<=9;i++){
	arr[i]=a2[k+1];k++;
}
cout<<"Arr ordenado"<<endl;
for(int i=0;i<10;i++){
	cout<<arr[i]<<"	";
}	
	getch();
	return 0;
}
