#include <stdio.h>
#include <stdlib.h>

#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;


#endif // FECHA_H_INCLUDED

/** \brief Permite cargar por pantalla los datos de una fecha
 *
 * \param fecha eFecha estructura donde se almacenan los datos
 * \return void
 *
 */
void getFecha(eFecha fecha);
