#include <iostream>

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

void ordenarPorEquipoFecha(tipoGol (&vectorGoles)[157]) {
	tipoGol aux;
    for (int i = 0; i < 157; i++) {
        for (int j = 0; j < 156; j++) {
            if (vectorGoles[j].codigoEquipo > vectorGoles[j + 1].codigoEquipo) {
                aux = vectorGoles[j + 1];
                vectorGoles[j + 1] = vectorGoles[j];
                vectorGoles[j] = aux;
            }
            else if ((vectorGoles[j].codigoEquipo == vectorGoles[j + 1].codigoEquipo) && (vectorGoles[j].fecha > vectorGoles[j + 1].fecha)) {
                aux = vectorGoles[j + 1];
                vectorGoles[j + 1] = vectorGoles[j];
                vectorGoles[j] = aux;
            }
        }
    }
};

int main() {
    FILE* G = fopen("GOLES.DAT", "wb");
    tipoGol vectorGoles[] = {
        {1, Rusia, 20180614, "Gazinsky", 1},
        {2, Rusia, 20180614, "Cheryshev", 1},
        {3, Rusia, 20180614, "Dzyuba", 1},
        {4, Rusia, 20180614, "Cheryshev", 1},
        {5, Rusia, 20180614, "Golovin", 1},
        {6, Uruguay, 20180615, "Gimenez", 2},
        {8, Portugal, 20180615, "Ronaldo", 4},
        {9, Espana, 20180615, "D. Costa", 4},
        {10, Portugal, 20180615, "Ronaldo", 4},
        {11, Espana, 20180615, "D. Costa", 4},
        {12, Espana, 20180615, "Nacho", 4},
        {13, Portugal, 20180615, "Ronaldo", 4},
        {14, Francia, 20180616, "Griezmann", 5},
        {15, Australia, 20180616, "Jedinak", 5},
        {17, Argentina, 20180616, "Aguero", 6},
        {18, Islandia, 20180616, "Finnbogason", 6},
        {19, Dinamarca, 20180616, "Poulsen", 7},
        {21, Croacia, 20180616, "Modric", 8},
        {22, Serbia, 20180617, "Kolarov", 9},
        {23, Mexico, 20180617, "Lozano", 10},
        {24, Brasil, 20180617, "Coutinho", 11},
        {25, Suiza, 20180617, "Zuber", 11},
        {26, Suecia, 20180618, "Granqvist", 12},
        {27, Belgica, 20180618, "Mertens", 13},
        {28, Belgica, 20180618, "Lukaku", 13},
        {29, Belgica, 20180618, "Lukaku", 13},
        {30, Inglaterra, 20180618, "Kane", 14},
        {31, Tunez, 20180618, "Sassi", 14},
        {32, Inglaterra, 20180618, "Kane", 14},
        {33, Japon, 20180619, "Kagawa", 15},
        {34, Colombia, 20180619, "Quintero", 15},
        {35, Japon, 20180619, "Osako", 15},
        {37, Senegal, 20180619, "Niang", 16},
        {38, Polonia, 20180619, "Krychowiak", 16},
        {40, Rusia, 20180619, "Cheryshev", 17},
        {41, Rusia, 20180619, "Dzyuba", 17},
        {42, Egipto, 20180619, "Salah", 17},
        {43, Portugal, 20180620, "Ronaldo", 18},
        {44, Uruguay, 20180620, "Suarez", 19},
        {45, Espana, 20180620, "D. Costa", 20},
        {46, Dinamarca, 20180621, "Eriksen", 21},
        {47, Australia, 20180621, "Jedinak", 21},
        {48, Francia, 20180621, "Mbappe", 22},
        {49, Croacia, 20180621, "Rebic", 23},
        {50, Croacia, 20180621, "Modric", 23},
        {51, Croacia, 20180621, "Rakitic", 23},
        {52, Brasil, 20180622, "Coutinho", 24},
        {53, Brasil, 20180622, "Neymar", 24},
        {54, Nigeria, 20180622, "Musa", 25},
        {55, Nigeria, 20180622, "Musa", 25},
        {56, Serbia, 20180622, "Mitrovic", 26},
        {57, Suiza, 20180622, "Xhaka", 26},
        {58, Suiza, 20180622, "Shaqiri", 26},
        {59, Belgica, 20180623, "Hazard", 27},
        {60, Belgica, 20180623, "Lukaku", 27},
        {61, Tunez, 20180623, "Brown", 27},
        {62, Belgica, 20180623, "Lukaku", 27},
        {63, Belgica, 20180623, "Hazard", 27},
        {64, Belgica, 20180623, "Batshuayi", 27},
        {65, Tunez, 20180623, "Khazri", 27},
        {66, Mexico, 20180623, "Vela", 28},
        {67, Mexico, 20180623, "Hernandez", 28},
        {68, Corea_del_Sur, 20180623, "Heungmin", 28},
        {69, Suecia, 20180623, "Toivonen", 29},
        {70, Alemania, 20180623, "Reus", 29},
        {71, Alemania, 20180623, "Kroos", 29},
        {72, Inglaterra, 20180624, "Stones", 30},
        {73, Inglaterra, 20180624, "Kane", 30},
        {74, Inglaterra, 20180624, "Lingard", 30},
        {75, Inglaterra, 20180624, "Stones", 30},
        {76, Inglaterra, 20180624, "Kane", 30},
        {77, Inglaterra, 20180624, "Kane", 30},
        {78, Panama, 20180624, "Baloy", 30},
        {79, Senegal, 20180624, "Mane", 31},
        {80, Japon, 20180624, "Inui", 31},
        {81, Senegal, 20180624, "Wague", 31},
        {82, Japon, 20180624, "Honda", 31},
        {83, Colombia, 20180624, "Mina", 32},
        {84, Colombia, 20180624, "Falcao", 32},
        {85, Colombia, 20180624, "Cuadrado", 32},
        {86, Uruguay, 20180625, "Suarez", 33},
        {88, Uruguay, 20180625, "Cavani", 33},
        {89, Egipto, 20180625, "Salah", 34},
        {90, Arabia_Saudita, 20180625, "Alfaraj", 34},
        {91, Arabia_Saudita, 20180625, "Aldawsari", 34},
        {92, Marruecos, 20180625, "Boutaib", 35},
        {93, Espana, 20180625, "Isco", 35},
        {94, Marruecos, 20180625, "En Nesyri", 35},
        {95, Espana, 20180625, "Aspas", 35},
        {96, Portugal, 20180625, "Quaresma", 36},
        {97, Iran, 20180625, "Ansarifard", 36},
        {98, Peru, 20180626, "Carrillo", 37},
        {99, Peru, 20180626, "Guerrero", 37},
        {100, Argentina, 20180626, "Messi", 39},
        {101, Nigeria, 20180626, "Moses", 39},
        {102, Argentina, 20180626, "Rojo", 39},
        {103, Croacia, 20180626, "Badelj", 40},
        {104, Islandia, 20180626, "Sigurdsson", 40},
        {105, Croacia, 20180626, "Perisic", 40},
        {106, Corea_del_Sur, 20180627, "Younggwon", 41},
        {107, Corea_del_Sur, 20180627, "Heungmin", 41},
        {108, Suecia, 20180627, "Augustinsson", 42},
        {109, Suecia, 20180627, "Granqvist", 42},
        {111, Brasil, 20180627, "Paulinho", 43},
        {112, Brasil, 20180627, "Thiago Silva", 43},
        {113, Suiza, 20180627, "Dzemali", 44},
        {114, Costa_Rica, 20180627, "Waston", 44},
        {115, Suiza, 20180627, "Drmic", 44},
        {117, Polonia, 20180628, "Bednarek", 45},
        {118, Colombia, 20180628, "Mina", 46},
        {120, Tunez, 20180628, "Ben Youssef", 47},
        {121, Tunez, 20180628, "Khazri", 47},
        {122, Belgica, 20180628, "Januzaj", 48},
        {123, Francia, 20180630, "Griezmann", 49},
        {124, Argentina, 20180630, "Di Maria", 49},
        {125, Argentina, 20180630, "Mercado", 49},
        {126, Francia, 20180630, "Pavard", 49},
        {127, Francia, 20180630, "Mbappe", 49},
        {128, Francia, 20180630, "Mbappe", 49},
        {129, Argentina, 20180630, "Aguero", 49},
        {130, Uruguay, 20180630, "Cavani", 50},
        {131, Portugal, 20180630, "Pepe", 50},
        {132, Uruguay, 20180630, "Cavani", 50},
        {134, Rusia, 20180701, "Dzyuba", 51},
        {135, Dinamarca, 20180701, "Jorgensen", 52},
        {136, Croacia, 20180701, "Mandzukic", 52},
        {137, Brasil, 20180702, "Neymar", 53},
        {138, Brasil, 20180702, "Roberto Firmino", 53},
        {139, Japon, 20180702, "Haraguchi", 54},
        {140, Japon, 20180702, "Inui", 54},
        {141, Belgica, 20180702, "Vertonghen", 54},
        {142, Belgica, 20180702, "Fellaini", 54},
        {143, Belgica, 20180702, "Chadli", 54},
        {144, Suecia, 20180703, "Forsberg", 55},
        {145, Inglaterra, 20180703, "Kane", 56},
        {146, Colombia, 20180703, "Mina", 56},
        {147, Francia, 20180706, "Varane", 57},
        {148, Francia, 20180706, "Griezmann", 57},
        {150, Belgica, 20180706, "De Bruyne", 58},
        {151, Brasil, 20180706, "Renato Augusto", 58},
        {152, Inglaterra, 20180707, "Maguire", 59},
        {153, Inglaterra, 20180707, "Alli", 59},
        {154, Rusia, 20180707, "Cheryshev", 60},
        {155, Croacia, 20180707, "Kramaric", 60},
        {156, Croacia, 20180707, "Vida", 60},
        {157, Rusia, 20180707, "Fernandes", 60},
        {158, Francia, 20180710, "Umtiti", 61},
        {159, Inglaterra, 20180711, "Trippier", 62},
        {160, Croacia, 20180711, "Perisic", 62},
        {161, Croacia, 20180711, "Mandzukic", 62},
        {162, Belgica, 20180714, "Meunier", 63},
        {163, Belgica, 20180714, "Hazard", 63},
        {165, Croacia, 20180715, "Perisic", 64},
        {166, Francia, 20180715, "Griezmann", 64},
        {167, Francia, 20180715, "Pogba", 64},
        {168, Francia, 20180715, "Mbappe", 64},
        {169, Croacia, 20180715, "Mandzukic", 64},
	};

    // Es importante conocer el tamaño del vector
    ordenarPorEquipoFecha(vectorGoles);
    for (int i = 0; i < 157; i++) {
        fwrite(&vectorGoles[i], sizeof(tipoGol), 1, G);
    }
    fclose(G);
    system("PAUSE");
    return 0;
}