#include "Fecha.h"
#include "Input.h"



void getFecha(eFecha fecha)
{
    fecha.dia=getInt("  Ingrese dia: ", "   Dia ingresado invalido. Ingrese dia: ",1,31);
    fecha.mes=getInt("  Ingrese mes: ", "   Mes ingresado invalido. Ingrese mes: ",1,12);
    fecha.anio=getInt(" Ingrese anio: ", "  Anio ingresado invalido. Ingrese anio: ",1999,2100);
}
