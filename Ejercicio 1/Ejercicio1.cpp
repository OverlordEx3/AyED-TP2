#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

/* Incluyo la definicion de la estructura de gol */
#include "DefinicionEstructura.h"

/* Definiciones y etiquetas del usuario */
#define NOMBRE_ARCH_GOLES_ORIGINAL "goles2018.dat\0"
#define NOMBRE_ARCH_GOLES_ORDENADO "archivogol.dat\0"

using namespace std;

/*######################################## ZONA FUNCION AUX #########################################*/

/* Nombre					CodigoDeEquipoValido
 * Desc:					Valida que el codigo de equipo este dentro del rango.
 * Param[ENT]			<int>"codigo" - Codigo de equipo a validar.
 * Retorno:				<bool> Verdadero si el codigo es valido, caso contrario falso.
 * */
bool CodigoDeEquipoValido(int codigo)
{
	if(codigo == 0)
	{
		return false;
	}

	if(codigo > ArabiaSaudita)
	{
		return false;
	}

	return true;
}

/* Nombre					FechaValida
 * Desc:					Valida la fecha del partido ingresado.
 * Param[ENT]			<unsigned int>"mes" - Mes del partido.
 * Param[ENT]			<unsigned int>"dia" - Dia del partido.
 * Retorno:				<bool> Verdadero si la fecha es valida, caso contrario falso.
 * */
bool FechaValida(unsigned int mes, unsigned int dia)
{
	if(mes < 06 || mes > 07)
	{
		return false;
	}

	if(mes == 06 && dia < 14)
	{
		return false;
	}

	if(mes == 06 && dia > 30)
	{
		return false;
	}

	if(mes == 07 && dia > 15)
	{
		return false;
	}

	return true;
}

/* Nombre					ConvierteEnMinusculas
 * Desc:					Convierte la cadena de texto pasada como parametro
 * 							en minusculas. La cadena debe terminar en caracter nulo.
 * Param[ENT]			<char *>"cadena" - Puntero a una cadena de texto terminada en nulo.
 * Retorno:				Nada.
 * */
void ConvierteEnMinusculas(char *cadena)
{
	size_t size;

	if(cadena != NULL)
	{
		size = strlen(cadena);

		for(size_t c = 0; c < size; c++) {
			cadena[c] = tolower(cadena[c]);
		}
	}
}

/* Nombre					CodigoDeEquipoDesdeNombre
 * Desc:					Regresa el codigo de equipo, segun el enum "Equipos", basandose
 * 							en la cadena de texto pasada como parametro.
 * Param[ENT]			<const char *>"cadena" - Puntero a una cadena de texto terminada en nulo.
 * Retorno:				<Entero> Codigo de equipo, basado en el enum "Equipos". En caso de ser invalido, regresa 0.
 * */
