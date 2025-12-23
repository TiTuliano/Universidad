#include <iostream>
#include <cstring>

using namespace std;
typedef char cadena [50];

/* Diseñe un programa que solicite una frase por teclado, la invierta y la muestre por pantalla.
 Por ejemplo, si se introduce la frase “Hola caracola” debe mostrar por pantalla “alocarac aloH”*/

int main()
{
    cadena frase;
    cadena invertida;

    cout<<"Introduce una frase para invertirla: ";
    cin.getline(frase,50);

    int longitud=strlen(frase);
    int j=0;

    for(int i=longitud-1; i>=0; i--)
    {
        invertida[j]=frase[i];
        j++;
    }

    cout<<"La frase invertida es: "<<invertida<<endl;;

    if(strcmp(frase,invertida)==0)
        cout<<"La frase es un palindromo.";
    else
        cout<<"La frase no es un palindromo.";

    return 0;
}
