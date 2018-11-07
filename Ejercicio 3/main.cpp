#include <stdio.h>
#include <iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

typedef char cadena[31];

struct TRBol{
	
	int golFav;
	cadena nomE;
	
};

struct NodoArbol{
	
	NodoArbol *ptrIzq;
	NodoArbol *ptrDer;
	struct TRBol valor;
	
}equipos[32];




void insertarNodo(NodoArbol* &ptrArbol, NodoArbol equipos[],int i){
	
	
	if(ptrArbol == NULL){
		
		//Si encuentra un nodo vacio crea uno nuevo
		NodoArbol* aux = new NodoArbol();
		
		//carga los valores al nodo creado
		
		aux -> valor.golFav  = equipos[i].valor.golFav;
		
		aux -> valor.nomE  = equipos[i].valor.nomE;
		
		
		//Pone los hijos en NULL
		
		aux -> ptrIzq = NULL;
		
		aux -> ptrDer = NULL;
		
		ptrArbol = aux;
			
		
	}else{
		//Si es menor al nodo lo inserta en la izquierda
		if(equipos[i].valor.golFav < ptrArbol -> valor.golFav){
			insertarNodo( ptrArbol -> ptrIzq, equipos, i);
		}else{
			
			//Si es mayor o igual lo inserta en la rama derecha
			if( equipos[i].valor.golFav > ptrArbol -> valor.golFav ){	
				insertarNodo(ptrArbol -> ptrDer, equipos, i);
			}else{
				
				//cout<< "\n" <<"Valor duplicado";
				
			}
			
		}
		
	}
	
}

//Funcion para recorrido del arbol

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
	
	
	
	equipos[0].valor.nomE = "Rusia";
    equipos[0].valor.golFav = 11;
    
    equipos[1].valor.nomE = "Alemania";
    equipos[1].valor.golFav = 2;
    
    equipos[2].valor.nomE = "Brasil";
    equipos[2].valor.golFav = 8;
    
    equipos[3].valor.nomE = "Portugal";
    equipos[3].valor.golFav = 6;
    
    equipos[5].valor.nomE = "Belgica";
    equipos[5].valor.golFav = 16;
    
    equipos[6].valor.nomE = "Poloni";
    equipos[6].valor.golFav = 2;
	
	equipos[7].valor.nomE = "Francia";
    equipos[7].valor.golFav= 14;

    equipos[8].valor.nomE = "España";
    equipos[8].valor.golFav= 7;
    
    equipos[9].valor.nomE = "Peru";
    equipos[9].valor.golFav= 2;
    
    equipos[10].valor.nomE = "Suiza";
    equipos[10].valor.golFav= 5;
    
    equipos[11].valor.nomE = "Inglaterra";
    equipos[11].valor.golFav= 12;
    
    equipos[12].valor.nomE = "Colombia";
    equipos[12].valor.golFav= 6;
    
    equipos[13].valor.nomE = "Mexico";
    equipos[13].valor.golFav= 3;
    
    equipos[14].valor.nomE = "Uruguay";
    equipos[14].valor.golFav= 7;
   
    equipos[15].valor.nomE = "Croacia";
    equipos[15].valor.golFav= 14;
    
    equipos[16].valor.nomE = "Dinamarca";
    equipos[16].valor.golFav= 3;
    
    equipos[17].valor.nomE = "Islandia";
    equipos[17].valor.golFav= 2;
    
    equipos[18].valor.nomE = "Costa Rica";
    equipos[18].valor.golFav= 2;
    
    equipos[19].valor.nomE = "Suecia";
    equipos[19].valor.golFav= 6;
    
    equipos[20].valor.nomE = "Tunez";
    equipos[20].valor.golFav= 5;
    
    equipos[21].valor.nomE = "Egipto";
    equipos[21].valor.golFav= 2;
   
    equipos[22].valor.nomE = "Senegal";
    equipos[22].valor.golFav= 4;
    
    equipos[23].valor.nomE = "Iran";
    equipos[23].valor.golFav= 2;
    
    equipos[24].valor.nomE = "Serbia";
    equipos[24].valor.golFav= 2;
    
    equipos[25].valor.nomE = "Nigeria";
    equipos[25].valor.golFav= 3;
    
    equipos[26].valor.nomE = "Australia";
    equipos[26].valor.golFav= 2;
    
    equipos[27].valor.nomE = "Japon";
    equipos[27].valor.golFav= 6;
    
    equipos[28].valor.nomE = "Marruecos";
    equipos[28].valor.golFav= 2;
    
    equipos[29].valor.nomE = "Panama";
    equipos[29].valor.golFav= 2;
    
    equipos[30].valor.nomE = "Corea del Sur";
    equipos[30].valor.golFav= 3;
    
    equipos[31].valor.nomE = "Arabia Saudita";
    equipos[31].valor.golFav= 2;
	
	NodoArbol* ptrRaiz = NULL;
	

	
	/*
	preOrden(ptrRaiz);
	*/
	for(int i = 0; i<32;i++ ){
		
	insertarNodo(ptrRaiz,equipos,i);		
		
	}
	
	inOrder(ptrRaiz);
	
	//preOrden(ptrRaiz);	
	/*
	insertarNodo(ptrRaiz, 10);
	insertarNodo(ptrRaiz, 4);
	insertarNodo(ptrRaiz, 5);
	insertarNodo(ptrRaiz, 9);
	insertarNodo(ptrRaiz, 14);
	*/
	

	
	return 0;
}
