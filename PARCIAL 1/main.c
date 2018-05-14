#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "aviso.h"
#include "cliente.h"
#include "funciones.h"
#include "utn.h"
#define CLIENTE 10
#define AVISO 10

int main()
{
    Cliente array[CLIENTE];
    Aviso avisos[AVISO];
    //int i;
    int menu;
    int auxiliarId;
    cliente_init(array,CLIENTE);
    aviso_init(avisos,AVISO);

    cliente_altaForzada(array,"Luis","Suarez","14327416",CLIENTE);
    cliente_altaForzada(array,"Tomas","Suarez","39113917",CLIENTE);
    cliente_altaForzada(array,"Cecilia","Sarobe","16623266",CLIENTE);
    cliente_altaForzada(array,"Elisa","Mast","4000000",CLIENTE);
    aviso_altaForzada(avisos,array,AVISO,CLIENTE,"Primera publicacion",0);
    aviso_altaForzada(avisos,array,AVISO,CLIENTE,"Segunda publicacion",0);
    aviso_altaForzada(avisos,array,AVISO,CLIENTE,"PRUEBA ALTERNATIVA",1);
    aviso_altaForzada(avisos,array,AVISO,CLIENTE,"SEGUNDA PRUEBA ALTERNATIVA",1);
    do
    {
        fflush(stdin);
        getNumero(7,1,&menu,"1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n");
        switch(menu)
        {
            case 1:
                cliente_alta(array,CLIENTE);
                break;
            case 2:
                getNumero(100,0,&auxiliarId,"\nID: ","\nID INVALIDO");
                if((cliente_buscarPorId(array,CLIENTE,auxiliarId))>=0)
                {
                    aviso_mostrar(avisos,auxiliarId,AVISO);
                    aviso_baja(avisos,AVISO,auxiliarId);
                    cliente_baja(array,CLIENTE,auxiliarId);
                }
                break;
            case 3:
                cliente_modificacion(array,CLIENTE,auxiliarId);
                break;
            case 4:
                aviso_alta(avisos,array,AVISO,CLIENTE);
                break;
            case 5:
                getNumero(100,0,&auxiliarId,"\nID AVISO: ","\nID INVALIDO");
                aviso_pausa(avisos,AVISO,auxiliarId);
                break;
            case 6:
                getNumero(100,0,&auxiliarId,"\nID AVISO: ","\nID INVALIDO");
                aviso_reanudar(avisos,AVISO,auxiliarId);
                break;
            case 7:
                cliente_mostrar(array,CLIENTE);
                break;
        }

    }while(menu != 9);

    return 0;
}
