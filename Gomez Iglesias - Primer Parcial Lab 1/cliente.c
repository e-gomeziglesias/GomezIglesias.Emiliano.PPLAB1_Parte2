#include "cliente.h"

int buscarCliente(eCliente lista[], int tam, int id)
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

void mostrarUnCliente(eCliente unCliente)
{
    printf("%d %10s %c\n", unCliente.id, unCliente.nombre, unCliente.sexo);
}

int mostrarClientes(eCliente lista[], int tam)
{
   system("cls");
    int retorno = 0;
    if(lista != NULL && tam > 0)
    {
        printf("        Listado de Clientes\n");
        printf("ID  Nombre      Sexo\n\n");

        for(int i=0; i<tam; i++)
        {
                mostrarUnCliente(lista[i]);
        }
        printf("\n\n\n");
        retorno = 1;
    }
    return retorno;
}

int cargarDescripcionCliente(int id, eCliente lista[], int tam, char descripcion[])
{
    int retorno = 0;
    if(id>= 1 && id<=5 && lista != NULL && tam > 0 && descripcion != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].id==id)
            {
                strcpy(descripcion, lista[i].nombre);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
