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

/*struct nodoGoleadores{
	cadena jugador;
	int goles;
	nodoGoleadores* prox;
};*/

int faseCompetencia(int idPartido);
nodo* buscarJugador(nodo* listaGoles, cadena nombreJugador);
void insertarPrimero(nodo* &listaGoles, tipoGol regGol);
void leerLista(nodo* lista);

void insertaPrimero(nodo* &lista,nodo* jugador);
void insertaEnMedio(nodo* lista,nodo* jugador);
void insertarOrdenado (nodo* &listaGoleadores,nodo* jugador);
void mostrarLista(nodo* lista);

void buscaEInserta(nodo* &listaGoleadores, nodo* jugador);

void goleadoresPorFecha(nodo* matrizGoles[33][8]);
void goleadoresMundial(nodo* matrizGoles[33][8]);


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
		

    goleadoresMundial(matrizGoles);
    //goleadoresPorFecha(matrizGoles); Esta funcion no compila bien
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

void insertaPrimero(nodo* &lista,nodo* jugador){
	nodo* aux=new nodo();
	strcpy(aux->jugador,jugador->jugador);
	aux->fecha=jugador->fecha;
	aux->goles=jugador->goles;
	aux->prox=lista;
	lista=aux;
}

void insertaEnMedio(nodo* lista,nodo* jugador){
	nodo* nuevo=new nodo();
	nodo* aux=lista; //Para no perder el primero trabajo sobre un auxiliar
	nuevo->fecha=jugador->fecha;
	nuevo->goles=jugador->goles;
	strcpy(nuevo->jugador,jugador->jugador);
	while (aux->prox!=NULL && jugador->goles<=aux->prox->goles){
		aux=aux->prox;
	}
	nuevo->prox=aux->prox;
	aux->prox=nuevo;
	nuevo=new nodo();
}

void insertarOrdenado(nodo* &listaGoleadores, nodo* jugador){
	if (listaGoleadores==NULL||jugador->goles>listaGoleadores->goles){//Si el jugador que llega tiene mas goles que el primero, lo inserta al principio
		insertaPrimero(listaGoleadores,jugador);
	}
	else{
		insertaEnMedio(listaGoleadores,jugador);
	}
	
}


//Sirve para Tabla de goleadores total
void buscaEInserta (nodo* &listaGoleadores, nodo* jugador){
	nodo* aux=buscarJugador(listaGoleadores,jugador->jugador);
	if (aux==NULL){
		insertarOrdenado(listaGoleadores,jugador);
	}
	else{
		aux->goles+=jugador->goles;
	}
}

void mostrarLista(nodo* lista){
	nodo* aux=lista;
	while (aux!=NULL){
		cout<<"Nombre del jugador: "<<aux->jugador<<" ,goles realizados: "<<aux->goles<<endl;
		aux=aux->prox;
	}
}

void goleadoresPorFecha(nodo* matrizGoles[33][8]){
	nodo* lista1=NULL;
	nodo* lista2=NULL;
	nodo* lista3=NULL;
	nodo* octavos=NULL;
	nodo* cuartos=NULL;
	nodo* semifinal=NULL;
	nodo* final=NULL;
	for (int i=1;i<8;i++){		
		for (int j=1;j<33;j++){
			nodo* aux= matrizGoles[j][i];
			while (aux->prox!=NULL){
			//Al tener que armar listas diferentes, uso un switch que va variando a medida que el bucle grande va avanzando				
				switch(i){
					case 1:
						insertarOrdenado(lista1,matrizGoles[j][i]);
						break;
					case 2:
						insertarOrdenado(lista2,matrizGoles[j][i]);
						break;
					case 3:
						insertarOrdenado(lista3,matrizGoles[j][i]);
						break;
					case 4:
						insertarOrdenado(octavos,matrizGoles[j][i]);
						break;
					case 5:
						insertarOrdenado(cuartos,matrizGoles[j][i]);
						break;
					case 6:
						insertarOrdenado(semifinal,matrizGoles[j][i]);
						break;
					case 7:
						break;
					case 8:
						break;
				} 				
			}
			aux=aux->prox;	
		}		
	}
	mostrarLista(lista1);
	//mostrarLista(lista2);
}


void goleadoresMundial(nodo* matrizGoles[33][8]){
	nodo* listaGoleadores;
	listaGoleadores=NULL; //Inicializo la nueva lista
	for (int i=1;i<8;i++){
		for (int j=1; j<33;j++){
			if (matrizGoles[i][j]!=NULL){//Sin esta linea rompe cuando un equipo no hizo goles en una determinada fecha		
				buscaEInserta(listaGoleadores,matrizGoles[i][j]);
			}
		}
	}
	mostrarLista(listaGoleadores);	
}





