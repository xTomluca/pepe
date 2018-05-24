#include "alumno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int ultimoId=-1;

Cliente* cliente_new()
{
    return malloc(sizeof(Cliente));
}

Cliente* cliente_newP(char* dni, char* apellido, char* cuit, char* nombre, float altura, int edad, int id)
{
    Cliente* this = cliente_new();

    if(!cliente_setCuit(this, cuit))
    {
        cliente_setApellido(this, apellido);
    }
    if(!cliente_setAltura(this,altura))
        if(id>0)
        {
            this->id = id;
        }

    return this;
}

void cliente_delete(Cliente* this)
{
    free(this);
}

int  cliente_setEdad(Cliente* this, int edad)
{
    int retorno = -1;
    if(this != NULL && edad >= 0)
    {
        retorno = 0;
        this->edad = edad;
    }
    return retorno;
}

int cliente_getEdad(Cliente* this, int* edad)
{
    int retorno = -1;
    if(this != NULL && edad != NULL)
    {
        retorno = 0;
        *edad = this->edad;
    }
    return retorno;

}
///CAMPO----------------ENTIDAD-NOMBRE-DE-CAMPO
int cliente_setAltura(Cliente* this, float altura)
{
    int retorno = -1;
    if(this!=NULL && isValidAltura(altura))
    {
        this->altura = altura;
        retorno = 0;
    }
    return 0;
}

int cliente_getAltura(Cliente* this, float* altura)
{
    int retorno = -1;
    if(this!=NULL && altura != NULL)
    {
        *altura=this->altura;
        retorno = 0;
    }
    return retorno;
}

int isValidAltura(int altura)
{

    return 1;
}

///CAMPO----------------ENTIDAD-NOMBRE-DE-CAMPO
int cliente_setCuit(Cliente* this, char* cuit)
{
    int retorno = -1;
    if(this!=NULL && !isValidCuit(cuit))
    {
        strcpy(this->cuit,cuit);
        retorno = 0;
    }
    return retorno;
}

int cliente_getCuit(Cliente* this, char* cuit)
{
    int retorno = -1;
    if(this!=NULL && cuit != NULL)
    {
        strcpy(cuit,this->cuit);
        retorno = 0;
    }
    return retorno;
}

int isValidCuit(char* cuit)
{

    return 0;
}

///********APELLIDO;;;*************--------------///


int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this!=NULL && !isValidApellido(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno = 0;
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this!=NULL && apellido != NULL)
    {
        strcpy(apellido,this->apellido);
        retorno = 0;
    }

    return retorno;
}

int isValidApellido(char* apellido)
{
    int retorno=0;
    /*if((strlen(apellido)==7||strlen(apellido)==8) && apellido!=NULL)
    {
        retorno=0;
    }*/
    return retorno;
}
int cliente_setId(Cliente* this)
{
    int retorno = -1;
    if(this!=NULL)
    {
        ultimoId+=1;
    }
    return retorno;
}
int cliente_setNewId(Cliente* this)
{
    int retorno = -1;
    if(this!=NULL)
    {
        ultimoId+=1;
    }
    return retorno;
}
Cliente* arrayCliente_getById (Cliente* array[], int cantidad, int id)
{
    Cliente *retorno = NULL;
    int i, auxiliarId;
    for(i=0;i<cantidad;i++)
    {
        cliente_getId(array[i],&auxiliarId);
        if(auxiliarId == id)
        {
            retorno = array[i];
            break;
        }
    }
}
