#include <iostream>
#include <string.h> // Para el uso de getline() y strcpy()
#include <windows.h>
using namespace std;

typedef char cadena[30];

struct tipoClasificado {
    int numeroBolillero;
    cadena nombreEquipo;
    cadena confederacion;
    int codigoConfederacion; // 0: AFC, 1: CAF, 2: Concacaf, 3: Conmebol, 4: OFC, 5: UEFA
};

struct tipoClasificado2 {
    cadena nombreEquipo;
    char letraGrupo;
    cadena confederacion;
};

void cargarVector(tipoClasificado2 (&vectorEquipos)[32]);
void ordenarPorGrupo(tipoClasificado2 (&vectorEquipos)[32]); // Ordena el arreglo por letra de grupo
void ordenarPorNombre(tipoClasificado2 (&vectorEquipos)[32]); // Ordena el arreglo por nombre de equipo
void ordenarPorConfederacion(tipoClasificado2 (&vectorEquipos)[32], int inicio, int fin); // Ordena un intervalo del arreglo por confederacion
void ordenarPorGrupoConfederacion(tipoClasificado2 (&vectorEquipos)[32]); // Ordena el arreglo por grupo y confederacion, en ese orden
void ordenarPorConfederacionNombre(tipoClasificado2 (&vectorEquipos)[32], int inicio, int fin); // Si en un intervalo del arreglo hay dos equipos con la misma confederacion, los ordena por nombre
void ordenarPorGrupoConfederacionNombre(tipoClasificado2 (&vectorEquipos)[32]); // // Ordena el arreglo por letra de grupo, confederacion y nombre, en ese orden

int main () {
    tipoClasificado2 vectorEquipos[32];
    int opcion, i;
    cargarVector(vectorEquipos);
    do {
        cout
            << "MENU PRINCIPAL DEL EJERCICIO 3" << endl
            << "1: Mostrar equipos ordenados por grupo" << endl
            << "2: Mostrar equipos ordenados por nombre" << endl
            << "3: Mostrar equipos ordenados por confederacion" << endl
            << "4: Mostrar equipos ordenados por grupo y confederacion" << endl
            << "5: Mostrar equipos ordenados por grupo, confederacion y nombre" << endl
            << "0: Salir" << endl
            << "Ingrese opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion) {
            case 0:
                system("PAUSE");
                return 0;
            case 1:
                cout << "Ordenando equipos..." << endl;
                Sleep(3000);
                ordenarPorGrupo(vectorEquipos);
                cout << "EQUIPOS ORDENADOS POR GRUPO" << endl;
                for (i = 0; i < 32; i++) {
                    cout << vectorEquipos[i].letraGrupo << " - " << vectorEquipos[i].nombreEquipo << endl;
                }
                cout << endl;
                break;
            case 2:
                cout << "Ordenando equipos..." << endl;
                Sleep(3000);
                ordenarPorNombre(vectorEquipos);
                cout << "EQUIPOS ORDENADOS POR NOMBRE" << endl;
                for (i = 0; i < 32; i++) {
                    cout << vectorEquipos[i].nombreEquipo << endl;
                }
                cout << endl;
                break;
            case 3:
                cout << "Ordenando equipos..." << endl;
                Sleep(3000);
                ordenarPorConfederacion(vectorEquipos, 0, 32);
                cout << "EQUIPOS ORDENADOS POR CONFEDERACION" << endl;
                for (i = 0; i < 32; i++) {
                    cout << vectorEquipos[i].confederacion << " - " << vectorEquipos[i].nombreEquipo << endl;
                }
                cout << endl;
                break;
            case 4:
                cout << "Ordenando equipos..." << endl;
                Sleep(3000);
                ordenarPorGrupoConfederacion(vectorEquipos);
                cout << "EQUIPOS ORDENADOS POR GRUPO/CONFEDERACION" << endl;
                for (i = 0; i < 32; i++) {
                    cout << vectorEquipos[i].letraGrupo << " - " << vectorEquipos[i].confederacion << " - " << vectorEquipos[i].nombreEquipo << endl;
                }
                cout << endl;
                break;
            case 5:
                cout << "Ordenando equipos..." << endl;
                Sleep(3000);
                ordenarPorGrupoConfederacionNombre(vectorEquipos);
                cout << "EQUIPOS ORDENADOS POR GRUPO/CONFEDERACION/NOMBRE" << endl;
                for (i = 0; i < 32; i++) {
                    cout << vectorEquipos[i].letraGrupo << " - " << vectorEquipos[i].confederacion << " - " << vectorEquipos[i].nombreEquipo << endl;
                }
                cout << endl;
                break;
        }
    } while (opcion != 0);
}

