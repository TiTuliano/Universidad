#include <iostream>

using namespace std;

int main()
{
    int tabla[3][3];
    int op;

    do
    {
         cout <<"1. Pedir Datos"<<endl
         <<"2. Mostrar"<<endl
         <<"3. Analizar"<<endl
         <<"4. Sumar una fila"<<endl
         <<"5. Sumar una columna"<<endl
         <<"6. Sumar diagonal principal"<<endl
         <<"7. Sumar diagonal secundaria"<<endl
         <<"8. Intercambiar filas"<<endl
         <<"9. Intercambiar columnas"<<endl
         <<"10. Salir"<<endl
         <<"Elija opcion:";

         cin>>op;

         switch(op)
         {
            case 1:
                {   int dato=0;

                    for(int i=0; i<3; i++)
                    {
                        for(int j=0; j<3; j++)
                        {
                            cout<<"Introduce un dato: ";
                            cin>>dato;
                            if(dato<0)
                            {
                                cout<<"Error. No se admieten valores negativos"<<endl;
                            }
                            else
                                tabla[i][j]=dato;

                        }


                    }
                    break;
                }



            case 2:
                {
                    for(int i=0; i<3; i++)
                    {
                        for(int j=0; j<3; j++)
                        {
                            cout<<tabla[i][j]<<"\t"; //\t para tabular

                        } cout<<endl;

                    }
                    break;
                }

            case 3:
                {
                    int pares=0;
                    int impares=0;

                    for(int i=0; i<3; i++)
                    {
                        for(int j=0; j<3; j++)
                        {
                           if(tabla[i][j]%2==0)
                            pares++;
                           else
                            impares++;

                        }
                    }
                    cout<<"Hay "<<pares<<" numeros pares y "<<impares<<" numeros impares."<<endl;
                    break;
                }

            case 4:
                {
                    int f1,f2,suma=0;
                    cout<<"Introduce las primera fila a sumar (0,1,2): ";
                    cin>>f1;
                    cout<<"Introduce la segunda fila a sumar (0,1,2): ";
                    cin>>f2;

                    for(int j=0; j<3; j++)
                        {
                            suma+=tabla[f1][j]+tabla[f2][j];
                        }


                    cout<<"La suma es: "<<suma<<endl;
                    break;
                }

            case 5:
                {
                    int c1,c2,suma=0;
                    cout<<"Introduce las primera columna a sumar (0,1,2): ";
                    cin>>c1;
                    cout<<"Introduce la segunda columna a sumar (0,1,2): ";
                    cin>>c2;

                    for(int i=0; i<3; i++)
                        {
                            suma+=tabla[i][c1]+tabla[i][c2];
                        }


                    cout<<"La suma es: "<<suma<<endl;
                    break;
                }

            case 6:
                {
                    int suma=0;
                    for(int i=0; i<3; i++)
                    {
                      suma=suma+tabla[i][i];
                    }
                    cout<<"La suma de la diagonal principal es: "<<suma<<endl;
                    break;
                }

            case 7:
                {
                    int suma=0;
                    for(int i=0; i<3; i++)
                    {
                     suma=suma+tabla[i][2-i];
                    }
                    cout<<"La suma de la diagonal secundaria es: "<<suma<<endl;
                    break;
                }

            case 8:
                {
                    int indice1,indice2;
                    cout<<"Introduce el indice 1: ";
                    cin>>indice1;
                    cout<<"Introduce el indice 2: ";
                    cin>>indice2;
                    cout<<endl;

                    for(int j=0; j<3; j++)
                    {
                        int aux=tabla[indice1][j];
                        tabla[indice1][j]=tabla[indice2][j];
                        tabla[indice2][j]=aux;

                    }
                    cout<<"Filas intercambiadas"<<endl;
                    break;


                }

             case 9:
                {
                    int indice1,indice2;
                    cout<<"Introduce el indice 1: ";
                    cin>>indice1;
                    cout<<"Introduce el indice 2: ";
                    cin>>indice2;
                    cout<<endl;

                    for(int i=0; i<3; i++)
                    {
                        int aux=tabla[i][indice1];
                        tabla[i][indice1]=tabla[i][indice2];
                        tabla[i][indice2]=aux;

                    }
                    cout<<"Columnas intercambiadas"<<endl;
                    break;


                }
             case 10:
                cout<<"Saliendo del programa..."<<endl;
                break;



            default:cout<<"Error"<<endl;

        }

    }while(op!=10);

    return 0;
}
