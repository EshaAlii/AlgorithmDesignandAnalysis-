#include <iostream>

using namespace std;

// Count_Sort Function: Sorts our 2D array (matrix)
void Count_Sort(int** arr, int size, int k){

    int** B = new int *[size];

    // Values for user to input into our 2D array (matrix)
    for (int i = 0; i < size; i++){
        B[i] = new int[10];
        for (int j = 0; j < 10; j++){
            B[i][j] = 0;
        }
    }


    // Initialize our C vector to have all 0's
    int* C = new int [size];
    for (int i = 0; i < size; i++){
        C[i] = 0;
    }

    // C Vector will contain number of elements equal to i
    for (int i = 0; i < size; i++){
        C[arr[i][k]]++;
    }

    // C vector will contain number of elements less than or equal to i
    for (int i = 1; i <= 10; i++){
        C[i] = C[i] + C[i-1];
    }

    // We then fill our B vector and set our initial vector equal to it
    for (int i = size-1; i >= 0; i--){
        B[C[arr[i][k]]-1] = arr[i];
        C[arr[i][k]]--;
    }

    // Set our inital vector equal to our now sorted B
    for (int i = 0; i < size; ++i){
        arr[i] = B[i];
    }

}

// Radix_Sort Function: Calls on Count_Sort function and iterates through it
void Radix_Sort(int** arr, int size){

    // From 9 to 0...
    for (int k = 9; k >= 0; k--){
        // Use Count_Sort to sort our 2D array (matrix)
        Count_Sort(arr, size, k);
    }
}

// Print_Array Function: Prints our 2D array (matrix)
void Print_Vect(int** arr, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < 10; j++){
            cout << arr[i][j] << ";";
        }
        cout << endl;
    }
}

// Main Function: Runs our driver program
int main(int arcg, char** argv){
    // Size of the 2D array
    int size;
    
    // User enters size of the 2D array (matrix)
    cin >> size;

    // Initialize our 2D array (matrix)
    int** arr = new int *[size];

    // Values for user to input into our 2D array (matrix)
    for (int i = 0; i < size; i++){
        arr[i] = new int[10];
        for (int j = 0; j < 10; j++){
            cin >> arr[i][j];
        }
    }


    // Use Radix_Sort to sort our 2D array (matrix)
    Radix_Sort(arr, size);

    // Use Print_Vect to print our 2D array (matrix)
    Print_Vect(arr, size);

    // End Program
    return 0;
}
