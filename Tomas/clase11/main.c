#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "Contratacion.h"
#define QTY 10
#define LEN_CONT    1000

int main()
{
    Pantalla array[QTY];
    Contratacion contrataciones[LEN_CONT];
    int menu;
    int auxiliarId;



    pantalla_init(array,QTY);
    cont_init(contrataciones,LEN_CONT);

    do
    {
        getValidInt("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                pantalla_alta(array,QTY);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_baja(array,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_modificacion(array,QTY,auxiliarId);
                break;
            case 4:
                pantalla_mostrar(array,QTY);
                cont_alta(contrataciones,LEN_CONT,array,QTY);
                break;
            case 5:
                pantalla_ordenar(array,QTY,0);
                break;
            case 6:
                pantalla_mostrarDebug(array,QTY);
                break;
        }

    }while(menu != 9);

    return 0;
}