void cargarVector(tipoClasificado2 (&vectorEquipos)[32]) {
    FILE* A = fopen("GRUPO_A.DAT", "rb");
    FILE* B = fopen("GRUPO_B.DAT", "rb");
    FILE* C = fopen("GRUPO_C.DAT", "rb");
    FILE* D = fopen("GRUPO_D.DAT", "rb");
    FILE* E = fopen("GRUPO_E.DAT", "rb");
    FILE* F = fopen("GRUPO_F.DAT", "rb");
    FILE* G = fopen("GRUPO_G.DAT", "rb");
    FILE* H = fopen("GRUPO_H.DAT", "rb");
    tipoClasificado regClasificado;
    int contador = 0;
    int i;
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, A);
        strcpy(vectorEquipos[contador].nombreEquipo, regClasificado.nombreEquipo);
        vectorEquipos[contador].letraGrupo = 'A';
        strcpy(vectorEquipos[contador].confederacion, regClasificado.confederacion);
        contador++;
    }
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, B);
        strcpy(vectorEquipos[contador].nombreEquipo, regClasificado.nombreEquipo);
        vectorEquipos[contador].letraGrupo = 'B';
        strcpy(vectorEquipos[contador].confederacion, regClasificado.confederacion);
        contador++;
    }
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, C);
        strcpy(vectorEquipos[contador].nombreEquipo, regClasificado.nombreEquipo);
        vectorEquipos[contador].letraGrupo = 'C';
        strcpy(vectorEquipos[contador].confederacion, regClasificado.confederacion);
        contador++;
    }
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, D);
        strcpy(vectorEquipos[contador].nombreEquipo, regClasificado.nombreEquipo);
        vectorEquipos[contador].letraGrupo = 'D';
        strcpy(vectorEquipos[contador].confederacion, regClasificado.confederacion);
        contador++;
    }
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, E);
        strcpy(vectorEquipos[contador].nombreEquipo, regClasificado.nombreEquipo);
        vectorEquipos[contador].letraGrupo = 'E';
        strcpy(vectorEquipos[contador].confederacion, regClasificado.confederacion);
        contador++;
    }
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, F);
        strcpy(vectorEquipos[contador].nombreEquipo, regClasificado.nombreEquipo);
        vectorEquipos[contador].letraGrupo = 'F';
        strcpy(vectorEquipos[contador].confederacion, regClasificado.confederacion);
        contador++;
    }
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, G);
        strcpy(vectorEquipos[contador].nombreEquipo, regClasificado.nombreEquipo);
        vectorEquipos[contador].letraGrupo = 'G';
        strcpy(vectorEquipos[contador].confederacion, regClasificado.confederacion);
        contador++;
    }
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, H);
        strcpy(vectorEquipos[contador].nombreEquipo, regClasificado.nombreEquipo);
        vectorEquipos[contador].letraGrupo = 'H';
        strcpy(vectorEquipos[contador].confederacion, regClasificado.confederacion);
        contador++;
    }
    fclose(A);
    fclose(B);
    fclose(C);
    fclose(D);
    fclose(E);
    fclose(F);
    fclose(G);
    fclose(H);
};

