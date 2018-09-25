#include <stdio.h>
#include <stdlib.h>

 
struct nodo{
    int nro;
    struct nodo *sgte;
};

int vec[20],contador=0;
 
typedef nodo *ptrPila;   // creando nodo tipo puntero( tipo de dato )
 
// Apilar elemento      

void push( ptrPila &p, int valor )
{
     ptrPila aux;
     aux = new(struct nodo);  // apuntamos al nuevo nodo creado
     aux->nro = valor;
     vec[contador]=aux->nro;
     aux->sgte = p ;
     contador++;
     p = aux ;
}
 
//Desapilar elemento(devuelve elemento)      

int pop( ptrPila &p )
{
     int num ;
     ptrPila aux;
     
     aux = p ;
     num = aux->nro;   // asignamos el primer vamor de la pila
     
     p = aux->sgte ;
     delete(aux);
     
     return num;
}
 
//Muestra elementos de la pila      

void mostrar_pila( ptrPila p )
{
     ptrPila aux;
     aux = p;     // apunta al inicio de la lista
     
     while( aux !=NULL )
     {
            printf("\t %d \n", aux->nro);
            aux = aux->sgte;
     }    
}

void mostrar_pila_inversa( )
{
     
     for(int i=0;i<contador; i++){
     	printf("%d\n",vec[i]);
	 }
        
     
}
 
//Eliminar todos los elementos de la pila      

void destruir_pila( ptrPila &p)
{
     ptrPila aux;
     
     while( p != NULL)
     {
           aux = p;
           p = aux->sgte;
           delete(aux);
     }
}
 
//Menu de opciones    

void menu()
{
    printf("\n\t IMPLEMENTACION DE UNA PILA\n\n");
    printf(" 1. APILAR                                \n");
    printf(" 2. DESAPILAR                             \n");
    printf(" 3. MOSTRAR PILA                          \n");
    printf(" 4. DESTRUIR PILA                         \n");
    printf(" 5. VER PILA INVERSA                      \n");
    printf(" 6. SALIR                                 \n");
    printf("\n INGRESE OPCION: ");
}
 
//funcion Principal        
int main()
{
    ptrPila p = NULL;  // creando pila
    int dato;
    int op;
    int x ; // numero que devuelve la funcon pop
   
    system("color 0b");
 
    do
    {
        menu();  scanf("%d", &op);
 
        switch(op)
        {
            case 1:
 
                 printf( "\n NUMERO A APILAR: "); scanf("%d",&dato);
                 push( p, dato );
                 printf("\n\n\t\tNumero  %d apilado...\n\n",dato);
            break;
 
 
            case 2:
 
                 x = pop( p );
                 printf("\n\n\t\tNumero %d desapilado...\n\n",x);
            break;
                 
 
            case 3:
 
                 printf( "\n\n MOSTRANDO PILA\n\n");
                 if(p!=NULL)
                    mostrar_pila( p );
                 else
                    printf("\n\n\tPila vacia..!\n");
            break;
 
 
            case 4:
 
                 destruir_pila( p );
                 printf("\n\n\t\tPila eliminada...\n\n");
            break;
            
           case 5: 
           	printf( "\n\n MOSTRANDO PILA\n\n");
                 if(p!=NULL)
                    mostrar_pila_inversa( );
                 else
                    printf("\n\n\tPila vacia..!\n");
           		
         }
 
        printf("\n\n");
        system("pause");  system("cls");
 
    }while(op!=6);
   
   
    return 0;
}


