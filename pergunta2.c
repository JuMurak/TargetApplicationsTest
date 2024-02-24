#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int a, b, n, i, fib;
    a = 0;
    b = 1;
    n = 0;
    i = 0;
    fib = 0;
    
    printf("Digite um numero para verificar se pertence a sequencia de Fibonacci:\n");
    scanf("%d", &n);

    while(i<=n){
        if(n<=2){
            printf("Pertence a sequencia de Fibonacci");
            return 0;
        }else{
            fib = a + b;
            a = b;
            b = fib;
            if(n==fib){
                printf("Pertence a sequencia de Fibonacci");
                return 0;
            }
        }
        i++;
    }
    printf("NAO Pertence");

    return 0;
}