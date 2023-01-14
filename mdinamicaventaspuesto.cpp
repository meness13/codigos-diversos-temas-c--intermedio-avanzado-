#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
int main(){
	int i,j,f=9,c=2,*tablaB;		
	string **tablaA,**Trpta;
	string t1A[f][c]={	
					{"VIDAL",	"ASISTENTE"	},
					{"MORALES",	"VENTAS"	},
					{"SANZ",	"VENTAS"	},
					{"IGLESIAS","GERENTE"	},
					{"MARTIN",	"VENTAS"	},
					{"VAZQUEZ",	"GERENTE"	},
					{"MORENO",	"GERENTE"	},
					{"JIMENEZ",	"ANALISTA"	},
					{"GARCIA",	"PRESIDENTE"},
				};
	int t1B[f]={	800,
					1600,
					1250,
					2975,
					1250,
					2850,
					2450,
					3000,
					5000;
					}	;	

	tablaA = new string*[f];  
	for(i=0; i<f; i++){
		tablaA[i] = new string[c];	
	}

	tablaB = new int[f];
	for(i=0; i<f; i++){
			tablaB[i] = t1B[i];
	}cout<< "\n";

	cout<< "**********\n";	
	for(i=0; i<f; i++){
		for(j=0; j<c; j++){
			tablaA[i][j] = t1A[i][j];
			cout<< tablaA[i][j] << " ";
		} cout<< tablaB[i] << " \n";
	}
	cout<< "----------\n";
	string buscar = "VENTAS";
	cout<< "\nEL PUESTO ES: " << buscar<<"\n""";
		
	int f_ = 0;
	int c_ = 2;
	for(i=0;i<f;i++){
		if(!tablaA[i][1].find("VENTAS") ){
			f_++;
		}		
	}
	Trpta = new string*[f];  
	for(i=0; i<f_; i++){
		Trpta[i] = new string[c_];	
	}
	
	int tmp=0;
	char tmpnum[20];
	int sum = 0;
	for(i=0;i<f;i++){
		if(!tablaA[i][1].find(buscar) ){
			Trpta[tmp][0] = tablaA[i][0];
			itoa(tablaB[i],tmpnum,10);
			Trpta[tmp][1] = tmpnum;		
			sum = sum + tablaB[i];
			tmp++;
		}		
	}
	cout<< "----------\n" ;
	for(i=0;i<f_;i++){		
		cout<<"Find2: "<<Trpta[i][0]<<" " <<Trpta[i][1]<< "\n";				
	}
	cout<<"\nEl promedio de SUELDO es: "<< (1.0*sum/f_);

	delete[] tablaA;
	delete[] Trpta;
	return 0;
}

