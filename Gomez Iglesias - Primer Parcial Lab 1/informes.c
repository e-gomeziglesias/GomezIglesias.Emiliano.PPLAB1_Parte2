#include "informes.h"

//1. Mostrar autos del color elegido por el usuario
int mostrarAutosDeUnColor(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl)
{
    int retorno = 0;
    if(listaA != NULL && tamA>0 && listaC!=NULL && tamC>0 && listaM!=NULL && tamM>0 && listaCl!=NULL && tamCl>0)
    {
        int hayUno=0;
        int idColor;
        int iC;
        int iM;
        int iCl;

        printf("\nMOSTRAR AUTOS DE UN COLOR\n\n");
        mostrarColores(listaC,tamC);
        idColor=getInt("Ingrese el id del color a mostrar: ", "El id ingresado es invalido. Ingrese el id del color a mostrar: ",5000,5004);
        printf("ID      Patente            Marca             Color              Modelo          Cliente\n\n");
        for(int i=0; i<tamA; i++)
        {
            if(listaA[i].isEmpty==0 && listaA[i].idColor==idColor)
            {
                iC=buscarColor(listaC,tamC,idColor);
                iM=buscarMarca(listaM, tamM, listaA[i].idMarca);
                iCl=buscarCliente(listaCl,tamCl,listaA[i].idCliente);
                mostrarUnAuto(listaA[i],listaC[iC],listaM[iM],listaCl[iCl]);
                hayUno=1;
            }
        }
        retorno = 1;
        if(hayUno==0)
        {
            printf("\nNo hay autos de ese color\n\n");
            retorno = 0;
        }
    }
    return retorno;
}

//2. Mostrar autos del color elegido por el usuario
int mostrarAutosDeUnaMarca(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl)
{
    int retorno = 0;
    if(listaA != NULL && tamA>0 && listaC!=NULL && tamC>0 && listaM!=NULL && tamM>0 && listaCl!=NULL && tamCl>0)
    {
        int hayUno=0;
        int idMarca;
        int iC;
        int iM;
        int iCl;

        printf("\nMOSTRAR AUTOS DE UNA MARCA\n\n");
        mostrarMarcas(listaM,tamM);
        idMarca=getInt("Ingrese el id de la marca a mostrar: ", "El id ingresado es invalido. Ingrese el id de la marca a mostrar: ",1000,1004);

        printf("ID      Patente            Marca             Color              Modelo          Cliente\n\n");
        for(int i=0; i<tamA; i++)
        {
            if(listaA[i].isEmpty==0 && listaA[i].idMarca==idMarca)
            {
                iC=buscarColor(listaC,tamC,listaA[i].idColor);
                iM=buscarMarca(listaM, tamM, idMarca);
                iCl=buscarCliente(listaCl,tamCl,listaA[i].idCliente);
                mostrarUnAuto(listaA[i],listaC[iC],listaM[iM],listaCl[iCl]);
                hayUno=1;
            }
        }
        retorno = 1;
        if(hayUno==0)
        {
            printf("\nNo hay autos de esa marca\n\n");
            retorno = 0;
        }
    }
    return retorno;
}

//3. Mostrar el o los autos mas viejos
int mostrarAutoViejo(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl)
{
    int retorno = 0;
    int anios[tamA];
    int menorAnio;
    int flag = 0;
    int iC;
    int iM;
    int iCl;
    if(listaA != NULL && tamA>0 && listaC!=NULL && tamC>0 && listaM!=NULL && tamM>0 && listaCl!=NULL && tamCl>0)
    {
        for (int i=0; i<tamA;i++)
        {
            if(listaA[i].isEmpty==0)
            {
                anios[i]=listaA[i].modelo;
            }
            else
            {
                anios[i]=-1;
            }
        }
        for (int i=0; i<tamA-1; i++)
        {
            if((flag==0 ||anios[i]<menorAnio) && (anios[i]!=-1))
            {
                menorAnio = anios[i];
                flag=1;
            }
        }
        for(int i=0; i<tamA-1;i++)
        {
            if(listaA[i].modelo == menorAnio && listaA[i].isEmpty==0)
            {
                iC=buscarColor(listaC,tamC,listaA[i].idColor);
                iM=buscarMarca(listaM,tamM,listaA[i].idMarca);
                iCl=buscarCliente(listaCl,tamCl,listaA[i].idCliente);
                mostrarUnAuto(listaA[i],listaC[iC],listaM[iM],listaCl[iCl]);
            }
        }
        retorno = 1;
    }
    return retorno;
}

