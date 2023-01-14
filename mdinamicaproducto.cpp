#include <iostream>
using namespace std;

void mulmatvec(int m, int n, double **a, double *x, double *b){
  int i,j;

  for(i = 0; i < m; i++){
    b[i] = 0.;
    for(j = 0; j < n; j++)
      b[i] += a[i][j]*x[j];
  }
  return;
}

int main(){
  int i,j,m,n;

  cout << "Ingrese el numero de filas en la matriz \n";
  cin >> m;
  cout << "Ingrese el numero de columnas en la matriz \n";
  cin >> n;

  // Asignando espacio para los vectores
  double *x = new double[n];
  double *b = new double[m];

  // Asignando espacio para la matriz
  double **a = new double* [m];
  for(i = 0; i < m; i++)
    a[i] = new double[n];

  if(!x || !b || !a){
    cerr << "No es posible asignar espacio\n";
    return 1;
  }

  cout << "Ingrese los elementos de la matriz A\n";
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      cin >> a[i][j];

  cout << "Ingrese los elementos del vector x\n";
  for(j = 0; j < n; j++)
    cin >> x[j];

  mulmatvec(m,n,a,x,b);

  cout << "\nA*x = \n"<<endl;
  for(i = 0; i < m; i++)
    cout << b[i] << "\n";

  delete [] a;
  delete [] b;
  delete [] x;

  return 0;
}
