//#include "pch.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>

//#pragma warning(disable : 4996)

using namespace std;

typedef char cadena[20];

struct tipoGol {
	int idGol;
	int codigoEquipo;
	int fecha;
	cadena nombreJugador;
	int idPartido;
};

struct nodo {
	cadena jugador;
	int fecha;
	int goles;
	nodo* prox;
};

int faseCompetencia(int idPartido);
nodo* buscarJugador(nodo* listaGoles, cadena nombreJugador);
void insertarPrimero(nodo* &listaGoles, tipoGol regGol);
void generarMatriz(nodo* (&matrizGoles)[33][8]);
void golesPorEquipo(nodo* matrizGoles[33][8]);
void ordenarPorGoles(nodo* &listaGoleadores);
void imprimirGoleadores(nodo* listaGoleadores);
void goleadoresPorFecha(nodo* matrizGoles[33][8]);
void goleadoresCompetencia(nodo* matrizGoles[33][8]);

int main() {
	int opcion;
	nodo* matrizGoles[33][8];
	do {
		cout
			<< "MENU PRINCIPAL DEL EJERCICIO 2" << endl
			<< "1: Generar matriz de goles por partido" << endl
			<< "2: Mostrar cantidad de goles por equipo" << endl
			<< "3: Mostrar goleadores por fecha" << endl
			<< "4: Mostrar goleadores de la competencia" << endl
			<< "0: Salir" << endl
			<< "Ingrese opcion: ";
		cin >> opcion;
		cout << endl;
		switch (opcion) {
		case 0:
			system("PAUSE");
			return 0;
		case 1:
			cout << "Generando matriz...";
			Sleep(1500);
			generarMatriz(matrizGoles);
			cout << " Matriz generada correctamente." << endl << endl;
			break;
		case 2:
			cout << "Calculando goles por equipo..." << endl;
			Sleep(1500);
			golesPorEquipo(matrizGoles);
			cout << endl << endl;
			break;
		case 3:
			cout << "Calculando goleadores por fecha..." << endl;
			Sleep(1500);
			goleadoresPorFecha(matrizGoles);
			break;
		case 4:
			cout << "Calculando goleadores de la competencia..." << endl;
			Sleep(1500);
			goleadoresCompetencia(matrizGoles);
			break;
		}
	} while (opcion != 0);
}

int faseCompetencia(int idPartido) { // Retorna codigo de fase de competencia segun idPartido
	if ((idPartido >= 1) && (idPartido <= 16)) { // Partido 1 de fase de grupos
		return 1;
	}
	else if ((idPartido >= 17) && (idPartido <= 32)) { // Partido 2 de fase de grupos
		return 2;
	}
	else if ((idPartido >= 33) && (idPartido <= 48)) { // Partido 3 de fase de grupos
		return 3;
	}
	else if ((idPartido >= 49) && (idPartido <= 56)) { // Octavos de final
		return 4;
	}
	else if ((idPartido >= 57) && (idPartido <= 60)) { // Cuartos de final
		return 5;
	}
	else if ((idPartido == 61) || (idPartido == 62)) { // Semifinal
		return 6;
	}
	else if ((idPartido == 63) || (idPartido == 64)) { // Tercer puesto y final
		return 7;
	}
};

nodo* buscarJugador(nodo* listaGoles, cadena nombreJugador) { // Retorna direccion del nodo con nombreJugador (si existe), o NULL (si no existe)
	nodo* posicionBuscada = listaGoles;
	while ((posicionBuscada != NULL) && (strcmp(posicionBuscada->jugador, nombreJugador) != 0)) {
		posicionBuscada = posicionBuscada->prox;
	}
	return posicionBuscada;
};

void insertarPrimero(nodo* &listaGoles, tipoGol regGol) { // Crea nuevo nodo con la informacion de regGol y lo inserta en la primera posicion de listaGoles
	nodo* nuevo = new nodo();
	strcpy(nuevo->jugador, regGol.nombreJugador);
	nuevo->fecha = regGol.fecha;
	nuevo->goles = 1;
	nuevo->prox = listaGoles;
	listaGoles = nuevo;
};

void generarMatriz(nodo* (&matrizGoles)[33][8]) {
	FILE* G = fopen("GOLES.DAT", "rb");
	tipoGol regGol;
	nodo* posicionBuscada;
	int i, j;
	for (i = 0; i < 33; i++) { // Inicializacion de matrizGoles en NULL
		for (j = 0; j < 8; j++) {
			matrizGoles[i][j] = NULL;
		}
	}
	int codigoFase;
	fread(&regGol, sizeof(tipoGol), 1, G); // Inicio de lectura secuencial de GOLES.DAT
	while (!feof(G)) {
		codigoFase = faseCompetencia(regGol.idPartido); // Obtengo codigoFase para posicionarme en la columna correspondiente de matrizGoles
		posicionBuscada = buscarJugador(matrizGoles[regGol.codigoEquipo][codigoFase], regGol.nombreJugador); // Verifico si regGol.nombreJugador existe en matrizGoles[regGol.codigoEquipo][codigoFase]
		if (posicionBuscada == NULL) { // Si no existe, creo nuevo nodo e inserto en el primer lugar
			insertarPrimero(matrizGoles[regGol.codigoEquipo][codigoFase], regGol);
		}
		else { // Si existe, incremento posicionBuscada -> goles
			posicionBuscada->goles++;
		}
		fread(&regGol, sizeof(tipoGol), 1, G); // Avanzo al siguiente registro de GOLES.DAT
	}
	fclose(G);
};

