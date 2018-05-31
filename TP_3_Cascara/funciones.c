#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

static int isValidTitle(char* titulo)
{
    return 1;
}

static int isValidDescription(char* description)
{
    return 1;
}

static int isValidGenre(char* genre)
{
    return 1;
}

static int isValidDuration(float duration)
{
    return 1;
}

static int isValidIsEmpty(int isEmpty)
{
    return 1;
}
/*static int buscarLugarLibre(EMovie* PMovie,int limite)
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
}*/

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
///*******************************************************************************************************************************************

EMovie* movie_new(void)
{

    EMovie* returnAux = (EMovie*) malloc(sizeof(EMovie));
    return returnAux;

}

void movie_delete(EMovie* this)
{
    if(this != NULL)
        free(this);
}

int movie_getIsEmpty(EMovie* this, int* isEmpty)
{
    int retorno = -1;
    if(this != NULL && isEmpty != NULL)
    {
        retorno = 0;
        *isEmpty = this->isEmpty;
    }
    return retorno;
}

int movie_setIsEmpty(EMovie* this, int isEmpty)
{
    int retorno = -1;
    if(this != NULL && isValidIsEmpty(isEmpty))
    {
        retorno = 0;
        this->isEmpty = isEmpty ;
    }
    return retorno;
}


int movie_setTitle(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL && isValidTitle(titulo))
    {
        retorno = 0;
        strcpy(this->titulo,titulo);
    }
    return retorno;
}

int movie_getTitle(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        retorno = 0;
        strcpy(titulo,this->titulo);
    }
    return retorno;
}

int movie_setGenre(EMovie* this, char* genre)
{
    int retorno = -1;
    if(this != NULL && genre != NULL && isValidGenre(genre))
    {
        retorno = 0;
        strcpy(this->genero,genre);
    }
    return retorno;
}

int movie_getGenre(EMovie* this, char* genre)
{
    int retorno = -1;
    if(this != NULL && genre != NULL)
    {
        retorno = 0;
        strcpy(genre,this->genero);
    }
    return retorno;
}

int movie_setDuration(EMovie* this, float duration)
{
    int retorno = -1;
    if(this != NULL && isValidDuration(duration))
    {
        retorno = 0;
        this->duracion = duration;
    }
    return retorno;
}

int movie_getDuration(EMovie* this, float* duration)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        *duration = this->duracion;
    }
    return retorno;
}

int movie_setDescription(EMovie* this, char* description)
{
    int retorno = -1;
    if(this != NULL && description != NULL && isValidDescription(description))
    {
        retorno = 0;
        strcpy(this->descripcion,description);
    }
    return retorno;
}

int movie_getDescription(EMovie* this, char* description)
{
    int retorno = -1;
    if(this != NULL && description != NULL)
    {
        retorno = 0;
        strcpy(description,this->descripcion);
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

int agregarPelicula(EMovie* movie,int limite)
{
    char title[4096];
    char description[4096];
    char descriptionTest[4096];
    char tituloTest[4096];
    char genre[4096];
    char generoTest[4096];
    float duration;
    float durationTest;
    /*char descripcion[300];
    float puntaje;
    char linkImagen[300];*/
    EMovie* this;
    //int i = buscarLugarLibre(movie,limite);
    this = movie_new();
    if(    !getCadena(title,"\nIngrese titulo pelicula: ", "\nSE PRODUJO ERROR AL INGRESAR TITULO!", 4096)
        && !getArrayTexto(genre,"\nIngrese genero: ","\nSE PRODUJO ERROR AL INGRESAR GENERO!",4096)
        && !getCadena(description,"\nIngrese descripcion pelicula: ", "\nSE PRODUJO ERROR AL INGRESAR DESCRIPCION!", 4096)
        && !getNumeroFloat(5,1,&duration,5,2,"\nIngrese puntaje pelicula: ","\nSE PRODUJO ERROR AL INGRESAR PUNTAJE!"))
    {
        if(!movie_setTitle(this,title))
        {
            if(!movie_setDescription(this,description))
            {
                if(!movie_setGenre(this,genre))
                {
                    if(!movie_setDuration(this,duration))
                    {
                        movie_getTitle(this,tituloTest);
                        movie_getDescription(this,descriptionTest);
                        movie_getGenre(this,generoTest);
                        movie_getDuration(this,&durationTest);
                        printf("%s",tituloTest);
                        printf("\n---%s",descriptionTest);
                        printf("\n----------%s",generoTest);
                        printf("\n----------%f",durationTest);
                        return this;
                    }
                }
            }
        }
    }
   /* if(!getCadena(titulo,"\nIngrese titulo pelicula: ", "\nSE PRODUJO ERROR AL INGRESAR TITULO!", 50))
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
                            strcpy(movie->titulo,titulo);
                            strcpy(movie->genero,genero);
                            movie->duracion=duracion;
                            strcpy(movie->descripcion,descripcion);
                            movie->puntaje=puntaje;
                            strcpy(movie->linkImagen,linkImagen);
                            movie->isEmpty=0;
                            retorno = 0;
                            printf("\nSE CARGO PELICULA CON EXITO! %d",i);
                            printf("\nTITULO %s",movie->titulo);
                            printf("\nDURACION: %f",movie->duracion);
                            printf("\nPUNTAJE : %f",movie->puntaje);
                            printf("\nGENERO %s",movie->genero);
                            printf("\nDESCRIPCION %s",movie->descripcion);
                            printf("\nLINK %s",movie->linkImagen);

                        }
                    }
                }
            }

        }
    }*/
    movie_delete(this);
    return NULL;
}
