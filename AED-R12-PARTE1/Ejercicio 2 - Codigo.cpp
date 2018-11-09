#include <iostream>
#include <stdio.h> // Para el uso de NULL
#include <stdlib.h> // Para el uso de rand() y srand()
#include <time.h> // Para el uso de time()
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

bool verificarConfederacion(int contadorEquipos, int codigoConfederacion); // Verifica la confederacion de un equipo e indica si es apto o no para un grupo
void convertirMatriz(tipoClasificado matrizGrupos[4][8]); // Toma los datos de la matriz de equipos/grupos definitiva y crea los archivos GRUPO_X.DAT
bool sortearBolillero(int a, int b, tipoClasificado (&matrizGrupos)[4][8], bool (&equipoUtilizado)[32], int (&contadorEquipos)[6][8]); // Sortea los equipos de un bolillero
void sortearGrupos(); // Sortea todos los bolilleros
void mostrarGrupos();

int main () {
    int opcion;
    do {
        cout
            << "MENU PRINCIPAL DEL EJERCICIO 2" << endl
            << "1: Sortear grupos" << endl
            << "2: Mostrar grupos" << endl
            << "0: Salir" << endl
            << "Ingrese opcion: ";
        
        cin >> opcion;
        cout << endl;
        switch (opcion) {
            case 0:
                system("PAUSE");
                return 0;
            case 1:
                sortearGrupos();
                break;
            case 2:
                mostrarGrupos();
                break;
        }
    } while (opcion != 0);
}

bool verificarConfederacion(int contadorEquipos, int codigoConfederacion) {
    switch (codigoConfederacion) {
        case 0: // AFC
            return (contadorEquipos < 1) ? true : false;
            break;
        case 1: // CAF
            return (contadorEquipos < 1) ? true : false;
            break;
        case 2: // Concacaf
            return (contadorEquipos < 1) ? true : false;
            break;
        case 3: // Conmebol
            return (contadorEquipos < 1) ? true : false;
            break;
        case 4: // OFC
            return (contadorEquipos < 1) ? true : false;
            break;
        case 5: // UEFA
            return (contadorEquipos < 2) ? true : false;
            break;
    }
};

