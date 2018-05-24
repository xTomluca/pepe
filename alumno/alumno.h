typedef struct
{
    char dni[50];
    char apellido[50];
    char cuit[50];
    char nombre[50];
    float altura;
    int edad;
    int id;
}Cliente;


Cliente* cliente_new();
void cliente_delete(Cliente* this);
int cliente_getCuit(Cliente* this, char* cuit);
int  cliente_setEdad(Cliente* this, int edad);
int cliente_getEdad(Cliente* this, int* edad);
int isValidAltura(int altura);
int cliente_getAltura(Cliente* this, float *altura);
int cliente_setAltura(Cliente* this, float altura);
int isValidCuit(char* cuit);
int isValidApellido(char* apellido);
int cliente_setId(Cliente* this);
int cliente_setCuit(Cliente* this, char* cuit);
int cliente_setApellido(Cliente* this, char* apellido);
Cliente* cliente_newP(char* dni, char* apellido, char* cuit, char* nombre, float altura, int edad, int id);
