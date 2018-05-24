#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"

void mostrar(Cliente* array[],int cantidad);
void cargar(Cliente* array[],int cantidad);

int main()
{
    Cliente* arrayPunteroClientes[50];
    cargar(arrayPunteroClientes,50);



    mostrar(arrayPunteroClientes,50);
    return 0;
}

void cargar(Cliente** array,int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        *(array+i) = cliente_newP("39113917","suarez", "30535994540", "tomas", i+3, 23, i);
    }
}

void mostrar(Cliente* array[],int cantidad)
{
    int i;
    /*char nombre[50];
    char cuit[50];
    float altura;
    for(i=0;i<cantidad;i++)
    {
        cliente_getCuit(array[i], cuit);
        cliente_getAltura(array[i], &altura);
        cliente_getApellido(*(array+i), nombre);
        printf("\nApellido: %s Cuit: %s - Altura: %f",nombre,cuit,altura);*/
    Cliente* auxiliarCliente;
    for(i=5;i<10;i++)
    {
        auxiliarCliente = arrayCliente_getById(array,cantidad, i);
        if(auxiliarCliente != NULL)
        {
            cliente_setAltura(auxiliarCliente, 88);
        }
    }
}


