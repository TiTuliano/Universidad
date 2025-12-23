#include <iostream>
#include <conio.h>   // Para getch()
#include <cstring>   // Para strlen() y strupr()
#include <cctype>    // Para toupper()

using namespace std;

int main()
{
    char palabraSecreta[50];
    char palabraOculta[50];
    char letra;
    int puntos = 9;
    int i = 0;
    char c;

    cout << "Introduce la palabra secreta (se mostrara *): ";
    while((c = getch()) != 13) // Leer hasta Enter
    {
        palabraSecreta[i] = c;
        i++;
        cout << '*';
    }
    palabraSecreta[i] = '\0';

    strupr(palabraSecreta);  // Convertir a mayúsculas
    int longitud = strlen(palabraSecreta);

    for(i = 0; i < longitud; i++)
        palabraOculta[i] = '_';
    palabraOculta[longitud] = '\0';

    cout << "\nComienza el juego:\n";

    bool letraAcertada;
    while(puntos > 0 && strcmp(palabraOculta, palabraSecreta) != 0)
    {
        letraAcertada = false; // reiniciar cada turno

        cout << "Palabra: " << palabraOculta << endl;
        cout << "Introduce una letra: ";
        cin >> letra;
        letra = toupper(letra);

        for(int i = 0; i < longitud; i++)
        {
            if(palabraSecreta[i] == letra)
            {
                palabraOculta[i] = letra;
                letraAcertada = true;
            }
        }

        if(!letraAcertada)
        {
            puntos--;
            cout << "Letra incorrecta. Puntos restantes: " << puntos << "\n";
        }
    }

    if(strcmp(palabraOculta, palabraSecreta) == 0)
    {
        cout << "\n¡Felicidades! Has adivinado la palabra: " << palabraSecreta << "\n";
        cout << "Puntos finales: " << puntos << "\n";
    }
    else
    {
        cout << "\nSe han acabado los puntos. La palabra era: " << palabraSecreta << "\n";
    }

    return 0;
}


