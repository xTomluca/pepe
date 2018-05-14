#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "funciones.h"

/** \brief
 * \param array Cliente*
 * \param limite int
 * \return int
 *
 */
int cliente_init(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int cliente_mostrarDebug(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %d\n",array[i].idCliente, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

int cliente_mostrar(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %d\n",array[i].idCliente, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}


int cliente_altaForzada(Cliente* array,char* nombre, char* apellido, char* cuit,int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibreCliente(array,limite);
        if(i >= 0)
        {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        strcpy(array[i].apellido,apellido);
                        strcpy(array[i].cuit,cuit);
                        array[i].idCliente = proximoIdCliente();
                        array[i].isEmpty = 0;

        }
    }
    return retorno;
}

int cliente_alta(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50],apellido[50],cuit[50];
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibreCliente(array,limite);
        if(i >= 0)
        {
            if(!getArrayChar(nombre,"\nIngrese Nombre: ","ERROR, NOMBRE NO CONTIENE NUMEROS: "))
            {
                if(!getArrayChar(apellido,"\nIngrese Apellido: ","ERROR, APELLIDO NO CONTIENE NUMEROS: "))
                {
                    if(!getCharNumeros(cuit, "Ingrese cuit: ","ERROR, EL CUIT NO CONTIENE LETRAS: "))
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        strcpy(array[i].apellido,apellido);
                        strcpy(array[i].cuit,cuit);
                        array[i].idCliente = proximoIdCliente();
                        array[i].isEmpty = 0;
                    }
                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int cliente_baja(Cliente* array, int limiteC, int id)
{
    int retorno = -1;
    int i;
    char borrar;
    if(limiteC > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limiteC;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                    printf("\nDESEA BORRAR? S/N: ");
                    borrar = getchar();
                    if('s'==borrar)
                    {
                        array[i].isEmpty = 1;
                        retorno = 0;
                        break;
                    }
            }
        }



    }
    return retorno;
}




int cliente_modificacion(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    char nombre[50],apellido[50],cuit[50];
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                if(!getArrayChar(nombre,"\nIngrese Nombre: ","ERROR, NOMBRE NO CONTIENE NUMEROS: "))
                {
                    if(!getArrayChar(apellido,"\nIngrese Apellido: ","ERROR, APELLIDO NO CONTIENE NUMEROS: "))
                    {
                        if(!getCharNumeros(cuit, "Ingrese cuit: ","ERROR, EL CUIT NO CONTIENE LETRAS: "))
                        {
                            retorno = 0;
                            strcpy(array[i].nombre,nombre);
                            strcpy(array[i].apellido,apellido);
                            strcpy(array[i].cuit,cuit);
                        }
                    }
                }
                else
                {
                    retorno = -3;
                }
                retorno = 0;
                break;

            }
        }
    }
    return retorno;
}

int cliente_ordenar(Cliente* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    ///COMPARA CARACTER CON CARACTER SI EL PRIMERO ESTA ANTES EN EL ABC DEVUELVE +
                    ///IGUALES DEVUELVE 0
                    if(( strcmp(array[i].nombre, array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int buscarLugarLibreCliente(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int proximoIdCliente()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

int cliente_buscarPorId(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
