#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERDADERO  1
#define FALSO 0
#define DUPLICADO 0
#define SIN_MEMORIA 0
#define TODO_OK 0
#define ERROR -1
#define OK 1
#define ERROR_DE_STOCK 0

/*
**DEFINO COMO VAN A SER LOS t_dato QUE SE VAN A USAR
**EN LAS LISTA, A LA HORA DE USAR LA LISTA VA A SER GENERICA
**PARA CUALQUIER TIPO DE DATO
*/
typedef int t_dato;

typedef int(t_cmp)(void*, void*);

typedef struct{
    char cod[20];
    int cantidad;
}t_producto;

/*
**DEFINO LA ESTRUCTURA DE LOS NODOS CON LOS QUE VA A ESTAR FORMADA LA LISTA
*/
typedef struct s_sig{
    t_dato info;
    struct s_sig* sig;
}t_nodo;

/*
**DEFINO LA LISTA, EL TIPO t_lista VA A SER UN PUNTERO A UN NODO DE TIPO t_nodo
**DEFINIDO ANTERIORMENTE
*/
typedef t_nodo* t_lista;

/*
**CREO LA LISTA, ASIGNANDOLE AL PUNTERO A NODO NULL
**LOGICAMENTE QUIERE DECIR QUE SI LA VARIABLE LISTA NO APUNTA
**A NADA ES PORQUE NO TIENE NINUNG NODO.
*/
void crear_lista(t_lista* pl){
    *pl = NULL;
}

/*
**VACIAR LISTA, RECORRO TODA LA LISTA Y VOY LIBERANDO LA MEMORIA
**DE LOS NODOS.
*/
void vaciar_lista(t_lista* pl){
    t_nodo* nae = *pl;
    while(*pl){
        *pl = nae->sig;
        free(nae);
        nae = *pl;
    }
}

/*
**INSERTO EN UNA LISTA QUE ESTA ORDENADA DE FORMA ASCENDENTE, TENGO QUE PASAR COMO PARAMETRO
**UNA FUNCION DE COMPARACION PORQUE COMO LA FUNCION ES GENERICA TIENE QUE SERVIR PARA CUALQUIER TIPO DE DATO
**ENTONCES LA FUNCION COMPARACION VA A SER LA QUE SE ENCARGA DE COMPARAR EL TIPO DE DATO
*/
int insertar_en_lista_ord_asc(t_lista* pl,const t_dato* d, t_cmp cmp){//en una lista ordenada en orden ascendente

    while(*pl && cmp(d, &(*pl)->info) > 0){//RECORRO LA LISTA HASTA ENCONTRAR LA POSICION DE INSERCION DE ACUERDO AL ORDEN
        pl = &(*pl)->sig;
    }
    if(*pl && cmp(d, &(*pl)->info ) == 0)//ME FIJO QUE EL CONTENIDO QUE QUIERO AGREGAR NO SEA DUPLICADO
        return DUPLICADO;
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));//RESERVO MEMORIA DEL TAMAÑO DE UN t_nodo, ME DEVUELVE UN PUNTERO A ESE SECTOR DE MEMORIA
    if(!nue)//VERIFICO QUE MALLOC NO ME HALLA RETORNADO NULL POR FALTA DE MEMORIA, SI LO HIZO RETORNO FALTA DE MEMORIA
        return SIN_MEMORIA;
    nue->info = *d;//GUARDO EL DATO A INSERTAR
    nue->sig = *pl;//HAGO QUE EL NUEVO NODO APUNTE AL SIGUIENTE
    *pl = nue;//CONEXION ENTRE EL NODO ANTERIOR Y EL NUEVO.
    return TODO_OK;
}

/*
**BUSCO EN LA LISTA ORDENADA EL DATO QUE PASE COMO PARAMETRO(LA DIRECCION DEL DATO)
*/
int buscar_en_lista_ord_asc(t_lista* pl, t_dato* d, t_cmp cmp){
    while(*pl && cmp(d,&(*pl)->info)>0)//ME POSICIONO EN UN NODO ANTERIOR AL NODO QUE GUARDA EL DATO QUE QUIERO
        pl = &(*pl)->sig;
    if(*pl && cmp(d,&(*pl)->info)==0){//VERIFICO QUE NO QUEDE EN NULL PL Y SI NO LO ES, CORROBORO QUE SEA EL DATO QUE BUSCO
        *d = (*pl)->info;
        return VERDADERO;
    }
    return FALSO;
}

