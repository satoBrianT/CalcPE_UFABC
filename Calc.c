#include <stdio.h>
#include <math.h>
#include "dataStructures.h"
// #include "stack.c"
// #include "quickSort.c"


int OperationSelector();
int InputTypeSelector();
long int Sum(long int num1, long int num2);
long int Sub(long int num1, long int num2);
long int Mult(long int num1, long int num2);
long int Div(long int num1, long int num2);
long int Module(long int num1, long int num2);
void Sort(long int *x);
void Operation(int option, Stack *s);
void FileReader(Stack *s, Stack *sAux);
void FileOutput(Stack *s, int operation);
Stack InputValues(Stack *s);

int main(){
    int option, typeInput, isValueSaved; 
    Stack s;
    initializeStack(&s);

    FileReader();

    option = OperationSelector();

    while (option != 0)
    {
        if(option>=0 && option<=6){
            // s = InputValues(&s);
            Operation(option, &s);
            printf("\nDeseja salvar o valor para continuar a operacao ou realizar uma com novo valores?\n0 -  Nova operação\n1 - Salvar valor\n");
            scanf("%d", &isValueSaved);
            if(isValueSaved == 0 && !isStackEmpty(&s)) popValueStackInt(&s);
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

int InputTypeSelector(){
    int option;

    printf("Entrada será por teclado ou arquivo: \n");
    printf("1 - Teclado;\n2 - Arquivo;\n");
    scanf("%d", &option);
    return option;
}

void ExecuteOperation(int option, int inputType, Stack *s){
    while (option != 0)
    {
        if(option>=0 && option<=6){
            // s = InputValues(&s);
            if(inputType == 2){
                Stack sAux;
                initializeStack(sAux);
                FileReader(s, sAux);
                while (s->top > 0)
                {
                  Operation(option, &s);
                }
                pushValueStackInt(&sAux, popValueStackInt(&s));

                
            }
            Operation(option, &s);
            printf("\nDeseja salvar o valor para continuar a operacao ou realizar uma com novo valores?\n0 -  Nova operação\n1 - Salvar valor\n");
            scanf("%d", &isValueSaved);
            if(isValueSaved == 0 && !isStackEmpty(&s)) popValueStackInt(&s);
        }else{
            printf("Digite um valor válido. ");
        }
        option = OperationSelector();
    }
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
    quick_sort(x, 9);
    printf("Ordenado: ");
    for(int i=0; i<9; i++){
        printf("%ld ", x[i]);
    }
}

void Operation(int option, Stack *s){
    long int num1, num2, result;
    // long int x[]= { 10, 7, 8, 1, 1000, 9, 4, 14, 13};
    switch(option){
        case 1:
            InputValues(s);
            num2 = popValueStackInt(s);
            num1 = popValueStackInt(s);
            result = Sum(num1, num2);
            pushValueStackInt(s, result);
            printf("%ld+%ld = %ld", num1, num2, result);
            // return result;
            break;
        case 2:
            InputValues(s);
            num2 = popValueStackInt(s);
            num1 = popValueStackInt(s);
            result = Sub(num1, num2);
            pushValueStackInt(s, result);
            printf("%ld-%ld = %ld", num1, num2, result);
            // return result;
            break;
        case 3:
            InputValues(s);
            num2 = popValueStackInt(s);
            num1 = popValueStackInt(s);
            result = Mult(num1, num2);
            pushValueStackInt(s, result);
            printf("%ld*%ld = %ld", num1, num2, result);
            // return result;
            break;
        case 4:
            InputValues(s);
            num2 = popValueStackInt(s);
            num1 = popValueStackInt(s);
            result = Div(num1, num2);
            pushValueStackInt(s, result);
            printf("%ld/%ld = %ld", num1, num2, result);
            // return result;
            break;
        case 5:
            InputValues(s);
            num2 = popValueStackInt(s);
            num1 = popValueStackInt(s);
            result = Module(num1, num2);
            pushValueStackInt(s, result);
            printf("Resto de %ld/%ld: %ld", num1, num2, result);
            // return result;
            break;
        case 6:
            Sort(x);
            break; //alterar para função de sort;
        default:
            break;
    }
};

Stack InputValues(Stack *s){
    long int num1, num2;
    if(isStackEmpty(s)){
        printf("Insira o primeiro valor: ");
        scanf("%ld", &num1);
        pushValueStackInt(s, num1);
        printf("Insira o segundo valor: ");
        scanf("%ld", &num2);
        pushValueStackInt(s, num2);

        return *s;
    }
    printf("Insira novo valor: ");
    scanf("%ld", &num1);
    pushValueStackInt(s, num1);

    return *s;
}

void FileReader(Stack *s, Stack *sAux){
    char fileName[100];
    long int * buffer = NULL, aux;
    long file_size;
    FILE *pFile;
    
    printf("Insira o nome e/ou PATH do arquivo (inclua a extensão): ");
    scanf( "%s", fileName);

    pFile = fopen(fileName, "r");
    if(pFile == NULL){
        printf("ERROR: Arquivo não encontrado ou impossível de abrir\n");
    }

    file_size = 0;
    while (fscanf(pFile, "%li", &aux)!= EOF){
        file_size ++;
    }
    

    rewind(pFile);
    buffer = ( long int *) malloc ( sizeof ( long int ) * ( file_size + 1) );
    if ( buffer == NULL ) {
        printf (" Erro de alocacao de memoria.\n") ;
        fclose (pFile);
        exit(1);
    }

    for (int i = 0; i < file_size; i++) {
        if (fscanf(pFile, "%li", &buffer[i]) != 1) {
            printf("Erro na leitura do número %d\n", i);
            break;
        }
    }

    for (int i = file_size-1; i>=0; i--) {
        printf("%ld\n", buffer[i]);
        pushValueStackInt(s,buffer[i]);
        pushValueStackInt(sAux,buffer[i]);
    }
    fclose(pFile);
    free(buffer);
}

void FileOutput(Stack *s, int operation){
    FILE *pFile = fopen("resultado.txt", "w");
    if(pFile == NULL){
        printf("ERROR: Nao foi possivel abrir o arquivo.")
        exit(1);
    }
    long int *arr = (long int*)malloc(((s->top)+1) * sizeof(long int));
    long int result =  popValueStackInt(&s);
    int control = 0;
    while (!isStackEmpty(&s)) {
        arr[control] = popValueStackInt(&s);
        control++
    }

    if(control > 0){
        fprintf(pFile, "%ld", arr[0]);
    }
    for(int i = 1; i<control, i++){
        switch (operation)
        {
        case 1:
            fprintf(pFile, " + %ld", arr[i]);
            if (i==control-1) fprintf(pFile, " = %ld", result);
            break;
        case 2:
            fprintf(pFile, " - %ld", arr[i]);
            if (i==control-1) fprintf(pFile, " = %ld", result);
            break;
        case 3:
            fprintf(pFile, " * %ld", arr[i]);
            if (i==control-1) fprintf(pFile, " = %ld", result);
            break;
        case 4:
            fprintf(pFile, " / %ld", arr[i]);
            if (i==control-1) fprintf(pFile, " = %ld", result);
            break;
        case 5:
            fprintf(pFile, " / %ld", arr[i]);
            if (i==control-1) fprintf(pFile, " = %ld", result);
            break;       
        case 6:
            fprintf(pFile, "  %ld", arr[i]);
            break;
        default:
            break;
        }
    }

    fclose(pFile);
    free(arr);
}

