#include <stdio.h>
#include <math.h>
#include "dataStructures.h"
// #include "stack.c"
// #include "quickSort.c"


int OperationSelector();
long int Sum(long int num1, long int num2);
long int Sub(long int num1, long int num2);
long int Mult(long int num1, long int num2);
long int Div(long int num1, long int num2);
long int Module(long int num1, long int num2);
void Sort(long int *x);
long int Operation(int option, Stack *s);
Stack InputValues(Stack *s);

int main(){
    int option, isValueSaved; 
    Stack s;
    initializeStack(&s);

    option = OperationSelector();

    while (option != 0)
    {
        if(option>=0 && option<=6){
            // s = InputValues(&s);
            printf("%ld\n", Operation(option, &s));
            printf("Deseja salvar o valor para continuar a operação ou realizar uma com novo valores?\n0 -  Nova operação\n1 - Salvar valor\n");
            scanf("%d", &isValueSaved);
            if(isValueSaved == 0 && !isStackEmpty(&s)) popValueStackDouble(&s);
        }else{
            printf("Digite um valor válido. ");
        }
        option = OperationSelector();
    }
    return 0;
}

int OperationSelector(){
    int option;
    printf("Selecione uma operacao: \n");
    printf("1 - Soma;\n2 - Subtracao;\n3 - Multiplicacao;\n4 - Divisao\n5 - Modulo;\n6 - Ordenacao de numeros;\n0 - Sair\n");
    
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        printf("Operacao selecionada foi: %d - Soma\n", option);
        break;
    case 2: 
        printf("Operacao selecionada foi: %d - Subtracao\n", option);
        break;
    case 3: 
        printf("Operacao selecionada foi: %d - Multiplicacao\n", option);
        break;
    case 4:
        printf("Operacao selecionada foi: %d - Divisao\n", option);
        break;
    case 5:
        printf("Operacao selecionada foi: %d - Modulo\n", option);
        break;
    case 6:
        printf("Operacao selecionada foi: %d - Ordenacao de numeros\n", option);
        break;
    case 0:
        printf("Programa encerrado\n");
        break;
    default:
        printf("Operacao invalida, selecione novamente: \n");
        break;
    }
    return option;
}

long int Sum(long int num1, long int num2){
    return num1 + num2;
}

long int Sub(long int num1, long int num2){
    return num1 - num2;
}

long int Mult(long int num1, long int num2){
    return num1*num2;
}

long int Div(long int num1, long int num2){
    if(num2 == 0){
        printf("Divisao por:%ld nao valida, insira um valor valido\n", num2);
        return num1;
    }
    return num1/num2;
}

long int Module(long int num1, long int num2){
    return num1%num2;
}

void Sort(long int *x){
    // int len = sizeof(*x) / sizeof(x[0]);
    // printf("size: %d\n", len);

    quick_sort(x, 0, 9);

    for(int i=0; i<9; i++){
        printf("%ld ", x[i]);
    }
}

long int Operation(int option, Stack *s){
    long int num1, num2, result;
    switch(option){
        case 1:
            InputValues(s);
            num2 = popValueStackDouble(s);
            num1 = popValueStackDouble(s);
            result = Sum(num1, num2);
            pushValueStackDouble(s, result);
            return result;
        case 2:
            InputValues(s);
            num2 = popValueStackDouble(s);
            num1 = popValueStackDouble(s);
            result = Sub(num1, num2);
            pushValueStackDouble(s, result);
            return result;
        case 3:
            InputValues(s);
            num2 = popValueStackDouble(s);
            num1 = popValueStackDouble(s);
            result = Mult(num1, num2);
            pushValueStackDouble(s, result);
            return result;
        case 4:
            InputValues(s);
            num2 = popValueStackDouble(s);
            num1 = popValueStackDouble(s);
            result = Div(num1, num2);
            pushValueStackDouble(s, result);
            return result;
        case 5:
            InputValues(s);
            num2 = popValueStackDouble(s);
            num1 = popValueStackDouble(s);
            result = Module(num1, num2);
            pushValueStackDouble(s, result);
            return result;
        case 6:
            long int x[]= { 10, 7, 8, 1, 1000, 9, 4, 14, 13};
            Sort(x);
            return 0.0; //alterar para função de sort;
        default:
            return 0.0;
            break;
    }
};

Stack InputValues(Stack *s){
    long int num1, num2;
    // Stack stackControl = *s;
    if(isStackEmpty(s)){
        printf("Insira o primeiro valor: ");
        scanf("%ld", &num1);
        pushValueStackDouble(s, num1);
        printf("Insira o segundo valor: ");
        scanf("%ld", &num2);
        pushValueStackDouble(s, num2);

        return *s;
    }
    printf("Insira novo valor: ");
    scanf("%ld", &num1);
    pushValueStackDouble(s, num1);

    return *s;
}
