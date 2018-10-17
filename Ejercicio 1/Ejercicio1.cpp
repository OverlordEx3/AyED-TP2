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
NodoGol *goles;

static void InsertaNodoPorFecha(NodoGol* &base, RegistroGol Nodo)
{
	NodoGol *baseAux;
	NodoGol *nuevoNodo = new NodoGol();

	nuevoNodo->gol = Nodo;

	if(Nodo.fecha < base->gol.fecha)
	{
		nuevoNodo->siguiente = base;
		base = nuevoNodo;

		return;
	}

	/* copia de la base */
	baseAux = base;
	while(baseAux->siguiente != NULL && baseAux->siguiente->gol.fecha < Nodo.fecha)
	{
		baseAux = baseAux->siguiente;
	}

	nuevoNodo->siguiente = baseAux->siguiente;
	baseAux->siguiente = nuevoNodo;

	return;
}

static void InsertaNodo(NodoGol* &base, RegistroGol Nodo)
{
	NodoGol *baseAux;
	NodoGol *nuevoNodo = new NodoGol();

	nuevoNodo->gol = Nodo;
	if(base == NULL)
	{
		nuevoNodo->siguiente = NULL;
		nuevoNodo->anterior = NULL;
		base = nuevoNodo;
		return;
	}

	if(Nodo.codigoDeEquipo < base->gol.codigoDeEquipo)
	{
		nuevoNodo->siguiente = base;
		nuevoNodo->anterior = base->anterior;
		base = nuevoNodo;

		return;
	}

	baseAux = base; /* copia de la base */
	while(baseAux->siguiente != NULL && baseAux->siguiente->gol.codigoDeEquipo < Nodo.codigoDeEquipo)
	{
		baseAux = baseAux->siguiente;
	}

	if(baseAux->siguiente != NULL && baseAux->siguiente->gol.codigoDeEquipo == Nodo.codigoDeEquipo)
	{
		/* A partir de aca, insertar por fecha */
		InsertaNodoPorFecha(baseAux, Nodo);
		return;
	}

	/*  Inserto nuevo nodo en la posicion hallada
	 * Que no es igual ni mayor que el codigo de equipo a insertar */
	nuevoNodo->siguiente = baseAux->siguiente;
	nuevoNodo->anterior = baseAux;
	baseAux->siguiente = nuevoNodo;

	return;
}

int seleccionequipo(string aux)
{
	if(aux.compare("rusia") == 0)
	{
		return Rusia;
	} else if(aux.compare("alemania") == 0)
	{
		return Alemania;
	} else if(aux.compare("brasil") == 0)
	{
		return Brasil;
	} else if(aux.compare("portugal") == 0)
	{
		return Portugal;
	} else if(aux.compare("argentina") == 0)
	{
		return Argentina;
	} else if(aux.compare("belgica") == 0)
	{
		return Belgica;
	} else if(aux.compare("polonia") == 0)
	{
		return Polonia;
	} else if(aux.compare("francia") == 0)
	{
		return Francia;
	} else if(aux.compare("españa") == 0)
	{
		return Espana;
	}  else if(aux.compare("peru") == 0)
	{
		return Peru;
	}  else if(aux.compare("suiza") == 0)
	{
		return Suiza;
	} else if(aux.compare("inglaterra") == 0)
	{
		return Inglaterra;
	} else if(aux.compare("colombia") == 0)
	{
		return Colombia;
	} else if(aux.compare("mexico") == 0)
	{
		return Mexico;
	} else if(aux.compare("uruguay") == 0)
	{
		return Uruguay;
	} else if(aux.compare("croacia") == 0)
	{
		return Croacia;
	}  else if(aux.compare("dinamarca") == 0)
	{
		return Dinamarca;
	} else if(aux.compare("islandia") == 0)
	{
		return Islandia;
	} else if(aux.compare("costa rica") == 0)
	{
		return CostaRica;
	} else if(aux.compare("suecia") == 0)
	{
		return Suecia;
	} else if(aux.compare("tunez") == 0)
	{
		return Tunez;
	}  else if(aux.compare("egipto") == 0)
	{
		return Egipto;
	} else if(aux.compare("senegal") == 0)
	{
		return Senegal;
	}  else if(aux.compare("iran") == 0)
	{
		return Iran;
	} else if(aux.compare("serbia") == 0)
	{
		return Serbia;
	} else if(aux.compare("nigeria") == 0)
	{
		return Nigeria;
	} else if(aux.compare("australia") == 0)
	{
		return Australia;
	} else if(aux.compare("japon") == 0)
	{
		return Japon;
	} else if(aux.compare("marruecos") == 0)
	{
		return Marruecos;
	} else if(aux.compare("panama") == 0)
	{
		return Panama;
	} else if(aux.compare("corea del sur") == 0)
	{
		return CoreaDelSur;
	} else if(aux.compare("arabia saudita") == 0)
	{
		return ArabiaSaudita;
	}

	return 0;
}

