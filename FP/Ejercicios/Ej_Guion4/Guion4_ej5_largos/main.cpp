#include <iostream>

using namespace std;

class TicTacToe
{
    char Tablero[3][3];

public:
    TicTacToe();
    void LimpiarTablero();
    void Pintar();
    bool PonerFicha(char ficha, int fila, int columna);
    bool ComprobarFila(char ficha, int fila);
    bool ComprobarColumna(char ficha, int columna);
    bool ComprobarDiagonales(char ficha, int fila, int columna);
    bool TableroCompleto();
};

TicTacToe::TicTacToe()
{
    LimpiarTablero();
}

void TicTacToe::LimpiarTablero()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            Tablero[i][j]=' ';
        }
    }
}

void TicTacToe::Pintar()
{
    for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout << " " << Tablero[i][j];
                if (j < 2) cout << " |";
            }
        cout << endl;
        if (i < 2) cout << "---+---+---" << endl;
    }
}

bool TicTacToe::PonerFicha(char ficha,int fila,int columna)
{
    bool puesta=false;
    if(Tablero[fila][columna]==' ')
    {
       Tablero[fila][columna]=ficha;
       puesta=true;
    }
    return puesta;

}

bool TicTacToe::ComprobarFila(char ficha, int fila)
{
    bool gana=false;
    int linea=0;
    for(int j=0; j<3; j++)
    {
        if(Tablero[fila][j]==ficha)
            linea++;
    }
    if(linea==3)
    {
        gana=true;
    }
    return gana;
}

bool TicTacToe::ComprobarColumna(char ficha, int columna)
{
    bool gana=false;
    int colum=0;
    for(int i=0; i<3; i++)
    {
        if(Tablero[i][columna]==ficha)
            colum++;
    }
    if(colum==3)
    {
        gana=true;
    }
    return gana;
}

bool TicTacToe::ComprobarDiagonales(char ficha, int fila, int columna)
{
    bool gana=false;
    int diagonal=0;
    int diagonalSecundaria=0;

    for(int i=0; i<3; i++)
    {
        if(Tablero[i][i]==ficha)
            diagonal++;
    }

    for(int i=0; i<3; i++)
    {
        if(Tablero[i][2-i]==ficha)
            diagonalSecundaria++;
    }


    if(diagonal==3 || diagonalSecundaria==3)
    {
        gana=true;
    }
    return gana;
}

bool TicTacToe::TableroCompleto()
{
    bool encontrado=true;

    for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(Tablero[i][j]==' ')
                    encontrado=false;
            }
        }

    return encontrado;
}

void PedirPosicion(char ficha, int &fila, int &columna)
{
    cout << "Turno del jugador " << ficha << endl;

    do {
        cout << "Introduce fila (0-2): ";
        cin >> fila;
    } while (fila < 0 || fila > 2);

    do {
        cout << "Introduce columna (0-2): ";
        cin >> columna;
    } while (columna < 0 || columna > 2);
}

int main()
{
    TicTacToe juego;            // Crear objeto de la clase
    char jugador='X';           // Comienza el jugador X
    int fila, columna;          // Posiciones introducidas por el jugador
    bool terminado=false;       // Control del final del juego

    cout << "=== JUEGO DEL TRES EN RAYA ===" << endl << endl;
    juego.Pintar();             // Mostrar tablero inicial

    while(terminado==false)
    {
        // Pedir la posicion al jugador actual
        PedirPosicion(jugador, fila, columna);

        // Intentar poner la ficha en el tablero
        if(juego.PonerFicha(jugador, fila, columna)==true)
        {
            // Mostrar el tablero actualizado
            juego.Pintar();

            // Comprobar si el jugador ha ganado
            if(juego.ComprobarFila(jugador, fila)==true ||
               juego.ComprobarColumna(jugador, columna)==true ||
               juego.ComprobarDiagonales(jugador, fila, columna)==true)
            {
                cout << endl << "Ha ganado el jugador " << jugador << "!" << endl;
                terminado=true;
            }
            else
            {
                // Comprobar si el tablero esta completo (empate)
                if(juego.TableroCompleto()==true)
                {
                    cout << endl << "Empate! No quedan casillas libres." << endl;
                    terminado=true;
                }
                else
                {
                    // Cambiar de jugador
                    if(jugador=='X')
                        jugador='O';
                    else
                        jugador='X';
                }
            }
        }
        else
        {
            // Si la casilla está ocupada
            cout << "Esa casilla ya esta ocupada. Intenta otra." << endl;
        }
    }

    cout << endl << "Fin de la partida." << endl;
    return 0;
}