int CodigoDeEquipoDesdeNombre(const char* cadena)
{
	/* Convierto la cadena en minusculas */
	ConvierteEnMinusculas((char *)cadena);

	if(strcmp("rusia", cadena) == 0)
	{
		return Rusia;
	} else if(strcmp("alemania", cadena) == 0)
	{
		return Alemania;
	} else if(strcmp("brasil", cadena) == 0)
	{
		return Brasil;
	} else if(strcmp("portugal", cadena) == 0)
	{
		return Portugal;
	} else if(strcmp("argentina", cadena) == 0)
	{
		return Argentina;
	} else if(strcmp("belgica", cadena) == 0)
	{
		return Belgica;
	} else if(strcmp("polonia", cadena) == 0)
	{
		return Polonia;
	} else if(strcmp("francia", cadena) == 0)
	{
		return Francia;
	} else if(strcmp("espana", cadena) == 0)
	{
		return Espana;
	}  else if(strcmp("peru", cadena) == 0)
	{
		return Peru;
	}  else if(strcmp("suiza", cadena) == 0)
	{
		return Suiza;
	} else if(strcmp("inglaterra", cadena) == 0)
	{
		return Inglaterra;
	} else if(strcmp("colombia", cadena) == 0)
	{
		return Colombia;
	} else if(strcmp("mexico", cadena) == 0)
	{
		return Mexico;
	} else if(strcmp("uruguay", cadena) == 0)
	{
		return Uruguay;
	} else if(strcmp("croacia", cadena) == 0)
	{
		return Croacia;
	}  else if(strcmp("dinamarca", cadena) == 0)
	{
		return Dinamarca;
	} else if(strcmp("islandia", cadena) == 0)
	{
		return Islandia;
	} else if(strcmp("costa rica", cadena) == 0)
	{
		return CostaRica;
	} else if(strcmp("suecia", cadena) == 0)
	{
		return Suecia;
	} else if(strcmp("tunez", cadena) == 0)
	{
		return Tunez;
	}  else if(strcmp("egipto", cadena) == 0)
	{
		return Egipto;
	} else if(strcmp("senegal", cadena) == 0)
	{
		return Senegal;
	}  else if(strcmp("iran", cadena) == 0)
	{
		return Iran;
	} else if(strcmp("serbia", cadena) == 0)
	{
		return Serbia;
	} else if(strcmp("nigeria", cadena) == 0)
	{
		return Nigeria;
	} else if(strcmp("australia", cadena) == 0)
	{
		return Australia;
	} else if(strcmp("japon", cadena) == 0)
	{
		return Japon;
	} else if(strcmp("marruecos", cadena) == 0)
	{
		return Marruecos;
	} else if(strcmp("panama", cadena) == 0)
	{
		return Panama;
	} else if(strcmp("corea del sur", cadena) == 0)
	{
		return CoreaDelSur;
	} else if(strcmp("arabia saudita", cadena) == 0)
	{
		return ArabiaSaudita;
	}

	return 0;
}

/* Nombre					ImprimeGol
 * Desc:					Imprime la informacion formateada del gol pasado como parametro.
 * Param[ENT]			<RegistroGol *>"gol" - Puntero a una estructura de gol.
 * Retorno:				Nada.
 * */
void ImprimeGol(RegistroGol *gol)
{
	if(!gol)
	{
		/* Puntero invalido */
		return;
	}
	/* Se usa printf aca, ya que es mas sencillo formatear la salida */
	printf("%5d - %10d - %8d - %s\n", gol->idGol, gol->idPartido, gol->fecha, gol->nombreDelJugador);
}
/*#######################################FIN ZONA FUNCION AUX########################################*/

/*##################################### ZONA FUNCION INSERCION ######################################*/

/* Nombre					InsertarAlInicio
 * Desc:					Inserta un nuevo nodo al inicio de la lista, modificando la base.
 * Param[ENT]			<NodoGol *&>"base" - Referencia a la base de la lista.
 * Param[ENT]			<RegistroGol>"gol" - Registro del gol a insertar.
 * Retorno:				Nada.
 * */
static void InsertarAlInicio(NodoGol *&base, RegistroGol gol)
{
	NodoGol *nuevoNodo = new NodoGol();

	nuevoNodo->gol = gol;
	nuevoNodo->siguiente = base;
	base = nuevoNodo;
}

/* Nombre					Insertar
 * Desc:					Inserta un nuevo nodo despues del nodo apuntado por "destino".
 * Param[ENT]			<NodoGol *&>"destino" - Referencia al nodo anterior.
 * Param[ENT]			<RegistroGol>"gol" - Registro del gol a insertar.
 * Retorno:				Nada.
 * */
static void Insertar(NodoGol *&destino, RegistroGol gol)
{
	NodoGol *nuevoNodo = new NodoGol();

	nuevoNodo->gol = gol;
	nuevoNodo->siguiente = destino->siguiente;
	destino->siguiente = nuevoNodo;
}

/* Nombre					InsertarAlFinal
 * Desc:					Inserta un nuevo nodo al final de la lista.
 * Param[ENT]			<NodoGol *&>"destino" - Referencia al último nodo de la lista.
 * Param[ENT]			<RegistroGol>"gol" - Registro del gol a insertar.
 * Retorno:				Nada.
 * */
