#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Input.h"

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
}eCliente;


#endif // CLIENTE_H_INCLUDED


/** \brief busca el indice de un cliente en un array dado su id
 *
 * \param lista[] eCliente array donde buscar al cliente
 * \param tam int tamaño del array
 * \param id int id a buscar
 * \return int -1 si error, el indice si ok
 *
 */
int buscarCliente(eCliente lista[], int tam, int id);

/** \brief imprime por pantalla el indice, nombre y sexo de un cliente
 *
 * \param unCliente eCliente elemento estructura tipo eCliente
 * \return void
 *
 */
void mostrarUnCliente(eCliente unCliente);

/** \brief muestra por pantalla un listado de los nombres de cada cliente con su id y su sexo
 *
 * \param lista[] eCliente array de estructuras tipo eCliente
 * \param tam int tamaño del array
 * \return int 1 si ok, 0 si error
 *
 */
int mostrarClientes(eCliente lista[], int tam);

/** \brief permite cargar el nombre de un cliente en un array char, dado su id
 *
 * \param id int id a buscar
 * \param lista[] eCliente array donde buscar el cliente
 * \param tam int tamaño del array
 * \param descripcion[] char array char donde guardar el nombre del cliente
 * \return int 0 si error, 1 si ok
 *
 */
int cargarDescripcionCliente(int id, eCliente lista[], int tam, char descripcion[]);
