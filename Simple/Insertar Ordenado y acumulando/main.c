#include <stdio.h>
#include <stdlib.h>

#include "lista_tomas.h"

int comparer(const t_dato*, const t_dato*);

int main()
{
    t_lista list = NULL;

    t_dato persona1 = {"Tomas", 1};
    t_dato persona2 = {"Esteban", 2};
    t_dato persona3 = {"Tomas", 3};
    t_dato persona4 = {"Ana", 1};
    t_dato persona5 = {"Tomas", 1};
    t_dato persona6 = {"Ana", 1};

    poner_al_final(&list, &persona1);
    poner_al_final(&list, &persona2);
    poner_al_final(&list, &persona3);
    poner_al_final(&list, &persona4);
    poner_al_final(&list, &persona5);
    poner_al_final(&list, &persona6);

    list_show(&list);
    eliminarUnicosDeUnaListaNoOrdenada(&list,comparer);
    //eliminar_dup(&list,comparer);
    printf("\nlista sin unicos\n\n");
    list_show(&list);
    return 0;
}

int comparer(const t_dato* p1, const t_dato* p2) {
    return strcmp(p1->nombre, p2->nombre);
}
