#include <stdlib.h>
#include <stdio.h>
#include "color.h"
#include "marca.h"
#include "cliente.h"
#include "Input.h"
#include "menu.h"

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{
    int id;
    char patente[20];
    int idMarca;
    int idColor;
    int modelo;
    int idCliente;
    int isEmpty;
}eAuto;

#endif // AUTO_H_INCLUDED

/** \brief inicializa en 1 la variable isEmpty
 *
 * \param lista[] eAuto array de estructuras del tipo eAuto
 * \param tamLista int tamaño del array
 * \return int 1 si ok, 0 si hubo error
 *
 */
int inicializarAutos(eAuto lista[], int tamLista);
/** \brief busca un indice apto para cargar un nuevo auto(isEmpty=1)
 *
 * \param lista[] eAuto array de estructuras del tipo eAuto
 * \param tamLista int tamaño del array
 * \return int -1 si no hay lugares libres. Si hay lugares libres devuelve el indice libre
 *
 */
int buscarLibreAuto(eAuto lista[], int tamLista);
/** \brief
 *
 * \param listaA[] eAuto permite al usuario cargar los datos de una estructura tipo eAuto
 * \param tamA int tamaño del array de estructuras del tipo eAuto
 * \param listaC[] eColor array de estructuras del tipo eColor
 * \param tamC int tamaño del array de estructuras del tipo eColor
 * \param listaM[] eMarca array de estructuras del tipo eMarca
 * \param tamM int tamaño del array de estructuras del tipo eMarca
 * \param listaCl[] eCliente array de estructuras del tipo eCliente
 * \param tamCl int tamaño del array de estructuras del tipo eCliente
 * \param pIdAuto int* puntero a la direccion de memoria del siguiente id de auto disponible
 * \return int
 *
 */
int altaAuto(eAuto listaA[], int tamA,eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl, int* pIdAuto);

/** \brief imprime por pantalla los datos de un elemento tipo eAuto y de las estructuras que con este se relacionan
 *
 * \param unAuto eAuto elemento tipo eAuto
 * \param unColor eColor elemento tipo eColor
 * \param unaMarca eMarca elemento tipo eMarca
 * \param unCliente eCliente elemento tipo eCliente
 * \return void
 *
 */
void mostrarUnAuto(eAuto unAuto, eColor unColor, eMarca unaMarca, eCliente unCliente);

/** \brief dado un array de estructuras de tipo eAuto, imprime por pantalla toda la informacion relacionada a la misma
 *
 * \param listaA[] eAuto array de estructuras tipo eAuto
 * \param tamA int cantidad de elementos de la estructura eAuto
 * \param listaC[] eColor array de estructuras tipo eColor
 * \param tamC int cantidad de elementos de la estructura eColor
 * \param listaM[] eMarca array de estructuras tipo eMarca
 * \param tamM int cantidad de elementos de la estructura eMarca
 * \param listaCl[] eCliente array de estructuras del tipo eCliente
 * \param tamCl int tamaño del array de estructuras del tipo eCliente
 * \return int 1 si ok, 0 si hubo algun problema
 *
 */
int mostrarAutos(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl);

/** \brief busca, dentro de un array de estructuras de tipo eAuto, el indice del auto que coincida con el id dado
 *
 * \param lista[] eAuto array donde se buscara el indice
 * \param tam int tamaño del array
 * \param id int id a buscar en el array
 * \return int -1 si no lo encontro o el numero de indice en caso contrario
 *
 */
int buscarAuto(eAuto lista[], int tam, int id);

/** \brief permite la baja logica de un elemento de un array tipo eAuto
 *
 * \param listaA[] eAuto array de estructuras del tipo eAuto
 * \param tamA int tamaño del array de autos
 * \param listaC[] eColor array de estructuras del tipo eColor
 * \param tamC int tamaño del array de estructuras del tipo eColor
 * \param listaM[] eMarca array de estructuras del tipo eMarca
 * \param tamM int tamaño del array de estructuras del tipo eMarca
 * \param listaCl[] eCliente array de estructuras del tipo eCliente
 * \param tamCl int tamaño del array de estructuras del tipo eCliente
 * \return int 0 si hubo error, 1 si ok
 *
 */
int bajaAuto(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl);

/** \brief permite modificar distintas variables de un elemento dentro de una estructura tipo eAuto, mediante un submenu
 *
 * \param listaA[] eAuto array de estructuras tipo eAuto
 * \param tamA int tamaño del array de estructuras tipo eAuto
 * \param listaC[] eColor array de estructuras tipo eColor
 * \param tamC int tamaño del array de estructuras tipo eColor
 * \param listaM[] eMarca array de estructuras tipo eMarca
 * \param tamM int tamaño del array de estructuras tipo eMarca
 * \param listaCl[] eCliente array de estructuras del tipo eCliente
 * \param tamCl int tamaño del array de estructuras del tipo eCliente
 * \return int 0 si hubo un problema, 1 si se pudo realizar la modificacion
 *
 */
int modificarAuto(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl);
/** \brief ordena un array de estructuras tipo eAuto por marca ascendente y, luego, por patente ascendente
 *
 * \param listaA[] eAuto array a  ordenar
 * \param tamA int tamaño del array
 * \param listaM[] eMarca array de marcas
 * \param tamM int tamaño del array de marcas
 * \return int 0 si no se pudo ordenar, 1 si se ordeno exitosamente
 *
 */
int ordenarAutosMarcaYPatente(eAuto listaA[], int tamA, eMarca listaM[], int tamM);
/** \brief dada la patente de un auto, permite buscar el indice del mismo en un array de estructuras tipo eAuto
 *
 * \param listaA[] eAuto array de estructuras tipo eAuto
 * \param tamA int tamaño del array de estructuras tipo eAuto
 * \param patente[] char cadena donde se indica la patente del auto
 * \param tamP int tamaño de la cadena
 * \return int -1 si no se encuentra la patente o sino el indice del auto que coincide con la patente
 *
 */
int buscarIndiceAutoPorPatente(eAuto listaA[], int tamA, char patente[], int tamP);
