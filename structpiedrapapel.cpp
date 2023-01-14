#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;
struct ppt{
int d; // Diego
int f; // Fernando
} juego[2];

int main(){
	int n,i=0;
	cout<<"ingrese la cantidad de partidas"<<endl;cin>>n;
	cout<<"Piedra = 0"<<"Papel = 1"<<"Tijeras = 2"<<endl;
do{
	
	cout<<"Que juega diego";
	cin>>juego[i].d;cout<<"\n";
	cout<<"Que juega fernando";
	cin>>juego[i].f;

		if(juego[i].d == 0 ){
			cout<<"Diego saco Piedra"<<endl;
		}else if(juego[i].d == 1 ){
			cout<<"Diego saco papel"<<endl;
		}else if(juego[i].d == 2 ){
			cout<<"Diego saco tijeras"<<endl;
		}else if(juego[i].f == 0 ){
			cout<<"Fernando saco Piedra"<<endl;
		}else if(juego[i].f == 1 ){
			cout<<"Fernando saco papel"<<endl;
		}else if(juego[i].f == 2 ){
			cout<<"Fernando saco tijeras"<<endl;
		}
		
		if ((juego[i].f==1 && juego[i].d==0) ||  (juego[i].f==2 && juego[i].d==1) ||  (juego[i].f==0 && juego[i].d==2)){
	         cout<<"gana Fernando";cout<<"\n";
	   }
	   	if ((juego[i].d==1 && juego[i].f==0) ||  (juego[i].d==2 && juego[i].f==1) ||  (juego[i].d==0 && juego[i].f==2)){
	         cout<<"gana Diego";cout<<"\n";
	   }else{
	   	cout<<"Empate";cout<<"\n";
	   }
cout<<"\n";
	i++;	
	}while(i<n);
		
	getch();
	return 0;
}