void convertirMatriz(tipoClasificado matrizGrupos[4][8]) {
    FILE* A = fopen("GRUPO_A.DAT", "wb");
    FILE* B = fopen("GRUPO_B.DAT", "wb");
    FILE* C = fopen("GRUPO_C.DAT", "wb");
    FILE* D = fopen("GRUPO_D.DAT", "wb");
    FILE* E = fopen("GRUPO_E.DAT", "wb");
    FILE* F = fopen("GRUPO_F.DAT", "wb");
    FILE* G = fopen("GRUPO_G.DAT", "wb");
    FILE* H = fopen("GRUPO_H.DAT", "wb");
    int i, j;
    for (i = 0; i < 4; i++) { // Recorre la matriz verticalmente (Bol 1, Bol 2, Bol 3, Bol 4)
        for (j = 0; j < 8; j++) { // Recorre la matriz horizontalmente (Grupo A, Grupo B, ..., Grupo H)
            switch (j) {
                case 0: // Grabo en archivo GRUPO_A.DAT
                    fwrite(&matrizGrupos[i][j], sizeof(tipoClasificado), 1, A);
                    break;
                case 1: // Grabo en archivo GRUPO_B.DAT
                    fwrite(&matrizGrupos[i][j], sizeof(tipoClasificado), 1, B);
                    break;
                case 2: // Grabo en archivo GRUPO_C.DAT
                    fwrite(&matrizGrupos[i][j], sizeof(tipoClasificado), 1, C);
                    break;
                case 3: // Grabo en archivo GRUPO_D.DAT
                    fwrite(&matrizGrupos[i][j], sizeof(tipoClasificado), 1, D);
                    break;
                case 4: // Grabo en archivo GRUPO_E.DAT
                    fwrite(&matrizGrupos[i][j], sizeof(tipoClasificado), 1, E);
                    break;
                case 5: // Grabo en archivo GRUPO_F.DAT
                    fwrite(&matrizGrupos[i][j], sizeof(tipoClasificado), 1, F);
                    break;
                case 6: // Grabo en archivo GRUPO_G.DAT
                    fwrite(&matrizGrupos[i][j], sizeof(tipoClasificado), 1, G);
                    break;
                case 7: // Grabo en archivo GRUPO_H.DAT
                    fwrite(&matrizGrupos[i][j], sizeof(tipoClasificado), 1, H);
                    break;
            }
        }
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

bool sortearBolillero(int a, int b, tipoClasificado (&matrizGrupos)[4][8], bool (&equipoUtilizado)[32], int (&contadorEquipos)[6][8]) {
    FILE* BOL = fopen("BOLILLEROS.DAT", "rb");
    tipoClasificado regClasificado;
    bool equipoDisponible = false; // Funciona como bandera cuando se encuentra un equipo compatible
    int contadorIntentos = 0; // Cuenta los intentos de búsqueda
    int i, j, num;
    int contadorEquipos_Copia[6][8];
    for (i = a; i <= b; i++) { // Inicializo la parte del arreglo con la que estoy trabajando
        equipoUtilizado[i] = false;
    }
    for (i = 0; i < 6; i++) { // Copio la matriz de contadores
        for (j = 0; j < 8; j++) {
            contadorEquipos_Copia[i][j] = contadorEquipos[i][j];
        }
    }
    for (i = 0; i < 8; i++) {
        equipoDisponible = false;
        contadorIntentos = 0;
        while (!equipoDisponible) {
            if (contadorIntentos > 1000) { // Si realiza una determinada cantidad de intentos y no encuentra un equipo compatible, cancela la busqueda para sortear todo el bolillero nuevamente
                return false;
            }
            num = (rand() % 8) + a; // Número al azar entre a y b
            while (equipoUtilizado[num]) { // Selecciona un numero al azar hasta que encuentre un equipo que NO haya sido sorteado
                num = (rand() % 8) + a;
            }
            fseek(BOL, num*sizeof(tipoClasificado), SEEK_SET); // Se posiciona en el equipo encontrado
            fread(&regClasificado, sizeof(tipoClasificado), 1, BOL);
            equipoDisponible = verificarConfederacion(contadorEquipos[regClasificado.codigoConfederacion][i], regClasificado.codigoConfederacion); // Verifica que no existan equipos de la misma confederacion en el grupo
            contadorIntentos++; // Lleva una cuenta de los intentos realizados
        }
        matrizGrupos[regClasificado.numeroBolillero - 1][i] = regClasificado;
        equipoUtilizado[num] = true;
        contadorEquipos_Copia[regClasificado.codigoConfederacion][i]++;
    }
    for (i = 0; i < 6; i++) { // Si supera el sorteo, grabo los datos en la matriz de contadores original
        for (j = 0; j < 8; j++) {
            contadorEquipos[i][j] = contadorEquipos_Copia[i][j];
        }
    }
    fclose(BOL);
    return true;
};

void sortearGrupos() {
    FILE* BOL = fopen("BOLILLEROS.DAT", "rb");
    tipoClasificado regClasificado;
    tipoClasificado matrizGrupos[4][8]; // Distribución de los equipos de cada bolillero en los grupos
    bool equipoUtilizado[32] = {false}; // Indica con "true" los equipos que ya fueron sorteados
    bool check; // Verifica si una función se ejecutó correctamente
    int i, j, num; // Variables comunes
    int contadorEquipos[6][8]; // Cantidad de equipos de una determinada confederación en cada grupo
    for (i = 0; i < 6; i++) { // Inicialización de contadores
        for (j = 0; j < 8; j++) {
            contadorEquipos[i][j] = 0;
        }
    }
    srand(time(NULL));
    cout << "Sorteando grupos..." << endl;
    Sleep(3000);
    for (i = 0; i < 8; i++) { // Sorteo bolillero 1. La "i" me indica sobre qué grupo se está trabajando
        if (i == 0) { // Primer caso
            fseek(BOL, 0, SEEK_SET);
            fread(&regClasificado, sizeof(tipoClasificado), 1, BOL);
            matrizGrupos[regClasificado.numeroBolillero - 1][i] = regClasificado;
            equipoUtilizado[0] = true;
            contadorEquipos[regClasificado.codigoConfederacion][i]++;
        }
        else {
            num = rand() % 8; // Número al azar entre 0 y 7
            while (equipoUtilizado[num]) {
                num = rand() % 8;
            }
            fseek(BOL, num*sizeof(tipoClasificado), SEEK_SET);
            fread(&regClasificado, sizeof(tipoClasificado), 1, BOL);
            matrizGrupos[regClasificado.numeroBolillero - 1][i] = regClasificado;
            equipoUtilizado[num] = true;
            contadorEquipos[regClasificado.codigoConfederacion][i]++;
        }
    }
    check = false;
    while (!check) { // Sorteo bolillero 2
        check = sortearBolillero(8, 15, matrizGrupos, equipoUtilizado, contadorEquipos);
    }
    check = false;
    while (!check) { // Sorteo bolillero 3
        check = sortearBolillero(16, 23, matrizGrupos, equipoUtilizado, contadorEquipos);
    }
    check = false;
    while (!check) { // Sorteo bolillero 4
        check = sortearBolillero(24, 31, matrizGrupos, equipoUtilizado, contadorEquipos);
    }
    convertirMatriz(matrizGrupos);
    fclose(BOL);
	cout << "SORTEO EXITOSO" << endl << endl;
};

void mostrarGrupos() {
    FILE* A = fopen("GRUPO_A.DAT", "rb");
    FILE* B = fopen("GRUPO_B.DAT", "rb");
    FILE* C = fopen("GRUPO_C.DAT", "rb");
    FILE* D = fopen("GRUPO_D.DAT", "rb");
    FILE* E = fopen("GRUPO_E.DAT", "rb");
    FILE* F = fopen("GRUPO_F.DAT", "rb");
    FILE* G = fopen("GRUPO_G.DAT", "rb");
    FILE* H = fopen("GRUPO_H.DAT", "rb");
    tipoClasificado regClasificado;
    cout << "Leyendo grupos..." << endl;
    Sleep(3000);
    int i;
    cout << "GRUPO A" << endl;
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, A);
        cout << regClasificado.nombreEquipo << " - " << regClasificado.confederacion << endl;
    }
    cout << endl << "GRUPO B" << endl;
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, B);
        cout << regClasificado.nombreEquipo << " - " << regClasificado.confederacion << endl;
    }
    cout << endl << "GRUPO C" << endl;
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, C);
        cout << regClasificado.nombreEquipo << " - " << regClasificado.confederacion << endl;
    }
    cout << endl << "GRUPO D" << endl;
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, D);
        cout << regClasificado.nombreEquipo << " - " << regClasificado.confederacion << endl;
    }
    cout << endl << "GRUPO E" << endl;
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, E);
        cout << regClasificado.nombreEquipo << " - " << regClasificado.confederacion << endl;
    }
    cout << endl << "GRUPO F" << endl;
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, F);
        cout << regClasificado.nombreEquipo << " - " << regClasificado.confederacion << endl;
    }
    cout << endl << "GRUPO G" << endl;
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, G);
        cout << regClasificado.nombreEquipo << " - " << regClasificado.confederacion << endl;
    }
    cout << endl << "GRUPO H" << endl;
    for (i = 0; i < 4; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, H);
        cout << regClasificado.nombreEquipo << " - " << regClasificado.confederacion << endl;
    }
    fclose(A);
    fclose(B);
    fclose(C);
    fclose(D);
    fclose(E);
    fclose(F);
    fclose(G);
    fclose(H);
    cout << endl;
};