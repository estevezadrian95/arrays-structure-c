#ifndef F_01_H_INCLUDED
#define F_01_H_INCLUDED

typedef struct
{
    long dni;
    char apynom[20];
}t_info;

typedef struct snodo
{
    t_info informacion;
    struct snodo *siguiente;
}t_nodo;

typedef t_nodo *t_lista;

void mostrar_lista (t_lista *p);
void Crear_lista (t_lista *p);
int Cargar_lista_inicio(t_lista *p, t_info *d);




#endif // F_01_H_INCLUDED
