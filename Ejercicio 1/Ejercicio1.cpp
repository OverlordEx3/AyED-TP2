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

/* Definiciones y etiquetas del usuario */
#define NOMBRE_ARCH_GOLES_ORIGINAL "goles2018.dat\0"
#define NOMBRE_ARCH_GOLES_ORDENADO "archivogol.dat\0"

using namespace std;

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
	while(baseAux->siguiente != NULL || (baseAux->gol.codigoDeEquipo == Nodo.codigoDeEquipo && baseAux->gol.fecha < Nodo.fecha))
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
		base = nuevoNodo;
		return;
	}

	baseAux = base; /* copia de la base */
	while(baseAux->siguiente != NULL || baseAux->gol.codigoDeEquipo < Nodo.codigoDeEquipo)
	{
		baseAux = baseAux->siguiente;
	}

	if(baseAux->gol.codigoDeEquipo == Nodo.codigoDeEquipo)
	{
		/* A partir de aca, insertar por fecha */
		InsertaNodoPorFecha(baseAux, Nodo);
		return;
	}

	/*  Inserto nuevo nodo en la posicion hallada
	 * Que no es igual ni mayor que el codigo de equipo a insertar */
	nuevoNodo->siguiente = baseAux->siguiente;
	baseAux->siguiente = nuevoNodo;

	return;
}

