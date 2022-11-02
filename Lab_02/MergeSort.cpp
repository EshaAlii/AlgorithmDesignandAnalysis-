#include <iostream>

using namespace std;

// Merge Function
void Merge(int arr[], int p, int q, int r){

  // We create the sizes of our temp arrays
  int leftsize = q - p + 1;
  int rightsize = r - q;

  // We then create our temporary arrays
  int *leftarr = new int [leftsize];
  int *rightarr = new int [rightsize];

  // Copy the left side of the array into our temp array
  for (int i = 0; i < leftsize; i++){
    leftarr[i] = arr[p + i];
  }

  // Copy the right side of the array into our temp array
  for (int j = 0; j < rightsize; j++){
    rightarr[j] = arr[q + j + 1];
  }

  // We use this to maintain our indexes of our temp and main arrays
  int i = 0;
  int j = 0;
  int k = p;

  // While the left and right size are not reached...
  while (i < leftsize && j < rightsize){
    // If the leftarray indeces is less than or equal to the right array indences...
    if (leftarr[i] <= rightarr[j]){
      // We place the leftsubarray into our original array and increment...
      arr[k] = leftarr[i];
      i++;
    } 
    else{
      // Otherwise we place the rightsubarray into our original array and increment...
      arr[k] = rightarr[j];
      j++;
    }
    k++;
  }

  // Once we run out of elements in the left or right subarrays...

  // We will run the following to account for any remaining elements
  while (i < leftsize){
    arr[k] = leftarr[i];
    i++;
    k++;
  }
  
  while (j < rightsize){
    arr[k] = rightarr[j];
    j++;
    k++;
  }

}

// Merge Sort Function
void MergeSort(int arr[], int p, int r){
  if (p < r){
    int q = (p+(r-p)/2);
    MergeSort(arr, p, q);
    MergeSort(arr, q+1, r);
    Merge(arr, p, q, r);
  }

}

// Main Function
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

  // Call on MergeSort function to sort our array
  MergeSort(arr, 0, size - 1);

  // Print out our array
  for (int i = 0; i < size; i++){
    cout << arr[i] << ";";
  }
  
  // End Program
  return 0;

}