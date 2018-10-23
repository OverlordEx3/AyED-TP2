#include <iostream>
#include <string.h>

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
void leerLista(nodo* lista);

int main() {
    FILE* G = fopen("GOLES.DAT", "rb");
    tipoGol regGol;
	nodo* posicionBuscada;
    nodo* matrizGoles[33][8]; // No se utiliza la fila 0 ni la columna 0
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
            posicionBuscada -> goles++;
        }
        fread(&regGol, sizeof(tipoGol), 1, G); // Avanzo al siguiente registro de GOLES.DAT
    }
    fclose(G);
    system("PAUSE");
    return 0;
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
    while ((posicionBuscada != NULL) && (strcmp(posicionBuscada -> jugador, nombreJugador) != 0)) {
        posicionBuscada = posicionBuscada -> prox;
    }
    return posicionBuscada;
};

void insertarPrimero(nodo* &listaGoles, tipoGol regGol) { // Crea nuevo nodo con la informacion de regGol y lo inserta en la primera posicion de listaGoles
    nodo* nuevo = new nodo();
    strcpy(nuevo -> jugador, regGol.nombreJugador);
    nuevo -> fecha = regGol.fecha;
    nuevo -> goles = 1;
    nuevo -> prox = listaGoles;
    listaGoles = nuevo;
};