#include <iostream>

using namespace std;

int main()
{
    int s,m,h,seg;

    cout<<"Introduce los segundos a convertir: ";
    cin>>s;

    h=s/3600;
    m=(s%3600)/60;
    seg=(s%3600)-m*60;

    cout<<s<<" segundos son: "<<h<<" horas "<<m<<" minutos "<<seg<<" segundos.";

    return 0;
}