//4.Mostrar listado de autos separados por marca.
int mostrarAutosSeparadosPorMarca(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl)
{
    int retorno = 0;
    if(listaA != NULL && tamA>0 && listaC!=NULL && tamC>0 && listaM!=NULL && tamM>0 && listaCl!=NULL && tamCl>0)
    {
        int iC;
        int iCl;
        int flag;

        printf("\nMOSTRAR AUTOS POR MARCA\n\n");
        printf("ID      Patente            Marca             Color              Modelo       Cliente\n\n");
        for(int m=0; m<tamM; m++)
        {

            printf("\n\n\n");
            mostrarUnaMarca(listaM[m]);
            flag=0;
            for(int a=0;a<tamA;a++)
            {
                if(listaA[a].isEmpty==0 && listaA[a].idMarca==listaM[m].id)
                {
                    iC=buscarColor(listaC,tamC,listaA[a].idColor);
                    iCl=buscarCliente(listaCl,tamCl,listaA[a].idCliente);
                    mostrarUnAuto(listaA[a],listaC[iC],listaM[m],listaCl[iCl]);
                    flag=1;
                }
            }
            if(flag==0)
            {
                printf("\nNo hay autos de esta marca\n\n");
            }
        }
    }
    return retorno;
}

//5.Elegir un color y una marca y contar cuantos autos hay de ese color y esa marca
int contarAutosPorColorYPorMarca(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    int retorno = 0;
    if(listaA != NULL && tamA>0 && listaC!=NULL && tamC>0 && listaM!=NULL && tamM>0)
    {
        int idColor;
        int idMarca;
        char color[20];
        char marca[20];
        int contadorAutos=0;
        mostrarColores(listaC,tamC);
        idColor=getInt("Ingrese el id del color elegido: ", "El id elegido es invalido. Ingrese el id del color: ",5000,5004);
        cargarDescripcionColor(idColor,listaC,tamC,color);
        printf("\nEligio el color %s\n\n",color);
        mostrarMarcas(listaM,tamM);
        idMarca=getInt("Ingrese el id de la marca elegida: ", "El id elegido es invalido. Ingrese el id de la marca: ",1000,1004);
        cargarDescripcionMarca(idMarca,listaM,tamM,marca);
        printf("\nEligio la marca %s\n\n",marca);
        for(int i=0; i<tamA;i++)
        {
            if(listaA[i].isEmpty==0 && listaA[i].idColor==idColor && listaA[i].idMarca==idMarca)
            {
                contadorAutos++;
            }
        }
        if(contadorAutos==0)
        {
            printf("\n\nNo se encontraron autos que cumplan con los filtros elegidos.\n\n");
        }
        else
        {
            printf("\n\nSe encontraron %d autos de color %s y de la marca %s\n\n",contadorAutos,color,marca);
        }
        retorno = 1;
    }
    return retorno;
}


//6.Mostrar la/las marcas mas elegidas
int mostrarMarcasMasElegidas(eAuto listaA[],int tamA, eMarca listaM[], int tamM)
{
    int retorno=0;
    int iM;
    int contadorMarcas[tamM];
    int maximo;
    if(listaA!=NULL && tamA>0 && listaM!=NULL && tamM>0)
    {
        //inicializo contador
        for(int i=0; i<tamM; i++)
        {
            contadorMarcas[i]=0;
        }
        for(int a=0; a<tamA; a++)
        {
            if(listaA[a].isEmpty==0)
            {
                iM=buscarMarca(listaM,tamM,listaA[a].idMarca);
                contadorMarcas[iM]++;
            }
        }
        for (int m=0; m<tamM; m++)
        {
            if(m==0 || contadorMarcas[m]>maximo)
            {
                maximo=contadorMarcas[m];
            }
        }
        printf("\nLa(s) marca(s) mas elegida(s) (%d veces) por los clientes es/son: \n\n", maximo);
        for(int m=0; m<tamM; m++)
        {
            if(contadorMarcas[m]==maximo)
            {
                mostrarUnaMarca(listaM[m]);
            }
        }
        retorno =1;
    }
    return retorno;
}

