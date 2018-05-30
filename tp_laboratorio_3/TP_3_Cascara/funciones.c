#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


static int buscarLugarLibre(EMovie* PMovie,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && PMovie != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(PMovie->isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/*static int buscarPorNombre(EMovie* PMovie,int limite, char* titulo)
{
    int retorno = -1;
    int i;
    if(limite > 0 && PMovie != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!PMovie->isEmpty && PMovie->titulo==titulo)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}*/


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
        if(isdigit(auxCarga[i])!=0)
        {
            i++;
            retorno =0;
        }
        else
        {
            printf("ERROR VERIFICACION DIGITO"/*, mensajeError*/);
            fflush(stdin);
            fgets(auxCarga, tamanioVector, stdin);
            j=strlen(auxCarga);
            i=0;
            retorno =1;

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

int getArrayTexto(char* texto,char* textoInstruccion,char* textoError, int limite)
{
    int retorno=1;
    char auxTexto[limite];
    printf("%s",textoInstruccion);
    fflush(stdin);
    fgets(auxTexto, limite, stdin);
    if(!verificacionChar(auxTexto,textoError,limite))
    {
            strcpy(texto, auxTexto);
            retorno=0;
    }
    return retorno;
}

/** \brief Valida NUMERO.
 *
 * \param numMax int Defino NUMERO maximo.
 * \param numMin int Defino NUMERO minima.
 * \param numero int* Mediante puntero paso NUMERO.
 * \return int retorno [0] si se cargo la NUMERO con exito. [1] = ERROR.
 *
 */
int getNumeroFloat(float numMax, float numMin, float *numero,int limite,int intentos,char *mensaje, char *mensajeError){
    int retorno=1;
    float auxNum;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&auxNum);
    while((auxNum > (float)numMax || auxNum < (float)numMin))
    {
        if(intentos==0)
            return 1;
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%f",&auxNum);
        intentos-=1;
    }
        *numero = auxNum;
        retorno=0;
    return retorno;
}

/** \brief Obtiene Cadena Alfanumerica
 *
 * \param array char* Mediante puntero pasa texto
 * \param mensaje char* Instruccion usuario
 * \param mensajeError char* Muestra error
 * \return int retorna [0] si se obtuvo cadena, [1] ERROR
 *
 */
int getCadena(char* array, char *mensaje, char *mensajeError, int limite)
{
    int retorno=1;
    char auxArray[limite];
    printf("%s",mensaje);
    fflush(stdin);
    fgets(auxArray, limite, stdin);

    if(strlen(auxArray)>0 && auxArray!=NULL)
    {
            strcpy(array, auxArray);
            retorno=0;
    }
    else
    {
        printf("%s",mensajeError);
    }

    return retorno;
}

/** \brief Inicializo array en estado = 1 (NO CARGADO).
 *
 * \param aCargar EPersona* Trabajo sobre array personas.
 * \param limite int Limite del array (Limite de personas).
 * \return int retorno [0] si se realizo la inicializacion con exito. [1] = ERROR.
 *
 */
int init_personas(EMovie* PMovie,int limite)
{
    int retorno = 1;
    int i;
    if(limite > 0 && PMovie != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            PMovie->isEmpty=1;
        }
    }
    return retorno;
}

int agregarPelicula(EMovie* PMovie,EMovie* movie,int limite)
{
    char titulo[50];
    char genero[20];
    float duracion;
    char descripcion[300];
    float puntaje;
    char linkImagen[300];
    int retorno=1;
    int i = buscarLugarLibre(movie,limite);
    if(!getCadena(titulo,"\nIngrese titulo pelicula: ", "\nSE PRODUJO ERROR AL INGRESAR TITULO!", 50))
    {
        if(!getArrayTexto(genero,"\nIngrese genero: ","\nSE PRODUJO ERROR AL INGRESAR GENERO!",20))
        {
            if(!getNumeroFloat(
                               4,0,&duracion,5,2,"\nIngrese duracion pelicula(MIN 0.01, MAX 4.00hs): ","\nSE PRODUJO ERROR AL INGRESAR DURACION!"))
            {
                if(!getCadena(descripcion,"\nIngrese descripcion pelicula: ","\nSE PRODUJO ERROR AL INGRESAR PUNTAJE!",300))
                {
                    if(!getNumeroFloat(5,1,&puntaje,5,2,"\nIngrese puntaje pelicula: ","\nSE PRODUJO ERROR AL INGRESAR PUNTAJE!"))
                    {
                        if(!getCadena(linkImagen,"\nIngrese link imagen pelicula: ","\nSE PRODUJO ERROR AL INGRESAR LINK!",300))
                        {
                            PMovie = &movie[i];
                            strcpy(PMovie->titulo,titulo);
                            strcpy(PMovie->genero,genero);
                            PMovie->duracion=duracion;
                            strcpy(PMovie->descripcion,descripcion);
                            PMovie->puntaje=puntaje;
                            strcpy(PMovie->linkImagen,linkImagen);
                            PMovie->isEmpty=0;
                            retorno = 0;
                            printf("\nSE CARGO PELICULA CON EXITO! %d",i);
                            printf("\nTITULO %s",PMovie->titulo);
                            printf("\nDURACION: %f",PMovie->duracion);
                            printf("\nPUNTAJE : %f",PMovie->puntaje);
                            printf("\nGENERO %s",PMovie->genero);
                            printf("\nDESCRIPCION %s",PMovie->descripcion);
                            printf("\nLINK %s",PMovie->linkImagen);

                        }
                    }
                }
            }

        }
    }
    return retorno;
}
