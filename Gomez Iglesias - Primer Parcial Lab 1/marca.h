#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Input.h"

#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;


#endif // MARCA_H_INCLUDED
/** \brief dado el id de una marca, permite buscar en un array de estructuras tipo eMarca el indice que coincida con el id dado
 *
 * \param lista[] eMarca array donde buscar el id
 * \param tam int tamaño del array
 * \param id int id a buscar
 * \return int 1 si ok, 0 si error
 *
 */
int buscarMarca(eMarca lista[], int tam, int id);

/** \brief imprime por pantalla el indice y descripcion de una marca
 *
 * \param unaMarca eMarca estructura tipo eMarca
 * \return void
 *
 */
void mostrarUnaMarca(eMarca unaMarca);

/** \brief muestra por pantalla un listado de la descripcion de cada marca con su id
 *
 * \param lista[] eMarca array de estructuras tipo eMarca
 * \param tam int tamaño del array
 * \return int 1 si ok, 0 si error
 *
 */
int mostrarMarcas(eMarca lista[], int tam);

/** \brief permite cargar la descripcion de una marca en un array char, dado su id
 *
 * \param id int id a buscar
 * \param lista[] eColor array donde buscar la marca
 * \param tam int tamaño del array
 * \param descripcion[] char array char donde guardar la descripcion
 * \return int 0 si error, 1 si ok
 *
 */
int cargarDescripcionMarca(int id, eMarca lista[], int tam, char descripcion[]);


