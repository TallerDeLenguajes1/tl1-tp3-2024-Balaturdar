#include<stdio.h>
#include<stdlib.h>


//char *TiposProductos[]={“Galletas”,”Snack”,”Cigarrillos”,”Caramelos”,”Bebidas”};

struct{
    int ProductoID;         //Numerado en ciclo iterativo
    int Cantidad;           // entre 1 y 10
    char *TipoProducto;     // Algún valor del arreglo TiposProductos
    float PrecioUnitario;   // entre 10 - 100
}typedef producto;

struct{
    int ClienteID;              // Numerado en el ciclo iterativo
    char *NombreCliente;        // Ingresado por usuario
    int CantidadProductosAPedir;// (aleatorio entre 1 y 5)
    producto *Productos         //El tamaño de este arreglo depende de la variable
                                // “CantidadProductosAPedir”
}typedef cliente;

void cargaClientes(cliente *clientes){
    
};



int main(int argc, char const *argv[])
{
    int cantClientes;
    cliente *clientes;
    
    do{
        printf("\n**Ingrese la cantidad de clientes que visitara el preventista (1-5)**");
        scanf("%d",cantClientes);
        if(cantClientes>5 || cantClientes < 1){
            puts("el preventista puede visitar hasta 5 clientes");
        }
    } while (cantClientes>5 || cantClientes < 1);
    clientes = (cliente *)malloc(cantClientes * sizeof(cliente));

    

    return 0;
}