void ConvierteEnMinusculas(char *aux)
{
	size_t size;

	if(aux != NULL)
	{
		size = strlen(aux);

		for(int c = 0; c < size; c++) {
			aux[c] = tolower(aux[c]);
		}
	}
}
int seleccionequipo(const char* aux)
{

	/* Convierto la cadena en minusculas */
	ConvierteEnMinusculas((char *)aux);

	if(strcmp("rusia", aux) == 0)
	{
		return Rusia;
	} else if(strcmp("alemania", aux) == 0)
	{
		return Alemania;
	} else if(strcmp("brasil", aux) == 0)
	{
		return Brasil;
	} else if(strcmp("portugal", aux) == 0)
	{
		return Portugal;
	} else if(strcmp("argentina", aux) == 0)
	{
		return Argentina;
	} else if(strcmp("belgica", aux) == 0)
	{
		return Belgica;
	} else if(strcmp("polonia", aux) == 0)
	{
		return Polonia;
	} else if(strcmp("francia", aux) == 0)
	{
		return Francia;
	} else if(strcmp("españa", aux) == 0)
	{
		return Espana;
	}  else if(strcmp("peru", aux) == 0)
	{
		return Peru;
	}  else if(strcmp("suiza", aux) == 0)
	{
		return Suiza;
	} else if(strcmp("inglaterra", aux) == 0)
	{
		return Inglaterra;
	} else if(strcmp("colombia", aux) == 0)
	{
		return Colombia;
	} else if(strcmp("mexico", aux) == 0)
	{
		return Mexico;
	} else if(strcmp("uruguay", aux) == 0)
	{
		return Uruguay;
	} else if(strcmp("croacia", aux) == 0)
	{
		return Croacia;
	}  else if(strcmp("dinamarca", aux) == 0)
	{
		return Dinamarca;
	} else if(strcmp("islandia", aux) == 0)
	{
		return Islandia;
	} else if(strcmp("costa rica", aux) == 0)
	{
		return CostaRica;
	} else if(strcmp("suecia", aux) == 0)
	{
		return Suecia;
	} else if(strcmp("tunez", aux) == 0)
	{
		return Tunez;
	}  else if(strcmp("egipto", aux) == 0)
	{
		return Egipto;
	} else if(strcmp("senegal", aux) == 0)
	{
		return Senegal;
	}  else if(strcmp("iran", aux) == 0)
	{
		return Iran;
	} else if(strcmp("serbia", aux) == 0)
	{
		return Serbia;
	} else if(strcmp("nigeria", aux) == 0)
	{
		return Nigeria;
	} else if(strcmp("australia", aux) == 0)
	{
		return Australia;
	} else if(strcmp("japon", aux) == 0)
	{
		return Japon;
	} else if(strcmp("marruecos", aux) == 0)
	{
		return Marruecos;
	} else if(strcmp("panama", aux) == 0)
	{
		return Panama;
	} else if(strcmp("corea del sur", aux) == 0)
	{
		return CoreaDelSur;
	} else if(strcmp("arabia saudita", aux) == 0)
	{
		return ArabiaSaudita;
	}

	return 0;
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

void mostrarArchivo (const char *nombreArchivo)
{
	int c=0 ;
	RegistroGol Gol;
	FILE *f;

	f = fopen (nombreArchivo,"rb");
	if (f != NULL)
	{
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

void GeneraArchivoGoles(NodoGol *goles)
{
	FILE *fGoles;
	NodoGol *CopiaGoles = goles;

	fGoles = fopen(NOMBRE_ARCH_GOLES_ORDENADO, "wb+");
	if(fGoles == NULL)
	{
		cout << "Error al abrir/crear el archivo de goles." << endl;
		return;
	}

	while(CopiaGoles != NULL)
	{
		fwrite((void *)&CopiaGoles->gol, sizeof(RegistroGol), 1, fGoles);
		CopiaGoles = CopiaGoles->siguiente;
	}

	fclose(fGoles);
}

void CargarGoles(NodoGol* &goles)
{
	RegistroGol Gol;
	char NombreEquipo[MAX_LARGO_CADENA];
	int dia = 0;
	int mes = 0;

	Gol.idGol=0;
	cout << "Ingrese ID de Partido (0 para terminar de agregar partidos): ";
	cin >> Gol.idPartido;//id del partido
	while (Gol.idPartido != 0 && Gol.idPartido < 65)
	{
		cout<<"ID de gol:" << Gol.idGol<<endl; //id del gol

		cout<<"Nombre de equipo: ";
		cin.ignore();
		cin.getline(NombreEquipo, 256);
		Gol.codigoDeEquipo= seleccionequipo(NombreEquipo);//codigo de equipo //TODO chequear valido

		cout<<"Nombre del jugador que hizo GOL: ";
		cin.getline(Gol.nombreDelJugador, sizeof(Gol.nombreDelJugador)); //Nombre del jugador

		cout<<"Fecha:" << endl;
		cout<<"Mes: ";
		cin>>mes;
		cout<<"Dia: ";
		cin>>dia;
		Gol.fecha= (10000*2018) + (mes*100) + (dia);
		/* Busca - inserta */
		InsertaNodo(goles, Gol);

		Gol.idGol++;
		cout << "Ingrese ID de Partido (0 para terminar de agregar partidos): ";
		cin >> Gol.idPartido;//id del partido repito para el corte
	}
	cout<<"-------------------------------------"<<endl;

	/* Genero el archivo final */
	GeneraArchivoGoles(goles);
}

void CargarGolesAutomatico(NodoGol* &goles)
{
	RegistroGol Gol;
	FILE *fGoles;

	fGoles = fopen(NOMBRE_ARCH_GOLES_ORIGINAL, "rb");

	if(fGoles == NULL)
	{
		printf("Error al abrir el archivo de goles original.\n");
		return;
	}

	fread((void *)&Gol,sizeof(RegistroGol), 1, fGoles);
	while (!feof(fGoles))
	{
		/* Busca - inserta */
		InsertaNodo(goles, Gol);
		/* Leo el siguiente */
		fread((void *)&Gol,sizeof(RegistroGol), 1, fGoles);
	}
	cout<<"-------------------------------------"<<endl;

	GeneraArchivoGoles(goles);

	/* Cierro finalmente los archivos */
	fclose(fGoles);
}

/* Punto de entrada del programa */
int main(void)
{
	int opcion;
	/* Listado de goles */
	NodoGol *goles = NULL;

	cout << "1: Cargar goles (MANUAL)" << endl;
	cout << "2: Cargar goles (AUTO)" << endl;
	cout << "3: Ver listado de goles original" << endl;
	cout << "4: Ver listado de goles ordenado" << endl;
	cout << "5: Ver listado de goles ordenado (LOCAL)" << endl;
	cout << "0: Salir" << endl;
	cout << endl;

	do{
		cout << "Opcion: ";

		cin>>opcion;
		switch(opcion)	{
		case 0:
			cout<<"Final del programa" << endl;
			break;

		case 1:
			CargarGoles(goles);
			break;

		case 2:
			CargarGolesAutomatico(goles);
			break;

		case 3:
			mostrarArchivo(NOMBRE_ARCH_GOLES_ORIGINAL);
			break;

		case 4:
			mostrarArchivo(NOMBRE_ARCH_GOLES_ORDENADO);
			break;

		case 5:
			MostrarNodos(goles);
			break;
		default:
			cout<<"Error, opcion invalida";
			break;
		}
	}while(opcion != 0);

	return 0;
}