/*
**ELIMINO DE LA LISTA EL DATO QUE PASE COMO PARAMETRO
*/
int eliminar_de_lista_ord_asc(t_lista* pl, t_dato* d, t_cmp cmp){
    while(*pl && cmp(d,&(*pl)->info)>0)//ME POSICIONO EN UN NODO ANTERIOR AL NODO QUE GUARDA EL DATO QUE QUIERO
        pl = &(*pl)->sig;
    if(*pl && cmp(d,&(*pl)->info)==0){//VERIFICO QUE NO QUEDE EN NULL PL Y SI NO LO ES, CORROBORO QUE SEA EL DATO QUE QUIERO ELIMINAR
        t_nodo* nae;
        *d = (*pl)->info;//PARA QUE HAGO ESTO SI YO NO QUIERO OBTENER EL DATO, LO QUIERO ELIMINAR.
        nae = *pl;
        *pl = nae->sig;
        free(nae);
        return VERDADERO;
    }
    return FALSO;
}

/*
**FUNCION DE COMPARACION PARA EL TIPO t_producto HECHA DE FORMA GENERICA
*/
int cmp_prod(const void* pv1, const void* pv2){
    t_producto* p1 = (t_producto*) pv1;
    t_producto* p2 = (t_producto*) pv2;

    return strcmp(p1->cod, p2->cod);
}

/*
**FUNCION PARA ACTUALIZAR UN t_producto HECHO DE FORMA GENERICA
*/
int actualzar_prod(void* pv1, const void* pv2){
    t_producto* p1 = (t_producto*) pv1;
    t_producto* p2 = (t_producto*) pv2;

    if(p1->cantidad + p2->cantidad < 0)
        return ERROR_DE_STOCK;
    p1->cantidad += p2->cantidad;
    return OK;
}

/*
**FUNCION DE INSERCION EN UNA LISTA CON LA VARIANTE DE QUE SI EL DATO QUE QUIERO INSERTA YA EXISTE SE ACTUALIZA EL DATO
**SI NO EXISTE SE AGREGA NORMALMENTE. PASA COMO PARAMENTROS ADEMAS DE LA LISTA Y EL DATO LA FUNCIONES DE COMPARACION
**Y LA FUNCION DE ACTUALIZACION DEL DATO, ESTO ES PORQUE LA LISTA ESTA HECHA DE FORMA GENERICA.
*/
int insertar_actualizar_lista_ord(t_lista* pl, const t_dato* d, t_cmp cmp, t_actualizar act){
    while(*pl && cmp(d, &(*pl)->info)>0)//ME POSICIONO EN UN NODO ANTERIOR AL NODO QUE GUARDA EL DATO QUE QUIERO
        pl = &(*pl)->sig;
    if(*pl && cmp(d, &(*pl)->info)==0){//VERIFICO QUE NO QUEDE EN NULL PL Y SI NO LO ES, CORROBORO QUE SEA EL DATO QUE QUIERO ACTUALIZAR
        return act(&(*pl)->info, d);//ACTUALIZO EL DATO Y RETORNO SI SE PUDO ACTUALIZAR O NO
    }
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));//RESERVO MEMORIA PARA UN NODO NUEVO
    if(!nue)//CORRROBORO QUE HALLA MEMORIA, SI NO HAY DEVUELVO FALTA DE MEMORIA
        return SIN_MEMORIA;
    nue->info = *d;
    nue->sig = *pl;
    *pl = nue;
    return OK;
}

