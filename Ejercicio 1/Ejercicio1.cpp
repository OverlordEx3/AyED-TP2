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
#include <random>
#include <time.h>

/* Incluyo la definicion de la estructura de gol */
#include "DefinicionEstructura.h"

using namespace std;

typedef struct nodoGol{
	RegistroGol gol;
	struct nodoGol *siguiente;
	struct nodoGol *anterior;
}NodoGol;

/* Registro global de goles */
NodoGol *Goles;

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

static void Inserta(NodoGol **listaDeNodos, RegistroGol *registro)
{
	/* Nodo nuevo a ser insertado */
	NodoGol *nodoAuxiliar = new NodoGol();

	CopiarRegistro(&nodoAuxiliar->gol, registro);

	nodoAuxiliar->siguiente = (*listaDeNodos)->siguiente;
	(*listaDeNodos)->siguiente = nodoAuxiliar;

	nodoAuxiliar->anterior = *listaDeNodos;
	if(nodoAuxiliar->siguiente != NULL)
	{
		nodoAuxiliar->siguiente->anterior = nodoAuxiliar;
	}
}

static NodoGol* NodoMedio(NodoGol* principio, NodoGol* final)
{
	NodoGol *nodoLento = principio, *nodoRapido = principio->siguiente;

	while(nodoRapido != final)
	{
		/* El nodo rapido avanza dos posiciones por vuelta del ciclo */
		nodoRapido = nodoRapido->siguiente;
		if(nodoRapido != final)
		{
			nodoRapido = nodoRapido->siguiente;
			nodoLento = nodoLento->siguiente;
		}
	}

	return nodoLento;
}

static bool Busca(NodoGol *listaDeNodos, NodoGol* final, RegistroGol *registro)
{
	NodoGol* pivote;

//	if(largo == 0)
//	{
//		/* No existe una referencia donde buscar
//		 * O un registro a encontrar.
//		 * Agrego uno */
//		Inserta(&listaDeNodos, registro);
//		return true;
//	}

	pivote = NodoMedio(listaDeNodos, final);

	if(pivote->gol.codigoDeEquipo == registro->codigoDeEquipo)
	{
		/* Se encontro */
		return true;
	} else if (pivote->gol.codigoDeEquipo > registro->codigoDeEquipo)
	{
		if(listaDeNodos == pivote)
		{
			Inserta(&listaDeNodos->anterior, registro);
			return true;
		}
		return Busca(listaDeNodos, pivote, registro);
	} else if(pivote->gol.codigoDeEquipo < registro->codigoDeEquipo)
	{
		if(listaDeNodos == pivote)
		{
			Inserta(&listaDeNodos, registro);
			return true;
		}
		return Busca(pivote->siguiente, final, registro);
	}

	return false;
}

static bool BuscaEInserta(NodoGol *arreglo, RegistroGol *registro, unsigned char largo)
{
	return Busca(arreglo, NULL, registro);
}

static void Imprime(NodoGol *lista)
{
	cout << "Codigo de Equipo"<< endl; //TODO completar
	while(lista != NULL)
	{
		cout << lista->gol.codigoDeEquipo << endl;
		lista = lista->siguiente;
	}
}

/* Punto de entrada del programa */
int main(void)
{
	RegistroGol RegistroAInsertar;
	int fibo[] = {144, 2, 3, 10946, 4181, 1597, 21, 987 , 55, 89, 1, 233, 610, 377, 34, 13, 2584, 8 , 6765, 5};
	cout << "Entry point." << endl;

	if(Goles == NULL)
	{
		/* Lista vacia, creo el primer nodo */
		Goles = new NodoGol();
		Goles->siguiente = Goles->anterior = NULL;
	}

	srand(time(NULL));

	for(int i = 0; i < 20; i++)
	{
		RegistroAInsertar.codigoDeEquipo = fibo[i];
		BuscaEInserta(Goles, &RegistroAInsertar, i);
	}

	Imprime(Goles);

	system("PAUSE");
	return 0;
}



