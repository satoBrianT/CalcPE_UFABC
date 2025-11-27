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

void initializeStack(Stack *stack);

int isStackEmpty(Stack *s);
int isStackFull(Stack *s);

void pushValueStackInt(Stack *s, long int value);
void pushValuesQuickSort(Stack *s, BndType value);

long int popValueStackInt(Stack *s);
BndType popValueStackQuickSort(Stack *s);

void freeStack(Stack *stack);

// int partition(long int *arr, int il, int ih);
void partition(long int *arr, int lb, int ub, int *pj);
// void quick_sort(long int *arr, int il, int ih);
void quick_sort(long int *arr, int n);

#endif
