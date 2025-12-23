#include <iostream>
#include <cstring>

using namespace std;
typedef char cadena[50];

int main()
{
    cadena frase;
    cadena compacta;
    cout<<"escribe una frase: ";
    cin.getline(frase,50);


    int j=0;
    for(int i=0; i<strlen(frase); i++)
    {
        if(frase[i]!=' ')
        {
            compacta[j]=frase[i];
            j++;
        }
    }

    cout<<compacta;

    return 0;
}
