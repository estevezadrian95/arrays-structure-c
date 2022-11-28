#ifndef F_LDE_H_INCLUDED
#define F_LDE_H_INCLUDED

typedef struct
{


}t_info;

typedef struct s_nodo_DE
{
    t_info info;
    struct s_nodo_DE *sig,
                     *ant;
}t_nodo_DE,*t_listaDE;

void Crear_Lista(t_listaDE *p);
int Lista_Vacia(t_listaDE *p);
int Lista_Llena(t_listaDE *p);
int insertar_Lista_Doble_Ordenado(t_listaDE *p, const t_info *d, int (*cmp)(const t_info *d1, const t_info *d2));
int Buscar_Lista_Doble_Ordenado (const t_listaDE *p, const t_info *d, int (*cmp)(const t_info *d1, const t_info *d2));
int EliminarXClave_LDE (t_listaDE *p, const t_info *d, int (*cmp)(const t_info *d1, const t_info *d2));

#endif // F_LDE_H_INCLUDED
