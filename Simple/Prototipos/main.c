#include <stdio.h>
#include <stdlib.h>
#include"F_Lista_Simple.h"

int main()
{
    t_info info1={14,"Adrian"};
    t_info info2={34,"Tomas"};
    t_info info3={7,"Gaston"};
    t_info info4={99,"Jose"};
    t_info info5={58,"Pepe"};
    t_info info6={99,"Jorge"};
    t_info info7={4,"Jonathan"};
    t_info info8={58,"Pepe"};
    t_info info9={99,"Jorge"};
    t_info info10={4,"Jonathan"};
    t_info aBuscar;
    int encontrado;

    t_lista lista;
    int i=0;

    crear_lista(&lista);
    if(lista_llena(&lista))
    printf("lista llena");

    insertar_al_final(&lista,&info1);
    insertar_al_final(&lista,&info2);
    insertar_al_final(&lista,&info3);
    insertar_al_final(&lista,&info4);
    insertar_al_final(&lista,&info5);
    insertar_al_final(&lista,&info6);
    insertar_al_final(&lista,&info7);
    insertar_al_final(&lista,&info8);
    insertar_al_final(&lista,&info9);
    insertar_al_final(&lista,&info10);

    printf("\nLISTA DESORDENADA\n");
    recorrer_lista(&lista,mostrar);

    printf("\nLISTA ORDENADA\n");
    ordenar_lista(&lista, &comparar);
    recorrer_lista(&lista,&mostrar);

    printf("\nLISTA SIN DUPLICADOS\n");
    eliminar_duplicados(&lista,comparar);
    recorrer_lista(&lista, &mostrar);

    printf("\nBUSQUEDA EN LISTA\n");
    aBuscar.clave=14;
    encontrado=buscar_en_lista(&lista,&aBuscar,&comparar);
    encontrado==1?printf("\n\n  %d  -  %s \n\n", aBuscar.clave, aBuscar.nombre):printf("\n\nNO EXISTE\n\n");

    return 0;
}
