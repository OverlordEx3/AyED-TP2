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

struct registroGol {
    int idGol;
    int codigoDeEquipo;
    int fecha;
    cadena nombreDelJugador;
    int idPartido;    
};

int main() {
    FILE* G = fopen("GOLES.DAT", "rb");
    registroGol regGol;
    cout << "ID GOL\tID EQUIPO\tFECHA\tJUGADOR\tID PARTIDO" << endl;
    fread(&regGol, sizeof(registroGol), 1, G);
    while (!feof(G)) {
        cout << regGol.idGol << "\t" << regGol.codigoDeEquipo << "\t" << regGol.fecha << "\t" << regGol.nombreDelJugador << "\t" << regGol.idPartido << endl;
        fread(&regGol, sizeof(registroGol), 1, G);
    }
    fclose(G);
    system("PAUSE");
    return 0;
}