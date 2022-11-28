#include<stdio.h>
#include<conio.h>
#include"F_LDE.h"
#define SIN_MEM 0
#define TODO_BIEN 1
#define CLA_DUP 2
#define NOT_FOUND 3

void Crear_Lista(t_listaDE *p)
{
    *p=NULL;
}

int Lista_Vacia(t_listaDE *p)
{
    return *p==NULL;
}

int Lista_Llena(t_listaDE *p)
{
    t_nodo_DE *aux=(t_nodo_DE*)malloc(sizeof(t_nodo_DE));
    free(aux);
return aux==NULL;
}

int insertar_Lista_Doble_Ordenado(t_listaDE *p, const t_info *d, int (*cmp)(const t_info *d1, const t_info *d2))
{
    t_nodo_DE *act, *sigAux, *antAux, *nue;
    act = *p;
    if(act)
    {
        while(act -> sig && cmp(d, &act -> info)>0)
            act = act -> sig;
        if(act -> ant && cmp(d, &act -> info)<0)     //1º bloque if. me desplazo dentro de la lista
            act = act -> ant;
        if(cmp(d,&act -> info) == 0)
        {
            //acciones por clave duplicada
            return CLA_DUP;
        }
    }
    if(act)
    {
        if(cmp(d, &act -> info)>0)
        {
            antAux = act;
            sigAux = act -> sig;                //2º bloque if. me posiciono a izquierda o derecha del nodo y asigno antAux y sigAux segun corresponda
        }
        else
        {
            antAux = act -> ant;
            sigAux = act;
        }
    }
    else
        antAux = sigAux = NULL;

    nue = ( t_nodo_DE*)malloc(sizeof(t_nodo_DE));
    if(nue == NULL)
        return SIN_MEM;

    nue -> info = *d;
    nue -> ant = antAux;
    nue -> sig = sigAux;

    if(antAux)
        antAux -> sig = nue;
    if(sigAux)
        sigAux -> ant = nue;

    *p = nue;///L lista siempre va a estar apuntando al ultimo insertado por orden de la catedra

    return TODO_BIEN;
}

int Buscar_Lista_Doble_Ordenado (const t_listaDE *p, const t_info *d, int (*cmp)(const t_info *d1, const t_info *d2))
{
    t_nodo_DE *act;
    act=*p;

    if(act)//si hay algo en la lista
    {
        while (act->sig && cmp(&act->info,d)>0)
            act=act->sig;
    }
    if(cmp(&act->info,d)!=0)
        return NOT_FOUND; //no encontrado

    *d=act->info;

return TODO_BIEN;
}

int EliminarXClave_LDE (t_listaDE *p, const t_info *d, int (*cmp)(const t_info *d1, const t_info *d2))
{
    t_nodo_DE *act, *antAux, *sigAux;
    act=*p;

    if(act)
    {
        while(act->sig && cmp(&act->info,d)!=0)//seguir mientras exista el siguiente y no lo encuentra
        act=act->sig;
    }

    if(cmp(&act->info,d)!=0)
        return NOT_FOUND;
    //si quiero obtener el dato y despues borrarlo saco el const de t_info y primero pongo
    //*d=act->info;
    act->ant=antAux;
    act->sig=sigAux;

    sigAux->ant=antAux;
    antAux->sig=sigAux;

    free(act);

return TODO_BIEN;
}

void Vaciar_Lista (t_lista *p)
{
    t_nodo *aux;
    while (*p)
    {
        aux=*p;
        *p=aux->siguiente;
        free(aux);
    }
}
