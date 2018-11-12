//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

//#pragma warning(disable : 4996)

using namespace std;

typedef char cadena[20];

//Creo la estructura del archivo
struct tipoGolesEquipo {
	cadena nombreEquipo;
	int goles;
};

struct nodoGolesEquipo {
	nodoGolesEquipo *ptrIzq;
	nodoGolesEquipo *ptrDer;
	struct tipoGolesEquipo info;
	string nombreEquipo;
}vectorGolesEquipo[32];

//Funcion para leer archivos
void leerArchivo() {
	//Instancio el archivo para trabajar desde el nombre del struct
	tipoGolesEquipo regGolesEquipo;	
	//Cargo el archivo con el que quiero trabajar
	FILE * G = fopen("goles_equipo.dat", "rb");
	//Este while imprime todos los datos del archivo
	fread(&regGolesEquipo, sizeof(regGolesEquipo), 1, G);
	cout << "**********************************\n";
	while (!feof(G)) {
		cout << "Nombre del equipo: " << regGolesEquipo.nombreEquipo << "\n";
		cout << "Goles a favor: " << regGolesEquipo.goles << "\n\n";
		//Abro el archivo para poder leerlo
		fread(&regGolesEquipo, sizeof(regGolesEquipo), 1, G);
	}
	cout << "**********************************\n\n";
	fclose(G);
}

void cargarVector(nodoGolesEquipo  vectorGolesEquipo[]) {
	//Inicializo un valor para poder recorrer el array
	int i = 0;
	//Creo un string local para poder almacenarlo en el array
	string nombreEquipo;
	//Instancio el archivo para trabajar desde el nombre del struct
	tipoGolesEquipo regGolesEquipo;
	//Cargo el archivo con el que quiero trabajar
	FILE * G = fopen("goles_equipo.dat", "rb");
	//Este while imprime todos los datos del archivo
	fread(&regGolesEquipo, sizeof(regGolesEquipo), 1, G);
	while (!feof(G)) {
		//Transformo los characters a tipo string, luego los asigno al array
		string nombreEquipo = regGolesEquipo.nombreEquipo;
		//Copio los valores del archivo al vector
		vectorGolesEquipo[i].nombreEquipo = nombreEquipo;
		vectorGolesEquipo[i].info.goles = regGolesEquipo.goles;
		//Actualizo el contador
		i = i + 1;
		fread(&regGolesEquipo, sizeof(regGolesEquipo), 1, G);
	}
	fclose(G);
}

void leerVector(nodoGolesEquipo  vectorGolesEquipo[]) {
	cout << "**********************************\n";
	for (int i = 0; i < 32; i++) {
		cout << "Nombre de equipo: " << vectorGolesEquipo[i].nombreEquipo << "\nGoles a favor: " << vectorGolesEquipo[i].info.goles << "\n\n";
	}
	cout << "**********************************\n\n";
}

//Funcione para crear el Arbol
void insertarNodo(nodoGolesEquipo* &ptrArbol, nodoGolesEquipo vectorGolesEquipo[], int i) {
	if (ptrArbol == NULL) {
		//Si encuentra un nodo vacio crea uno nuevo
		nodoGolesEquipo* aux = new nodoGolesEquipo();
		//Carga los valores de los goles del array  al nodo creado
		aux->info.goles = vectorGolesEquipo[i].info.goles;
		//Carga los valores de los paises del array al nodo creado*
		aux->nombreEquipo = vectorGolesEquipo[i].nombreEquipo;
		//Pone los hijos en NULL para que despues los asignen
		aux->ptrIzq = NULL;
		aux->ptrDer = NULL;
		ptrArbol = aux;
	}
	else {
		//Si es menor al nodo lo inserta en la izquierda
		if (vectorGolesEquipo[i].info.goles < ptrArbol->info.goles) {
			insertarNodo(ptrArbol->ptrIzq, vectorGolesEquipo, i);
		}
		else {
			//Si es mayor o igual lo inserta en la rama derecha
			if (vectorGolesEquipo[i].info.goles > ptrArbol->info.goles) {
				insertarNodo(ptrArbol->ptrDer, vectorGolesEquipo, i);
			}
			else {
				insertarNodo(ptrArbol->ptrDer, vectorGolesEquipo, i);
			}
		}
	}
}

//Funcion para ordenar el arbol
void inOrder(nodoGolesEquipo* &ptrArbol) {
	if (ptrArbol == NULL) {
		return;
	}
	else {
		inOrder(ptrArbol->ptrIzq);
		cout << "Nombre de equipo: " << ptrArbol->nombreEquipo << "\nGoles a favor: " << ptrArbol->info.goles << "\n\n";
		inOrder(ptrArbol->ptrDer);
	}
}

int main(int argc, char** argv) {
	nodoGolesEquipo* ptrRaiz = NULL;
	//Variable para elegir que opcion elegir
	int opcion;
	cout << "Segunda Parte TP Anual de Algoritmos y Estructura de Datos 2018" << "\n";
	cout << "Ejercicio 3\n\n";
	do {
		cout << "1: Leer los datos del archivo " << "\n" << "2: Para cargar vector e imprimir los datos del vector " << "\n" << "3: Para ordernar los equipos por cantidad de goles " << "\n" << "0: Salir " << "\n\n" << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
			case 0: {
				cout << "\n";
				cout << "Fin de programa.";
				break;
			}
			case 1: {
				cout << "\n\n";
				leerArchivo();
				break;
			}
			case 2: {
				cout << "\n\n";
				cargarVector(vectorGolesEquipo);
				leerVector(vectorGolesEquipo);
				break;
			}
			case 3: {
				cout << "\n**********************************\n\n";
				for (int i = 0; i < 32; i++) {
					insertarNodo(ptrRaiz, vectorGolesEquipo, i);
				}
				inOrder(ptrRaiz);
				cout << "**********************************\n\n";
				break;
			}
			default: {
				cout << "Error, opcion invalida";
				break;
			}
		}
	} while (opcion != 0);
	return 0;
}