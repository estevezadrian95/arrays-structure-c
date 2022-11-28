#ifndef F_LISTA_SIMPLE_H_INCLUDED
#define F_LISTA_SIMPLE_H_INCLUDED


typedef struct{

    int clave;
    char nombre[15];

}t_info;

typedef struct s_nodo
{
    t_info info;
    struct s_nodo *siguiente;
}t_nodo, *t_lista;


void crear_lista(t_lista *p);
int lista_vacia(t_lista *p);
int lista_llena(t_lista *p);
int insertar_en_orden_actualizando(t_lista *p, t_info *d, int (*comparar)(const t_info *dato1, const t_info *dato2), void (*acumular)(t_info *dato1, const t_info *dato2));
int insertar_al_final(t_lista *p, t_info *d);
int insertar_al_princpio(t_lista *p, t_info *d);
int buscar_en_lista(t_lista *p, t_info *d, int (*comparar)(const t_info *dato1, const t_info *dato2));
int ordenar_lista (t_lista *p, int (*comparar)(const t_info *dato1, const t_info *dato2));
void eliminar_duplicados (t_lista *p, int (*comparar)(const t_info *dato1, const t_info *dato2));
int comparar (const t_info *a, const t_info *b);
void mostrar(const t_info *d);
void recorrer_lista(const t_lista *p, void mostrar(const t_info *d));


#endif // F_LISTA_SIMPLE_H_INCLUDED
