#ifndef STACK_H_
#define STACK_H_
#define MAX_STACK_SIZE 256
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int lb;
    int ub;
} BndType;

typedef union {
    long int items[MAX_STACK_SIZE];
    BndType bounds[MAX_STACK_SIZE];
}StackTypes;


typedef struct {
    StackTypes *data;
    long int top;
} Stack;

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

#endif
