#include <stdio.h>

#define MAX 50

void exibirVetor(int vetor[], int tamanho) {
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int buscaElementoBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

void excluirElemento(int vetor[], int *tamanho, int valor) {
    int pos = buscaElementoBinaria(vetor, *tamanho, valor);
    if (pos == -1) {
        printf("Elemento não encontrado.\n");
        return;
    }
    for (int i = pos; i < (*tamanho) - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    (*tamanho)--;
    printf("Elemento removido com sucesso.\n");
}

void adicionarElementoOrdenado(int vetor[], int *tamanho, int valor) {
    if (*tamanho >= MAX) {
        printf("Vetor cheio! Não é possível inserir mais elementos.\n");
        return;
    }

    int i = *tamanho - 1;
    while (i >= 0 && vetor[i] > valor) {
        vetor[i + 1] = vetor[i];
        i--;
    }
    vetor[i + 1] = valor;
    (*tamanho)++;
    printf("Elemento inserido com sucesso.\n");
}

void exibirMenu(int vetor[], int *tamanho) {
    int opcao, valor;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Exibir todo o vetor\n");
        printf("2. Consultar posição de um elemento (Busca Binária)\n");
        printf("3. Excluir um elemento\n");
        printf("4. Adicionar um valor ordenado\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            exibirVetor(vetor, *tamanho);
        } else if (opcao == 2) {
            printf("Digite o valor para consultar: ");
            scanf("%d", &valor);
            int posicao = buscaElementoBinaria(vetor, *tamanho, valor);
            if (posicao != -1)
                printf("Elemento encontrado na posição %d\n", posicao);
            else
                printf("Elemento não encontrado.\n");
        } else if (opcao == 3) {
            printf("Digite o valor para remover: ");
            scanf("%d", &valor);
            excluirElemento(vetor, tamanho, valor);
        } else if (opcao == 4) {
            printf("Digite o valor para inserir: ");
            scanf("%d", &valor);
            adicionarElementoOrdenado(vetor, tamanho, valor);
        } else if (opcao == 5) {
            printf("Saindo...\n");
        } else {
            printf("Opção inválida!\n");
        }
    } while (opcao != 5);
}

int main() {
    int vetor[MAX];
    int tamanho;

    do {
        printf("Digite o tamanho do vetor (entre 3 e 50): ");
        scanf("%d", &tamanho);
    } while (tamanho < 3 || tamanho > 50);

    int elementosInseridos = 0;
    while (elementosInseridos < tamanho) {
        int valor;
        printf("Digite o valor %d: ", elementosInseridos + 1);
        scanf("%d", &valor);
        adicionarElementoOrdenado(vetor, &elementosInseridos, valor);
    }

    exibirMenu(vetor, &tamanho);

    return 0;
}