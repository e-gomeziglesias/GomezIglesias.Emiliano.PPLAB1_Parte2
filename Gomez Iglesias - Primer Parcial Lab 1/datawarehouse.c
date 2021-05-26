#include "datawarehouse.h"

    eAuto autos[5]={{100,"AAA111",1000,5000,1989,1,0},
                        {101,"CAB321",1000,5000,1980,2,0},
                        {102,"ABC129",1002,5002,2015,5,0},
                        {103,"KIL789",1001,5002,2020,4,0},
                        {104,"AMI087",1001,5004,2012,3,0}};

    eColor colores[5]={{5000,"NEGRO"},
                        {5001,"BLANCO"},
                        {5002,"GRIS"},
                        {5003,"ROJO"},
                        {5004,"AZUL"}};

    eMarca marcas[5]={{1000,"Renault"},
                        {1001, "Fiat"},
                        {1002,"Ford"},
                        {1003, "Chevrolet"},
                        {1004, "Peugeot"}};

    eServicio servicios[4] = {{20000,"Lavado", 250},
                                {20001, "Pulido", 300},
                                {20002, "Encerado", 400},
                                {20003, "Completo", 600}};

    eTrabajo trabajos[5]={{30000,"AAA111",20001,{07,1,2021},0},
                            {30001,"CAB321",20002,{10,3,2021},0},
                            {30002,"KIL789",20000,{15,4,2021},0},
                            {30003,"AAA111",20002,{15,4,2021},0},
                            {30004,"CAB321",20001,{23,2,2021},0}};


    eCliente clientes [5]={{1,"Juan",'m'},
                        {2,"Maria",'f'},
                        {3,"Pamela",'f'},
                        {4,"Marcos",'m'},
                        {5, "Pablo", 'm'}};


int hardcodearAutos(eAuto lista[],int tam, int* nextId)
{
    int retorno = 0;
    if (lista != NULL && tam > 0)
    {
        for (int i=0; i<tam ; i++)
        {
            lista[i] = autos[i];
            *nextId = *nextId +1;
        }
        retorno = 1;
    }
     return retorno;
}

int hardcodearServicios(eServicio lista[],int tam)
{
    int retorno = 0;
    if (lista != NULL && tam > 0)
    {
        for (int i=0; i<tam ; i++)
        {
            lista[i]=servicios[i];
        }
        retorno = 1;
    }
     return retorno;
}

int hardcodearMarcas(eMarca lista[],int tam)
{
    int retorno = 0;
    if (lista != NULL && tam > 0)
    {
        for (int i=0; i<tam ; i++)
        {
            lista[i] = marcas[i];
        }
        retorno = 1;
    }
     return retorno;
}

int hardcodearColores(eColor lista[],int tam)
{
    int retorno = 0;
    if (lista != NULL && tam > 0)
    {
        for (int i=0; i<tam ; i++)
        {
            lista[i]=colores[i];
        }
        retorno = 1;
    }
     return retorno;
}

int hardcodearTrabajos(eTrabajo lista[],int tam, int* nextId)
{
    int retorno = 0;
    if (lista != NULL && tam > 0)
    {
        for (int i=0; i<tam ; i++)
        {
            lista[i]=trabajos[i];
            *nextId = *nextId +1;
        }

        retorno = 1;
    }
     return retorno;
}

int hardcodearClientes(eCliente lista[],int tam)
{
    int retorno = 0;
    if (lista != NULL && tam > 0)
    {
        for (int i=0; i<tam ; i++)
        {
            lista[i]=clientes[i];
        }
        retorno = 1;
    }
     return retorno;
}
