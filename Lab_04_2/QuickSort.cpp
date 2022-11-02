#include <iostream>

using namespace std;

// Partition Function
int Partition(int arr[], int p, int r){
    int x = arr[r];
    int i = p-1;

    for (int j = p; j <= r - 1; j++){
        if (arr[j] <= x){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);

    return (i+1);
}

// Random Parition (aka random pivot) function
int rand_partition(int arr[], int p, int r){
    int k = p + rand() % (r - p);
    swap(arr[k], arr[r]);
    return Partition(arr, p, r);

}

// QuickSort Function
void QuickSort(int arr[], int p, int r){
    int q;
    if (p < r){
        q = rand_partition(arr,p,r);
        QuickSort(arr, p, q-1);
        QuickSort(arr, q+1, r);
    }
}


int main(){

    // Initialize our variables
  int size; // Size of our array

  // User enters size of the array
  cin >> size;

  // Intiialize an array pointer of unspecified size
  int *arr = new int [size];

  // If the size is less than or equal to zero, end the program
  if (size <= 0){
    return 0;
  }

  // User enters inputs of the array
  for (int i = 0; i < size; i++){
    cin >> arr[i];
  }

  // Call on HeapSort function to sort our array
  QuickSort(arr, 0, size-1);

  // Print out our array
  for (int i = 0; i < size; i++){
      cout << arr[i] << ";";
    }
    
    // End Program
    return 0;
}