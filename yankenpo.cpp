#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

typedef struct{
	int d;	
	int f;	
} Juego;

int ganar(int d, int f){		
	if(d==f) 	  return 2;	
	if(d==0) 	  return (f==1)? 1:0;
	else if(d==1) return (f==2)? 1:0;
		  		 	  return (f==0)? 1:0;
}
int main(){
	int n=5, i;
	Juego *partida = new Juego[n], *pp= partida;
	srand(time(0));

	for(i=0;i<n;i++, pp++){
		pp->d = rand()%3;			
		pp->f = rand()%3;
	}

	char ppt [3][10] = {"Piedra", "Papel", "Tijera"};
	char jugadores [3][10] = {"Diego", "Fernando", "Empate"};
	int ganador, resultado[3] = {0,0,0};
	cout << "Juego\tDiego\tFernando\tGanador\n";
	pp = partida;
	for(i=0;i<n;i++, pp++){
		ganador = ganar(pp->a, pp->b);
		resultado[ganador]++; 
		cout << i+1 << "\t" << ppt[pp->a] << "\t" << ppt[pp->b] << "\t"  << jugadores[ganador] << endl;
	}
// Reporte del ganador
	if(resultado[0] == resultado[1]) 	 cout << "Hay empate"<<endl;
	else if(resultado[0] > resultado[1]) cout << "El ganador de la partida es: " << jugadores[0] << endl;
		  else 									 cout << "El ganador de la partida es: " << jugadores[1] << endl;
	delete [] partida;
}