void CargarGoles(NodoGol* &goles)
{
	RegistroGol Gol;
	string NombreEquipo;
	int dia = 0;
	int mes = 0;

	Gol.idGol=0;
	cout << "Ingrese ID de Partido (0 para terminar de agregar partidos): ";
	cin >> Gol.idPartido;//id del partido
	while (Gol.idPartido != 0 && Gol.idPartido < 65)
	{
		cout<<"ID de gol:" << Gol.idGol<<endl; //id del gol

		cout<<"Nombre de equipo"<<endl;
		cin>>NombreEquipo;
		Gol.codigoDeEquipo= seleccionequipo(NombreEquipo);//codigo de equipo //TODO chequear valido

		cout<<"Nombre del jugador que hizo GOL"<<endl;
		cin>>Gol.nombreDelJugador;//Nombre del jugador

		cout<<"Fecha:" << endl;
		cout<<"mes: ";
		cin>>mes;
		cout<<"dia: ";
		cin>>dia;
		Gol.fecha= (10000*2018) + (mes*100) + (dia);
		/* Busca - inserta */
		InsertaNodo(goles, Gol);

		Gol.idGol++;
		cout << "Ingrese ID de Partido (0 para terminar de agregar partidos): ";
		cin >> Gol.idPartido;//id del partido repito para el corte
	}
	cout<<"-------------------------------------"<<endl;
}

void MostrarNodos(NodoGol *Nodos)
{
	NodoGol *aux = Nodos;

	cout<<"IdGol"<<" "<<"Codigo de equipo"<<"           "<<"Fecha"<<"             "<<"Nombre de jugador"<<"   "<<"Id Partido"<<endl;
	while(aux != NULL)
	{
		cout<<aux->gol.idGol<<"                 "<<aux->gol.codigoDeEquipo<<"           "<<aux->gol.fecha<<"               "<<aux->gol.nombreDelJugador<<"                    "<<aux->gol.idPartido<<endl;
		aux = aux->siguiente;
	}
}

void mostrarArchivo ()
{
	int c=0 ;
	RegistroGol Gol;
	FILE *f;
	f = fopen ("archivogol.dat","rb");
	if (f != NULL)
	{
		//cout<<"Id gol"<<endl;
		fread (&Gol, sizeof(Gol), 1, f);
		cout<<"IdGol"<<" "<<"Codigo de equipo"<<"           "<<"Fecha"<<"             "<<"Nombre de jugador"<<"   "<<"Id Partido"<<endl;
		while (!feof(f))
		{
			cout<<Gol.idGol<<"                 "<<Gol.codigoDeEquipo<<"           "<<Gol.fecha<<"               "<<Gol.nombreDelJugador<<"                    "<<Gol.idPartido<<endl;
			fread (&Gol, sizeof(Gol), 1, f);

			c++;
		}
	}
	fclose (f);
}

/* Punto de entrada del programa */
int main(void)
{
    CargarGoles(goles);
    MostrarNodos(goles);
	system("PAUSE");
	return 0;
}



