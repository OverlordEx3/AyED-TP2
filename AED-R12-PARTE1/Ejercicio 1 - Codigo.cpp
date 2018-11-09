#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

typedef char cadena[30];

struct tipoClasificado {
    int numeroBolillero;
    cadena nombreEquipo;
    cadena confederacion;
    int codigoConfederacion; // 0: AFC, 1: CAF, 2: Concacaf, 3: Conmebol, 4: OFC, 5: UEFA
};

void generarBolillerosAuto();
void generarBolillerosMan();
void leerArchivo();

int main () {
    int opcion;
    do {
        cout
            << "MENU PRINCIPAL DEL EJERCICIO 1" << endl
            << "1: Generar archivo automaticamente" << endl
            << "2: Generar archivo manualmente" << endl
            << "3: Leer archivo generado" << endl
            << "0: Salir" << endl
            << "Ingrese opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion) {
            case 0:
                system("PAUSE");
                return 0;
            case 1:
                generarBolillerosAuto();
                break;
            case 2:
                generarBolillerosMan();
                break;
            case 3:
                leerArchivo();
                break;
        }
    } while (opcion != 0);
}

void generarBolillerosAuto() {
    FILE* BOL = fopen("BOLILLEROS.DAT", "wb");
	tipoClasificado regClasificado;
    tipoClasificado vectorEquipos[32] = {
        {1, "Rusia", "UEFA", 5},
        {1, "Alemania", "UEFA", 5},
        {1, "Brasil", "Conmebol", 3},
        {1, "Portugal", "UEFA", 5},
        {1, "Argentina", "Conmebol", 3},
        {1, "Belgica", "UEFA", 5},
        {1, "Polonia", "UEFA", 5},
        {1, "Francia", "UEFA", 5},
        {2, "Espana", "UEFA", 5},
        {2, "Peru", "Conmebol", 3},
        {2, "Suiza", "UEFA", 5},
        {2, "Inglaterra", "UEFA", 5},
        {2, "Colombia", "Conmebol", 3},
        {2, "Mexico", "Concacaf", 2},
        {2, "Uruguay", "Conmebol", 3},
        {2, "Croacia", "UEFA", 5},
        {3, "Dinamarca", "UEFA", 5},
        {3, "Islandia", "UEFA", 5},
        {3, "Costa Rica", "Concacaf", 2},
        {3, "Suecia", "UEFA", 5},
        {3, "Tunez", "CAF", 1},
        {3, "Egipto", "CAF", 1},
        {3, "Senegal", "CAF", 1},
        {3, "Iran", "AFC", 0},
        {4, "Serbia", "UEFA", 5},
        {4, "Nigeria", "CAF", 1},
        {4, "Australia", "AFC", 0},
        {4, "Japon", "AFC", 0},
        {4, "Marruecos", "CAF", 1},
        {4, "Panama", "Concacaf", 2},
        {4, "Corea del Sur", "AFC", 0},
        {4, "Arabia Saudita", "AFC", 0},
    };
    cout << "Generando archivo..." << endl;
    Sleep(3000);
    int i;
    for (i = 0; i < 32; i++) {
        regClasificado = vectorEquipos[i];
        fwrite(&regClasificado, sizeof(tipoClasificado), 1, BOL);
    }
    fclose(BOL);
    cout << "CARGA EXITOSA" << endl << endl;
}

void generarBolillerosMan() {
	FILE* BOL = fopen("BOLILLEROS.DAT", "wb");
	tipoClasificado regClasificado;
	int i;
	for (i = 0; i < 32; i++) {
        switch (i) {
            case 0:
                cout << "BOLILLERO 1" << endl;
                break;
            case 8:
                cout << "BOLILLERO 2" << endl;
                break;
            case 16:
                cout << "BOLILLERO 3" << endl;
                break;
            case 24:
                cout << "BOLILLERO 4" << endl;
                break;
            default:
                break;
        }
		cout << "EQUIPO " << i + 1 << endl;
        if ((i >= 0) && (i < 8)) {
            regClasificado.numeroBolillero = 1;
        }
        else if ((i >= 8) && (i < 16)) {
            regClasificado.numeroBolillero = 2;
        }
        else if ((i >= 16) && (i < 24)) {
            regClasificado.numeroBolillero = 3;
        }
        else {
            regClasificado.numeroBolillero = 4;
        }
		cout << "Nombre del equipo: ";
        fflush(stdin); // Limpieza de buffer
		cin.getline(regClasificado.nombreEquipo, 30, '\n');
        cout << "Codigo de confederacion (0: AFC, 1: CAF, 2: Concacaf, 3: Conmebol, 4: OFC, 5: UEFA): ";
		cin >> regClasificado.codigoConfederacion;
        switch (regClasificado.codigoConfederacion) {
            case 0:
                strcpy(regClasificado.confederacion, "AFC");
                break;
            case 1:
                strcpy(regClasificado.confederacion, "CAF");
                break;
            case 2:
                strcpy(regClasificado.confederacion, "Concacaf");
                break;
            case 3:
                strcpy(regClasificado.confederacion, "Conmebol");
                break;
            case 4:
                strcpy(regClasificado.confederacion, "OFC");
                break;
            case 5:
                strcpy(regClasificado.confederacion, "UEFA");
                break;
		}
		fwrite(&regClasificado, sizeof(tipoClasificado), 1, BOL);
        cout << endl;
	}
	fclose(BOL);
	cout << "CARGA EXITOSA" << endl << endl;
}

void leerArchivo() {
    FILE* BOL = fopen("BOLILLEROS.DAT", "rb");
    tipoClasificado regClasificado;
    cout << "Leyendo archivo..." << endl;
    Sleep(3000);
    int i;
    cout << "BOLILLERO 1" << endl;
    for (i = 0; i < 8; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, BOL);
        cout << regClasificado.nombreEquipo << " - " << regClasificado.confederacion << endl;
    }
    cout << endl << "BOLILLERO 2" << endl;
    for (i = 8; i < 16; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, BOL);
        cout << regClasificado.nombreEquipo << " - " << regClasificado.confederacion << endl;
    }
    cout << endl << "BOLILLERO 3" << endl;
    for (i = 16; i < 24; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, BOL);
        cout << regClasificado.nombreEquipo << " - " << regClasificado.confederacion << endl;
    }
    cout << endl << "BOLILLERO 4" << endl;
    for (i = 24; i < 32; i++) {
        fread(&regClasificado, sizeof(tipoClasificado), 1, BOL);
        cout << regClasificado.nombreEquipo << " - " << regClasificado.confederacion << endl;
    }
    fclose(BOL);
    cout << endl;
};