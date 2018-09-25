#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

struct nodo{
	int nro;
	struct nodo *siguiente;
};

typedef struct nodo *Puntero;

class Pila{
	public:
		 Pila(void);
		 void Apilar(int);
		 int Desapilar(void);
		 void Cima(void);
		 bool Pila_vacia(void);
		 void Mostrarpila(void);
		 void Destruirpila(void);
		 
	private:
	 	Puntero cima;
		 	 
};

Pila :: Pila(void){
	cima=NULL;
}

bool Pila::Pila_vacia(void){
	if(cima==NULL){
		return true;
		
	}else{
		return false;
	}
}

void Pila::Apilar(int x){
	
		Puntero p_aux;
		p_aux = new (struct nodo);
		p_aux->nro = x;
		p_aux->siguiente=cima;
		cima = p_aux;
}

void Pila::Cima(){
		 int x;
		 if(cima==NULL){
		 	printf("\n\n\t Pila Vacia...!");
		 }else{
		 	x=cima->nro;
		 	printf("\n\tLa cima es: %d\n",x);
		 }
}

int Pila :: Desapilar(void){
	int x;
	Puntero p_aux;
	if(cima==NULL){
		printf("\n\n\t Pila vacia..!");
	}else{
		p_aux = cima;
		x=p_aux->nro;
		cima = cima->siguiente;
		delete(p_aux);
	}
}

void Pila::Mostrarpila(void){
	Puntero p_aux;
	p_aux = cima;
	
	while(p_aux != NULL){
		printf("\t%d\n",p_aux->nro);
		p_aux = p_aux->siguiente;
	}
}

void Pila::Destruirpila(void){
	Puntero p_aux;
	while(cima!=NULL){
		p_aux = cima;
		cima = cima->siguiente;
		delete(p_aux);
	}
}

void menu(void){
	
	printf("\t-----------------------------\n");
	printf("\t IMPLEMENTACION DE UNA PILA  \n");
	printf("\t-----------------------------\n");
	printf("\t|                           |\n");
	printf("\t|    1. APILAR              |\n");
	printf("\t|    2. DESAPILAR           |\n");
	printf("\t|    3. MOSTRAR PILA        |\n");
	printf("\t|    4. DESTRUIR PILA       |\n");
	printf("\t|    5. MOSTRAR CIMA        |\n");
	printf("\t|    6. SALIR               |\n");
	printf("\t|                           |\n");
	printf("\t-----------------------------\n");
	printf("\t Ingrese opcion : ");
}

int main(){
	system("color 0a");
	Pila pila;
	int x,op;
	
	do{
		menu(); scanf("%d",&op);
		switch(op){
			case 1: printf("\n\t INGRESE LE NUMERO A APILAR");
					scanf("%d",&x);
					pila.Apilar(x);
					printf("\n\n\t Numero %d apilado\n",x);
					break;
			case 2: 
			 		if(pila.Pila_vacia()==true){
			 			printf("\n\n\t Pila vacia..!");
					 }else{
					 	x = pila.Desapilar();
					 	printf("\n\n\t Numero %d desapilado\n",x);
					 }
					 break;
			
			case 3: 
					printf("\n\n\t MOSTRANDO PILA \n\n");
					if(pila.Pila_vacia()!=true){
						pila.Mostrarpila();
					}else{
						printf("\n\n\t Pila vacia...!\n");
					}
					break;
			
			case 4: 
					pila.Destruirpila();
					printf("\n\n\t Pila eliminada....\n\n");
					break;
			
			case 5: 
			   		pila.Cima();
			   		break;
		}
		printf("\n\n");
		system("pause"); system("cls");
		
	}while(op!=6);
	
	return 0;
}
