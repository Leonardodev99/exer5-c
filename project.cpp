#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void merge(int arr[], int left, int middle, int right, long long int *inversions) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;


    int L[n1], R[n2];

    
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            
            *inversions += n1 - i;
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right, long long int *inversions) {
    if (left < right) {
        
        int middle = left + (right - left) / 2;

        
        mergeSort(arr, left, middle, inversions);
        mergeSort(arr, middle + 1, right, inversions);

        
        merge(arr, left, middle, right, inversions);
    }
}

int main(int argc, char *argv[]) {
	 int n;
	 int i;
	 int arr[n];

    printf("Informe o tamanho da matriz: ");
    scanf("%d", &n);

    
    printf("Informe os elementos da matriz:\n ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    long long int inversions = 0;


    mergeSort(arr, 0, n - 1, &inversions);

    printf("O array fornecido é: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("As inversões sao:");
    for ( i = 0; i < n; i++) {
        printf("(%d,%d) ", arr[i],arr[i+1]);
    }
    printf("\nAs inversões são: %lld\n", inversions);
	system("pause");
	
	return 0;
}

