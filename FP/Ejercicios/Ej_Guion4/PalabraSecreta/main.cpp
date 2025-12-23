#include <iostream>
#include <conio.h>   // getch()
#include <cstring>   // strlen(), strupr()
#include <cctype>    // toupper()

using namespace std;

class PalabraOculta {
private:
    char palabraSecreta[25];
    char palabraJugada[25];
    int Puntos;

public:
    void Iniciar();
    bool Jugada(char letra);
    int getPuntos();
    void MostrarJugada();
    void DescubrirSecreta();
};

void PalabraOculta::Iniciar() {
    int i = 0;
    char c;

    cout << "Introduce la palabra secreta: ";

    // Lectura sin eco y mostrando '*'
    do {
        c = getch();
        if (c != '\r') {   // ENTER
            palabraSecreta[i] = c;
            cout << "*";
            i++;
        }
    } while (c != '\r');

    palabraSecreta[i] = '\0';

    // Convertir a mayúsculas
    strupr(palabraSecreta);

    // Inicializar palabra jugada con guiones
    for (int j = 0; j < i; j++) {
        palabraJugada[j] = '-';
    }
    palabraJugada[i] = '\0';

    // Puntos iniciales
    Puntos = 9;

    cout << endl;
}

bool PalabraOculta::Jugada(char letra) {
    bool acierto = false;
    letra = toupper(letra);

    for (int i = 0; palabraSecreta[i] != '\0'; i++) {
        if (palabraSecreta[i] == letra) {
            palabraJugada[i] = letra;
            acierto = true;
        }
    }

    if (!acierto) {
        Puntos--;
    }

    // Comprobar si se ha adivinado la palabra
    if (strcmp(palabraSecreta, palabraJugada) == 0) {
        return true;
    }

    return false;
}

int PalabraOculta::getPuntos() {
    return Puntos;
}

void PalabraOculta::MostrarJugada() {
    cout << palabraJugada << endl;
}

void PalabraOculta::DescubrirSecreta() {
    cout << palabraSecreta << endl;
}

int main() {
    PalabraOculta juego;
    char letra;
    bool ganada = false;

    juego.Iniciar();

    cout << "Palabra a adivinar: ";
    juego.MostrarJugada();

    while (juego.getPuntos() > 0 && !ganada) {
        cout << "Introduce una letra: ";
        cin >> letra;

        ganada = juego.Jugada(letra);

        cout << "Estado actual: ";
        juego.MostrarJugada();
        cout << "Puntos: " << juego.getPuntos() << endl;
    }

    if (ganada) {
        cout << "Has adivinado la palabra." << endl;
    } else {
        cout << "Has perdido. La palabra era: ";
        juego.DescubrirSecreta();
        cout << endl;
    }

    cout << "Puntos finales: " << juego.getPuntos() << endl;

    return 0;
}
