#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Input.h"

#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED
/** \brief dado el id de un color, permite buscar en un array de estructuras tipo eColor el indice que coincida con el id dado
 *
 * \param lista[] eColor array donde buscar el id
 * \param tam int tamaño del array
 * \param id int id a buscar
 * \return int 1 si ok, 0 si error
 *
 */
int buscarColor(eColor lista[], int tam, int id);
/** \brief imprime por pantalla el indice y descripcion de un color
 *
 * \param unColor eColor elemento estructura tipo eColor
 * \return void
 *
 */
void mostrarUnColor(eColor unColor);
/** \brief muestra por pantalla un listado de la descripcion de cada color con su id
 *
 * \param lista[] eColor array de estructuras tipo eColor
 * \param tam int tamaño del array
 * \return int 1 si ok, 0 si error
 *
 */
int mostrarColores(eColor lista[], int tam);

/** \brief permite cargar la descripcion de un color en un array char, dado su id
 *
 * \param id int id a buscar
 * \param lista[] eColor array donde buscar el color
 * \param tam int tamaño del array
 * \param descripcion[] char array char donde guardar la descripcion
 * \return int 0 si error, 1 si ok
 *
 */
int cargarDescripcionColor(int id, eColor lista[], int tam, char descripcion[]);
