#include "auto.h"



int inicializarAutos(eAuto lista[], int tamLista)
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


int buscarLibreAuto(eAuto lista[], int tamLista)
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


int altaAuto(eAuto listaA[], int tamA,eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl, int* pIdAuto)
{
    system("cls");
    int retorno = 0;
    int indice;
    int iC;
    int iM;
    int iCl;
    char continuar = 'S';
    if(listaA != NULL && tamA>0 && listaC != NULL && tamC>0 && listaM!=NULL && tamM>0 && listaCl!=NULL && tamCl>0)
    {
        indice=buscarLibreAuto(listaA,tamA);
        eAuto auxLista;
        if (indice==-1)
        {
            printf("No hay lugares disponibles\n\n");
        }
        else
        {
            do
            {
                auxLista=listaA[indice];
                auxLista.id = (*pIdAuto);
                printf("\nId asignado: %d\n", auxLista.id);
                //patente
                getStringFull(auxLista.patente,"Ingrese la patente: ","Patente ingresada invalida. Ingrese una patente valida: ",20);
                //marca
                mostrarMarcas(listaM,tamM);
                printf("\nIngreso:\n\n");
                auxLista.idMarca = getInt("Ingrese el id de la marca: ", "El id ingresado es invalido. Ingrese el id: ",1000,1004);
                iM = buscarMarca(listaM,tamM, auxLista.idMarca);
                printf("\nIngreso:\n\n");
                mostrarUnaMarca(listaM[iM]);
                //color
                mostrarColores(listaC,tamC);
                auxLista.idColor = getInt("Ingrese el id del color: ", "El id ingresado es invalido. Ingrese el id: ",5000,5004);
                iC = buscarColor(listaC,tamC,auxLista.idColor);
                printf("\nIngreso:\n\n");
                mostrarUnColor(listaC[iC]);
                //modelo
                auxLista.modelo=getInt("Ingrese modelo(anio) del auto: ","El modelo ingresado es invalido. Ingrese modelo: ",1970,2021);
                auxLista.isEmpty = 0;

                //cliente
                mostrarClientes(listaCl,tamCl);
                auxLista.idCliente = getInt("Ingrese el id del cliente: ", "El id ingresado es invalido. Ingrese el id: ",1,5);
                iCl=buscarCliente(listaCl,tamCl,auxLista.idCliente);
                printf("\nIngreso:\n\n");
                mostrarUnCliente(listaCl[iCl]);

                listaA[indice] = auxLista;
                (*pIdAuto)=(*pIdAuto)+1;
                retorno = 1;
                continuar = getUpperChar("\nDesea dar de alta otro auto? (S/N): ");
            }while(continuar=='S');
        }
    }
    return retorno;
}


void mostrarUnAuto(eAuto unAuto, eColor unColor, eMarca unaMarca, eCliente unCliente)
{
    printf("%d      %-10s        %-10s        %-10s        %-d          %-10s\n", unAuto.id, unAuto.patente, unaMarca.descripcion, unColor.nombreColor, unAuto.modelo, unCliente.nombre);
}


int mostrarAutos(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl)
{
    system("cls");
    int retorno = 0;
    int flagUnoCargado = 0;
    int iC;
    int iM;
    int iCl;

    if(listaA != NULL && tamA > 0 && listaC != NULL && tamC > 0 &&  listaM!= NULL && tamM > 0 && listaCl !=NULL && tamCl>0)
    {
        printf("        Listado de Autos\n\n");
        printf("ID      Patente            Marca             Color              Modelo          Cliente\n\n");

        for(int i=0; i<tamA; i++)
        {
            if(!listaA[i].isEmpty)
            {
                iC=buscarColor(listaC,tamC,listaA[i].idColor);
                iM=buscarMarca(listaM,tamM,listaA[i].idMarca);
                iCl=buscarCliente(listaCl,tamCl,listaA[i].idCliente);
                mostrarUnAuto(listaA[i],listaC[iC],listaM[iM],listaCl[iCl]);
                flagUnoCargado = 1;
            }
        }
        if(flagUnoCargado == 0)
        {
            printf("No hay autos para mostrar. \n\n");
        }
        printf("\n\n\n");
        retorno = 1;
    }
    return retorno;
}


