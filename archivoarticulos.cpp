#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream fsOut;
    ifstream fsIn;
    string namefile,namefile2;
    int cod,cant,opc,crear,codart,cancomp,canven,nq;
    float pre;
    string nom;
    char linea[80];
    cout<<"Digite 1 si desea crear el archivo= ";
    cin>>crear;
    if (crear==1){
    //while (true){
	   	cout<<"nombre del archivo: ";
    	cin>>namefile;
    	//fsOut.open(namefile.c_str(),ios::app);	
    }
    bool flag=true;
	while (flag==true){
	   cout<<"1)Ingresar articulo\n";
	   cout<<"2)Lista de articulos\n";
	   cout<<"3)Buscar por codigo de articulo\n";	   
	   cout<<"4)Comprar \n";	   
	   cout<<"5)Vender \n";	   
	   cout<<"6)Salir\n";
	   cout<<"Elija una opcion:";
	   cin>>opc;
	   if (opc==1){
	   	  fsOut.open(namefile.c_str(),ios::app);	
	   	  cout<<"Codigo= ";cin>>cod;
	   	  cout<<"Cantidad= ";cin>>cant;
	   	  cout<<"Precio= ";cin>>pre;
		  cin.ignore();	   	
	   	  cout<<"Nombre= ";
		  getline(cin,nom);
          fsOut<<cod<<endl;
          fsOut<<cant<<endl;
          fsOut<<pre<<endl;       
          fsOut<<nom<<endl;	   			   		   	
	      fsOut.close();
    	  cout<<"Se genero el archivo. Busquelo en su disco duro\n";          
	   }
	   else if (opc==2){
	   	      cout<<"nombre del archivo: ";
	   	      cin>>namefile;
	   	      fsIn.open(namefile.c_str());
	   	      
	   	      int nlin=0;
              while ( !fsIn.eof() ){
              		 fsIn>>cod>>cant>>pre>>nom;
					 nlin=nlin+1;
		      }
			  fsIn.close();	
			  fsIn.open(namefile.c_str());
	   	      int c=1;	   	      
              //if ( fsIn.is_open() ){
              	while ( !fsIn.eof() ){
              		fsIn>>cod>>cant>>pre>>nom;
              		if (c<nlin)    				    
						cout<<"cod= "<<cod<<"cant= "<<cant<<"pre= "<<pre<<"nom="<<nom<<endl;       				   
       				c++;
       		    }
       		   fsIn.close();
       }
	   else if (opc==3){
	   	      //cout<<"nombre del archivo: ";
	   	      //cin>>namefile;
	   	      fsIn.open(namefile.c_str());
	   	      cout<<"Codigo articulo= ";
	   	      cin>>codart;
              while ( !fsIn.eof() ){
              		fsIn>>cod>>cant>>pre>>nom;
              		if (codart==cod ){
					  cout<<"cod= "<<cod<<"cant= "<<cant<<"pre= "<<pre<<"nom="<<nom<<endl;
					}       				
       		    }
       		  fsIn.close();
       }     
	   else if (opc==4){
	   	      cout<<"archivo origen: ";
	   	      cin>>namefile;
	   	      fsIn.open(namefile.c_str());
	   	      
	   	      cout<<"archivo destino: ";
	   	      cin>>namefile2;
	   	      fsOut.open(namefile2.c_str());
	   	      int nlin=0;
              while ( !fsIn.eof() ){
              		 fsIn>>cod>>cant>>pre>>nom;
					 nlin=nlin+1;
		      }
			  fsIn.close();	
			  fsIn.open(namefile.c_str());
	   	      cout<<"Codigo articulo= ";
	   	      cin>>codart;
	   	      cout<<"cantidad comprada= ";
	   	      cin>>cancomp;
	   	      int c=1;
              while ( !fsIn.eof() ){
              		fsIn>>cod>>cant>>pre>>nom;
              		if (codart==cod ){
              			nq=cant+cancomp;
			            fsOut<<cod<<endl;
			            fsOut<<nq<<endl;
			            fsOut<<pre<<endl;       
			            if (c<nlin)
			               fsOut<<nom<<endl;	   			   		   	
			            else
			               fsOut<<nom;	   			   		   	
					}     
					else{
			            fsOut<<cod<<endl;
			            fsOut<<cant<<endl;
			            fsOut<<pre<<endl;          							
			            if (c<nlin)
			               fsOut<<nom<<endl;	   			   		   	
			            else
			               fsOut<<nom;	   			   		   				            
					}			
					c++;
       		  }
       		  fsOut.close();
       		  fsIn.close();
       		  cout<<"Se actualizo el archivo\n";       		  
       }       
	   else if (opc==5){
	   	      cout<<"archivo origen: ";
	   	      cin>>namefile;
	   	      fsIn.open(namefile.c_str());
	   	      
	   	      cout<<"archivo destino: ";
	   	      cin>>namefile2;
	   	      fsOut.open(namefile2.c_str());

	   	      int nlin=0;
              while ( !fsIn.eof() ){
              		 fsIn>>cod>>cant>>pre>>nom;
					 nlin=nlin+1;
		      }
			  fsIn.close();	
			  fsIn.open(namefile.c_str());
				 	   	      
	   	      cout<<"Codigo articulo= ";
	   	      cin>>codart;
	   	      cout<<"cantidad a vender= ";
	   	      cin>>canven;
	   	      int c=0;
              while ( !fsIn.eof() ){
              		fsIn>>cod>>cant>>pre>>nom;
              		if (codart==cod ){
              			if (cant>=canven){
              			    nq=cant-canven;
			                fsOut<<cod<<endl;
			                fsOut<<nq<<endl;
			                fsOut<<pre<<endl;       
				            if (c<nlin)
				               fsOut<<nom<<endl;	   			   		   	
				            else
				               fsOut<<nom;			                
			            }
			            else
			                cout<<"Stock insuficiente!!"<<endl;
				            fsOut<<cod<<endl;
				            fsOut<<cant<<endl;
				            fsOut<<pre<<endl;          							               
				            if (c<nlin)
				               fsOut<<nom<<endl;	   			   		   	
				            else
				               fsOut<<nom;	   			   		   	
					}	
					else{
			            fsOut<<cod<<endl;
			            fsOut<<cant<<endl;
			            fsOut<<pre<<endl;          							
			            if (c<nlin)
			               fsOut<<nom<<endl;	   			   		   	
			            else
			               fsOut<<nom;	   			   		   				            
					}			
					c++;					
					
       		    }
       		  cout<<"Se actualizo el archivo...\n";
       		  fsOut.close();
       		  fsIn.close();
       }       
       else
           flag=false;       	   	  	   
	}
    return 0;
}
