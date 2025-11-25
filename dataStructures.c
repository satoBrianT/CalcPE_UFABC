#include "dataStructures.h"
#include <stdlib.h>
#include <stdio.h>

void initializeStack(Stack *stack) {
    stack->data = malloc(sizeof(StackTypes));
    stack->top = -1;
}

int isStackEmpty(Stack *s){
    return s->top == -1;
};

int isStackFull(Stack *s){
    return s->top == MAX_STACK_SIZE - 1;
};

void pushValueStackDouble(Stack *s, long int value){
    if(isStackFull(s)){
        printf("Error: Stack overflow");
        exit(1);
    }
    s->data->items[++(s->top)] = value;
    // printf("Valor adicionado a pilha: %d\n",value);
};

void pushValuesQuickSort(Stack *s, BndType value){
    if(isStackFull(s)){
        printf("Error: Stack overflow");
        exit(1);
    }
    s->data->bounds[++(s->top)] = value;
    // printf("Valor adicionado a pilha: %d\n",value);
}

double popValueStackDouble(Stack *s){
    if(isStackEmpty(s)){
        printf("ERRO: Stack underflow");
        exit(1);
    }

    double poppedValue = s->data->items[(s->top)];
    (s->top)--;
    return poppedValue;
};

BndType popValueStackQuickSort(Stack *s){
    if(isStackEmpty(s)){
        printf("ERRO: Stack underflow");
        exit(1);
    }

    BndType poppedValue = s->data->bounds[(s->top)];
    (s->top)--;
    return poppedValue;
};

void freeStack(Stack *stack) {  // NOVO: Liberar memória
    free(stack->data);
}

int partition(long int *arr, int il, int ih){
    long int pivot, temp;
    int i;
    // temp = (long int*)malloc(ih * (sizeof(long int)));

    pivot = arr[ih];
    i = (il - 1);

    for(int j = il; j<=ih; j++){
        if(arr[j]<pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[ih];
    arr[ih] = arr[i+1];
    arr[i+1] = temp;

    return i+1;
}

void quick_sort(long int *arr, int il, int ih){
    long int pivot;
    if(il<ih){
        pivot = partition(arr, il, ih);
        quick_sort(arr, il, pivot-1);
        quick_sort(arr, pivot+1, ih);
    }
}

