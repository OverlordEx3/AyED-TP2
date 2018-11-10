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

static void InsertarInicio(NodoGol *&base, RegistroGol Nodo)
{
	NodoGol *nuevoNodo = new NodoGol();

	nuevoNodo->gol = Nodo;
	nuevoNodo->siguiente = base;
	base = nuevoNodo;
}

static void Insertar(NodoGol *&Destino, RegistroGol Nodo)
{
	NodoGol *nuevoNodo = new NodoGol();

	nuevoNodo->gol = Nodo;
	nuevoNodo->siguiente = Destino->siguiente;
	Destino->siguiente = nuevoNodo;
}

static void InsertarFinal(NodoGol *&Destino, RegistroGol Nodo)
{
	NodoGol *nuevoNodo = new NodoGol();

	nuevoNodo->gol = Nodo;
	nuevoNodo->siguiente = NULL;
	Destino->siguiente = nuevoNodo;
}

static void InsertaNodoPorFecha(NodoGol *&Anterior, NodoGol* &base, RegistroGol Nodo)
{
	NodoGol *baseAux, *baseAnterior;

	/* Copio la base */
	baseAux = base;
	baseAnterior = Anterior;
	while(baseAux != NULL && baseAux->gol.codigoDeEquipo == Nodo.codigoDeEquipo && Nodo.fecha >= baseAux->gol.fecha)
	{
		baseAnterior = baseAux;
		baseAux = baseAux->siguiente;
	}

	/*  Inserto nuevo nodo en la posicion hallada */
	if(baseAux == NULL)
	{
		/* Recorri la lista y no halle nada */
		InsertarFinal(baseAnterior, Nodo);
	} else if(baseAnterior == Anterior) {
		/* La fecha del primer elemento es mayor
		 * La base auxiliar anterior no cambio */
		Insertar(Anterior, Nodo);
	} else {
		Insertar(baseAnterior, Nodo);
	}
}

static void InsertaNodo(NodoGol* &base, RegistroGol Nodo)
{
	NodoGol *baseAux, *baseAnterior;

	if(base == NULL)
	{
		InsertarInicio(base, Nodo);
		return;
	}


	/* Copio la base */
	baseAux = base;
	baseAnterior = base;

	while(baseAux != NULL && Nodo.codigoDeEquipo > baseAux->gol.codigoDeEquipo)
	{
		baseAnterior = baseAux;
		baseAux = baseAux->siguiente;
	}

	/*  Inserto nuevo nodo en la posicion hallada */
	if(baseAux == NULL)
	{
		/* Recorri la lista y no halle nada */
		InsertarFinal(baseAnterior, Nodo);
	} else if(baseAux->gol.codigoDeEquipo == Nodo.codigoDeEquipo)
	{
		/* Inserto por fecha */
		InsertaNodoPorFecha(baseAnterior, baseAux, Nodo);
	} else if(baseAux == baseAnterior) {
		/* Nuevo primer elemento */
		InsertarInicio(base, Nodo);
	} else {
		/* No era ni el primer ni el ultimo elemento,
		 * Ni tampoco habia nadie igual */
		Insertar(baseAnterior, Nodo);
	}

	return;
}

void ConvierteEnMinusculas(char *aux)
{
	size_t size;

	if(aux != NULL)
	{
		size = strlen(aux);

		for(size_t c = 0; c < size; c++) {
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

void ImprimeInformacion(RegistroGol *nodo)
{
	/* Se usa printf aca, ya que es mas sencillo formatear la salida
	 */
	printf("%5d - %10d - %8d - %s\n", nodo->idGol, nodo->idPartido, nodo->fecha, nodo->nombreDelJugador);
}

void MostrarNodos(NodoGol *Nodos)
{
	NodoGol *aux = Nodos;
	int IdActual = 0;

	while(aux != NULL)
	{
		if(IdActual != aux->gol.codigoDeEquipo)
		{
			IdActual = aux->gol.codigoDeEquipo;
			/* Imprime encabezado */
			cout<<"-------------------------------------"<<endl;
			cout<<"Equipo #: " << IdActual << endl;
			cout<<"IdGol"<<" - " <<"Id Partido"<<" - "<<"  Fecha "<<" - "<<"Nombre de jugador"<<endl;
		}

		ImprimeInformacion(&aux->gol);

		aux = aux->siguiente;
	}
}

void mostrarArchivo (const char *nombreArchivo)
{
	int IdActual=0 ;
	RegistroGol Gol;
	FILE *f;

	f = fopen (nombreArchivo,"rb");
	if (f == NULL)
	{
		cout << "Error al abrir el archivo " << nombreArchivo << endl;
		return;
	}

	fread (&Gol, sizeof(Gol), 1, f);
	while (!feof(f))
	{
		if(IdActual != Gol.codigoDeEquipo)
		{
			IdActual = Gol.codigoDeEquipo;
			/* Imprime encabezado */
			cout<<"-------------------------------------"<<endl;
			cout<<"Equipo #: " << IdActual << endl;
			cout<<"IdGol"<<" - " <<"Id Partido"<<" - "<<"  Fecha "<<" - "<<"Nombre de jugador"<<endl;
		}

		ImprimeInformacion(&Gol);

		fread (&Gol, sizeof(Gol), 1, f);
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
		Gol.codigoDeEquipo= seleccionequipo(NombreEquipo);//codigo de equipo

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

	/* Genero el archivo final */
	GeneraArchivoGoles(goles);
}

void CargarGolesAutomatico(NodoGol* &goles)
{
	RegistroGol Gol;
	FILE *fGoles;

	cout << "Procesando archivo " << NOMBRE_ARCH_GOLES_ORIGINAL << endl;
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

	do{
		cout << "1: Cargar goles (MANUAL)" << endl;
		cout << "2: Cargar goles (AUTO)" << endl;
		cout << "3: Ver listado de goles original" << endl;
		cout << "4: Ver listado de goles ordenado (por equipo y fecha)" << endl;
		cout << "5: Ver listado de goles ordenado (por equipo y fecha) (LOCAL)" << endl;
		cout << "0: Salir" << endl;
		cout << endl;
		cout << "Opcion: ";

		cin>>opcion;
		switch(opcion)	{
		case 0:
			cout<<"Final del programa" << endl;
			break;

		case 1:
			goles = NULL;
			CargarGoles(goles);
			break;

		case 2:
			goles = NULL;
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

		cout<<"-------------------------------------"<<endl;
	}while(opcion != 0);

	return 0;
}
