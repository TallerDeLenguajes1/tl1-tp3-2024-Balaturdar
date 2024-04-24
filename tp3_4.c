#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

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
    producto *Productos;        //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
}typedef cliente;

void cargaClientes(cliente *clientes, int cantClientes){
    char * buff = (char *)malloc(100*sizeof(char));
    for (int i = 0; i < cantClientes; i++)
    {
        clientes->ClienteID = i+1;
        
        printf("\n Ingrese el nombre del cliente: ");
        fflush(stdin);
        gets(buff);
        clientes[i].NombreCliente = (char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(clientes->NombreCliente, buff);

        clientes->CantidadProductosAPedir = 1 + rand() % 10;

        clientes->Productos = (producto *)malloc(clientes->CantidadProductosAPedir * sizeof(producto));
        
        cargaProductos(clientes->Productos, clientes->CantidadProductosAPedir);

        clientes++;
    }
    free(buff);
};

void cargaProductos(producto *productos, int cantProductos){
    int indice ;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    
    for (int i = 0; i < cantProductos; i++)
    {
        productos->ProductoID = i+1;

        productos->Cantidad= 1+rand()%10;
        
        indice = rand()%5;
        productos->TipoProducto = (char *) malloc((strlen(TiposProductos[indice])+1)*sizeof(char));
        strcpy(productos->TipoProducto, TiposProductos[indice]);

        productos->PrecioUnitario = 10 + rand()%91;
    }
};

float montoTotal(producto *productos){
    return productos->PrecioUnitario * productos->Cantidad;
};

int main(int argc, char const *argv[])
{
    int cantClientes;
    cliente *clientes;
    srand(time(NULL));

    do{
        printf("\n**Ingrese la cantidad de clientes que visitara el preventista (1-5)**");
        scanf("%d",&cantClientes);
        if(cantClientes>5 || cantClientes < 1){
            puts("el preventista puede visitar hasta 5 clientes");
        }
    } while (cantClientes>5 || cantClientes < 1);

    clientes = (cliente *)malloc(cantClientes * sizeof(cliente));

    cargaClientes(clientes,cantClientes);

    for (int  i = 0; i < cantClientes; i++)
    {
        float total=0;
        printf("\n**Cliente nº %d **",clientes->ClienteID);
        printf("\n**Nombre del cliente: %s **",clientes->NombreCliente);
        printf("\n**Cantidad de productos pedidos: %d **",clientes->CantidadProductosAPedir);
        printf("\n**-Listado de productos-**");
        for (int j = 0; j < clientes->CantidadProductosAPedir; j++){
            printf("\n**Tipo de producto: %s **",clientes->Productos->TipoProducto);
            printf("\n**Identificador del producto: %d **",clientes->Productos->ProductoID);
            printf("\n**Cantidad: %d **",clientes->Productos->Cantidad);
            printf("\n**Precio unitario: %.2f **",clientes->Productos->PrecioUnitario);
            printf("\n**costo: %.2f **",montoTotal(clientes->Productos));
            puts("--------------------------------------------------------------------------------");
            total += montoTotal(clientes->Productos);
            clientes->Productos++;
        }
        printf("\n**Monto total: %.2f**",total);
        puts("--------------------------------------------------------------------------------");
        clientes++;
    }
    clientes - cantClientes;
    for (int i = 0; i < cantClientes; i++)
    {
        for (int j = 0; j < clientes->CantidadProductosAPedir; j++)
        {
            free(clientes->Productos[j].TipoProducto);
            clientes->Productos[j];
        }
        free(clientes->Productos);
        clientes++;
    }
    free(clientes-cantClientes);

    return 0;
}
