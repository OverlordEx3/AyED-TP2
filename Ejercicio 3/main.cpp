#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

typedef char str30[31];

//Creo la estructura del archivo
struct TRBol{
	
	//No podes crear un string aca o se ropme todo CUIDADO D:
	//string nomEs;
	int golFav;
	str30 nomE;
	
};

struct NodoArbol{
	
	NodoArbol *ptrIzq;
	NodoArbol *ptrDer;
	struct TRBol valor;
	string nomEs;
	
}VecPaisesGol[32];


//Funcion para leer archivos

void leerArchivo(){
	
	
	//Instancio el archivo para trabajar desde el nombre del struct
	
	TRBol RBol;
	
	//Cargo el archivo con el que quiero trabajar
	
	FILE * FBol = fopen("equipos.dat","rb");;
	
	//Este while imprime todos los datos del archivo :3
	
	fread(&RBol,sizeof(RBol),1,FBol);
	
	cout<<"**********************************\n";
	
	while(!feof(FBol)){
		

		
		cout<<"Nombre del equipo: "<<RBol.nomE<<"\n";
		
			
		cout<<"Goles a Favor: "<<RBol.golFav<<"\n\n";
		
		//Abro el archivo para poder leerlo
		//ACORDATE QUE TIENE QUE IR AL FINAL, SINO TE LEE 2 VECES EL ARCHIVO AL FINAL :O
		
		fread(&RBol,sizeof(RBol),1,FBol);
		
	}
	cout<<"**********************************\n\n";
	fclose(FBol);
	
}

void cargarVector(NodoArbol  VecPaisesGol[]){
	
	//Inicializo un valor para poder recorrer el array
	int i = 0;
	
	//Creo un string local para poder almacenarlo en el array
	string nomEs;
	
	//Instancio el archivo para trabajar desde el nombre del struct
	
	TRBol RBol;
	
	//Cargo el archivo con el que quiero trabajar
	
	FILE * FBol = fopen("equipos.dat","rb");
	
	//Este while imprime todos los datos del archivo :3
	
	fread(&RBol,sizeof(RBol),1,FBol);
	
	while(!feof(FBol)){
		
		//Transformo los characters a tipo string, luego los asigno al array
		string nomEs = RBol.nomE;
		
		//Copio los valores del archivo al vector
		
		VecPaisesGol[i].nomEs = nomEs;
		//memcpy(VecPaisesGol[i].valor.nomEs, RBol.nomE, strlen(RBol.nomE));
		
		VecPaisesGol[i].valor.golFav = RBol.golFav;
		
		//Acutalizo el contador
		
		i = i + 1;
		
		fread(&RBol,sizeof(RBol),1,FBol);
		
	}
	
	fclose(FBol);
	
	
}

void leerVector(NodoArbol  VecPaisesGol[]){
			
	cout<<"**********************************\n";	
	
	for(int i = 0; i < 32; i++){
		
		cout<<"Nombre de equipo: "<< VecPaisesGol[i].nomEs<< "\nGoles a favor: "<< VecPaisesGol[i].valor.golFav<<"\n\n";
			
	}
	cout<<"**********************************\n\n";
}

//Funcione para crear el Arbol
void insertarNodo(NodoArbol* &ptrArbol, NodoArbol VecPaisesGol[],int i){
	
	
	if(ptrArbol == NULL){
		
		//Si encuentra un nodo vacio crea uno nuevo
		NodoArbol* aux = new NodoArbol();
		
		//Carga los valores de los goles del array  al nodo creado
		
		aux -> valor.golFav  = VecPaisesGol[i].valor.golFav;
		
		//Carga los valores de los paises del array al nodo creado*
		
		aux -> nomEs  = VecPaisesGol[i].nomEs;
		
		
		//Pone los hijos en NULL para que despues los asignen
		
		aux -> ptrIzq = NULL;
		
		aux -> ptrDer = NULL;
		
		ptrArbol = aux;
			
		
	}else{
		//Si es menor al nodo lo inserta en la izquierda
		if(VecPaisesGol[i].valor.golFav < ptrArbol -> valor.golFav){
			insertarNodo( ptrArbol -> ptrIzq, VecPaisesGol, i);
		}else{
			
			//Si es mayor o igual lo inserta en la rama derecha
			if( VecPaisesGol[i].valor.golFav > ptrArbol -> valor.golFav ){	
				insertarNodo(ptrArbol -> ptrDer, VecPaisesGol, i);
			}else{
				
				insertarNodo(ptrArbol -> ptrDer, VecPaisesGol, i);
				
			}
			
		}
		
	}
	
}

//Funcion para ordenar el arbol
void inOrder(NodoArbol* &ptrArbol){
	
	
	
	if(ptrArbol == NULL){
		
		return;
		
	}else{
		
		inOrder(ptrArbol ->ptrIzq);
		cout<<"Nombre de equipo: "<<ptrArbol -> nomEs<< "\nGoles a favor: " <<ptrArbol -> valor.golFav<<"\n\n";
		inOrder(ptrArbol -> ptrDer);
		
	}
		
	
}

int main(int argc, char** argv) {
	
	NodoArbol* ptrRaiz = NULL;
	
	//Variable para elegir que opcion elegir
	
	int opcion;
	
	cout<<"Segunda Parte TP Anual de Algoritmos y Estructura de Datos 2018"<<"\n";
	cout<<"Ejercicio 3\n\n";
	
	do{
		
		cout<< "1: Leer los datos del archivo "<<"\n"<< "2: Para cargar vector e imprimir los datos del vector "<<"\n"<<"3: Para ordernar los equipos por cantidad de goles "<<"\n"<< "0: Salir "<<"\n\n"<<"Opcion: ";
		cin>>opcion;
		switch(opcion)	{
			case 0:{
				cout<<"\n";
				cout<<"Fin de programa.";
				break;
			}
		
			case 1:{
				cout<<"\n\n";
				leerArchivo();
				break;
			}
			case 2:{
				cout<<"\n\n";
				cargarVector(VecPaisesGol);
				leerVector(VecPaisesGol);
				break;
			}
			case 3:{
				
				cout<<"\n**********************************\n\n";
				
				for(int i = 0; i<32;i++ ){
				insertarNodo(ptrRaiz,VecPaisesGol,i);		
				}
				inOrder(ptrRaiz);
				
				cout<<"**********************************\n\n";
				break;
			}
			default:{
				cout<<"Error, opcion invalida";
				break;
			}
		}
	}while(opcion != 0);

	
	return 0;
}
