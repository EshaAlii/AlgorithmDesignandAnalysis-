#include <iostream>

using namespace std;

// Max_Heapify Function
void Max_Heapify(int arr[], int i, int size){

    // Left(i)
    int l = 2 * i + 1;

    // Right(i)
    int r = 2 * i + 2;

    // Initialize largest as our root
    int largest = i;

    // If left child is larger than the root...
    if (l < size && arr[l] > arr[i]){
        // We say our largest root is the left child
        largest = l;
    }

    // If right child is larger than the root...
    if (r < size && arr[r] > arr[largest]){
        // We say our largest root is the right child
        largest = r;
    }

    // If the largest isn't the root
    if (largest != i){
        // Swap our indeces with the largest and current index
        swap(arr[i],arr[largest]);

        // Recursively call our function on our subtree
        Max_Heapify(arr, largest, size);
    }

}

// Build_Max_Heap Function
void BuildMaxHeap(int arr[], int size){

    // Build our heap/rearrange our heap
    for (int i = (size/2) -1; i >= 0; i--){
        Max_Heapify(arr, i, size);
    }
}

// HeapSort Function
void HeapSort(int arr[], int size){

    // Call on BuildMaxHeap function
    BuildMaxHeap(arr, size);

    // Traverse our heap....
    for(int i = size-1; i > 0; i--){
        // Swap our current root to the end
        swap(arr[0],arr[i]);

        // Call Max_Heapify on our smaller heap
        Max_Heapify(arr,0,i);
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
  HeapSort(arr, size);

  // Print out our array
  for (int i = 0; i < size; i++){
      cout << arr[i] << ";";
    }
    
    // End Program
    return 0;
}