#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int count;
} ListaEstatica;

void initListaEstatica(ListaEstatica* lista) {
    lista->count = 0;
}

bool addListaEstatica(ListaEstatica* lista, int value) {
    if (lista->count < MAX_SIZE) {
        lista->arr[lista->count++] = value;
        return true;
    }
    return false;
}

bool removeListaEstatica(ListaEstatica* lista, int value) {
    for (int i = 0; i < lista->count; i++) {
        if (lista->arr[i] == value) {
            lista->arr[i] = lista->arr[--lista->count]; 
            return true;
        }
    }
    return false;
}

bool searchListaEstatica(ListaEstatica* lista, int value) {
    for (int i = 0; i < lista->count; i++) {
        if (lista->arr[i] == value) {
            return true;
        }
    }
    return false;
}

// Pilha Estática
typedef struct {
    int arr[MAX_SIZE];
    int top;
} PilhaEstatica;

void initPilhaEstatica(PilhaEstatica* pilha) {
    pilha->top = -1;
}

bool pushPilhaEstatica(PilhaEstatica* pilha, int value) {
    if (pilha->top < MAX_SIZE - 1) {
        pilha->arr[++pilha->top] = value;
        return true;
    }
    return false;
}

bool popPilhaEstatica(PilhaEstatica* pilha, int* value) {
    if (pilha->top >= 0) {
        *value = pilha->arr[pilha->top--];
        return true;
    }
    return false;
}

// Fila Estática
typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} FilaEstatica;

void initFilaEstatica(FilaEstatica* fila) {
    fila->front = 0;
    fila->rear = 0;
}

bool enqueueFilaEstatica(FilaEstatica* fila, int value) {
    if (fila->rear < MAX_SIZE) {
        fila->arr[fila->rear++] = value;
        return true;
    }
    return false;
}

bool dequeueFilaEstatica(FilaEstatica* fila, int* value) {
    if (fila->front < fila->rear) {
        *value = fila->arr[fila->front++];
        return true;
    }
    return false;
}

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} ListaDinamica;

void initListaDinamica(ListaDinamica* lista) {
    lista->head = NULL;
}

void addListaDinamica(ListaDinamica* lista, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = lista->head;
    lista->head = newNode;
}

bool removeListaDinamica(ListaDinamica* lista, int value) {
    Node* current = lista->head;
    Node* prev = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                lista->head = current->next; 
            } else {
                prev->next = current->next; 
            }
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

