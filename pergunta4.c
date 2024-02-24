#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    double sp, rj, mg, es, outros, soma;
    sp = 67836.43;
    rj = 36678.66;
    mg = 29229.88;
    es = 27165.48;
    outros = 19849.43;
    soma = sp + rj + mg + es + outros;

    printf("Porcentagem de contribuicao do faturamento mensal por estado:\n");
    printf("SP: %.2f %%\n",(sp*100)/soma);
    printf("RJ: %.2f %%\n",(rj*100)/soma);
    printf("MG: %.2f %%\n",(mg*100)/soma);
    printf("ES: %.2f %%\n",(es*100)/soma);
    printf("OUTROS: %.2f %%\n",(outros*100)/soma);
   
   return 0;
}