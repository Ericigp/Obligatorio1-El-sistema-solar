#ifndef VERLET_HPP_INCLUDED
#define VERLET_HPP_INCLUDED

#include <cmath>

#define h 0.1 //Saltos de 0.001
#define N 9 //2 cuerpos

using namespace std;

static const double G =6.67e-11;//Constante de gravitacion
static const double c =1.496e11;//Distancia tierra sol
static const double Ms =1.99e30;//Masa del sol

double modulo (double a, double b);//Función que calcula un módulo
void aceleracion (double m[],double r[][2],double a[][2]);//Función que calcula la aceleración de los planetesimales
void posicion (double r[][2],double v[][2],double a[][2]);//Función que calcula la nueva posición de los planetesimales
void velocidadaux(double v[][2],double a[][2], double w[][2]);//Función que calcula la velocidad auxiliar que mas tarde usaremos para calcular la velocidad real
void velocidad(double v[][2],double [][2],double aceleracion[][2]);//Función que calcula la velocidad de los planetesimales
void energia(double m[],double r[][2],double v[][2],double e[],double &etot);//Función que calcula la energía

#endif // VERLET_HPP_INCLUDED
