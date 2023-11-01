#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
typedef int bool;

typedef struct {
    char nome[100];
    int produtos;
    int tempoDeChegada;
    int tempoDeSaida;
    struct Cliente* prox;
} Cliente;

void printCliente(Cliente* cliente) {
    printf("%s / %d produto(s) / Tempo de chegada: %dsec / Tempo de saida: %dsec \n", cliente->nome, cliente->produtos, cliente->tempoDeChegada, cliente->tempoDeSaida);
}

void calculaTempoDeSaida(Cliente* cliente, int K) {
    cliente->tempoDeSaida = cliente->tempoDeChegada + 10 + K * cliente->produtos;
}


typedef struct {
    Cliente* inicio;
    Cliente* fim;
} FILA;

void inicializarFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int tamanho(FILA* f) {
    Cliente* end = f->inicio;
    int tam = 0;
    while (end != NULL) {
        tam++;
        end = end->prox;
    }
    return tam;
}

bool inserirNaFila(FILA* f, Cliente* cliente, int velocidade) {
    Cliente* novo = (Cliente*) malloc(sizeof(Cliente));
    // Atribui os valores ao novo
    strcpy(novo->nome, cliente->nome);
    novo->produtos = cliente->produtos;
    novo->tempoDeChegada = cliente->tempoDeChegada;
    calculaTempoDeSaida(novo, velocidade);
    novo->prox = NULL;

    if (f->inicio==NULL) f->inicio = novo;
    else f->fim->prox = novo;
    f->fim = novo;
    return true;
}

void exibirFila(FILA* f) {
    Cliente* end = f->inicio;
    while (end != NULL) {
        printCliente(end);
        end = end->prox;
    }
}

/*

bool excluirDaFila(FILA* f, REGISTRO* reg) {
    if (f->inicio==NULL) return false;
    *reg = f->inicio->reg;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if (f->inicio == NULL) f->fim = NULL;
    return true;
}

void reinicializarFila(FILA* f) {
    PONT end = f->inicio;
    while (end != NULL) {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}
*/



void main() {
    Cliente * cliente = (Cliente *)malloc(sizeof(Cliente));
    FILA * fila = (FILA *)malloc(sizeof(FILA));
    inicializarFila(fila);

    int K;
    printf("Qual a velocidade dos atendentes? ");
    scanf("%d", &K);
    getchar();

    while(1) {
        printf("Insira as informacoes do cliente (ou digite nada para sair): ");

        char input[100];
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        if (input[0] == '\n') {
            break;
        }

        if (sscanf(input, "%s %d %d", cliente->nome, &cliente->tempoDeChegada, &cliente->produtos) != 3) {
            printf("Formato de entrada invalido. Tente novamente.\n");
        } else {
            cliente->prox = NULL;
            inserirNaFila(fila, cliente, K);
        }
    }

    exibirFila(fila);

    return 0;
}
