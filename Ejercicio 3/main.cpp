#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

typedef char str30[31];

//Creo la estructura del archivo
struct TRBol{
	
	string nomEs;
	int golFav;
	str30 nomE;
	
};

struct NodoArbol{
	
	NodoArbol *ptrIzq;
	NodoArbol *ptrDer;
	struct TRBol valor;
	
}VecPaisesGol[32];

//Funcion para cargar equipos

void cargarEquipos(){
	
	int salir = 0;
	
	//Instancio el archivo para poder utilizarlo y cargarle los datos
	
	TRBol RBol;
	
	//Con esto señalo el archivo con el que quiero trabajar
	
	FILE * FBol = fopen("bolillero.dat","wb+");;

	//Ciclo para cargar los equipos y goles
	
	for(int i = 0; i < 32; i++){
		
		cout<<"Ingrese el nombre del equipo: ";
		//CON EL GETLINE GUARDO LOS NOMBRES CON ESPACIOS
		cin.getline(RBol.nomE,15);
		cin.getline(RBol.nomE,15,'\n') ;
		
		cout<<"Ingrese Goles a Favor: ";
		cin>>RBol.golFav;
		cout<<"\n";
			
			
		fwrite(&RBol,sizeof(RBol),1,FBol);
		
		
	}
	
	fclose(FBol);
	
}

//Funcion para leer archivos

void leerArchivo(){
	
	
	//Instancio el archivo para trabajar desde el nombre del struct
	
	TRBol RBol;
	
	//Cargo el archivo con el que quiero trabajar
	
	FILE * FBol = fopen("bolillero.dat","rb");;
	
	//Este while imprime todos los datos del archivo :3
	
	fread(&RBol,sizeof(RBol),1,FBol);
	
	while(!feof(FBol)){
		

		
		cout<<"Nombre del equipo: "<<RBol.nomE<<"\n";
		
			
		cout<<"Goles a Favor: "<<RBol.golFav<<"\n\n";
		
		//Abro el archivo para poder leerlo
		//ACORDATE QUE TIENE QUE IR AL FINAL, SINO TE LEE 2 VECES EL ARCHIVO AL FINAL :O
		
		fread(&RBol,sizeof(RBol),1,FBol);
		
	}
	
	fclose(FBol);
	
}

void cargarVector(NodoArbol  VecPaisesGol[]){
	
	//Inicializo un valor para poder recorrer el array
	int i = 0;
	
	//Instancio el archivo para trabajar desde el nombre del struct
	
	TRBol RBol;
	
	//Cargo el archivo con el que quiero trabajar
	
	FILE * FBol = fopen("bolillero.dat","rb");
	
	//Este while imprime todos los datos del archivo :3
	
	fread(&RBol,sizeof(RBol),1,FBol);
	
	while(!feof(FBol)){
		
		//Transformo los characters a tipo string, luego los asigno al array
		string nomEs = RBol.nomE;
		//Copio los valores del archivo al vector
		
		VecPaisesGol[i].valor.nomEs = nomEs;
		//memcpy(VecPaisesGol[i].valor.nomEs, RBol.nomE, strlen(RBol.nomE));
		
		VecPaisesGol[i].valor.golFav = RBol.golFav;
		
		//Acutalizo el contador
		
		i = i + 1;
		
		fread(&RBol,sizeof(RBol),1,FBol);
		
	}
	
	fclose(FBol);
	
	
}

void leerVector(NodoArbol  VecPaisesGol[]){
	
	for(int i = 0; i < 32; i++){
		
		cout<<"Equipo: "<< VecPaisesGol[i].valor.nomEs<<" --- Goles: "<< VecPaisesGol[i].valor.golFav<<"\n";
		
		
	}
	
}

//Funcione para crear el Arbol
void insertarNodo(NodoArbol* &ptrArbol, NodoArbol VecPaisesGol[],int i){
	
	
	if(ptrArbol == NULL){
		
		//Si encuentra un nodo vacio crea uno nuevo
		NodoArbol* aux = new NodoArbol();
		
		//carga los valores al nodo creado
		
		aux -> valor.golFav  = VecPaisesGol[i].valor.golFav;
		
		//*************************************************************
		//Problema por tipo de datos que le pasa D:
		//*************************************************************
		
		//aux -> valor.nomE  = VecPaisesGol[i].valor.nomE;
		
		
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
		cout<<"Equipo: "<<ptrArbol -> valor.nomE<< " - Goles: " <<ptrArbol -> valor.golFav<<"\n";
		inOrder(ptrArbol -> ptrDer);
		
	}
		
	
}

int main(int argc, char** argv) {
	
	NodoArbol* ptrRaiz = NULL;
	
	//Varialbe para elegir si quiero escribir archivo o solo leerlo
	
	
	int opcion;
	
	cout<<"Bienvenido!!!\n";
	
	do{
		
		cout<<"Ingrese 1 para cargar equipos: (No es necesario) "  <<"\n"<< "2 para leer los equipos cargados: "<<"\n"<< "3 cargar Vector: "<<"\n"<<"4 Leer vector: "<<"\n"<<"5 para ordernar y 0 para salir: ";
		cin>>opcion;
		switch(opcion)	{
			case 0:{
				cout<<"Final del programa";
				break;
			}
		
			case 1:{
				cargarEquipos();
				break;
			}
			case 2:{
				leerArchivo();
				break;
			}
			case 3:{
				cargarVector(VecPaisesGol);
				break;
			}
			case 4:{
				leerVector(VecPaisesGol);
				break;
			}
			case 5:{
				for(int i = 0; i<32;i++ ){
				insertarNodo(ptrRaiz,VecPaisesGol,i);		
				}
				inOrder(ptrRaiz);
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
