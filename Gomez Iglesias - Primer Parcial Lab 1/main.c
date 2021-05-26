//Npmbre: Gomez Iglesias, Emiliano
//Division 1A


#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "menu.h"
#include "auto.h"
#include "color.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
#include "datawarehouse.h"
#include "cliente.h"
#include "informes.h"

#define TAMA 10
#define TAMC 5
#define TAMM 5
#define TAMS 4
#define TAMT 10
#define TAMCL 5

int main()
{
    /*eAuto autos[TAMA]={{100,"AAA111",1000,5000,1989,0},
                        {101,"CAB321",1000,5000,1980,0},
                        {102,"ABC129",1002,5002,2015,0},
                        {103,"KIL789",1001,5002,2020,0},
                        {104,"AMI087",1001,5004,2012,0}};

    eColor colores[TAMC]={{5000,"NEGRO"},
                        {5001,"BLANCO"},
                        {5002,"GRIS"},
                        {5003,"ROJO"},
                        {5004,"AZUL"}};

    eMarca marcas[TAMM]={{1000,"Renault"},
                        {1001, "Fiat"},
                        {1002,"Ford"},
                        {1003, "Chevrolet"},
                        {1004, "Peugeot"}};

    eServicio servicios[TAMS] = {{20000,"Lavado", 250},
                                {20001, "Pulido", 300},
                                {20002, "Encerado", 400},
                                {20003, "Completo", 600}};

    eTrabajo trabajos[TAMT]={{30000,"AAA111",20001,{07,1,2021},0},
                            {30001,"CAB321",20002,{10,3,2021},0},
                            {30002,"KIL789",20000,{15,4,2021},0},
                            {30003,"AAA111",20002,{15,4,2021},0},
                            {30004,"CAB321",20001,{23,2,2021},0}};
*/

    eAuto autos[TAMA];
    eColor colores[TAMC];
    eMarca marcas[TAMM];
    eServicio servicios[TAMS];
    eTrabajo trabajos[TAMT];
    eCliente clientes[TAMCL];

    inicializarAutos(autos, TAMA);
    inicializarTrabajos(trabajos,TAMT);

    char salir = 'N';
    char salirInf='N';

    int nextIdAuto = 100;
    int nextIdTrabajo = 30000;

    hardcodearAutos(autos,5, &nextIdAuto);
    hardcodearColores(colores,TAMC);
    hardcodearMarcas(marcas,TAMM);
    hardcodearServicios(servicios,TAMS);
    hardcodearTrabajos(trabajos,5,&nextIdTrabajo);
    hardcodearClientes(clientes,TAMCL);

    do
    {
        system("cls");
        printf("\n");
        switch(menu())
        {
        case 'A':
            printf("ALTA AUTO\n");
            altaAuto(autos,TAMA,colores,TAMC,marcas,TAMM, clientes, TAMCL, &nextIdAuto);
            break;
        case 'B':
            printf("MODIFICAR AUTO\n");
            modificarAuto(autos,TAMA,colores,TAMC,marcas,TAMM,clientes, TAMCL);
            break;
        case 'C':
            printf("BAJA AUTO\n");
            bajaAuto(autos,TAMA,colores,TAMC,marcas,TAMM, clientes, TAMCL);
            break;
        case 'D':
            system("cls");
            printf("LISTAR AUTOS\n");
            ordenarAutosMarcaYPatente(autos,TAMA,marcas,TAMM);
            mostrarAutos(autos,TAMA,colores,TAMC,marcas,TAMM, clientes, TAMCL);
            break;
        case 'E':
            printf("LISTAR MARCAS\n");
            mostrarMarcas(marcas,TAMM);
            break;
        case 'F':
            printf("LISTAR COLORES\n");
            mostrarColores(colores,TAMC);
            break;
        case 'G':
            printf("LISTAR SERVICIOS\n");
            mostrarServicios(servicios,TAMS);
            break;
        case 'H':
            printf("ALTA TRABAJO\n");
            altaTrabajo(trabajos,TAMT,autos,TAMA,colores,TAMC,marcas,TAMM,servicios,TAMS,clientes, TAMCL, &nextIdTrabajo);
            break;
        case 'I':
            printf("LISTAR TRABAJOS\n");
            mostrarTrabajos(trabajos,TAMT,autos,TAMA,servicios,TAMS);
            break;
        case 'J':
            printf("INFORMES\n\n");
            do
            {
                switch(menuInformes())
                {
                case 1:
                    printf("\nMOSTRAR AUTOS DE UN COLOR\n");
                    mostrarAutosDeUnColor(autos,TAMA,colores,TAMC,marcas,TAMM,clientes,TAMCL);
                    break;
                case 2:
                    printf("\nMOSTRAR AUTOS DE UNA MARCA\n");
                    mostrarAutosDeUnaMarca(autos,TAMA,colores,TAMC,marcas,TAMM,clientes,TAMCL);
                    break;
                case 3:
                    printf("\nMOSTRAR AUTOS MAS VIEJOS\n");
                    mostrarAutoViejo(autos,TAMA,colores,TAMC,marcas,TAMM,clientes,TAMCL);
                    break;
                case 4:
                    printf("\nMOSTRAR AUTOS SEPARADOS POR MARCA\n");
                    mostrarAutosSeparadosPorMarca(autos,TAMA,colores,TAMC,marcas,TAMM,clientes,TAMCL);
                    break;
                case 5:
                    printf("\nCONTAR AUTOS POR COLOR Y POR MARCA\n");
                    contarAutosPorColorYPorMarca(autos,TAMA,colores,TAMC,marcas,TAMM);
                    break;
                case 6:
                    printf("\nMOSTRAR MARCAS MAS ELEGIDAS\n");
                    mostrarMarcasMasElegidas(autos,TAMA,marcas,TAMM);
                    break;
                case 7:
                    printf("\nMOSTRAR LOS TRABAJO DE UN AUTO\n");
                    mostrarTrabajosDeUnAuto(autos,TAMA,marcas,TAMM,colores,TAMC,servicios,TAMS,trabajos,TAMT,clientes,TAMCL);
                    break;
                case 8:
                    printf("\nMOSTRAR LA SUMA DE IMPORTES DE UN AUTO\n");
                    mostrarSumaDeImportesDeUnAuto(autos,TAMA,marcas,TAMM,colores,TAMC,servicios,TAMS,trabajos,TAMT,clientes,TAMCL);
                    break;
                case 9:
                    printf("Opcion 9\n");
                    break;
                case 10:
                    printf("Opcion 10\n");
                    break;
                case 11:
                    salirInf = getUpperChar("Confirma salida? S/N: ");
                    break;
                }
                system("pause");
            }while (salirInf == 'N');
        case 'K':
            salir = getUpperChar("Confirma salida? S/N: ");
            break;
        default:
            printf("\n\nLa opcion ingresada es invalida.\n");
        }
        system("pause");
    }while(salir == 'N');
}
