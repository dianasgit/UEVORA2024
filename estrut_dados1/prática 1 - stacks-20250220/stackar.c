#include "stackar.h"
#include "fatal.h"
#include <stdlib.h>


#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )


struct StackRecord     
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};



Stack CreateStack( int MaxElements )
{

    Stack S;	

	if( MaxElements < MinStackSize )
		Error( "Stack size is too small" );

	S = malloc( sizeof( struct StackRecord ) );
	if( S == NULL )
		FatalError( "Out of space!!!" );

	S->Array = malloc( sizeof( ElementType ) * MaxElements );
	if( S->Array == NULL )
		FatalError( "Out of space!!!" );

	S->Capacity = MaxElements;
	MakeEmpty( S );

	return S;
}



void DisposeStack( Stack S )
{
    if( S != NULL )
    {
        free( S->Array );
        free( S );
    }
}

								//TopOfStack= mantém o índice do elemento mais recente da pilha.
int IsEmpty( Stack S )      	//verifica se a pilha está vazia
{
    return S->TopOfStack == EmptyTOS;     // compara: se apilha está vazia o top terá o valor de emptytos que é -1 logo retorna 1 se não retorn 0
}
 
int IsFull( Stack S )   //verifica se a pilha está cheia
{
    return S->TopOfStack == S->Capacity - 1;		//retorna 1 se o indice do top da stack é igual a capacidady(que 'o tamalho maximo definido) da stack-1
}

void MakeEmpty( Stack S )
{
    S->TopOfStack = EmptyTOS;		//vai resetar o indice do top ficar igual ao empty que é -1   --- mas os elementos NÃO ESTÃO SENDO APAGADOS ficiamente, porém não ficam mais acessíveis já que o top foi redefinido
}

void Push( ElementType X, Stack S )   	//inserir elemento X na pilha
{
    if( IsFull( S ) )    				//1º verifica se a pilha está cheia
        Error( "Full stack" );			//se cheia retorna erro
    else
        S->Array[ ++S->TopOfStack ] = X;		//se não, faz push de X no top
}

ElementType Top( Stack S )    				//retorna o elemento do topo
{
    if( !IsEmpty( S ) )						//se não vazia
        return S->Array[ S->TopOfStack ];
    Error( "Empty stack" );
    return 0;  
}

ElementType Pop( Stack S )
{
    if( IsEmpty( S ) )
        Error( "Empty stack" );
    else
        return S->Array[ S->TopOfStack-- ];
    return 0; 
}

int main (){


Stack S1=CreateStack(5);
int num =10;

while (IsFull!= 0){
Push(num,S1);
printf("Valor no topo da stack: %d \n",Top(S1)); 
num = num +10;
}




return 0;
}