//7.Pedir un auto y mostrar todos los trabajos que se le hicieron al mismo.
int mostrarTrabajosDeUnAuto(eAuto listaA[], int tamA, eMarca listaM[], int tamM, eColor listaC[], int tamC, eServicio listaS[], int tamS, eTrabajo listaT[], int tamT, eCliente listaCl[], int tamCl)
{
    int retorno = 0;
    if(listaA!=NULL && tamA>0 && listaM!=NULL && tamM>0 && listaC!=NULL && tamC>0 && listaS!=NULL && tamS>0 && listaT!=NULL && tamT>0 && listaCl!=NULL && tamCl>0)
    {
        int iC;
        int iM;
        int iA;
        int iS;
        int iCl;
        int flag=0;
        int idAuto;

        mostrarAutos(listaA,tamA, listaC,tamC, listaM,tamM, listaCl,tamCl);
        idAuto=getInt("Ingrese el id del auto: ", "El id ingresado es invalido. Ingrese el id del auto: ",100,109);
        iA=buscarAuto(listaA,tamA,idAuto);
        iM=buscarMarca(listaM,tamM,listaA[iA].idMarca);
        iC=buscarColor(listaC,tamC,listaA[iA].idColor);
        iCl=buscarCliente(listaCl,tamCl,listaA[iA].idCliente);
        printf("\nHa elegido el siguiente auto:\n");
        mostrarUnAuto(listaA[iA],listaC[iC],listaM[iM],listaCl[iCl]);
        printf(" \n\n");
        for(int t=0; t<tamT; t++)
        {
            if(strcmpi(listaT[t].patente,listaA[iA].patente)==0 && listaT[t].isEmpty==0)
            {
                iS = buscarServicio(listaS,tamS,listaT[t].idServicio);
                mostrarUnTrabajo(listaT[t],listaA[iA], listaS[iS]);
                flag=0;
            }
        }
        if(flag==0)
        {
            printf("\nNo se encontraron trabajos asociados a ese auto.\n");
            retorno = 0;
        }
        retorno =1;
    }
    return retorno;
}

//8.Pedir un auto e informar la suma de los importes que se le hicieron al mismo.
int mostrarSumaDeImportesDeUnAuto(eAuto listaA[], int tamA, eMarca listaM[], int tamM, eColor listaC[], int tamC, eServicio listaS[], int tamS, eTrabajo listaT[], int tamT, eCliente listaCl[], int tamCl)
{
    int retorno = 0;
    int iA;
    int iM;
    int iC;
    int iS;
    int iCl;
    int idAuto;
    float total = 0;
    if(listaA!=NULL && tamA>0 && listaM!=NULL && tamM>0 && listaC!=NULL && tamC>0 && listaS!=NULL && tamS>0 && listaT!=NULL && tamT>0 && listaCl!=NULL && tamCl>0)
    {
        mostrarAutos(listaA,tamA, listaC,tamC, listaM,tamM,listaCl,tamCl);
        idAuto=getInt("Ingrese el id del auto: ", "El id ingresado es invalido. Ingrese el id del auto: ",100,109);
        iA=buscarAuto(listaA,tamA,idAuto);
        iM=buscarMarca(listaM,tamM,listaA[iA].idMarca);
        iC=buscarColor(listaC,tamC,listaA[iA].idColor);
        iCl=buscarCliente(listaCl,tamCl,listaA[iA].idCliente);
        printf("\nHa elegido el siguiente auto:\n");
        mostrarUnAuto(listaA[iA],listaC[iC],listaM[iM],listaCl[iCl]);
        printf(" \n\n");

        for(int t=0; t<tamT; t++)
        {
            if(listaT[t].isEmpty==0 && strcmpi(listaT[t].patente,listaA[iA].patente)==0)
            {
                iS=buscarServicio(listaS,tamS,listaT[t].idServicio);
                total=total+(listaS[iS].precio);
            }
        }
        if(total==0)
        {
            printf("\nNo se realizaron trabajos sobre el auto elegido\n\n");
        }
        else
        {
            printf("\nEl monto total de los trabajos realizados sobre el auto patente %s es de %.2f\n",listaA[iA].patente, total);
        }

        retorno = 1;
    }
    return retorno;
}

