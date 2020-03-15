#include "Verlet.hpp"

//Funcion que devuelve el vector aceleracion en funcion de la masa y la velocidad
//Revisar
void aceleracion (double m[],double r[][2],double a[][2])
{
    int i,j,k,t;
    double aux[2];
    double aux2;

    for (i=0;i<N;i++)
    {
            for(t=0;t<2;t++)
                a[i][t]=0.0;

            for(j=0;j<N;j++)
            {
                if (i==j)
                    continue;

                else
                {
                    for (k=0;k<2;k++)
                        aux[k]=r[i][k]-r[j][k];//Calculo un vector que contenga la resta de cada componente

                    aux2=modulo(aux[0],aux[1]);//Calculo el módulo del vector descrito anteriormente

                    for(k=0;k<2;k++)
                        a[i][k]+=-1.0*m[j]*(aux[k])/pow(aux2,3);//Calculo la aceleración resultante
                }

            }
    }
    return;
}
double modulo (double a, double b)
{
    return sqrt(a*a+b*b);
}
void posicion(double r[][2],double v[][2],double a[][2])
{
    int i,j;//Contadores


    for (i=0;i<N;i++)//Contador para los N planetesimales
    {
        for(j=0;j<2;j++)//Contador para las dimensiones x,y
        {
            r[i][j]=r[i][j]+h*v[i][j]+(h*h/2.0)*a[i][j];
        }
    }
    return;
}
void velocidadaux(double v[][2],double a[][2], double w[][2])
{
    int i,j;//Contadores

    for (i=0;i<N;i++)//Contador para los planetesimales
    {
        for(j=0;j<2;j++)//Contador para las dimensiones x,y
        {
            w[i][j]=v[i][j]+(h/2)*a[i][j];
        }
    }
    return;
}
void velocidad(double v[][2],double w[][2],double a[][2])
{
    int i,j;//Contadores

    for (i=0;i<N;i++)//Contador para los planetesimales
    {
        for(j=0;j<2;j++)//Contador para las dimensiones x,y
        {
            v[i][j]=w[i][j]+(h/2)*a[i][j];
        }
    }
    return;
}

void energia(double m[],double r[][2],double v[][2],double e[],double &etot)
{
    int i,j,k;//Contadores
    double epot,ecin;//Energía potencial y cínetica
    double aux[2];//Vector auxiliar para facilitar el calculo
    double aux2,aux3;//Variables auxiliares para facilitar el calculo
        for (i=0;i<N;i++)
        {
            //Inicialización de las variables
            e[i]=0.0;
            epot=0.0;
            ecin=0.0;
            for (j=0;j<N;j++)
            {
                if(i==j)
                    continue;//Con esto evito que se calcule la energía potencial de la interacción consigo mismo
                else
                {
                    for(k=0;k<2;k++)
                        aux[k]=r[i][k]-r[j][k];//Calculo un vector que contenga la resta de cada componente

                    aux2=modulo(aux[0],aux[1]);

                    epot+=m[i]*m[j]/aux2;//Calculo de la energía potencial
                }
                aux3=0.0;
                for (k=0;k<2;k++)
                    aux3+=v[i][k]*v[i][k];
                ecin+=(m[i]*aux3)/(2.0);//Calculo de la energía cinetica

                e[i]=ecin-epot;//Vector con la energía total
            }
        }
        etot=0.0;
        for (i=0;i<N;i++)
            etot+=e[i];

    return;
}
