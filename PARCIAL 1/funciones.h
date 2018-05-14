#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string.h>
#include <ctype.h>

int getArrayChar(char* nombre, char *mensaje, char *mensajeError);
int getNumero(int numMax, int numMin, int *numero,char *mensaje, char *mensajeError);
int getDni(int *dni);
int verificacionDigito(char *auxCarga, char *mensajeError, int tamanioVector);
int verificacionChar(char *auxCarga, char *mensajeError, int tamanioVector);
int getCharNumeros(char* cuit, char *mensaje, char *mensajeError);
int getCadena(char* array, char *mensaje, char *mensajeError);
#endif // FUNCIONES_H_INCLUDED
