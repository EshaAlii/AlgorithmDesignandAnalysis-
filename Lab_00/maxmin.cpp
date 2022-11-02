#include <iostream>

using namespace std;  

int main(){

  // Initialize Variables
  int size;
  int *arr = new int[size];
  int Max;
  int Min;

  // User enters the size of the array
  cout << "Enter array size: " << endl;
  cin >> size;

  // If entered size isn't good, Error message
  if (size <= 0){
      cout << "ERROR: You entered an incorrect value for the array size!" << endl;
  }

  // Else...
  else{

    // User enters numbers into array
    cout << "Enter numbers into the array: " << endl;
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    // We assume that the Max and Min are the first numbers in the array 
    Max = arr[0];
    Min = arr[0];

    // For loop to go through the array
    for (int i = 1; i < size; i++){
      // Check if each value is viable to be the new Max...
      if (arr[i] > Max){
        Max = arr[i];
      }
      // And do the same for our Min value...
      if (arr[i] < Min){
        Min = arr[i];
      }
    }
    
    // We then return our Max and Min numbers as formatted
    cout << Max << ";" << Min << endl;
  }

  // Free our Allocated Space
  delete [] arr;

  // End Program
  return 0;

}
