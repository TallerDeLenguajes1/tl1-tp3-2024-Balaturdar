/*
Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
vez cargados sean listados por pantalla (Todo implementando reserva dinámica de memoria)
(Lea las notas 1 y 2)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANTNOMBRES 5


int main()
{
    char **nombres, *buff;
    nombres = (char**) malloc(CANTNOMBRES * sizeof(char*));
    buff = (char *)malloc(100 * sizeof(char));

    for (int i = 0; i < CANTNOMBRES; i++){
        puts("ingrese un nombre: ");
        gets(buff);
        nombres[i] = (char *)malloc(strlen(buff+1)*sizeof(char));
        strcpy(nombres[i],buff);
    }
    puts("listado de nombres");
    for (int i = 0; i < CANTNOMBRES; i++)
    {
        puts(nombres[i]);
    }
    
    for (int i = 0; i < CANTNOMBRES; i++)
    {
        free(nombres[i]);
    }
    
    
    free(nombres);
    free(buff);
    
    return 0;
}
