
#include<iostream>
using namespace std;
int main(){
	int *pv,*pvnew,*pvordenar,*cuatromayores;
	int i = 0, val,k,ii,jj;	
	int dim = 1,auxt;
	pv = new int[dim];
	cuatromayores = new int[4];
	do{
		cout <<"ingresar valor: ";		
		cin >> val;
		if (val > 0){
			if ( (i+1) > dim ){ 
				dim = dim * 2; 			
				int *pvnew = new int[dim];
				memcpy(pvnew, pv, dim * sizeof(int) ); 
				pv = pvnew; 
				
			}
			pv[i] = val; 
			i = i + 1;
			//cout <<"dimension actual "<< i <<"\n";
			cout <<"dimension tabla "<< dim <<"\n";
			int *pvordenar = new int[dim];
			memcpy(pvordenar, pv, dim * sizeof(int) );
			//cout <<"Datos Ingresados "<< dim <<"\n";			
			for (k=0;k<i;k++){					
				cout<<"["<<k<<"]"<<pvordenar[k]<<",  ";				
			}cout<<"\n";
			//ordeno
			if(i>1){
				for (ii=0;ii<i-1;ii++){
					for (jj=0;jj<i-1;jj++){
						if(pvordenar[jj]<pvordenar[jj+1]){
							auxt = pvordenar[jj];
							pvordenar[jj] = pvordenar[jj+1];
							pvordenar[jj+1] = auxt;
						}			
					}
				}
			}
			//me quedo con 4 mayores
			for (k=0;k<4;k++){					;			
				cuatromayores[k]=pvordenar[k];				
			}
			cout <<"Vector de Tamaño Cuatro con los Mayores\n";

			for (k=0;k<4;k++){					;									
				if(k<i){
					cout<<"["<<k<<"]"<<cuatromayores[k]<<",  ";	
				}
				
			}
			cout<<"\n-----------------------------\n";
		}else break; //si es negativo o cero sale del do while	
	}while(1);

	delete [] pv;
	delete [] pvnew;
	delete [] pvordenar;
	delete [] cuatromayores;
	return 0;
}
