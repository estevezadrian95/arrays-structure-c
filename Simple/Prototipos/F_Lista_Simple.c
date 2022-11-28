#include <stdio.h>
#include <stdlib.h>
#include"F_Lista_Simple.h"

void crear_lista(t_lista *p){
    *p=NULL;
}

int lista_vacia(t_lista *p){

    return *p==NULL;
}

int lista_llena(t_lista *p){

    t_nodo *aux=(t_nodo*)malloc(sizeof(t_nodo));
    free(aux);
return aux==NULL;
}

int insertar_en_orden_actualizando(t_lista *p, t_info *d, int (*comparar)(const t_info *dato1, const t_info *dato2), void (*acumular)(t_info *dato1, const t_info *dato2)){

    t_nodo *nuevo;

    while(*p && comparar(d, &(*p)->info)>0)
        p=&(*p)->siguiente;

    if(*p && comparar(d, &(*p)->info)==0)
    {
        acumular(&(*p)->info, d);
        return 5;///CLA_DUP
    }

    nuevo=(t_nodo*)malloc(sizeof(t_nodo));

    if(nuevo==NULL)
        return 0;///SIN_MEM

    nuevo->info      = *d;
    nuevo->siguiente = *p;
    *p               = nuevo;

return 1;///TODO_BIEN
}

int insertar_al_final(t_lista *p, t_info *d){

    t_nodo *nuevo;

    while (*p!=NULL)
        p=&(*p)->siguiente;

    nuevo=(t_nodo*)malloc(sizeof(t_nodo));
    if(nuevo==NULL)
        return 0;///SIN_MEM

    nuevo->info      = *d;
    nuevo->siguiente = *p;
    *p               = nuevo;
return 1;///TODO BIEN
}

int insertar_al_princpio(t_lista *p, t_info *d){

    t_nodo *nuevo=(t_nodo*)malloc(sizeof(t_nodo));
    if(nuevo==NULL)
        return 0;///SIN_MEM

    nuevo->info      = *d;
    nuevo->siguiente = *p;
    *p               = nuevo;
return 1;///TODO BIEN
}

int buscar_en_lista(t_lista *p, t_info *d, int (*comparar)(const t_info *dato1, const t_info *dato2)){

    while (*p && comparar(d, &(*p)->info)>0)///comparar(d, &(*p)->info)!=0  -------> lista desordenada
        p=&(*p)->siguiente;

    if(*p && comparar(d, &(*p)->info)== 0)
    {
        *d= (*p)->info;
        return 1;///ENCONTRADO;
    }
return 0;
}

int ordenar_lista (t_lista *p, int (*comparar)(const t_info *dato1, const t_info *dato2)){

    t_lista *q;
    t_nodo *act;
    t_nodo *sig;
    t_nodo *sigSig;
    int ordenado=1;

    if(*p==NULL)
        return 0;
    while (ordenado)
    {
        q=p;
        act=*q;
        sig=act->siguiente;
        ordenado = 0;

        while (sig!=NULL)
        {
            if(comparar(&act->info, &sig->info)>0)
            {
                ordenado=1;
                sigSig=sig->siguiente;

                act->siguiente    = sigSig;
                sig->siguiente    = act;

                *q=sig;
                act=*q;

                sig=act->siguiente;
            }
            act=sig;
            sig=sig->siguiente;
            q=&(*p)->siguiente;
        }
    }
}

void eliminar_duplicados (t_lista *p, int (*comparar)(const t_info *dato1, const t_info *dato2)){

    t_nodo *aux;
    t_lista *q;
    int duplicado = 0;

    while (*p!=NULL && (*p)->siguiente!= NULL)
    {
        duplicado = 0;
        q         = &(*p)->siguiente;

        while(*q!=NULL)
        {
            if(comparar(&(*p)->info, &(*q)->info)==0)
            {
                aux = *q;
                *q  = aux->siguiente;
                free(aux);
                duplicado=1;
            }
            else
            q=&(*q)->siguiente;
        }

    if(duplicado==1)
    {
        aux=*p;
        *p=aux->siguiente;
        free(aux);
    }
    else
         p=&(*p)->siguiente;

    }
}

int comparar (const t_info *a, const t_info *b){

return a->clave-b->clave;
}

void mostrar(const t_info *d){

    printf("\n  %d - %s\n", d->clave, d->nombre);
}

void recorrer_lista(const t_lista *p, void mostrar(const t_info *d)){

    while (*p)
    {
     mostrar(&(*p)->info);
     p=&(*p)->siguiente;
    }
}