static void InsertarAlFinal(NodoGol *&destino, RegistroGol gol)
{
	NodoGol *nuevoNodo = new NodoGol();

	nuevoNodo->gol = gol;
	nuevoNodo->siguiente = NULL;
	destino->siguiente = nuevoNodo;
}
/*###################################### FIN ZONA INSERCION #######################################*/

/*##################################### ZONA FUNCION LISTAS #######################################*/

/* Nombre					GuardarNodoPorFecha
 * Desc:					Guarda el nodo segun su fecha, respetando el codigo de equipo.
 * Param[ENT]			<NodoGol *&>"anterior" - Referencia al nodo anterior.
 * Param[ENT]			<NodoGol *&>"base" - Referencia al primer nodo dentro de un codigo de equipo.
 * Param[ENT]			<RegistroGol>"gol" - Registro del gol a insertar.
 * Retorno:				Nada.
 * */
static void GuardarNodoPorFecha(NodoGol *&anterior, NodoGol* &base, RegistroGol gol)
{
	NodoGol *baseAux, *baseAnterior;

	/* Copio la base */
	baseAux = base;
	baseAnterior = anterior;
	while(baseAux != NULL && baseAux->gol.codigoDeEquipo == gol.codigoDeEquipo && gol.fecha >= baseAux->gol.fecha)
	{
		baseAnterior = baseAux;
		baseAux = baseAux->siguiente;
	}

	/*  Inserto nuevo nodo en la posicion hallada */
	if(baseAux == NULL)
	{
		/* Recorri la lista y no halle nada */
		InsertarAlFinal(baseAnterior, gol);
	} else if(baseAnterior == anterior) {
		/* La fecha del primer elemento es mayor
		 * La base auxiliar anterior no cambio */
		Insertar(anterior, gol);
	} else {
		Insertar(baseAnterior, gol);
	}
}

/* Nombre					GuardarNodo
 * Desc:					Guarda el nodo por codigo de equipo. Si hay mas de uno, lo ordena por fecha.
 * Param[ENT]			<NodoGol *&>"base" - Referencia a la base de la lista donde guardar.
 * Param[ENT]			<RegistroGol>"gol" - Registro del gol a insertar.
 * Retorno:				Nada.
 * */
static void GuardarNodo(NodoGol* &base, RegistroGol gol)
{
	NodoGol *baseAux, *baseAnterior;

	if(base == NULL)
	{
		InsertarAlInicio(base, gol);
		return;
	}


	/* Copio la base */
	baseAux = base;
	baseAnterior = base;

	while(baseAux != NULL && gol.codigoDeEquipo > baseAux->gol.codigoDeEquipo)
	{
		baseAnterior = baseAux;
		baseAux = baseAux->siguiente;
	}

	/*  Inserto nuevo nodo en la posicion hallada */
	if(baseAux == NULL)
	{
		/* Recorri la lista y no halle nada */
		InsertarAlFinal(baseAnterior, gol);
	} else if(baseAux->gol.codigoDeEquipo == gol.codigoDeEquipo)
	{
		/* Inserto por fecha */
		GuardarNodoPorFecha(baseAnterior, baseAux, gol);
	} else if(baseAux == baseAnterior) {
		/* Nuevo primer elemento */
		InsertarAlInicio(base, gol);
	} else {
		/* No era ni el primer ni el ultimo elemento,
		 * Ni tampoco habia nadie igual */
		Insertar(baseAnterior, gol);
	}

	return;
}

/* Nombre					MostrarNodos
 * Desc:					Muestra la lista.
 * Param[ENT]			<NodoGol *>"goles" - Lista a mostrar.
 * Retorno:				Nada.
 * */
