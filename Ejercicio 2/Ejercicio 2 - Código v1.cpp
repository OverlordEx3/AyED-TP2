#include <iostream>
#include <string.h>

using namespace std;

typedef char cadena[20];

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
    Costa_Rica,
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
    Corea_del_Sur,
    Arabia_Saudita,
};

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

int etapaCompetencia(int idPartido);
nodo* buscarJugador(nodo* listaActual, cadena nombreJugador);
nodo* buscarUltimo(nodo* listaActual);
void insertarUltimo(nodo* &listaActual, tipoGol regGol);

int main() {
    FILE* G = fopen("GOLES.DAT", "rb");
    tipoGol regGol;
    nodo* listaActual;
	nodo* posicionBuscada;
    nodo* matrizGoles[33][8];
    for (int i = 0; i < 33; i++) {
        for (int j = 0; j < 8; j++) {
            matrizGoles[i][j] = NULL;
        }
    }
    int codigoFase;
    fread(&regGol, sizeof(tipoGol), 1, G);
    while (!feof(G)) {
        codigoFase = etapaCompetencia(regGol.idPartido);
        listaActual = matrizGoles[regGol.codigoEquipo][codigoFase];
        posicionBuscada = buscarJugador(listaActual, regGol.nombreJugador);
        if (posicionBuscada == NULL) {
            insertarUltimo(listaActual, regGol);
        }
        else {
            posicionBuscada -> goles++;
        }
        fread(&regGol, sizeof(tipoGol), 1, G);
    }
    fclose(G);
    system("PAUSE");
    return 0;
}

int etapaCompetencia(int idPartido) {
    if ((idPartido >= 1) && (idPartido <= 16)) { // Partido 1 de fase de grupos
        return 1;
    }
    else if ((idPartido >= 17) && (idPartido <= 32)) { // Partido 1 de fase de grupos
        return 2;
    }
    else if ((idPartido >= 33) && (idPartido <= 48)) { // Partido 1 de fase de grupos
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

nodo* buscarJugador(nodo* listaActual, cadena nombreJugador) {
    nodo* posicionBuscada = listaActual;
    while ((posicionBuscada != NULL) && (strcmp(posicionBuscada -> jugador, nombreJugador) != 0)) {
        posicionBuscada = posicionBuscada -> prox;
    }
    return posicionBuscada;
};

nodo* buscarUltimo(nodo* listaActual) {
    nodo* ultimaPosicion = listaActual;
    while (ultimaPosicion -> prox != NULL) {
        ultimaPosicion = ultimaPosicion -> prox;
    }
    return ultimaPosicion;
};

void insertarUltimo(nodo* listaActual, tipoGol regGol) {
    nodo* ultimaPosicion;
    nodo* nuevo = new nodo();
    strcpy(nuevo -> jugador, regGol.nombreJugador);
    nuevo -> fecha = regGol.fecha;
    nuevo -> goles = 1;
    if (listaActual == NULL) {
        listaActual = nuevo;
    }
    else {
        ultimaPosicion = buscarUltimo(listaActual);
        ultimaPosicion -> prox = nuevo;
    }
    nuevo -> prox = ultimaPosicion -> prox;
};