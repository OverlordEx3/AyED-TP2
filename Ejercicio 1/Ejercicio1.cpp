/*
 * Ejercicio1.cpp
 *
 *  Created on: 28 sep. 2018
 *      Author: eze_y
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

/* Incluyo la definicion de la estructura de gol */
#include "DefinicionEstructura.h"

using namespace std;

/* Registro global de goles */
RegistroGol *Goles;

static bool CopiarRegistro(RegistroGol *destino, RegistroGol *origen)
{
	if(destino == NULL || origen == NULL)
	{
		return false;
	}

	destino->codigoDeEquipo = origen->codigoDeEquipo;
	destino->fecha = origen->fecha;
	destino->idGol = origen->idGol;
	destino->idPartido = origen->idPartido;
	strcpy(destino->nombreDelJugador, origen->nombreDelJugador);

	return true;
}

/* Punto de entrada del programa */
int main(void)
{

	return 0;
}



