/*
Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna
es un mes. Ud. debe realizar las siguientes tareas:

a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.

b. Muestre por pantalla los valores cargados

c. Saque el promedio de ganancia por año y muestrelos por pantalla

d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de
cuándo ocurrió.

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int prod[5][12];
    //carga la matriz
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            prod[i][j] = 10000 + rand() % 40000;
        }
    }

    puts("Los valores de la matriz son: \n");

    //Muestra la matriz por pantalla
    for (int i = 0; i < 5; i++)
    {
        printf("\n %dº anio \n", (i+1));
        for (int j = 0; j < 12; j++)
        {
            printf("\n mes %d : %d ", (j+1),prod[i][j]);
        }
        printf("\n");
    }
    
    //promedio de cada año
    for (int i = 0; i < 5; i++)
    {
        float promedio = 0;
        printf("\nPromedio del %dº anio: ", (i+1));
        for (int j = 0; j < 12; j++)
        {
            promedio += prod[i][j];
        }
        promedio /= 12;
        printf("%.2f",promedio);
    }
    
    //d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de cuándo ocurrió.
    int max = 0,min = 6000000, minAnio=0, maxAnio=0, minMes=0, maxMes=0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            maxAnio = (prod[i][j] > max)? i : maxAnio;
            maxMes = (prod[i][j] > max)? j: maxMes;
            max = (prod[i][j]> max)? prod[i][j] : max;

            minAnio = (prod[i][j] < min)? i : minAnio;
            minMes = (prod[i][j] < min)? j : minMes;
            min = (prod[i][j] < min)? prod[i][j] : min;
        }
        
    }
    
    printf("\nEl valor maximo es: %d en el anio: %d y el mes: %d",max,(maxAnio+1),(maxMes+1));
    printf("\nEl valor minimo es: %d en el anio: %d y el mes: %d",min,(minAnio+1),(minMes+1));

    
    return 0;
}