bool searchListaDinamica(ListaDinamica* lista, int value) {
    Node* current = lista->head;
    while (current != NULL) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

typedef struct {
    Node* top;
} PilhaDinamica;

void initPilhaDinamica(PilhaDinamica* pilha) {
    pilha->top = NULL;
}

void pushPilhaDinamica(PilhaDinamica* pilha, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = pilha->top;
    pilha->top = newNode;
}

bool popPilhaDinamica(PilhaDinamica* pilha, int* value) {
    if (pilha->top != NULL) {
        Node* temp = pilha->top;
        *value = temp->data;
        pilha->top = temp->next;
        free(temp);
        return true;
    }
    return false;
}

// Fila Dinâmica
typedef struct {
    Node* front;
    Node* rear;
} FilaDinamica;

void initFilaDinamica(FilaDinamica* fila) {
    fila->front = fila->rear = NULL;
}

void enqueueFilaDinamica(FilaDinamica* fila, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (fila->rear == NULL) {
        fila->front = fila->rear = newNode;
        return;
    }
    fila->rear->next = newNode;
    fila->rear = newNode;
}

bool dequeueFilaDinamica(FilaDinamica* fila, int* value) {
    if (fila->front == NULL) {
        return false;
    }
    Node* temp = fila->front;
    *value = temp->data;
    fila->front = fila->front->next;
    if (fila->front == NULL) {
        fila->rear = NULL;
    }
    free(temp);
    return true;
}

int main() {
    int choice, subChoice, value;
    
    while (1) {
        printf("\nEscolha uma Estrutura de Dados:\n");
        printf("1. Estáticas\n");
        printf("2. Dinâmicas\n");
        printf("3. Sair\n");
        scanf("%d", &choice);

        if (choice == 3) break;

        if (choice == 1) {
            ListaEstatica lista;
            PilhaEstatica pilha;
            FilaEstatica fila;
            initListaEstatica(&lista);
            initPilhaEstatica(&pilha);
            initFilaEstatica(&fila);

            while (1) {
                printf("\nEscolha a Estrutura Estática:\n");
                printf("1. Lista\n2. Pilha\n3. Fila\n4. Voltar\n");
                scanf("%d", &subChoice);

                if (subChoice == 4) break;

                switch (subChoice) {
                    case 1:
                        printf("1. Adicionar 2. Remover 3. Buscar\n");
                        scanf("%d", &subChoice);
                        printf("Digite o valor: ");
                        scanf("%d", &value);
                        if (subChoice == 1) {
                            if (addListaEstatica(&lista, value))
                                printf("Valor %d adicionado.\n", value);
                            else
                                printf("Erro ao adicionar.\n");
                        } else if (subChoice == 2) {
                            if (removeListaEstatica(&lista, value))
                                printf("Valor %d removido.\n", value);
                            else
                                printf("Valor não encontrado.\n");
                        } else if (subChoice == 3) {
                            if (searchListaEstatica(&lista, value))
                                printf("Valor %d encontrado.\n", value);
                            else
                                printf("Valor não encontrado.\n");
                        }
                        break;

                    case 2: 
                        printf("1. Empilhar 2. Desempilhar\n");
                        scanf("%d", &subChoice);
                        if (subChoice == 1) {
                            printf("Digite o valor: ");
                            scanf("%d", &value);
                            if (pushPilhaEstatica(&pilha, value))
                                printf("Valor %d empilhado.\n", value);
                            else
                                printf("Erro ao empilhar.\n");
                        } else if (subChoice == 2) {
                            if (popPilhaEstatica(&pilha, &value))
                                printf("Valor %d desempilhado.\n", value);
                            else
                                printf("Pilha vazia.\n");
                        }
                        break;

                    case 3: 
                        printf("1. Enfileirar 2. Desenfileirar\n");
                        scanf("%d", &subChoice);
                        if (subChoice == 1) {
                            printf("Digite o valor: ");
                            scanf("%d", &value);
                            if (enqueueFilaEstatica(&fila, value))
                                printf("Valor %d enfileirado.\n", value);
                            else
                                printf("Erro ao enfileirar.\n");
                        } else if (subChoice == 2) {
                            if (dequeueFilaEstatica(&fila, &value))
                                printf("Valor %d desenfileirado.\n", value);
                            else
                                printf("Fila vazia.\n");
                        }
                        break;
                }
            }
        } else if (choice == 2) {
            ListaDinamica lista;
            PilhaDinamica pilha;
            FilaDinamica fila;
            initListaDinamica(&lista);
            initPilhaDinamica(&pilha);
            initFilaDinamica(&fila);

            while (1) {
                printf("\nEscolha a Estrutura Dinâmica:\n");
                printf("1. Lista\n2. Pilha\n3. Fila\n4. Voltar\n");
                scanf("%d", &subChoice);

                if (subChoice == 4) break;

                switch (subChoice) {
                    case 1: 
                        printf("1. Adicionar 2. Remover 3. Buscar\n");
                        scanf("%d", &subChoice);
                        printf("Digite o valor: ");
                        scanf("%d", &value);
                        if (subChoice == 1) {
                            addListaDinamica(&lista, value);
                            printf("Valor %d adicionado.\n", value);
                        } else if (subChoice == 2) {
                            if (removeListaDinamica(&lista, value))
                                printf("Valor %d removido.\n", value);
                            else
                                printf("Valor não encontrado.\n");
                        } else if (subChoice == 3) {
                            if (searchListaDinamica(&lista, value))
                                printf("Valor %d encontrado.\n", value);
                            else
                                printf("Valor não encontrado.\n");
                        }
                        break;

                    case 2: 
                        printf("1. Empilhar 2. Desempilhar\n");
                        scanf("%d", &subChoice);
                        if (subChoice == 1) {
                            printf("Digite o valor: ");
                            scanf("%d", &value);
                            pushPilhaDinamica(&pilha, value);
                            printf("Valor %d empilhado.\n", value);
                        } else if (subChoice == 2) {
                            if (popPilhaDinamica(&pilha, &value))
                                printf("Valor %d desempilhado.\n", value);
                            else
                                printf("Pilha vazia.\n");
                        }
                        break;

                    case 3: 
                        printf("1. Enfileirar 2. Desenfileirar\n");
                        scanf("%d", &subChoice);
                        if (subChoice == 1) {
                            printf("Digite o valor: ");
                            scanf("%d", &value);
                            enqueueFilaDinamica(&fila, value);
                            printf("Valor %d enfileirado.\n", value);
                        } else if (subChoice == 2) {
                            if (dequeueFilaDinamica(&fila, &value))
                                printf("Valor %d desenfileirado.\n", value);
                            else
                                printf("Fila vazia.\n");
                        }
                        break;
                }
            }
        }
    }

    return 0;
}
