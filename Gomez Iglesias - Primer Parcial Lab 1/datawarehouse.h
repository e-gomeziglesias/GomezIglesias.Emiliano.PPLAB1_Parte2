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


int hardcodearAutos(eAuto lista[],int tam, int* nextId);
int hardcodearServicios(eServicio lista[],int tam);
int hardcodearMarcas(eMarca lista[],int tam);
int hardcodearColores(eColor lista[],int tam);
int hardcodearTrabajos(eTrabajo lista[],int tam, int* nextId);
int hardcodearClientes(eCliente lista[],int tam);
