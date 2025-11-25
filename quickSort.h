// #ifndef QUICKSORT_H_
// #define QUICKSORT_H_
// #include <stdlib.h>
// #include <stdio.h>
// #include "stack.h"

// void Partition(double x[], int lb, int ub, int *pj){
//     int lower, upper;
//     double a, temp;

//     a = x[lb];
//     upper = ub;
//     lower = lb;

//     while(lower < upper){
//         while(x[lower] <= a && lower < ub){
//             lower++;
//         }
//         while(x[upper] > a){
//             upper--;
//         }
//         if(lower < upper){
//             temp = x[lower];
//             x[lower] = x[upper];
//             x[upper] = temp;
//         }
//     }
//     x[lb] = x[upper];
//     x[upper] = a;
//     *pj = upper;
// }


// void QuickSort(double x[], int n){
//     int i,j;
//     Stack s;
//     BndType newBnd;
    
//     initializeStack(&s);
//     newBnd.lb = 0;
//     newBnd.ub = n-1;
//     pushValuesQuickSort(&s, newBnd);

//     while(!isStackEmpty(&s)){
//         popValueStackQuickSort(&s);
//         while(newBnd.ub > newBnd.lb){
//             Partition(x, newBnd.lb, newBnd.ub, &j);
//             if(j-newBnd.lb > newBnd.ub - j){
//                 i = newBnd.ub;
//                 newBnd.ub = j-1;
//                 pushValuesQuickSort(&s, newBnd);
//                 newBnd.lb = j+1;
//                 newBnd.ub = i;
//             }else{
//                 i = newBnd.lb;
//                 newBnd.lb = j+1;
//                 pushValuesQuickSort(&s, newBnd);
//                 newBnd.lb = i;
//                 newBnd.ub = j-1;
//             }
//         }
//     }
// }

// #endif

// #ifndef QUICKSORT_H_
// #define QUICKSORT_H_
// #include <stdlib.h>
// #include <stdio.h>
// #include "stack.h"

// void Partition(long int x[], int lb, int ub, int *pj) {
//     long int a = x[lb];
//     int down = lb;
//     int up = ub;
    
//     while (down < up) {
//         while (x[down] <= a && down < ub) down++;
//         while (x[up] > a) up--;
//         if (down < up) {
//             // Swap
//             double temp = x[down];
//             x[down] = x[up];
//             x[up] = temp;
//         }
//     }
    
//     // Colocar o pivô na posição correta
//     x[lb] = x[up];
//     x[up] = a;
//     *pj = up;
// }

// void QuickSort(long int x[], int n) {
//     Stack s;
//     initializeStack(&s);
    
//     BndType initial;
//     initial.lb = 0;
//     initial.ub = n - 1;
//     pushValuesQuickSort(&s, initial);
    
//     while (!isStackEmpty(&s)) {
//         BndType current = popValueStackQuickSort(&s);  // CORREÇÃO: Armazenar o valor retornado
        
//         if (current.lb < current.ub) {
//             int j;
//             Partition(x, current.lb, current.ub, &j);
            
//             // Empilhar os subarrays
//             BndType left, right;
            
//             left.lb = current.lb;
//             left.ub = j - 1;
            
//             right.lb = j + 1;
//             right.ub = current.ub;
            
//             // Empilhar o maior subarray primeiro
//             if (left.ub - left.lb > right.ub - right.lb) {
//                 pushValuesQuickSort(&s, right);
//                 pushValuesQuickSort(&s, left);
//             } else {
//                 pushValuesQuickSort(&s, left);
//                 pushValuesQuickSort(&s, right);
//             }
//         }
//     }
    
//     freeStack(&s);  // Liberar memória
// }

// #endif


#ifndef QUICKSORT_H_
#define QUICKSORT_H_
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

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

#endif