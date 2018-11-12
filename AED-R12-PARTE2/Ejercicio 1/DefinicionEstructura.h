#ifndef DEFINICIONESTRUCTURA_H_
#define DEFINICIONESTRUCTURA_H_

#include <cstdio>
#include <cstdlib>

//#pragma warning(disable : 4996)
//#pragma once

#define MAX_LARGO_CADENA	19+1
 /* Para uso de la estructura */
typedef char cadena[MAX_LARGO_CADENA];

enum Equipos {
	Rusia = 1,
	Alemania,
	Brasil,
	Portugal,
	Argentina,
	Belgica,
	Polonia,
	Francia,
	Espana,
	Peru,
	Suiza,
	Inglaterra,
	Colombia,
	Mexico,
	Uruguay,
	Croacia,
	Dinamarca,
	Islandia,
	CostaRica,
	Suecia,
	Tunez,
	Egipto,
	Senegal,
	Iran,
	Serbia,
	Nigeria,
	Australia,
	Japon,
	Marruecos,
	Panama,
	CoreaDelSur,
	ArabiaSaudita,
};

/* Para usar como tipo en lugar de instancia de enumerador */
typedef enum Equipos CodigoDeEquipo;

/* Uso del enum:
   Cuando se requiera comparar el ID de un equipo contra un ingreso/variable,
	 Es conveniente usar las etiquetas que define el enum. Cada una contiene un valor, comenzando por Rusia
	 cuyo valor es 1 (Rusia = 1,)
	 Ejemplo:
	 switch(IngresoUsuario)
	 {
		case Rusia:
		//Hace algo
		break;
		case Alemania:
		//Hace algo
		break;
		---
		case ArabiaSaudita:
		//hace algo
		break;
		}

		O, usando un if:
		if(IngresoUsuario == ArabiaSaudita || IngresoUsuario == Egipto)
		{
			//Haz algo
		}

		Para manejar el ingreso de usuario y al mismo tiempo hacerlo compatible con el ejercicio
		es necesario comprobar que el ingreso (string llevado a entero) sea mayor a 0,
		y que sea menor a 33 (o menor/igual que 32, tambien sirve
	 */

	 /* Se recomienda utilizar notaci�n Camel Case para los identificadores,
	 tanto de variables como de funciones. Asimismo ser� obligatorio que
	 los nombres de dichos identificadores se consignen en espa�ol*/
struct registroGol {
	int idGol;
	int codigoDeEquipo;
	int fecha;
	cadena nombreDelJugador;
	int idPartido;
};

/* Para usar como tipo en lugar de instancia de estructura. */
typedef struct registroGol RegistroGol;

struct nodoGol
{
	struct nodoGol *siguiente;
	RegistroGol gol;
};

typedef struct nodoGol NodoGol;
#endif /* DEFINICIONESTRUCTURA_H_ */
