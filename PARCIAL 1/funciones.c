#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
/** \brief Verifica que el array de char contenga solo NUMEROS.
 *
 * \param auxCarga char* Array de char a validar.
 * \param mensajeError char* Mensaje de error a mostrar si se ingresa alguna LETRA.
 * \param tamanioVector int tamaño del array/vector.
 * \return int retorno [0] si no contiene LETRAS. [1] = ERROR.
 *
 */
int verificacionDigito(char *auxCarga, char *mensajeError, int tamanioVector)
{
    int i=0;
    int j=strlen(auxCarga);
    int retorno =1;
    while(i<j-1)
    {
        retorno =1;
        if(isdigit(auxCarga[i])!=0)
        {
            i++;
            retorno =0;
        }
        else
        {
            printf("%s", mensajeError);
            fflush(stdin);
            fgets(auxCarga, tamanioVector, stdin);
            j=strlen(auxCarga);
            i=0;

        }
    }
    return retorno;
}

/** \brief Verifica que el array de char contenga solo LETRAS.
 *
 * \param auxCarga char* Array de char a validar.
 * \param mensajeError char* Mensaje de error a mostrar si se ingresa algun NUMERO.
 * \param tamanioVector int tamaño del array/vector.
 * \return int retorno [0] si no contiene NUMEROS. [1] = ERROR.
 *
 */
int verificacionChar(char *auxCarga, char *mensajeError, int tamanioVector)
{
    int i=0;
    int j=strlen(auxCarga);
    int retorno =1;
    while(i<j-1)
    {
        retorno =1;
        if(!isdigit(auxCarga[i]))
        {
            i++;
            retorno =0;
        }
        else
        {
            printf("%s", mensajeError);
            fflush(stdin);
            fgets(auxCarga, tamanioVector, stdin);
            j=strlen(auxCarga);
            i=0;
        }
    }
    return retorno;
}

/** \brief Valida NOMBRE.
 *
 * \param nombre char* Mediante puntero paso array de char.
 * \return int retorno [0] si se cargo el NOMBRE con exito. [1] = ERROR.
 *
 */

int getArrayChar(char* nombre, char *mensaje, char *mensajeError)
{
    int retorno=1;
    char auxString[50];
    printf("%s",mensaje);
    fflush(stdin);
    fgets(auxString, 50, stdin);
    if(!verificacionChar(auxString,mensajeError,50))
    {
            strcpy(nombre, auxString);
            retorno=0;
    }
    return retorno;
}

/** \brief Valida CUIT.
 *
 * \param nombre char* Mediante puntero paso array de char.
 * \return int retorno [0] si se cargo el CUIT con exito. [1] = ERROR.
 *
 */

int getCharNumeros(char* cuit, char *mensaje, char *mensajeError)
{
    int retorno=1;
    char auxCuit[50];
    printf("%s",mensaje);
    fflush(stdin);
    fgets(auxCuit, 50, stdin);
    if(!verificacionDigito(auxCuit,mensajeError,50))
    {
            strcpy(cuit, auxCuit);
            retorno=0;
    }
    return retorno;
}

int getCadena(char* array, char *mensaje, char *mensajeError)
{
    int retorno;
    char auxArray[64];
    printf("%s",mensaje);
    fflush(stdin);
    fgets(auxArray, 64, stdin);
    strcpy(array, auxArray);
    retorno=0;
    return retorno;
}

/** \brief Valida EDAD.
 *
 * \param numMax int Defino edad maxima.
 * \param numMin int Defino edad minima.
 * \param edad int* Mediante puntero paso edad.
 * \return int retorno [0] si se cargo la EDAD con exito. [1] = ERROR.
 *
 */
int getNumero(int numMax, int numMin, int *numero,char *mensaje, char *mensajeError){
    char auxCharEdad[10];
    int retorno=1;
    int auxNum;
    int verificacion=0;
    printf("%s",mensaje);
    fflush(stdin);
    fgets(auxCharEdad, 10, stdin);
    if(!verificacionDigito(auxCharEdad,mensajeError, 10))
    {
        auxNum = atoi(auxCharEdad);

        while(auxNum > numMax || auxNum < numMin || verificacion==1)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            fgets(auxCharEdad, 10, stdin);
            verificacion = verificacionDigito(auxCharEdad,mensajeError, 10);
            if(!verificacion)
            {
                auxNum = atoi(auxCharEdad);
            }
        }
        *numero = auxNum;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida DNI.
 *
 * \param dni int* Mediante puntero devuelve DNI ingresado y validado.
 * \return int retorno [0] si se cargo el DNI con exito. [1] = ERROR.
 *
 */
int getDni(int *dni){

    char auxDni[10];
    int retorno=1;
    int longitudDni=0;
    int verificacion=0;
    printf("\nIngrese DNI: ");
    fflush(stdin);
    fgets(auxDni, 20, stdin);
    if(!verificacionDigito(auxDni,"EL DNI NO CONTIENE LETRAS, REINGRESE DNI VALIDO: ", 20))
    {
        longitudDni = strlen(auxDni);
        while(!(longitudDni == 8 || longitudDni == 9) || verificacion==1)
        {
            printf("\nEl DNI ingresado no es valido. REINGRESE DNI: ");
            fflush(stdin);
            fgets(auxDni, 20, stdin);
            verificacion = verificacionDigito(auxDni,"\nEL DNI NO CONTIENE LETRAS, REINGRESE DNI VALIDO:  ", 20);
            if(!verificacion)
            {
                longitudDni = strlen(auxDni);
            }
        }
        *dni = atoi(auxDni);
        retorno=0;
    }
    return retorno;
}