void ordenarPorGrupo(tipoClasificado2 (&vectorEquipos)[32]) {
    tipoClasificado2 aux;
    int i, j;
	for (i = 0; i < 32; i++) {
        for (j = 0; j < 31; j++) {
            if (vectorEquipos[j].letraGrupo > vectorEquipos[j + 1].letraGrupo) {
                aux = vectorEquipos[j + 1];
				vectorEquipos[j + 1] = vectorEquipos[j];
				vectorEquipos[j] = aux;
			}
		}
	}
};

void ordenarPorNombre(tipoClasificado2 (&vectorEquipos)[32]) {
    tipoClasificado2 aux;
    int i, j;
	for (i = 0; i < 32; i++) {
        for (j = 0; j < 31; j++) {
            if (strcmp(vectorEquipos[j].nombreEquipo, vectorEquipos[j + 1].nombreEquipo) > 0) {
                aux = vectorEquipos[j + 1];
				vectorEquipos[j + 1] = vectorEquipos[j];
				vectorEquipos[j] = aux;
			}
		}
	}
};

void ordenarPorConfederacion(tipoClasificado2 (&vectorEquipos)[32], int inicio, int fin) {
    tipoClasificado2 aux;
    int i, j;
    for (i = 0; i < fin - inicio; i++) {
        for (j = inicio; j < fin - 1; j++) {
            if (strcmp(vectorEquipos[j].confederacion, vectorEquipos[j + 1].confederacion) > 0) {
                aux = vectorEquipos[j + 1];
				vectorEquipos[j + 1] = vectorEquipos[j];
				vectorEquipos[j] = aux;
			}
        }
    }
};

void ordenarPorGrupoConfederacion(tipoClasificado2 (&vectorEquipos)[32]) {
    tipoClasificado2 aux;
    ordenarPorGrupo(vectorEquipos);
    ordenarPorConfederacion(vectorEquipos, 0, 4);
    ordenarPorConfederacion(vectorEquipos, 4, 8);
    ordenarPorConfederacion(vectorEquipos, 8, 12);
    ordenarPorConfederacion(vectorEquipos, 12, 16);
    ordenarPorConfederacion(vectorEquipos, 16, 20);
    ordenarPorConfederacion(vectorEquipos, 20, 24);
    ordenarPorConfederacion(vectorEquipos, 24, 28);
    ordenarPorConfederacion(vectorEquipos, 28, 32);
};

void ordenarPorConfederacionNombre(tipoClasificado2 (&vectorEquipos)[32], int inicio, int fin) {
    tipoClasificado2 aux;
    int i, j;
    for (j = inicio; j < fin - 1; j++) {
        if (strcmp(vectorEquipos[j].confederacion, vectorEquipos[j + 1].confederacion) == 0) {
            if (strcmp(vectorEquipos[j].nombreEquipo, vectorEquipos[j + 1].nombreEquipo) > 0) {
                aux = vectorEquipos[j + 1];
                vectorEquipos[j + 1] = vectorEquipos[j];
                vectorEquipos[j] = aux;
                break; // Solo se ordena por nombre cuando hay dos equipos de la UEFA en un mismo grupo
            }
        }
    }
}

void ordenarPorGrupoConfederacionNombre(tipoClasificado2 (&vectorEquipos)[32]) {
    tipoClasificado2 aux;
    ordenarPorGrupoConfederacion(vectorEquipos);
    ordenarPorConfederacionNombre(vectorEquipos, 0, 4);
    ordenarPorConfederacionNombre(vectorEquipos, 4, 8);
    ordenarPorConfederacionNombre(vectorEquipos, 8, 12);
    ordenarPorConfederacionNombre(vectorEquipos, 12, 16);
    ordenarPorConfederacionNombre(vectorEquipos, 16, 20);
    ordenarPorConfederacionNombre(vectorEquipos, 20, 24);
    ordenarPorConfederacionNombre(vectorEquipos, 24, 28);
    ordenarPorConfederacionNombre(vectorEquipos, 28, 32);
};