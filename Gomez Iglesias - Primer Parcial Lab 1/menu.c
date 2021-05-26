#include "menu.h"
#include "Input.h"




char menu(void)
{
    char opcion;
    system("cls");
    printf("    ****ABM Autos***\n\n");
    printf("A. ALTA AUTO\n");
    printf("B. MODIFICAR AUTO\n");
    printf("C. BAJA AUTO\n");
    printf("D. LISTAR AUTOS\n");
    printf("E. LISTAR MARCAS\n");
    printf("F. LISTAR COLORES\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. ALTA TRABAJO\n");
    printf("I. LISTAR TRABAJOS\n");
    printf("J. INFORMES\n");
    printf("K. SALIR");
    printf("\n\n");
    opcion = getUpperChar("Ingrese la opcion deseada: ");
    return opcion;
}


char menuModificar(void)
{
    char opcion;
    system("cls");
    printf("    ****Modificar Autos***\n\n");
    printf("A. Patente\n");
    printf("B. Marca\n");
    printf("C. Color\n");
    printf("D. Modelo\n");
    printf("E. Cliente\n");
    printf("F. SALIR");
    printf("\n\n");
    opcion = getUpperChar("Ingrese la opcion deseada: ");
    return opcion;
}


int menuInformes(void)
{
    int opcion;
    system("cls");
    printf("    ****INFORMES***\n\n");
    printf("1. MOSTRAR AUTOS DE UN COLOR \n");
    printf("2. MOSTRAR AUTOS DE UNA MARCA\n");
    printf("3. MOSTRAR EL/LOS AUTOS MAS VIEJOS\n");
    printf("4. MOSTRAR AUTOS SEPARADOS POR MARCA\n");
    printf("5. CONTAR AUTOS POR COLOR Y POR MARCA\n");
    printf("6. MOSTRAR MARCAS MAS ELEGIDAS\n");
    printf("7. MOSTRAR TRABAJOS DE UN AUTO\n");
    printf("8. MOSTRAR SUMA DE IMPORTES DE UN AUTO\n");
    printf("9. \n");
    printf("10. \n");
    printf("11. SALIR\n");
    printf("\n\n");
    opcion = getInt("Ingrese el numero de informe deseado: ", "La opcion ingresada es invalida. Ingrese la opcion deseada: ",1,11);
    return opcion;
}