/*
**FUNCION PARA INTERCAMBIAR DOS NODOS QUE SON ADYACENTES
*/
void intercambiar_adyacentes(t_nodo** n1, t_nodo** n2){
    t_nodo* cn1 = *n1;//GUARDO A DIRECCION DEL NODO SIGUIENTE A n1
    *n1 = *n2;
    *n2 = (*n2)->sig;
    (*n2)->sig = cn1;
}
/*
**FUNCION PARA INTERCAMBIAR 2 NODOS QUE NO SON ADYACENTES
*/
void intercambiar_no_adyacente(void** n1, void** n2){// se puede usar la funcion intercambiar generica
    void* aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

t_nodo** buscar_menor(t_nodo** ini, t_cmp cmp){
    t_nodo** menor = ini;
    t_nodo** act = &(*ini)->sig;
    while(*act){
        if(cmp(&(*act)->contenido, &(*menor)->contenido) < 0 )
            menor = act;
        act = &(*act)->sig;
    }
    return m;
}

/*
**FUNCION PARA ORDENAR UNA LISTA, LE PASO COMO PARAMETRO cmp QUE ME VA A DAR LA FORMA
**EN LA QUE SE ORDENAN LOS NODOS, DE ACUERDO AL TIPO DE DATO.
*/
void ordenar_lista(t_lista* pl, t_cmp cmp ){
    t_nodo** i=pl, **m;
    if(!*pl)
        return LISTA_VACIA;
    while((*i)->sig){
        m = buscar_menor(i, cmp);
        if( i != m){
            if((*i)->sig = *m)//sin los nodos a intercambiar son adyacentes
                intercambiar_adyacentes(i, m);
            else
                intercambiar_no_adyacentes(i, m);
        }
        i = &(*i)->sig;
    }
}

typedef int(*t_accion)(void*, void*);//prototipo de todas las acciones que le pase a grabarlista

int grabar_lista(void* pvinfo, void* pvdatos){
    FILE* arch = (FILE*)pvdatos;
    fwrite(pvinfo, sizeof(t_producto),1,arch);
    return TODO_OK;
}

int recorrer_lista(t_lista* pl, t_accion accion, void* datos){
    int ret = TODO_OK;
    while(*pl && ret == TODO_OK){
        ret = accion(&(*pl)->info, datos);
        pl = &(*pl)->sig;
    }
    return ret;
}

int main(){

//LISTA DINAMICA, tiene la misma estructura que la pila pero puedo poner y sacar en cualquier lado.
//Vamos a implementarla en orden.
/* PRIMITIVAS DE LISTA DINAMICA
    crear_lista
    vaciar_lista
    sacar_de_lista, se puede hacer de varias formas, por clave, por posicion, principio o fin.
    poner_en_lista, se puede hacer de varias formas, en orden,por posicion, al principio o al fin.
    buscar_en_lista, se puede buscar por clave o por posicion
    ordenar_lista, por clave o por otro campo
    lista_llena
    lista_vacia
    ver_tope_de_lista*/

    t_lista l;
    t_empleado emp;
    cargar_emp(&emp);
    crear_lista(&l);
    int ret = insertar_en_lista_ord_asc(&l, &emp, cmp);

    t_lista l;
    crear_lista(&l);
    cargar_lista(&l);
    t_producto prod;
    cargar_prod(&prod);
    int ret = insertar_actualizar_lista_ord(&l, &prod, cmp_prod, actualizar_prod);

    t_lista l;
    crear_lista(&l);
    cargar_lista(&l);
    FILE* arch = fopen("asdasd.txt", "wt");
    if(!arch)
        return ERR_ARCH;
    recorrer_lista(&l, grabar_prod, arch);
    fclose(arch);
}


/*
typedef struct{
    char cod[20];
    int cantidad;
}t_producto;

typedef t_producto t_dato;

typedef struct s_sig{
    t_producto info;
    struct s_sig* sig;
}t_nodo;

typedef t_nodo* t_lista;

int cmp_prod(const void* pv1, const void* pv2){
    t_producto* p1 = (t_producto*) pv1;
    t_producto* p2 = (t_producto*) pv2;

    return strcmp(p1->cod, p2->cod);
}

int actualzar_prod(void* pv1, const void* pv2){
    t_producto* p1 = (t_producto*) pv1;
    t_producto* p2 = (t_producto*) pv2;

    if(p1->cantidad + p2->cantidad < 0)
        return ERROR;
    p1->cantidad += p2->cantidad;
    return OK;
}
//otra forma de agregar a la lista
int insertar_actualizar_lista_ord(t_lista* pl,const t_dato* d,t_cmp cmp,t_actualizar act){
    while(*pl && cmp(d, &(*pl)->info)>0)
        pl = &(*pl)->sig;
    if(*pl && cmp(d, &(*pl)->info)==0){
        return act(&(*pl)->info, d);
    }
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return SIN_MEM;
    nue->info = *d;
    nue->sig = *pl;
    *pl = nue;
    return OK;
}
*/
