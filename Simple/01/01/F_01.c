#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "F_01.h"
#define SIN_MEM 0
#define EXITO 1

void Crear_lista (t_lista *p)
{
    *p=NULL;
}

int Cargar_lista_inicio(t_lista *p, t_info *d)
{
    t_nodo *nuevo = (t_nodo *)malloc(sizeof(t_nodo));
    if( nuevo==NULL)
    {
        return SIN_MEM;
    }
    else
    {
        nuevo->informacion=*d;
        nuevo->siguiente=*p;
        *p=nuevo;
        return EXITO;
    }

void mostrar_lista (t_lista *p)
{
    while (*p)
    {
        printf("%ld",p->informacion->dni);
        printf("%s",p->informacion->apynom);
        *p=*p->siguiente;
    }


}
