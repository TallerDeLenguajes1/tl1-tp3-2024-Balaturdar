#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main()
{
    int cantNombres;
    char **nombres, *buff;
    buff = (char *)malloc(100 * sizeof(char));

    printf("\nIngrese la cantidad de nombres que va a ingresar: ");
    nombres = (char**) malloc(cantNombres * sizeof(char*));

    for (int i = 0; i < cantNombres; i++){
        puts("ingrese un nombre: ");
        gets(buff);
        nombres[i] = (char *)malloc(strlen(buff+1)*sizeof(char));
        strcpy(nombres[i],buff);
    }
    puts("listado de nombres");
    for (int i = 0; i < cantNombres; i++)
    {
        puts(nombres[i]);
    }
    
    for (int i = 0; i < cantNombres; i++)
    {
        free(nombres[i]);
    }
    
    free(nombres);
    free(buff);
    
    return 0;
}
