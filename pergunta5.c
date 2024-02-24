#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i, cont;
    cont=0;
    //string a ser invertida, previamente definida, pela variável palavra.
    char palavra[20] = "Inverter";
    
    while(1){
        if(palavra[cont]=='\0'){
            for(i=cont-1; i>=0; i--){
                printf("%c", palavra[i]);
            }
            break;
        }
        cont++;
    }
    return 0;
}