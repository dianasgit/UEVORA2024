//
//  balanco.c
//  stacks
//
//  Created by Ligia Ferreira on 22/02/2023.
//
#include <stdio.h>
#include "stackar.h"

int éParentesisAbrir(char t){
   
}

int éParentesisFechar(char t){
    
}

int concordam(char a, char b){
   
    
}

int verifica_balanco(char *exp){
  
}

int main(){
    char exp[]="[()] {} {[()()]()}";
    int x=verifica_balanco(exp);
    if(x==0)
        printf("A expresssão \"%s\" não está balanceada!\n",exp);
    else
        printf("A expressão \"%s\" está balanceada!\n",exp);
    
}
