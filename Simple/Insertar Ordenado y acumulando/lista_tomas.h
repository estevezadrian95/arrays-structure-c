#ifndef LISTA_TOMAS_H_INCLUDED
#define LISTA_TOMAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define NOMBRE_TAM 20

typedef struct {
    char nombre[NOMBRE_TAM];
    int cantidad;
} t_dato;

typedef struct s_nodo {
    t_dato dato;
    struct s_nodo* siguiente;
} t_nodo;

typedef t_nodo* t_lista;

int list_push(t_lista* lista, const t_dato *dato);
int list_push_at(t_lista* lista, const t_dato *dato, int pos);
int list_push_in_order(t_lista* lista, const t_dato *dato, int(*compare)(const t_dato*, const t_dato*));
void list_show(t_lista* lista);

#endif // LISTA_TOMAS_H_INCLUDED
