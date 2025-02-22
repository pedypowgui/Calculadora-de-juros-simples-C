#include <stdio.h>
#include <stdlib.h>

//Definição de constante para retorno de possíveis erros 
#define ERRO_DADOS 1

//funções de cálculo de situação
float calcularCapital(float j, float i, int t);
float calcularJuros(float c, float i, int t);
float calcularTaxa(float j, float c, int t);
float calcularTempo(float j, float c, float i);

//ler a entrada de dados
float lerEntrada(const char *msg, int *contador);

int main(void) {

    float c, j, i;
    int t;
    int cont = 0;

    printf("\n\n========== CALCULADORA DE JUROS SIMPLES ==========\n");
    printf("Digite os valoros conforme solicitado.\n");
    printf("Se não souber algum, digite 0.\n\n");

    c = lerEntrada("Digite o valor do capital inicial (c): ", &cont);
    i = lerEntrada("Digite o valor da taxa desse juros (i): ", &cont) / 100;
    t = (int) lerEntrada("Digite o valor do tempo de aplicação desse juros(t): ", &cont);
    j = lerEntrada("Digite o valor do juros(j): ", &cont);

    //Mais de uma incognita, solução não possível
    if(cont > 1) {
        printf("Dados insuficientes.");
        exit(ERRO_DADOS);
    } 
    
    //Verificar qual operação deve ser feita de acordo com a variavel em falta
    if (c == 0) {
        printf("O valor da capital inicial e: R$%.2f", calcularCapital(j, i, t));
    } else if (i == 0) {
        printf("O valor da taxa inicial e: %.2f%%", calcularTaxa(j, c, t));
    } else if (t == 0) {
        printf("O tempo de aplicacao desse juros foi de: %0.fmes(es)", calcularTempo(j, c, i));
    } else if (j == 0) {
        printf("O juros total dessa aplicacao e de: R$%.2f", calcularJuros(c, i, t));
    } else {
        printf("Voce já tem todos os valores!");
        exit(ERRO_DADOS);
    }

    return 0;
}

float lerEntrada(const char *msg, int *contador) {
    float valor;
    
    printf("%s", msg);
    scanf("%f", &valor);
    
    if(valor == 0) {
        (*contador)++;
    }
    
    return valor;
}

//Cálcula o capital inicial, de acordo com a fórmula C = j / i * t.
float calcularCapital(float j, float i, int t) {
    if(i == 0 || t == 0) {
        printf("ERRO: Divisao por zero na operacao.\n");
        exit(ERRO_DADOS);
    }
    return j / (i * t);
}

//Cálculo da taxa do juros, de acordo com a fórmula i = j / c * t.
float calcularTaxa(float j, float c, int t) {
    if(c == 0 || t == 0) {
        printf("ERRO: Divisao por zero na operacao.\n");
        exit(ERRO_DADOS);
    }
    return (j / (c * t)) * 100;// a multiplicação serve para transformar o valor em porcentagem
}

//Cálculo do tempo em que o juros foi aplicado, de acordo com a fórmula t = j / c * i
float calcularTempo(float j, float c, float i) {
    if(c == 0 || i == 0) {
        printf("ERRO: Divisao por zero na operacao.\n");
        exit(ERRO_DADOS);
    }
    return j / (c * i);
}

//Calculo do juros, de acordo com a fórmula J = c * i * t
float calcularJuros(float c, float i, int t) {
    return c * i * t;
}
