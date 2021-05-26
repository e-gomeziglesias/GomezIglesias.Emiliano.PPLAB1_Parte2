#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "menu.h"
#include "auto.h"
#include "color.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


/** \brief Luego de que el usuario elija un color y una marca, se muestran por pantalla todos los autos que cumplen con ese filtro
 *
 * \param listaA[] eAuto listado de autos
 * \param tamA int tamaño del listado
 * \param listaC[] eColor listado de colores
 * \param tamC int tamaño del listado de colores
 * \param listaM[] eMarca listado de marcas
 * \param tamM int tamaño del listado de marcas
 * \param listaCl[] eCliente listado de clientes
 * \param tamCl int tamaño del listado de clientes
 * \return int 0 si error, 1 si ok
 *
 */
int mostrarAutosDeUnColor(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl);

/** \brief Seleccionada una marca por el usuario, se listan los autos de esa marca
 *
 * \param listaA[] eAuto listado de autos
 * \param tamA int tamaño del listado
 * \param listaC[] eColor listado de colores
 * \param tamC int tamaño del listado de colores
 * \param listaM[] eMarca listado de marcas
 * \param tamM int tamaño del listado de marcas
 * \param listaCl[] eCliente listado de clientes
 * \param tamCl int tamaño del listado de clientes
 * \return int 0 si error, 1 si ok
 *
 */
int mostrarAutosDeUnaMarca(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl);

/** \brief Busca, dentro de los autos dados de alta, el modelo mas viejo y lista todos los autos que tengan este modelo
 *
 * \param listaA[] eAuto listado de autos
 * \param tamA int tamaño del listado
 * \param listaC[] eColor listado de colores
 * \param tamC int tamaño del listado de colores
 * \param listaM[] eMarca listado de marcas
 * \param tamM int tamaño del listado de marcas
 * \param listaCl[] eCliente listado de clientes
 * \param tamCl int tamaño del listado de clientes
 * \return int 0 si error, 1 si ok
 *
 */
int mostrarAutoViejo(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl);


/** \brief muestra un listado de autos, separados por cada marca
 *
 * \param listaA[] eAuto listado de autos
 * \param tamA int tamaño del listado
 * \param listaC[] eColor listado de colores
 * \param tamC int tamaño del listado de colores
 * \param listaM[] eMarca listado de marcas
 * \param tamM int tamaño del listado de marcas
 * \param listaCl[] eCliente listado de clientes
 * \param tamCl int tamaño del listado de clientes
 * \return int 0 si error, 1 si ok
 *
 */
int mostrarAutosSeparadosPorMarca(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, eCliente listaCl[], int tamCl);


/** \brief Luego que el usuario elija un color y una marca, se cuentan cuantos autos cumplen con este filtro y se muestra el total
 *
 * \param listaA[] eAuto listado de autos
 * \param tamA int tamaño del listado de autos
 * \param listaC[] eColor listado de colores
 * \param tamC int tamaño del listado de colores
 * \param listaM[] eMarca listado de marcas
 * \param tamM int tamaño del listado de marcas
 * \return int 0 si error, 1 si ok
 *
 */
int contarAutosPorColorYPorMarca(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM);

/** \brief Cuenta la cantidad de veces que aparece una marca, busca la que mas se repite y muestra aquellas marcas que se hayan repetido esa cantidad de veces(las mas elegidas)
 *
 * \param listaA[] eAuto listado de autos
 * \param tamA int tamaño del listado de autos
 * \param listaM[] eMarca listado de marcas
 * \param tamM int tamaño del listado de marcas
 * \return int 0 si error, 1 si ok
 *
 */
int mostrarMarcasMasElegidas(eAuto listaA[],int tamA, eMarca listaM[], int tamM);


/** \brief Luego que el usuario elija un auto, se muestran los trabajos asociados al mismo.
 *
 * \param listaA[] eAuto lista de autos
 * \param tamA int tamaño de lista de autos
 * \param listaM[] eMarca lista de marcas
 * \param tamM int tamaño de lista de marcas
 * \param listaC[] eColor lista de colores
 * \param tamC int tamaño de la lista de colores
 * \param listaS[] eServicio lista de servicios
 * \param tamS int tamaño de la lista de servicios
 * \param listaT[] eTrabajo lista de trabajos
 * \param tamT int tamaño de la lista de trabajos
 * \param listaCl[] eCliente lsita de clientes
 * \param tamCl int tamaño de la lista de clientes
 * \return int 0 si error, 1 si ok
 *
 */
int mostrarTrabajosDeUnAuto(eAuto listaA[], int tamA, eMarca listaM[], int tamM, eColor listaC[], int tamC, eServicio listaS[], int tamS, eTrabajo listaT[], int tamT, eCliente listaCl[], int tamCl);

/** \brief Luego que el usuario elij un auto, se muestra el total de importes adjudicados al auto elegido
 *
 * \param listaA[] eAuto
 * \param tamA int
 * \param listaM[] eMarca
 * \param tamM int
 * \param listaC[] eColor
 * \param tamC int
 * \param listaS[] eServicio
 * \param tamS int
 * \param listaT[] eTrabajo
 * \param tamT int
 * \param listaCl[] eCliente
 * \param tamCl int
 * \return int
 *
 */
int mostrarSumaDeImportesDeUnAuto(eAuto listaA[], int tamA, eMarca listaM[], int tamM, eColor listaC[], int tamC, eServicio listaS[], int tamS, eTrabajo listaT[], int tamT, eCliente listaCl[], int tamCl);
