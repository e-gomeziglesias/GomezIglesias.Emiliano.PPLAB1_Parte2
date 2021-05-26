#include "trabajo.h"


int inicializarTrabajos(eTrabajo lista[], int tamLista)
{
    int retorno = 0;
    if(lista!=NULL && tamLista>0)
    {
        for (int i=0; i<tamLista; i++)
        {
            lista[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}


int buscarLibreTrabajo(eTrabajo lista[], int tamLista)
{
    int retorno = -1;
    if(lista!=NULL && tamLista>0)
    {
        for (int i=0; i<tamLista; i++)
        {
            if(lista[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int altaTrabajo(eTrabajo listaT[], int tamT, eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eServicio listaS[], int tamS, eCliente listaCl[], int tamCl, int* pNextIdTrabajo)
{
    system("cls");
    int retorno = 0;
    int indice;
    int iA;
    int iC;
    int iM;
    int iS;
    int iCl;
    char continuar = 'S';
    if(listaT !=NULL && tamT>0 && listaA != NULL && tamA>0 && listaC != NULL && tamC>0 && listaM != NULL && tamM >0 && listaS != NULL && tamS > 0 && listaCl != NULL && tamCl>0 && pNextIdTrabajo != NULL)
    {
        indice=buscarLibreTrabajo(listaT,tamT);
        eTrabajo auxLista;
        if (indice==-1)
        {
            printf("No hay lugares disponibles\n\n");
        }
        else
        {
            do
            {
                auxLista=listaT[indice];
                auxLista.id = (*pNextIdTrabajo);
                printf("\nId asignado: %d\n", auxLista.id);
                //patente
                mostrarAutos(listaA,tamA,listaC,tamC,listaM,tamM, listaCl, tamCl);
                getStringFull(auxLista.patente,"Ingrese la patente: ","Patente ingresada invalida. Ingrese una patente valida: ",20);
                iA = buscarIndiceAutoPorPatente(listaA,tamA,auxLista.patente,20);
                while(iA==-1)
                {
                    printf("La patente ingresada no existe\n");
                    getStringFull(auxLista.patente,"Ingrese la patente: ","Patente ingresada invalida. Ingrese una patente valida: ",20);
                    iA = buscarIndiceAutoPorPatente(listaA,tamA,auxLista.patente,20);
                    iC=buscarColor(listaC,tamC,listaA[iA].idColor);
                    iM=buscarMarca(listaM,tamM,listaA[iM].idMarca);
                    iCl=buscarCliente(listaCl,tamCl,listaA[iA].idCliente);
                }
                printf("\nSelecciono el auto:\n\n");
                mostrarUnAuto(listaA[iA],listaC[iC],listaM[iM], listaCl[iCl]);

                //servicio
                mostrarServicios(listaS,tamS);
                printf("\nIngreso:\n\n");
                auxLista.idServicio = getInt("Ingrese el id del servicio: ", "El id ingresado es invalido. Ingrese el id: ",20000,20004);
                iS = buscarServicio(listaS,tamS, auxLista.idServicio);
                mostrarUnServicio(listaS[iS]);
                //fecha
                getFecha(auxLista.fecha);
                //marco la posicion como ocupada
                auxLista.isEmpty = 0;
                //copio el auxiliar a la posicion indice del vector
                listaT[indice] = auxLista;
                //actualizo el siguiente idTrabajo
                (*pNextIdTrabajo)=(*pNextIdTrabajo)+1;
                retorno = 1;
                continuar = getUpperChar("\nDesea dar de alta otro trabajo? (S/N): ");
            }while(continuar=='S');
        }
    }
    return retorno;
}


void mostrarUnTrabajo(eTrabajo unTrabajo, eAuto unAuto, eServicio unServicio)
{
        printf("%d      %-10s       %-10s       %02d/%02d/%4d \n", unTrabajo.id, unAuto.patente, unServicio.descripcion, unTrabajo.fecha.dia, unTrabajo.fecha.mes, unTrabajo.fecha.anio);
}


int mostrarTrabajos(eTrabajo listaT[], int tamT, eAuto listaA[], int tamA, eServicio listaS[], int tamS)
{
    system("cls");
    int retorno = 0;
    int flagUnoCargado = 0;
    int iS;
    int iA;

    if(listaT != NULL && tamT>0 && listaS!= NULL && tamS > 0)
    {
        printf("            Listado de Trabajos\n\n");
        printf("ID          Patente         Servicio            Fecha\n\n");

        for(int i=0; i<tamT; i++)
        {
            if(listaT[i].isEmpty==0)
            {
                iA=buscarIndiceAutoPorPatente(listaA,tamA,listaT[i].patente, 20);
                iS=buscarServicio(listaS,tamS,listaT[i].idServicio);
                mostrarUnTrabajo(listaT[i],listaA[iA],listaS[iS]);
                flagUnoCargado = 1;
            }
        }
        if(flagUnoCargado == 0)
        {
            printf("No hay trabajos para mostrar. \n\n");
        }
        printf("\n\n\n");
        retorno = 1;
    }
    return retorno;
}
