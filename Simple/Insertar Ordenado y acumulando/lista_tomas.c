#include "lista_tomas.h"

int list_push(t_lista*  lista, const t_dato *dato) {
    t_nodo* nuevo_nodo = (t_nodo*)malloc(sizeof(nuevo_nodo));
    if (!nuevo_nodo) {
        return FALSE;
    }
    nuevo_nodo->dato = *dato;
    nuevo_nodo->siguiente = NULL;
    while(*lista) {
        lista = &(*lista)->siguiente;
    }
    *lista = nuevo_nodo;
    return 1;
}

int poner_al_final(t_lista *p, const t_dato *d){

    t_nodo *nuevo;
    while(*p)
        p=&(*p)->siguiente;

    nuevo=(t_nodo*)malloc(sizeof(t_nodo));
    nuevo->dato=*d;
    nuevo->siguiente=NULL;
    *p=nuevo;
return 1;
}


int list_push_at(t_lista* lista, const t_dato *dato, int pos) {
    t_nodo* nuevo_nodo;
    int i = 0;
    int out_of_range = FALSE;
    while (i < pos || out_of_range) {
        if (!*lista) {
            out_of_range = TRUE;
        }
        lista = &(*lista)->siguiente;
        ++i;
    }

    if (out_of_range) {
        return FALSE;
    }

    nuevo_nodo = malloc(sizeof(nuevo_nodo));
    if (!nuevo_nodo) {
        return FALSE;
    }
    nuevo_nodo->dato = *dato;

    nuevo_nodo->siguiente = *lista;
    *lista = nuevo_nodo;
    return TRUE;
}

int list_push_in_order(t_lista* lista,
                       const t_dato *dato,
                       int(*compare)(const t_dato *a, const t_dato *b)) {
    t_nodo* nuevo_nodo;
    int cmp ;
    while (*lista && (cmp = compare(&(*lista)->dato, dato)) < 0) {
        lista = &(*lista)->siguiente;
    }
    if (*lista && cmp == 0) {
        (*lista)->dato.cantidad += (*dato).cantidad;
        return TRUE;
    }
    nuevo_nodo = malloc(sizeof(t_nodo));
    if (!nuevo_nodo) {
        return FALSE;
    }
    nuevo_nodo->dato = *dato;
    nuevo_nodo->siguiente = *lista;
    *lista = nuevo_nodo;
    return TRUE;
}

void list_show(t_lista* lista) {
    while(*lista) {
        printf("%s - cantidad: %d \n",
            (*lista)->dato.nombre,
            (*lista)->dato.cantidad);
        lista = &(*lista)->siguiente;
    }
}

int eliminar_dup(t_lista *p,int (*cmp)(const t_dato *, const t_dato * ))
{
    t_nodo *aux;
    t_lista *q;
    int duplicado=0;

    while(*p!=NULL && (*p)->siguiente!=NULL)
    {
        duplicado=0;
        q=&(*p)->siguiente;

        while(*q)
        {
            if(cmp(&(*q)->dato, &(*p)->dato)==0)
            {
                duplicado=1;
                aux=*q;
                *q=aux->siguiente;
                free(aux);
            }
            else
                q=&(*q)->siguiente;
        }
        if(duplicado==1)
        {
                duplicado=1;
                aux=*p;
                *p=aux->siguiente;
                free(aux);
            }
            else
                p=&(*p)->siguiente;
        }
}

int eliminarUnicosDeUnaListaNoOrdenada(t_lista *pl,int (*cmp)(const t_dato *, const t_dato *) )
{
    t_lista *q=pl;
    int veces,cont=0;
    t_nodo *aux;
    while(*q && (*q)->siguiente)
    {
        q = pl;
        veces=2;
        while (veces && aux)
        {
            if(cmp(&(*q)->dato, &(*q)->dato)==0)
                veces--;
            q=&(*q)->siguiente;
        }
        if(veces==1)
        {
            aux=*q;
            *q=aux->siguiente;
            cont++;
            free(aux);
        }
        q=&(*q)->siguiente;
    }
    return cont;
}
