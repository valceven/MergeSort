#include <iostream>
#include <cstdlib>

using namespace std;

void mergeSort(int *array,int p,int q);
void merge(int *array,int p,int q, int r);

int main(){

    int size;

    cout << "Enter size of array: ";
    cin >> size;

    int* array = (int*) malloc(size * (sizeof(int)));

    for(int i = 0; i < size; i++){
        array[i] = (rand() % 20 + 1);
    }

    cout << "\nHere is the unsorted array: " << endl << endl;

    for(int i = 0; i < size; i++){
        if(i > 0 && i % 5 == 0){
            cout << endl;
        }
        cout << "[ " << array[i] <<  " ] ";
    }

    int choice = 0;

    cout << "\n\nPlease enter 1 to sort: ";
    cin >> choice;

    if(choice == 1){
        mergeSort(array,0,size-1);
        cout << "Sorted Array: " << endl;
        for(int i = 0; i < size; i++){
        if(i > 0 && i % 5 == 0){
            cout << endl;
        }
        cout << "[ " << array[i] <<  " ] ";
    }
    }
    
    cout << "\nBYE!" << endl;

    free(array);

    return 0;
}

void mergeSort(int *array, int l,int r){
    
    if(l < r){

        int m = l + (r - l) / 2;

        mergeSort(array,l,m);
        mergeSort(array,m + 1,r);
        merge(array,l,m,r);

    }
}

void merge(int* array,int l, int m, int r){

  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = array[l + i];
  for (int j = 0; j < n2; j++)
    M[j] = array[m + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = l;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    array[k] = M[j];
    j++;
    k++;
  }
}
