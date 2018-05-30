#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define limitePeliculas 100

int main()
{
    EMovie movie[limitePeliculas];
    EMovie* PMovie = movie;
    init_personas(movie,limitePeliculas);
    char seguir='s';
    int opcion=0;
    char test[5];
    float testt;
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(PMovie,movie,limitePeliculas);
                break;
            case 2:
                fflush(stdin);
                fgets(test,5,stdin);
                printf("%s",test);
                testt=atof(test);
                printf("%f",testt);
                break;
            case 3:
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