void MostrarNodos(NodoGol *goles)
{
	NodoGol *aux = goles;
	int IdActual = 0;

	while(aux != NULL)
	{
		if(IdActual != aux->gol.codigoDeEquipo)
		{
			IdActual = aux->gol.codigoDeEquipo;
			/* Imprime encabezado */
			cout<<"-------------------------------------"<<endl;
			cout<<"Equipo #: " << IdActual << endl;
			cout<<"IdGol"<<" - " <<"Id Partido"<<" - "<<"  Fecha "<<" - "<<"Nombre de jugador"<<endl;
		}

		ImprimeGol(&aux->gol);

		aux = aux->siguiente;
	}
}
/*####################################### FIN ZONA LISTAS  ########################################*/

/*#################################### ZONA FUNCION ARCHIVOS ######################################*/

/* Nombre					MostrarArchivo
 * Desc:					Carga y recorre un archivo de goles. Puede ser tanto sin ordenar, como uno ya ordenado.
 * Param[ENT]			<const char *>"nombreArchivo" - Cadena con el nombre del archivo a abrir.
 * Retorno:				Nada.
 * */
void MostrarArchivo (const char *nombreArchivo)
{
	int IdActual=0 ;
	RegistroGol Gol;
	FILE *f;

	f = fopen (nombreArchivo,"rb");
	if (f == NULL)
	{
		cout << "Error al abrir el archivo " << nombreArchivo << endl;
		return;
	}

	fread (&Gol, sizeof(Gol), 1, f);
	while (!feof(f))
	{
		if(IdActual != Gol.codigoDeEquipo)
		{
			IdActual = Gol.codigoDeEquipo;
			/* Imprime encabezado */
			cout<<"-------------------------------------"<<endl;
			cout<<"Equipo #: " << IdActual << endl;
			cout<<"IdGol"<<" - " <<"Id Partido"<<" - "<<"  Fecha "<<" - "<<"Nombre de jugador"<<endl;
		}

		ImprimeGol(&Gol);

		fread (&Gol, sizeof(Gol), 1, f);
	}
	fclose (f);
}

/* Nombre					GuardarArchivoDeGolesOrdenado
 * Desc:					Abre (o crea) el archivo de goles ordenado, y a continuacion vuelca una lista
 * 							de nodos en él.
 * Param[ENT]			<NodoGol *>"goles" - Lista de goles a guardar.
 * Retorno:				Nada.
 * */
void GuardarArchivoDeGolesOrdenado(NodoGol *goles)
{
	FILE *fGoles;
	NodoGol *CopiaGoles = goles;

	fGoles = fopen(NOMBRE_ARCH_GOLES_ORDENADO, "wb+");
	if(fGoles == NULL)
	{
		cout << "Error al abrir/crear el archivo de goles." << endl;
		return;
	}

	while(CopiaGoles != NULL)
	{
		fwrite((void *)&CopiaGoles->gol, sizeof(RegistroGol), 1, fGoles);
		CopiaGoles = CopiaGoles->siguiente;
	}

	fclose(fGoles);
}
/*###################################### FIN ZONA ARCHIVOS  #######################################*/

/*###################################### ZONA FUNCION CARGA ########################################*/

/* Nombre					CargarGolesManual
 * Desc:					Permite al usuario ingresar manualmente una lista de goles de forma manual.
 * Param[ENT]			<NodoGol *>"goles" - Lista de goles a guardar.
 * Retorno:				Nada.
 * */
