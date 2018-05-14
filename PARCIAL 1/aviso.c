#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "aviso.h"
#include "utn.h"
#include "funciones.h"
#include "cliente.h"

/** \brief
 * \param array Aviso*
 * \param limite int
 * \return int
 *
 */
int aviso_init(Aviso* array,int limite)
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

int aviso_mostrar(Aviso* array,int id,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty&&array[i].idCliente==id)
                printf("\nID AVISO: %d ID USUARIO: %d TEXTO: %s ESTADO: %d - %d\n",array[i].idAviso,array[i].idCliente, array[i].texto, array[i].estado, array[i].isEmpty);
        }
    }
    return retorno;
}

int aviso_alta(Aviso* array,Cliente* arrayCliente,int limiteA,int limiteC)
{
    int retorno = -1;
    int i,idAux,idAuxResultado;
    char texto[50];
    if(limiteA > 0 && limiteC > 0 && array != NULL && arrayCliente != NULL)
    {
        getNumero(100,0,&idAux,"Ingrese ID Usuario: ","\nID INVALIDO: ");
        idAuxResultado = cliente_buscarPorId(arrayCliente,limiteC,idAux);
        i = buscarLugarLibreAviso(array,limiteA);
        if(i >= 0 && idAuxResultado >=0)
        {
            if(!getCadena(texto,"Ingrese descripcion aviso: ","ERROR!!"))
            {
                retorno = 0;
                strcpy(array[i].texto,texto);
                array[i].idCliente = idAuxResultado;
                array[i].idAviso = proximoIdAviso();
                array[i].isEmpty = 0;
                array[i].estado=0;
                printf("Aviso publicado con exito!! El id es: %d\n", array[i].idAviso);
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


int aviso_baja(Aviso* array,int limite, int idCliente)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==idCliente)
            {
                printf("EXITOOOOOOOOOOOO");
                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
            else
            {
                printf("ERROR");
            }
        }
    }
    else
    {
        printf("ERROR");
    }
    return retorno;
}

int buscarLugarLibreAviso(Aviso* array,int limite)
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

int proximoIdAviso()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

int aviso_pausa(Aviso* array,int limite, int id)
{
    int retorno = -1;
    if(limite > 0 && array != NULL)
    {
            if(!array[id].isEmpty && array[id].idAviso==id && array[id].estado!=1)
            {
                array[id].estado = 1;
                printf("\nESTADO = 1, AVISO PAUSADO!!\n");
                retorno = 0;
            }
    }
    return retorno;
}

int aviso_reanudar(Aviso* array,int limite, int id)
{
    int retorno = -1;
    if(limite > 0 && array != NULL)
    {
            if(!array[id].isEmpty && array[id].idAviso==id && array[id].estado!=0)
            {
                array[id].estado = 0;
                printf("\nESTADO = 0, AVISO ACTIVO!!\n");
                retorno = 0;
            }
    }
    return retorno;
}

int aviso_altaForzada(Aviso* array,Cliente* arrayCliente,int limiteA,int limiteC, char* texto, int idCliente)
{
    int retorno = -1;
    int i;
    if(limiteA > 0 && limiteC > 0 && array != NULL && arrayCliente != NULL)
    {
        i = buscarLugarLibreAviso(array,limiteA);
        if(i >= 0)
        {

                retorno = 0;
                strcpy(array[i].texto,texto);
                array[i].idCliente = idCliente;
                array[i].idAviso = proximoIdAviso();
                array[i].isEmpty = 0;
                array[i].estado=0;
                printf("\nAviso publicado con exito!! El id es: %d", array[i].idAviso);
        }
    }
    return retorno;
}
