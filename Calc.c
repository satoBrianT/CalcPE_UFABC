#include <stdio.h>
#include <math.h>
#include "dataStructures.h"
// #include "stack.c"
// #include "quickSort.c"

/*
Prototipos das funções
*/
int OperationSelector();
int InputTypeSelector();
long int Sum(long int num1, long int num2);
long int Sub(long int num1, long int num2);
long int Mult(long int num1, long int num2);
long int Div(long int num1, long int num2);
long int Module(long int num1, long int num2);
void Sort(Stack *s, int inputType);
void Operation(int option, Stack *s, int inputType);
void FileReader(Stack *s, Stack *sAux);
void FileOutput(Stack *s, Stack *sAux, int operation);
void InputValues(Stack *s, int option);

int main(){
    int option, typeInput, isValueSaved; 
    Stack s, sAux;
    initializeStack(&s);
    initializeStack(&sAux);

    //seleção inicial de operação
    option = OperationSelector();
    //enquanto o usuário não optar por encerrar (inserir 0) o pograma continuara rodando
    while (option != 0)
    {
        //garantir que o valor inserido seja igual uma operação aceita
        if(option>=0 && option<=6){
            //selecionar se a operação será feita em por arquivo ou console
            typeInput = InputTypeSelector();
            if(typeInput == 1){
                InputValues(&s, option);
            }else{
                FileReader(&s, &sAux); //função para leitura do arquivo
            }
            Operation(option, &s, typeInput); //realização da operação após os valores seres ajustados na pilha
            if(typeInput == 2){
                FileOutput(&s, &sAux, option);//saida caso o input tenha sido um arquivo
                printf("\nDeseja salvar o valor para continuar a operacao ou realizar uma com novo valores ou encerrar o programa?\n0 - Finalizar;\n1 -  Nova operação.\n");
            }else{
                printf("\nDeseja salvar o valor para continuar a operacao ou realizar uma com novo valores ou encerrar o programa?\n0 - Finalizar;\n1 -  Nova operação;\n2 - Salvar valor.\n");
            }
            scanf("%d", &isValueSaved); //validar se a operacao sera continuada ou finalizada
            if(isValueSaved == 1 && !isStackEmpty(&s)){
                while (!isStackEmpty(&s) && !isStackEmpty(&sAux)) {
                    popValueStackInt(&s);
                    popValueStackInt(&sAux);
                };
            };
            if(isValueSaved == 0){
                printf("Programa encerrado\n");
                freeStack(&s);
                freeStack(&sAux);
                return 0;
            };
        }else{
            printf("Digite um valor válido. ");
        };
        option = OperationSelector();
    }
    freeStack(&s); //liberação da memória alocada na heap para as estruturas de pilha
    freeStack(&sAux);
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
    while(option<1 || option>2){
        printf("Selecione uma operaçao valida: \n");
        printf("1 - Teclado;\n2 - Arquivo;\n");
        scanf("%d", &option);
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

/*
funcao de sorteamento, recebe como paramentro uma Stack para ser usada posteriormente e o tipo de input;
caso o input tenha sido por arquivo sera feita somente a ordenacao;
caso contrario, os numeros serao printados no console.
*/
void Sort(Stack *s, int inputType){
    int size = s->top + 1;
    long int *arr = (long int *)malloc(size * sizeof(long int));
    int lastIndex = s->top;
    while (!isStackEmpty(s)){
        arr[s->top] = popValueStackInt(s);
    };
    //a funcao quick_sort é feita em uma library personalizada sendo chamada pelo arquivo de headers
    quick_sort(arr, size);
    if(inputType == 1){
        printf("Ordenado: ");
        for(int i=0; i<size; i++){
            printf("%ld ", arr[i]);
        };
    };
    /*
    A ordemd de leitura e priordade de uma pilha eh inversa de um vetor;
    Desta maneira, sabendo o tamanho do vetor, le-se do ultimo index, e empilhando os valores manualmente na pilha;
    */
    for(int i=lastIndex; i>=0; i--){
        pushValueStackInt(s,arr[i]);
    }
    free(arr);
}

void Operation(int option, Stack *s, int inputType){
    long int num1, num2, result;
    switch(option){
        case 1:
            if(inputType == 1){
                num2 = popValueStackInt(s);
                num1 = popValueStackInt(s);
                result = Sum(num1, num2);
                printf("%ld+%ld = %ld", num1, num2, result);
                pushValueStackInt(s, result);
            }else{
                while (s->top>0){
                    num2 = popValueStackInt(s);
                    num1 = popValueStackInt(s);                    
                    result = Sum(num2, num1);
                    pushValueStackInt(s, result);
                } 
            }
            break;
        case 2:
            if(inputType == 1){
                num2 = popValueStackInt(s);
                num1 = popValueStackInt(s);
                result = Sub(num1, num2);
                pushValueStackInt(s, result);
                printf("%ld-%ld = %ld", num1, num2, result);
            }else{
                while (s->top>0){
                    num2 = popValueStackInt(s);
                    num1 = popValueStackInt(s);                    
                    result = Sub(num2, num1);
                    pushValueStackInt(s, result);
                } 
            }
            break;
        case 3:
            if(inputType == 1){
                num2 = popValueStackInt(s);
                num1 = popValueStackInt(s);     
                result = Mult(num1, num2);
                pushValueStackInt(s, result);
                printf("%ld*%ld = %ld", num1, num2, result);
            }else{
                while (s->top>0){
                    num2 = popValueStackInt(s);
                    num1 = popValueStackInt(s);                    
                    result = Mult(num2, num1);
                    pushValueStackInt(s, result);
                }
            }
            break;
        case 4:
            if(inputType == 1){
                num2 = popValueStackInt(s);
                num1 = popValueStackInt(s);
                result = Div(num1, num2);
                pushValueStackInt(s, result);
                printf("%ld/%ld = %ld", num1, num2, result);
            }else{
                while (s->top>0){
                    num2 = popValueStackInt(s);
                    num1 = popValueStackInt(s);                    
                    result = Div(num2, num1);
                    pushValueStackInt(s, result);
                }
            }
            break;
        case 5:
            if(inputType == 1){
                num2 = popValueStackInt(s);
                num1 = popValueStackInt(s);
                result = Module(num1, num2);
                pushValueStackInt(s, result);
                printf("Resto de %ld/%ld: %ld", num1, num2, result);
            }else{
                while (s->top>0){
                    num2 = popValueStackInt(s);
                    num1 = popValueStackInt(s);                    
                    result = Div(num2, num1);
                    pushValueStackInt(s, result);
                }
            }
            break;
        case 6:
            Sort(s, inputType);
            break;
        default:
            break;
    }
};
/*
Funcao para receber os inputs do usuario;
Caso a operacao selecionada tenha sido a ordenacao, a insercao precisa ser feita com no minimo 10 numeros;
*/
void InputValues(Stack *s,int option){
    long int num1, num2;
    if(isStackEmpty(s) && option != 6 ){
        printf("Insira o primeiro valor: ");
        scanf("%ld", &num1);
        pushValueStackInt(s, num1);
        printf("Insira o segundo valor: ");
        scanf("%ld", &num2);
        pushValueStackInt(s, num2);
    }else if (isStackEmpty(s) && option == 6){
        num1 = 1;
        while (num1 != 0 ){ //este loop garante que os 10 numeros serao inseridos na pilha
            while(s->top<8){
                printf("Adicione um numero: ");
                scanf("%ld", &num2);
                pushValueStackInt(s, num2);
            };
            printf("Adicione um numero: ");
            scanf("%ld", &num2);
            pushValueStackInt(s, num2);
            printf("Deseja adicionar mais?\n 0-Não;\n 1-Sim;\n ");
            scanf("%ld", &num1);
        }
    }else{
        printf("Insira novo valor: ");
        scanf("%ld", &num1);
        pushValueStackInt(s, num1);
    }
}
/*
funcao que fara a leitura do arquivo, pelo seu nome;
*/
void FileReader(Stack *s, Stack *sAux){
    char fileName[400];
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
        printf ("Erro de alocacao de memoria.\n") ;
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
        pushValueStackInt(s,buffer[i]);
        pushValueStackInt(sAux,buffer[i]);
    }
    fclose(pFile);
    free(buffer);
}

/*
esta funcao formata o que sera escrito no arquvivo de saida, baseado na operacao selecionada pelo usuario
*/
void FileOutput(Stack *s, Stack *sAux, int operation){
    char fileName[400];
    long int result;
    printf("\nDigite o nome do arquivo de saida (adicione a extensão (EX.: .txt)): ");
    scanf( "%s", fileName);

    FILE *pFile = fopen(fileName, "w");
    if(pFile == NULL){
        printf("ERROR: Nao foi possivel abrir o arquivo.");
        exit(1);
    }
    long int *arr = (long int*)malloc(((s->top)+1) * sizeof(long int));
    int control = 0;
    if(operation != 6){
        result =  (!isStackEmpty(s)) ? popValueStackInt(s) : 0;
        
        while (!isStackEmpty(sAux)) {
            arr[control] = popValueStackInt(sAux);
            control++;
        }
    }else{
        while (!isStackEmpty(s)) {
            arr[control] = popValueStackInt(s);
            control++;
        }
    };

    for(int i = 0; i<control; i++){
        switch (operation)
        {
        case 1:
            if(i!=0) {
                fprintf(pFile, " + %ld", arr[i]);
            }else{
                fprintf(pFile, "%ld", arr[i]);
            }
            if (i==control-1) fprintf(pFile, " = %ld", result);
            break;
        case 2:
            if(i==0){
                fprintf(pFile, "%ld", arr[i]);
            }else{
                fprintf(pFile, " - %ld", arr[i]);
            }
            if (i==control-1) fprintf(pFile, " = %ld", result);
            break;
        case 3:
            if(i==0){
                fprintf(pFile, "%ld", arr[i]);
            }else{
                fprintf(pFile, " * %ld", arr[i]);
            } 
            if (i==control-1) fprintf(pFile, " = %ld", result);
            break;
        case 4:
            if(i==0){
                fprintf(pFile, "%ld", arr[i]);
            }else{
                fprintf(pFile, " / %ld", arr[i]);
            } 
            if (i==control-1) fprintf(pFile, " = %ld", result);
            break;
        case 5:
            if(i==0){
                fprintf(pFile, "%ld", arr[i]);
            }else{
                fprintf(pFile, " / %ld", arr[i]); 
            }
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

