#include <iostream>

using namespace std;

// Intialize a global varaible called NegativeInfinity and set that equal to largest negative the computer can handle
int NegativeInfinity = -2147483648;

// Struct that holds two arrays
struct Arrays{

  // length array
  int *length;

  // revenue array
  int *revenue;
};

// Our struct Arrays function which serves in place for Extended Bottum Up Rod Cutting
struct Arrays func(int price[], int size){

  // Create a struct of Arrays called arrays
  struct Arrays arrays;

  // Initialize our extra variable
  int extra = size + 1;

  // Make the length of our length and revenue arrays equal to extra
  arrays.length = new int [extra];
  arrays.revenue = new int [extra];

  // Intiailize the first input of our revenue array to be 0
  arrays.revenue[0] = 0;

  // From 1 to our extra variable...
  for (int j = 1; j < extra; j++){

    // Intialize a variable q to be equal to NegativeInfinity
    int q = NegativeInfinity;

    // From 0 to our j variable...
    for (int i = 0; i < j; i++){

      // If the price + the revenue array is greater than q
      if (q < price[i] + arrays.revenue[j-i-1]){

        // We say that our new q is the price + the revenue array
        q = price[i] + arrays.revenue[j-i-1];

        // And we say that the length of the array is i+1
        arrays.length[j] = i + 1;
      }
    }

    // We then make the revenue of the array equal to whatever q is at the end
    arrays.revenue[j] = q;
  }

  // And we return both our revenue and length arrays
  return arrays;
}

void PrintCutRodSolution(int price[], int size){
  
   // Create a struct of Arrays called arrays
  struct Arrays arrays;

  // Initialize our extra variable
  int extra = size + 1;

  // Make our arrays equal to the outputs of Extended Bottom Up Rod Cutting
  arrays = func(price, size);

  // Initialize our NegativeOne variable
  int NegativeOne = -1;

  // Output maximum revenue
  cout << arrays.revenue[size] << endl;

  // While our size isn't 0...
  while (size > 0){
    // Output the length of optimal rod cutting
    cout << arrays.length[size] << " ";
    
    // Decrement our size in relation to our length array
    size = size - arrays.length[size];
  }

  // End second line with -1
  cout << NegativeOne << endl;
  
}

int main(){
  
  // Initialize our size
  int size;

  // Get user input for size
  cin >> size;

  // Intialize our price array of the size
  int *price = new int [size];

  // Get user input for list of market prices 
  for (int i = 0; i < size; i++){
    cin >> price[i];
  }

  // Print out the maximum revenue + length of each piece of optimal rod cutting
  PrintCutRodSolution(price, size);

  // End program
  return 0;
 
}