void golesPorEquipo(nodo* matrizGoles[33][8]) { // Imprime la cantidad de goles por equipo
	cadena vectorEquipos[33] = {
		"-", "Rusia", "Alemania", "Brasil", "Portugal", "Argentina", "Belgica", "Polonia", "Francia",
		"Espana", "Peru", "Suiza", "Inglaterra", "Colombia", "Mexico", "Uruguay", "Croacia",
		"Dinamarca", "Islandia", "Costa_Rica", "Suecia", "Tunez", "Egipto", "Senegal",
		"Iran", "Serbia", "Nigeria", "Australia", "Japon", "Marruecos", "Panama", "Corea_del_Sur", "Arabia_Saudita",
	};
	nodo* p;
	int i, j;
	for (i = 1; i < 33; i++) {
		int cantidadGoles = 0;
		for (j = 1; j < 8; j++) {
			p = matrizGoles[i][j];
			while (p != NULL) {
				cantidadGoles += p->goles;
				p = p->prox;
			}
		}
		cout << vectorEquipos[i] << ": " << cantidadGoles << endl;
	}
};

void ordenarPorGoles(nodo* &listaGoleadores) {
	nodo* p = listaGoleadores;
	nodo* q;
	cadena auxJugador;
	int auxGoles;
	while (p != NULL) {
		q = p->prox;
		while (q != NULL) {
			if ((p->goles) < (q->goles)) {
				strcpy(auxJugador, q->jugador);
				auxGoles = q->goles;
				strcpy(q->jugador, p->jugador);
				q->goles = p->goles;
				strcpy(p->jugador, auxJugador);
				p->goles = auxGoles;
			}
			q = q->prox;
		}
		p = p->prox;
	}
};

void imprimirGoleadores(nodo* listaGoleadores) {
	nodo* p = listaGoleadores;
	while (p != NULL) {
		cout << p->jugador << ": " << p->goles << endl;
		p = p->prox;
	}
	cout << endl;
};

void goleadoresPorFecha(nodo* matrizGoles[33][8]) {
	nodo* p;
	nodo* nuevo;
	nodo* posicionBuscada;
	int i, j;
	for (j = 1; j < 8; j++) { // Recorro todas las fases
		nodo* listaGoleadores = NULL;
		for (i = 1; i < 33; i++) { // Por cada fase, recorro todos los goles de todos los equipos
			p = matrizGoles[i][j];
			while (p != NULL) {
				posicionBuscada = buscarJugador(listaGoleadores, p->jugador);
				if (posicionBuscada == NULL) { // Si no existe, creo nuevo nodo e inserto en primer lugar de listaGoleadores
					nuevo = new nodo();
					strcpy(nuevo->jugador, p->jugador);
					nuevo->fecha = -1; // Este campo no lo necesitamos
					nuevo->goles = p->goles;
					nuevo->prox = listaGoleadores;
					listaGoleadores = nuevo;
				}
				else { // Si existe, actualizo cantidad de goles
					posicionBuscada->goles += p->goles;
				}
				p = p->prox; // Avanzo al siguiente nodo
			}
		}
		ordenarPorGoles(listaGoleadores);
		cout << "TABLA DE GOLEADORES - FECHA " << j << endl;
		imprimirGoleadores(listaGoleadores); // Imprimo la lista de goleadores de cada fecha
	}
};

void goleadoresCompetencia(nodo* matrizGoles[33][8]) {
	nodo* p;
	nodo* nuevo;
	nodo* posicionBuscada;
	nodo* listaGoleadores = NULL;
	int i, j;
	for (j = 1; j < 8; j++) {
		for (i = 1; i < 33; i++) {
			p = matrizGoles[i][j];
			while (p != NULL) {
				posicionBuscada = buscarJugador(listaGoleadores, p->jugador);
				if (posicionBuscada == NULL) { // Si no existe, creo nuevo nodo e inserto en primer lugar de listaGoleadores
					nuevo = new nodo();
					strcpy(nuevo->jugador, p->jugador);
					nuevo->fecha = -1;
					nuevo->goles = p->goles;
					nuevo->prox = listaGoleadores;
					listaGoleadores = nuevo;
				}
				else { // Si existe, actualizo cantidad de goles
					posicionBuscada->goles += p->goles;
				}
				p = p->prox; // Avanzo al siguiente nodo
			}
		}
	}
	ordenarPorGoles(listaGoleadores);
	imprimirGoleadores(listaGoleadores);
};
