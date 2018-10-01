/*
 * Ejercicio1.cpp
 *
 *  Created on: 28 sep. 2018
 *      Author: eze_y
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

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

static bool Busca(RegistroGol *arreglo, RegistroGol *registro, unsigned char largo)
{
	int pivote = 0;
	if(arreglo == NULL)
	{
		//La referencia al arreglo donde buscar
		//Debe ser valida.
		//Si no lo es, se añade un elemento.
		return true;
	}

	pivote = largo/2;

	if(arreglo[pivote].fecha < registro->fecha)
	{
		if(pivote == 0)
		{
			return true;
		}
		return Busca(arreglo + (pivote + 1), registro, largo - pivote);
	} else if(arreglo[pivote].fecha > registro->fecha) {
		if(pivote == 0)
		{
			return true;
		}
		return Busca(arreglo, registro, pivote);
	} else {
		/* Ya existe */
		return false;
	}

	return false;
}

static bool BuscaEInserta(RegistroGol *arreglo, RegistroGol *registro, unsigned char largo)
{
	bool retorno = false;

	retorno = Busca(arreglo, registro, largo);

	if(retorno == true)
	{
		/* Copy element */
	}
}

/* Punto de entrada del programa */
int main(void)
{
	RegistroGol RegistroAInsertar;
	cout << "Entry point." << endl;


	memset((void *)&RegistroAInsertar, 0, sizeof(RegistroGol));
	RegistroAInsertar.fecha = 4;

	//10 elementos
	Goles = (RegistroGol *)malloc(sizeof(RegistroGol)*10);

	for(int i = 0, j = 0; i < 11; i++)
	{
		if(i+1 != 4) {
			Goles[j].fecha = i + 1;
			j++;
		}
	}

	if(BuscaEInserta(Goles, &RegistroAInsertar, 10))
	{
		cout << "Found" << endl;
	} else {
		cout << "Not found! :c" << endl;
	}

	system("PAUSE");
	return 0;
}



