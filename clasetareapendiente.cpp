#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int NumTareas=3;

class tarea{
 public:
    tarea(){ // constructor de la clase
        descripcion="Nueva Tarea";
        prioridad=0;
        estado=false;
    }
    string getDescripcion(){
        return(descripcion);
    }
    int getPrioridad(){
        return prioridad;
    }
    bool getEstado(){
        return estado;
    }
    void setDescripcion(string desc){
        descripcion= desc;
    }
    void setPrioridad(int pri){
        prioridad= pri;
    }
    void setEstado(bool est){
        estado=est;
    }
private:
    string descripcion;
    int prioridad;
    bool estado;
};

tarea tareas[NumTareas];
void listarTareas() ;

int main(){
    string desc;
    int prior, numTar; //Prioridad, Numero de tarea
    char yesno;
    listarTareas();
    cout<< "Desea Modificar una tarea? (S/N): ";
    cin >> yesno;
    while(yesno=='S'|| yesno=='s'){
        cout<< "\nIngrese el numero de la tarea a modificar: ";
        cin >> numTar;
        cin.ignore(1);
        cout << "\nIngrese la descripcion de la tarea y su prioridad. \n";
        cout << "Descripcion: "; getline(cin,desc); 
        cout << "Prioridad: "; cin>> prior;
        tareas[numTar].setDescripcion(desc);
        tareas[numTar].setPrioridad(prior);
        tareas[numTar].setEstado(true);
        listarTareas();
        cout<< "Desea Modificar otra tarea? (S/N): ";
        cin >> yesno;
    }    
    return 0;    
}

void listarTareas(){
    //listar tareas del dia
    cout << "Tareas del Dia" << endl;
    cout << "N° " << setw(30)<<"Descripcion " << setw(5) 
    << " estado" <<  setw(5) <<  " Prioridad"<< endl;
    for (int i =0; i<NumTareas; i++){
        cout << i << setw(30)<<tareas[i].getDescripcion() << setw(5) 
        << tareas[i].getEstado() << setw(7)  << tareas[i].getPrioridad()  << endl;
    }

}