int buscarAuto(eAuto lista[], int tam, int id)
{
    int retorno = -1;
    if(lista != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if((lista[i].isEmpty==0) &&(lista[i].id==id))
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int bajaAuto(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl)
{
    system("cls");
    int retorno=0;
    int iA;
    int iC;
    int iM;
    int iCl;
    if(listaA != NULL && tamA > 0 && listaC != NULL && tamC > 0 &&  listaM!= NULL && tamM > 0 && listaCl != NULL && tamCl>0)
    {
        int id;
        char confirmar = 'N';
        mostrarAutos(listaA,tamA,listaC, tamC, listaM, tamM, listaCl, tamCl);
        id = getInt("Ingrese ID del auto a borrar: ", "El ID ingresado es invalido. Ingrese ID: ",100, 1000);
        iA = buscarAuto(listaA,tamA,id);
        iC= buscarColor(listaC,tamC,listaA[iA].idColor);
        iM= buscarMarca(listaM,tamM,listaA[iA].idMarca);
        iCl=buscarCliente(listaCl,tamCl,listaA[iA].idCliente);
        if(iA != -1)
        {
            printf("\n\n\n");
            mostrarUnAuto(listaA[iA],listaC[iC],listaM[iM],listaCl[iCl]);
            confirmar = getUpperChar("\nEstas por dar de baja el auto. Continuar? (S/N): ");
            if(confirmar=='S')
            {
                listaA[iA].isEmpty=1;
                printf("\nBaja exitosa\n");
                retorno = 1;
            }
            else
            {
                printf("\nLa baja se cancelo por el usuario.\n");
            }
        }
    }

    return retorno;
}


int modificarAuto(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl)
{
    system("cls");
    int retorno=0;
    int id;
    int iA;
    int iC;
    int iM;
    int iCl;
    char confirmar = 'N';
    char salir = 'N';
    eAuto auxLista;
    if(listaA!=NULL && tamA >0 && listaC!=NULL && tamC >0 && listaM !=NULL && tamM >=0 && listaCl!=NULL && tamCl>0)
    {
        mostrarAutos(listaA,tamA,listaC,tamC,listaM,tamM,listaCl,tamCl);
        id = getInt("Ingrese ID del auto a modificar: ", "El ID ingresado es invalido. Ingrese ID: ",100, 1000);
        iA = buscarAuto(listaA,tamA,id);
        iC = buscarColor(listaC,tamC,listaA[iA].idColor);
        iM = buscarMarca(listaM, tamM, listaA[iA].idMarca);
        iCl=buscarCliente(listaCl,tamCl,listaA[iA].idCliente);

        auxLista = listaA[iA];
        if(iA != -1)
        {
            printf("\n\n\n");
            mostrarUnAuto(auxLista,listaC[iC],listaM[iM],listaCl[iCl]);
            confirmar = getUpperChar("\nEstas por modificar el auto. Continuar? (S/N): ");
            system("cls");
            if(confirmar=='S')
            {
                do
                {
                    printf("\n\n");
                    mostrarUnAuto(auxLista,listaC[iC],listaM[iM],listaCl[iCl]);
                    switch(menuModificar())
                    {
                    case 'A':
                        printf("\nModificar patente\n\n");
                        getStringFull(auxLista.patente,"Ingrese la patente: ","Patente ingresada invalida. Ingrese una patente valida: ",20);
                        break;
                    case 'B':
                        printf("\nModificar Marca\n\n");
                        mostrarMarcas(listaM,tamM);
                        printf("\nIngreso:\n\n");
                        auxLista.idMarca = getInt("Ingrese el id de la marca: ", "El id ingresado es invalido. Ingrese el id: ",1000,1004);
                        iM = buscarMarca(listaM,tamM, auxLista.idMarca);
                        mostrarUnaMarca(listaM[iM]);
                        break;
                    case 'C':
                        printf("\nModificar Color\n\n");
                        mostrarColores(listaC,tamC);
                        printf("\nIngreso:\n\n");
                        auxLista.idColor = getInt("Ingrese el id del color: ", "El id ingresado es invalido. Ingrese el id: ",5000,5004);
                        iC = buscarColor(listaC,tamC,auxLista.idColor);
                        mostrarUnColor(listaC[iC]);
                        break;
                    case 'D':
                        printf("\nModificar Modelo\n\n");
                        //modelo
                        auxLista.modelo=getInt("Ingrese modelo(anio) del auto: ","El modelo ingresado es invalido. Ingrese modelo: ",1970,2021);
                        break;
                    case 'E':
                        printf("\nModificar cliente\n\n");
                        mostrarClientes(listaCl,tamCl);
                        auxLista.idCliente = getInt("Ingrese el id del cliente: ", "El id ingresado es invalido. Ingrese el id: ",1,5);
                        iCl=buscarCliente(listaCl,tamCl,auxLista.idCliente);
                        printf("\nIngreso:\n\n");
                        mostrarUnCliente(listaCl[iCl]);
                    case 'F':
                        printf("\nSalir menu modificar empleado\n\n");
                        salir = getUpperChar("\nDesea salir del menu modificar? (S/N): ");
                        break;
                    }
                }while (salir == 'N');
                printf("\n\n");
                listaA[iA]=auxLista;
                mostrarUnAuto(auxLista,listaC[iC],listaM[iM],listaCl[iCl]);
                printf("\nModificacion exitosa\n");
                retorno = 1;
            }
            else
            {
                printf("\nSe cancelo modificacion por el usuario.\n");
            }
        }
        else
        {
            printf("\n\nNo hay autos registrados bajo ese id.\n\n\n");
        }
    }
    return retorno;
}


int ordenarAutosMarcaYPatente(eAuto listaA[], int tamA, eMarca listaM[], int tamM)
{
    int retorno = 0;
    eAuto auxLista;
    char auxMarcaI[20];
    char auxMarcaJ[20];
    if(listaA!=NULL && tamA>0 && listaM!=NULL && tamM>0)
    {
        for (int i=0; i<tamA-1; i++)
        {
            for(int j=i+1; j<tamA; j++)
            {
                cargarDescripcionMarca(listaA[i].idMarca,listaM,tamM,auxMarcaI);
                cargarDescripcionMarca(listaA[j].idMarca,listaM,tamM,auxMarcaJ);
                if(strcmpi(auxMarcaI,auxMarcaJ)>0)
                {
                    auxLista=listaA[i];
                    listaA[i]=listaA[j];
                    listaA[j]=auxLista;
                }
                else if((strcmpi(auxMarcaI,auxMarcaJ)==0)&&(strcmpi(listaA[i].patente,listaA[j].patente)>0))
                {
                    auxLista=listaA[i];
                    listaA[i]=listaA[j];
                    listaA[j]=auxLista;
                }
            }
        }
        retorno = 1;
    }
    return retorno;
}


int buscarIndiceAutoPorPatente(eAuto listaA[], int tamA, char patente[], int tamP)
{
    int retorno=-1;
    if(listaA!=NULL && tamA>0 && patente!=NULL && tamP>0)
    {
        for (int i=0; i<tamA; i++)
        {
            if (strcmpi(patente,listaA[i].patente)==0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
