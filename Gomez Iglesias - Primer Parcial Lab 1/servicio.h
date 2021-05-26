#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Input.h"

#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief imprime por pantalla el indice y descripcion de un servicio
 *
 * \param unServicio eServicio estructura tipo eServicio
 * \return void
 *
 */
void mostrarUnServicio(eServicio unServicio);

/** \brief muestra por pantalla un listado de la descripcion de cada servicio con su id
 *
 * \param lista[] eServicio array de estructuras tipo eServicio
 * \param tam int tamaño del array
 * \return int 1 si ok, 0 si error
 *
 */
int mostrarServicios(eServicio lista[], int tam);

/** \brief dado el id de un servicio, permite buscar en un array de estructuras tipo eServicio el indice que coincida con el id dado
 *
 * \param lista[] eServicio array donde buscar el id
 * \param tam int tamaño del array
 * \param id int id a buscar
 * \return int 1 si ok, 0 si error
 *
 */
int buscarServicio(eServicio lista[], int tam, int id);

/** \brief permite cargar la descripcion de un servicio en un array char, dado su id
 *
 * \param id int id a buscar
 * \param lista[] eServicio array donde buscar el servicio
 * \param tam int tamaño del array
 * \param descripcion[] char array char donde guardar la descripcion
 * \return int 0 si error, 1 si ok
 *
 */
int cargarDescripcionServicio(int id, eServicio lista[], int tam, char descripcion[]);
