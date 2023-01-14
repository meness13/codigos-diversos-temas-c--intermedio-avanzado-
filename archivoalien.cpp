
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

int M, N;
char *bug, *adn;

void leeEntrada()
{
        ifstream entrada;
        int i;
        char newLine;
        entrada.open("input.txt", ios ::in);
        
        if(entrada.is_open())
          {
             entrada>>M;
             entrada>>N;
          }
         else
          {
             cout<<"Error al abrir el archivo.."<<endl;             
          }

        bug = new char[M];
        adn = new char[N];
        for( i = 0; i < M; i++ )
                entrada>>bug[i];
        entrada>>newLine;
        for( i = 0; i < N; i++ )
                entrada>>adn[i];
        entrada.close();
}

int calculaBug()
{
        int qtty = 0, i, j, k, found;
        for( k = 0; k < N-M+1; k++ )
                for( i = 0; i < M; i++ )
                {
                        found = 1;
                        for( j = 0; j < M; j++ )
                        {
                                if( bug[(j+i)%M] != adn[k+j] )
                                {
                                        j = M;
                                        found = 0;
                                }
                        }
                        if( found )
                        {
                                i = M;
                                qtty++;
                                k += M-1;
                        }
                }
        return qtty;
}

void escribeSalida( int qtty )
{
        ofstream salida;
        salida.open("output.txt", ios ::out);
        salida<<qtty;
        salida.close();
}

int main()
{
        leeEntrada();
        escribeSalida( calculaBug() );
        delete[] bug;
        delete[] adn;
        return 0;
}

 