void CargarGolesManual(NodoGol* &goles)
{
	RegistroGol gol;
	char nombreEquipo[MAX_LARGO_CADENA];
	int dia = 0;
	int mes = 0;
	bool continuar = true;

	gol.idGol=0;
	cout << "Ingrese ID de Partido (0 para terminar de agregar partidos): ";
	cin >> gol.idPartido;//id del partido
	while (gol.idPartido != 0 && gol.idPartido < 65)
	{
		cout<<"ID de gol:" << gol.idGol<<endl; //id del gol

		/* Limpio el flujo */
		cin.ignore();
		do {
			cout<<"Nombre de equipo: ";
			cin.getline(nombreEquipo, 256);
			gol.codigoDeEquipo= CodigoDeEquipoDesdeNombre(nombreEquipo);//codigo de equipo

			continuar = CodigoDeEquipoValido(gol.codigoDeEquipo);

			if(continuar == false)
			{
				cout << nombreEquipo << " no es el nombre de algun pais que haya participado ";
				cout << "en el Mundial Rusia 2018. Reviselo." << endl;
			}

		} while(continuar != true);
		cout << endl;

		cout<<"Nombre del jugador que hizo GOL: ";
		cin.getline(gol.nombreDelJugador, sizeof(gol.nombreDelJugador)); //Nombre del jugador
		cout << endl;

		do {
			cout<<"Fecha:" << endl;
			cout<<"Mes: ";
			cin>>mes;
			cout<<"Dia: ";
			cin>>dia;

			continuar = FechaValida(mes, dia);

			if(continuar == false)
			{
				cout << "Ingrese una fecha desde el 14 de junio hasta el 15 de julio, inclusive" << endl;
			}
		} while(continuar != true);
		/* Calculo fecha */
		gol.fecha= (10000*2018) + (mes*100) + (dia);

		/* Guardo el nodo */
		GuardarNodo(goles, gol);

		gol.idGol++;
		cout << endl;
		cout << "Ingrese ID de Partido (0 para terminar de agregar partidos): ";
		cin >> gol.idPartido;//id del partido. Repito para el corte
	}

	/* Genero el archivo final */
	GuardarArchivoDeGolesOrdenado(goles);
}

/* Nombre					CargarGolesAutomatico
 * Desc:					Abre un archivo de goles que ya debe existir, y los carga en la lista de goles.
 * Param[ENT]			<NodoGol *>"goles" - Lista de goles a guardar.
 * Retorno:				Nada.
 * */
void CargarGolesAutomatico(NodoGol* &goles)
{
	RegistroGol Gol;
	FILE *fGoles;

	cout << "Procesando archivo " << NOMBRE_ARCH_GOLES_ORIGINAL << endl;
	fGoles = fopen(NOMBRE_ARCH_GOLES_ORIGINAL, "rb");

	if(fGoles == NULL)
	{
		printf("Error al abrir el archivo de goles original.\n");
		return;
	}

	fread((void *)&Gol,sizeof(RegistroGol), 1, fGoles);
	while (!feof(fGoles))
	{
		/* Guardo el nodo */
		GuardarNodo(goles, Gol);
		/* Leo el siguiente */
		fread((void *)&Gol,sizeof(RegistroGol), 1, fGoles);
	}

	GuardarArchivoDeGolesOrdenado(goles);

	/* Cierro finalmente los archivos */
	fclose(fGoles);
}
/*####################################### FIN ZONA CARGA   ########################################*/

/* Punto de entrada del programa */
int main(void)
{
	int opcion;
	/* Listado de goles */
	NodoGol *goles = NULL;

	do{
		cout << "1: Cargar goles (MANUAL)" << endl;
		cout << "2: Cargar goles (AUTO)" << endl;
		cout << "3: Leer archivo de goles original" << endl;
		cout << "4: Ver listado de goles ordenado (por equipo y fecha)" << endl;
		cout << "5: Ver listado de goles ordenado (por equipo y fecha) (LOCAL)" << endl;
		cout << "0: Salir" << endl;
		cout << endl;
		cout << "Opcion: ";

		cin>>opcion;
		switch(opcion)	{
		case 0:
			cout<<"Final del programa" << endl;
			break;

		case 1:
			goles = NULL;
			CargarGolesManual(goles);
			break;

		case 2:
			goles = NULL;
			CargarGolesAutomatico(goles);
			break;

		case 3:
			MostrarArchivo(NOMBRE_ARCH_GOLES_ORIGINAL);
			break;

		case 4:
			MostrarArchivo(NOMBRE_ARCH_GOLES_ORDENADO);
			break;

		case 5:
			MostrarNodos(goles);
			break;

		default:
			cout<<"Error, opcion invalida";
			break;
		}

		cout<<"-------------------------------------"<<endl;
	}while(opcion != 0);

	return 0;
}
