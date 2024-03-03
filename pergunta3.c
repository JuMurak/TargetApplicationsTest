#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h> //como a linguagem de programação que atualmente tenho maior experiência é o C, optei por resolver o exercício fazendo uso da biblioteca cJSON, para que fosse possível trabalhar com os dados json do desafio

//Dado um vetor que guarda o valor de faturamento diário de uma distribuidora, faça um programa, na linguagem que desejar, que calcule e retorne:
//O menor valor de faturamento ocorrido em um dia do mês;
//O maior valor de faturamento ocorrido em um dia do mês;
//Número de dias no mês em que o valor de faturamento diário foi superior à média mensal.

//IMPORTANTE:
// a) Usar o json ou xml disponível como fonte dos dados do faturamento mensal;
// b) Podem existir dias sem faturamento, como nos finais de semana e feriados. Estes dias devem ser ignorados no cálculo da média;

long tamanhoArquivo(FILE *fd) {
    fseek(fd, 0L, SEEK_END);
    long size = ftell(fd);

    fseek(fd, 0L, SEEK_SET);
    return size;
}

int main(void) {
    // abrindo o arquivo
    FILE *fp = fopen("dados.json", "r");
    if (fp == NULL) { 
        printf("Erro: Nao e possivel abrir o arquivo.\n"); 
        return 1;
    }
    // recuperando o tamanho do arquivo json
    long tamanho = tamanhoArquivo(fp);

    // lendo conteúdo do arquivo para uma string
    char buffer[tamanho];
    int len = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);
    
    // parse dados json, fazendo uso da biblioteca cJSON
    cJSON *json = cJSON_Parse(buffer); 
    if (json == NULL) { 
        const char *error_ptr = cJSON_GetErrorPtr(); 
        if (error_ptr != NULL) { 
            printf("Error: %s\n", error_ptr); 
        } 
        cJSON_Delete(json); 
        return 1; 
    }
     
    cJSON *dia = NULL;
    cJSON *valor = NULL;
    cJSON *entradaDia = NULL;
    int dia_menor = 0;
    double valor_menor = 0.0;
    int dia_maior = 0;
    double valor_aux = 0.0;
    double valor_maior = 0.0;
    int dias_contados = 0;
    double media = 0.0;

    //Parte1: Número de dias no mês em que o valor de faturamento diário foi superior à média mensal.
    cJSON_ArrayForEach(entradaDia, json)
    {
        cJSON *dia = cJSON_GetObjectItemCaseSensitive(entradaDia, "dia");
        cJSON *valor = cJSON_GetObjectItemCaseSensitive(entradaDia, "valor");

        if ((!cJSON_IsNumber(dia) || !cJSON_IsNumber(valor)))
        {
            cJSON_Delete(json); 
            return 1;
        }

        if (valor->valuedouble!=0.0){
            dias_contados++;
            media+=valor->valuedouble;
        }
    }
    // divisão por zero
    if (dias_contados == 0){
        cJSON_Delete(json); 
        return 1;
    }else{
        media = media / dias_contados;
        dias_contados = 0;
    }
        
    cJSON_ArrayForEach(entradaDia, json)
    {
        cJSON *dia = cJSON_GetObjectItemCaseSensitive(entradaDia, "dia");
        cJSON *valor = cJSON_GetObjectItemCaseSensitive(entradaDia, "valor");

        if ((!cJSON_IsNumber(dia) || !cJSON_IsNumber(valor)))
        {
            cJSON_Delete(json); 
            return 1;
        }

        //O menor valor de faturamento ocorrido em um dia do mês;
        if (valor->valuedouble!=0.0){
            valor_aux = valor->valuedouble;
            if (valor_menor == 0.0){
                dia_menor = dia->valueint;
                valor_menor = valor_aux;
            }
            if (valor_aux<valor_menor){
                dia_menor = dia->valueint;
                valor_menor = valor_aux;
            }
        }
        //O maior valor de faturamento ocorrido em um dia do mês;
        if (valor->valuedouble!=0.0 && valor->valuedouble>valor_maior){
            dia_maior = dia->valueint;
            valor_maior = valor->valuedouble;
        }
        //Parte 2: Número de dias no mês em que o valor de faturamento diário foi superior à média mensal.
        if (valor->valuedouble>media)
            dias_contados++;
    }
    printf("O menor valor de faturamento foi:\nDia: %d\nValor menor = %f\n\n", dia_menor, valor_menor);
    printf("O maior valor de faturamento foi:\nDia: %d\nValor maior = %f\n\n", dia_maior, valor_maior);
    printf("Número de dias no mês em que o valor de faturamento diário foi superior à média mensal: %d\n\n", dias_contados);
    //Liberando a mémoria usada, para evitar vazamento de memória e problemas
    cJSON_Delete(json); 
  
  return 0;
}