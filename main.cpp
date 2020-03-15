//Puede ser un problema de rescaling

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Verlet.hpp"//Librerias con todas las funciones necesarias para implementar el algoritmo de Verlet

#define h 0.1 //Saltos de 0.1
#define N 9 //9 cuerpos

using namespace std;

int main(void)
{
    double m[N];//Vector de masas
    double r[N][2];//Matriz de posiciones
    double v[N][2];//Matriz de velocidades
    double w[N][2];//Matriz de velocidades auxiliares
    double a[N][2];//Matriz de aceleraciones
    double e[N];//Vector de energias
    double etot;//Energía total
    double t=0.0;
    int i,j;//Contadores
    ofstream ofich, ofich2;//Ficheros en los que almacenar los datos
    ifstream fich,fich2,fich3;//Fichero con los datos iniciales

    //Apertura de ficheros
    ofich.open("Posiciones");
    ofich2.open("Energia total");
    fich.open("rIniciales.txt");
    fich2.open("vIniciales.txt");
    fich3.open("Masas.txt");

    //Lectura de datos desde fichero
    for(i=0;i<N;i++)
    {
        for(j=0;j<2;j++)
        {
            fich>>r[i][j];
            fich2>>v[i][j];
        }
        fich3>>m[i];
    }

    //Reescalado de las magnitudes
    for (i=0;i<N;i++)
    {
        for (j=0;j<2;j++)
        {
            r[i][j]=r[i][j]/c;
            v[i][j]=(v[i][j]/c)/(sqrt(G*Ms/(c*c*c)));
        }
        m[i]=m[i]/Ms;
    }

    //Implementación del algoritmo de Verlet utilizando las funciones dadas

    aceleracion(m,r,a);

    while (t<(500*sqrt(G*Ms/pow(c,3))))
    {
        energia(m,r,v,e,etot);
        posicion(r,v,a);
        velocidadaux(v,a,w);
        aceleracion(m,r,a);
        velocidad(v,w,a);

        for (i=0;i<N;i++)
        {
            for(j=0;j<2;j++)
                ofich<<r[i][j]<<"\t";
        }
        ofich<<endl;
        ofich2<<etot;
        ofich2<<endl;

        t+=h*sqrt(G*Ms/pow(c,3));
    }

    ofich.close();
    ofich2.close();
    fich.close();
    fich2.close();
    fich3.close();
    return 0;
}
