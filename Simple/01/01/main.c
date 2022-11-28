#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "F_01.h"
#define SIN_MEM 0
#define EXITO 1

int main()
{
    t_info info;
    t_lista lista;
    int i;

    Crear_lista(&lista);

    for (i=0;i<3;i++)
    {
        printf("\ningrese dni: ");
        scanf("%ld",&info.dni);
        fflush(stdin);
        printf("\ningrese apellido y nombre");
        gets(info.apynom);
        fflush(stdin);
        Cargar_lista_inicio(&lista,&info);
    }
    mostrar_lista(&lista);
    return 0;
}
