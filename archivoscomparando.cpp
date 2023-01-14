#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
//archivos uni...---->	
    ifstream i1("input1.txt", ios::in);
    ifstream i2("input2.txt", ios::in);
    if ( !i1.good() || !i2.good() ) {
        cout << "Error abriendo los archivos" << endl;
        return 1;
    }  
    char l1[100], l2[100];
    int sz1, sz2;
    int line = 0;
    while(i1.getline(l1, 100)) {
        int search = 0;
        if(i2.getline(l2, 100)) {
            if (strcmp(l1, l2)) {
                sz1 = strlen(l1);
                sz2 = strlen(l2);
                int colum = -1;
                for(int i = 0; i < sz1 && i < sz2 && colum == -1; i++) {
                    if (l1[i] != l2[i]) colum = i;
                }
                if (colum == -1) {
                    colum = sz1;
                    if (sz1 >= sz2) colum = sz2;
                }
                cout << "Diferencia en la linea y columna: (" << line << ", " << colum << ")" << endl;
            }
            search = 1;
        }
        if (!search) {
            cout << "Diferencia en la linea y columna: (" << line << ", 0)"<<endl;
        } 
        line++;    
    }
    return 0;
}
