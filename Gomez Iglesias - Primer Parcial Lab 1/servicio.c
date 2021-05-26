#include "servicio.h"




void mostrarUnServicio(eServicio unServicio)
{
    printf("%d      %10s     %.2f\n", unServicio.id, unServicio.descripcion, unServicio.precio);
}


int mostrarServicios(eServicio lista[], int tam)
{
   system("cls");
    int retorno = 0;
    if(lista != NULL && tam > 0)
    {
        printf("        Listado de Servicios\n");
        printf("ID          Descripcion    Precio\n\n");

        for(int i=0; i<tam; i++)
        {
                mostrarUnServicio(lista[i]);
        }
        printf("\n\n\n");
        retorno = 1;
    }
    return retorno;
}


int buscarServicio(eServicio lista[], int tam, int id)
{
    int retorno = -1;
    if(lista != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].id==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int cargarDescripcionServicio(int id, eServicio lista[], int tam, char descripcion[])
{
    int retorno = 0;
    if(id>= 20000 && id<=20003 && lista != NULL && tam > 0 && descripcion != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].id==id)
            {
                strcpy(descripcion, lista[i].descripcion);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
