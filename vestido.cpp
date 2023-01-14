#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void ordenar(string *vestidos, int size);
bool contieneString(string palabra, char color[50]);
int comparacionString(char palabra[50], char palabra2[50]);
int main()
{
    string vestidos[] = {"Vestido Clara blanca",
                         "Vestido Estela roja",
                         "Vestido Leonor blanca",
                         "Vestido Rosa blanca",
                         "Vestido Rosa roja",
                         "Vestido Clara verde",
                         "Vestido Estela blanca"};
    ordenar(vestidos, 7);
    return 0;
}
void ordenar(string *vestidos, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (contieneString(*(vestidos + i), "blanca"))
        {
            cout << *(vestidos + i)<<endl;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (contieneString(*(vestidos + i), "roja"))
        {
            cout << *(vestidos + i)<<endl;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (contieneString(*(vestidos + i), "verde"))
        {
            cout << *(vestidos + i)<<endl;
        }
    }
}
bool contieneString(string palabra, char color[50])
{
    char aux[50];
    int index = 0;
    bool encontro = false;
    for (char &c : palabra)
    {        
        if (c != char(32))
        {
            aux[index] = c;
            index++;
        }
        else
        {
            memset(aux, 0, 50 * (sizeof aux[0]));
            index = 0;
        }        
        if (comparacionString(aux, color) == 0)
        {
            encontro = true;
        }
    }
    return encontro;
}

int comparacionString(char palabra[50], char palabra2[50])
{
    return strcmp(palabra, palabra2);
}
