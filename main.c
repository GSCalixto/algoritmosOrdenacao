#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos de posição no vetor
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para embaralhar a ordem do vetor
void embaralhar(int vetor[], int tamanho) {
    // Inicializa a semente aleatória
    srand(time(NULL));

    // Percorre o vetor do último ao primeiro elemento
    for (int i = tamanho - 1; i > 0; i--) {
        // Gera um índice aleatório entre 0 e i (inclusive)
        int j = rand() % (i + 1);

        // Troca o elemento atual com o elemento no índice aleatório
        trocar(&vetor[i], &vetor[j]);
    }
}

// Função para intercalar os subvetores ordenados
void fundir(int vetor[], int inicio, int meio, int fim) {
    int tamanho_esq = meio - inicio + 1;
    int tamanho_dir = fim - meio;

    int vetor_esq[tamanho_esq], vetor_dir[tamanho_dir];
    int i, j, k;

    // Copia os elementos para os vetores temporários
    for (i = 0; i < tamanho_esq; i++)
        vetor_esq[i] = vetor[inicio + i];
    for (j = 0; j < tamanho_dir; j++)
        vetor_dir[j] = vetor[meio + 1 + j];

    // Intercala os elementos dos subvetores temporários de volta ao vetor original
    i = 0;  // Índice do subvetor esquerdo
    j = 0;  // Índice do subvetor direito
    k = inicio;  // Índice do vetor original

    while (i < tamanho_esq && j < tamanho_dir) {
        if (vetor_esq[i] <= vetor_dir[j]) {
            vetor[k] = vetor_esq[i];
            i++;
        } else {
            vetor[k] = vetor_dir[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes do subvetor esquerdo, se houver
    while (i < tamanho_esq) {
        vetor[k] = vetor_esq[i];
        i++;
        k++;
    }

    // Copia os elementos restantes do subvetor direito, se houver
    while (j < tamanho_dir) {
        vetor[k] = vetor_dir[j];
        j++;
        k++;
    }
}

// Função recursiva para dividir e mesclar o vetor
void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Chama a função recursivamente para dividir o vetor em subvetores
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        // Intercala os subvetores ordenados
        fundir(vetor, inicio, meio, fim);
    }
}

// Função para encontrar o pivô e particionar o vetor
int particionar(int vetor[], int inicio, int fim) {
    int pivot = vetor[fim];  // Pivô
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivot) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);
    return i + 1;
}

// Função recursiva para ordenar o vetor usando Quick Sort
void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        // Encontra o pivô e particiona o vetor
        int p = particionar(vetor, inicio, fim);

        // Chama a função recursivamente para ordenar os subvetores à esquerda e à direita do pivô
        quickSort(vetor, inicio, p - 1);
        quickSort(vetor, p + 1, fim);
    }
}

// Implementação do algoritmo Bubble Sort
void bubbleSort(int vetor[], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

// Implementação do algoritmo Selection Sort
void selectionSort(int vetor[], int tamanho) {
    int i, j, minIndex;
    for (i = 0; i < tamanho - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }
        trocar(&vetor[i], &vetor[minIndex]);
    }
}

// Implementação do algoritmo Insertion Sort
void insertionSort(int vetor[], int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

// Função para exibir o vetor ordenado
void exibirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[1000];
    int i;
    int opcao;

    // Preencher o vetor com números de 1 a 1000
    for (i = 0; i < 1000; i++) {
        vetor[i] = i + 1;
    }
  
    // Embaralha o vetor
    printf("\nVetor Desordenado:\n");
    embaralhar(vetor, 1000);
    exibirVetor(vetor, 1000);

    // Exibir o menu de seleção
    printf("\nSelecione o algoritmo de ordenacao:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    // Executar o algoritmo de ordenação selecionado
    switch (opcao) {
        case 1:
            bubbleSort(vetor, 1000);
            printf("\nVetor ordenado usando Bubble Sort:\n");
            exibirVetor(vetor, 1000);
            break;
        case 2:
            selectionSort(vetor, 1000);
            printf("\nVetor ordenado usando Selection Sort:\n");
            exibirVetor(vetor, 1000);
            break;
        case 3:
            insertionSort(vetor, 1000);
            printf("\nVetor ordenado usando Insertion Sort:\n");
            exibirVetor(vetor, 1000);
            break;
        case 4:
            mergeSort(vetor, 0, 999);
            printf("\nVetor ordenado usando Merge Sort:\n");
            exibirVetor(vetor, 1000);
            break;
        case 5:
            quickSort(vetor, 0, 999);
            printf("\nVetor ordenado usando Quick Sort:\n");
            exibirVetor(vetor, 1000);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }

    return 0;
}