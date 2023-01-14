#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream ar1("ar1.txt");
	if(ar1.is_open()){
		ar1 << 1 << "Adela" << endl;
		ar1 << 5 << "Maria" << endl;
		ar1.close();
	}
	ofstream ar2("ar2.txt");
	if(ar2.is_open()){
		ar2 << 2 << "Jose" << endl;
		ar2 << 4 << "Manuel" << endl;
		ar2 << 7 << "Alberto" << endl;		
		ar2.close();
	}
	ifstream iar1("ar1.txt");
	ifstream iar2("ar2.txt");
	int codigo1, codigo2;
	char nombre1[10], nombre2[10];
	if(iar1.is_open() && iar2.is_open()){
		cout << "Codigo  Nombre\n"; 
		iar1 >> codigo1 >> nombre1;
		iar2 >> codigo2 >> nombre2;
		while(!iar1.eof() && !iar2.eof()){	
			if(codigo1 < codigo2) {
				cout << codigo1 <<  "\t" << nombre1 << endl;
				iar1 >> codigo1 >> nombre1;
			} else {
				cout << codigo2 <<  "\t" << nombre2 << endl;
				iar2 >> codigo2 >> nombre2;
			}
		}
		while(!iar1.eof()){	
			cout << codigo1 <<  "\t" << nombre1 << endl;
			iar1 >> codigo1 >> nombre1;
		}
		while(!iar2.eof()){	
			cout << codigo2 <<  "\t" << nombre2 << endl;
			iar2 >> codigo2 >> nombre2;
		}
		iar1.close();
		iar2.close();
	}
}
