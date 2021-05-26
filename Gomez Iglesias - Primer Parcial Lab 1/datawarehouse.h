#include <stdio.h>
#include <stdlib.h>
#include "auto.h"
#include "color.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"


#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED



#endif // DATAWAREHOUSE_H_INCLUDED


/** \brief hardcodea los datos de autos en un array de estructuras de autos
 *
 * \param lista[] eAuto array de autos
 * \param tam int tamaño del array
 * \param nextId int* puntero al siguiente id
 * \return int 0 si error, 1 si ok
 *
 */
int hardcodearAutos(eAuto lista[],int tam, int* nextId);

/** \brief hardcodea los datos de servicios en un array de estructuras de servicios
 *
 * \param lista[] eServicio array de servicios
 * \param tam int tamaño del array
 * \return int 0 si errror 1 si ok
 *
 */
int hardcodearServicios(eServicio lista[],int tam);

/** \brief hardcodea los datos de marcas en un array de estructuras de marcas
 *
 * \param lista[] eMarca array de marcas
 * \param tam int tamaaño del array
 * \return int 0 s9 error, 1 si ok
 *
 */
int hardcodearMarcas(eMarca lista[],int tam);


/** \brief hardcodea los datos de colores en un array de estructuras de colores
 *
 * \param lista[] eColor array de colores
 * \param tam int tamaño del array
 * \return int 0 si error 1 si error
 *
 */
int hardcodearColores(eColor lista[],int tam);

/** \brief hardcodea los datos de trabajos en un array de estructuras de trabajos
 *
 * \param lista[] eTrabajo array de estructuras de traabajos
 * \param tam int tamaño del array
 * \param nextId int* punteor al siguiente id dispobile para cargar
 * \return int 0 si error 1 si ok
 *
 */
int hardcodearTrabajos(eTrabajo lista[],int tam, int* nextId);

/** \brief hardcodea los datos de clientes en un array de estructuras de clientes
 *
 * \param lista[] eCliente array de clientes
 * \param tam int tamaño del array
 * \return int 0 si error 1 si ok
 *
 */
int hardcodearClientes(eCliente lista[],int tam);
