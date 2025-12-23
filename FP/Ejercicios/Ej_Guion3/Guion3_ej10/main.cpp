#include <iostream>
#include <cstring>

using namespace std;
typedef char cadena[50];

int main()
{
    cadena nombre;
    cadena apellido1,apellido2;

    cout<<"Introduce tu nombre: ";
    cin.getline(nombre,50);

    cout<<"Introduce tu primer apellido: ";
    cin.getline(apellido1,50);

    cout<<"Introduce tu segundo apellido: ";
    cin.getline(apellido2,50);

    strcat(nombre, apellido1);

    cout<<"Tu nombre completo es: "<<strcat(nombre,apellido2);

    return 0;
}
