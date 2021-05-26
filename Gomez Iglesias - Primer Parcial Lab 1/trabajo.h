#include "fecha.h"
#include "auto.h"
#include "servicio.h"
#include "cliente.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    char patente[20];
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;


#endif // TRABAJO_H_INCLUDED

/** \brief inicializa en 1 la variable isEmpty
 *
 * \param lista[] eTrabajo array de estructuras del tipo eTrabajo
 * \param tamLista int tamaño del array
 * \return int 1 si ok, 0 si hubo error
 *
 */
int inicializarTrabajos(eTrabajo lista[], int tamLista);

/** \brief busca un indice apto para cargar un nuevo trabajo(isEmpty=1)
 *
 * \param lista[] eTrabajo array de estructuras del tipo eTrabajo
 * \param tamLista int tamaño del array
 * \return int -1 si no hay lugares libres. Si hay lugares libres devuelve el indice libre
 *
 */
int buscarLibreTrabajo(eTrabajo lista[], int tamLista);

/** \brief permite al usuario cargar los datos por pantalla en un array de estructuras tipo eTrabajo
 *
 * \param listaT[] eTrabajo array de estructuras tipo eTrabajo
 * \param tamT int
 * \param listaA[] eAuto array de estructuras tipo eAuto
 * \param tamA int
 * \param listaC[] eColor array de estructuras tipo eColor
 * \param tamC int
 * \param listaM[] eMarca array de estructuras tipo eMarca
 * \param tamM int
 * \param listaS[] eServicio array de estructuras tipo eServicio
 * \param tamS int
 * \param listaCl[] eCliente array de estructuras del tipo eCliente
 * \param tamCl int tamaño del array de estructuras del tipo eCliente
 * \param pNextIdTrabajo int* puntero a la direccion de memoria que guarda el siguiente idTrabajo disponible
 * \return int 1 si ok, 0 si hubo un problema
 *
 */
int altaTrabajo(eTrabajo listaT[], int tamT, eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eServicio listaS[], int tamS, eCliente listaCl[], int tamCl, int* pNextIdTrabajo);

/** \brief
 *
 * \param listaT[] eTrabajo
 * \param tamT int
 * \param listaA[] eAuto
 * \param tamA int
 * \param listaS[] eServicio
 * \param tamS int
 * \param idTrabajo int
 * \return int
 *
 */
int buscarTrabajo(eTrabajo listaT[], int tamT, eAuto listaA[], int tamA, eServicio listaS[], int tamS,int idTrabajo);

/** \brief imprime por pantalla un elemento del tipo eTrabajo, incluyendo la descripcion del servicio
 *
 * \param unTrabajo eTrabajo elemento estructura tipo eTrabajo
 * \param unAuto eAuto elemento estructura tipo eAuto
 * \param unServicio eServicio elemento estructura tipo eServicio
 * \return void
 *
 */
void mostrarUnTrabajo(eTrabajo unTrabajo, eAuto unAuto, eServicio unServicio);

/** \brief imprime un listado por pantalla de todos los elementos que no esten dados de baja de un array tipo eTrabajo
 *
 * \param listaT[] eTrabajo array de de estructuras del tipo eTrabajo, que sera la base para imprimir por pantalla
 * \param tamT int tamaño del array de estructuras tipo eTrabajo
 * \param listaA[] eAuto array de de estructuras del tipo eAuto. Permite relacionar la patente con el indice del auto.
 * \param tamA int tamaño del array de estructuras del tipo eAuto
 * \param listaS[] eServicio array de estructuras tipo eServicio. Permite relacionar el idServicio con su descripcion
 * \param tamS int tamaño del array de estructuras tipo eServicio
 * \return int devuelve 0 si hubo un problema o 1 si ok
 *
 */
int mostrarTrabajos(eTrabajo listaT[], int tamT, eAuto listaA[], int tamA, eServicio listaS[], int tamS);

