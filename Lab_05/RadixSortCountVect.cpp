#include <iostream>
#include <vector>

using namespace std;

// Count_Sort Function: Sorts our 2D vector (matrix)
void Count_Sort(vector< vector<int> > &vect, int size, int k){

    // Create our empty 2D B vector (matrix)
    vector< vector<int> > B;

    // Insert 0's into our 2D vector (matrix)
    for (int i = 0; i < size; i++){
        // Initialize a temporary 1D vector
        vector<int> temp;
        for (int j = 0; j < 10; j++){
            // Input 0 into into our 1D vector
            temp.push_back(0);
        }
        // Input our 1D vector into our 2D vector (matrix)
        B.push_back(temp);
        
        // Clear 1D vector to reuse
        temp.clear();
    }

    // Initialize our C vector to have all 0's
    vector<int> C(size, 0);

    // C Vector will contain number of elements equal to i
    for (int i = 0; i < size; i++){
        C[vect[i][k]]++;
    }

    // C vector will contain number of elements less than or equal to i
    for (int i = 1; i <= 10; i++){
        C[i] = C[i] + C[i-1];
    }

    // We then fill our B vector and set our initial vector equal to it
    for (int i = size-1; i >= 0; i--){
        B[C[vect[i][k]]-1] = vect[i];
        C[vect[i][k]]--;
    }

    // Set our inital vector equal to our now sorted B
    for (int i = 0; i < size; ++i){
        vect[i] = B[i];
    }

}

// Radix_Sort Function: Calls on Count_Sort function and iterates through it
void Radix_Sort(vector< vector<int> > &vect, int size){

    // From 9 to 0...
    for (int k = 9; k >= 0; k--){
        // Use Count_Sort to sort our 2D vector (matrix)
        Count_Sort(vect, size, k);
    }
}

// Print_Array Function: Prints our 2D vector (matrix)
void Print_Vect(vector< vector<int> > vect, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < 10; j++){
            cout << vect[i][j] << ";";
        }    
        cout << endl;
    }
}

// Main Function: Runs our driver program
int main(){
    // Size of the 2D vector
    int size;
    
    // User enters size of the 2D vector (matrix)
    cin >> size;

    // Initialize our 2D vector (matrix)
    vector< vector<int> > vect;

    // Values for user to input into our 2D vector (matrix)
    int val;

    // Take in user input for our 2D vector (matrix)
    for (int i = 0; i < size; i++){
        // Initialize a temporary 1D vector
        vector<int> temp;
        for (int j = 0; j < 10; j++){
            // Input values into our 1D vector
            cin >> val;
            temp.push_back(val);
        }
        // Input our 1D vector into our 2D vector (matrix)
        vect.push_back(temp);

        // Clear 1D vector to reuse
        temp.clear();
    }

    // Use Radix_Sort to sort our 2D vector (matrix)
    Radix_Sort(vect, size);

    // Use Print_Vect to print our 2D vector (matrix)
    Print_Vect(vect, size);

    // End Program
    return 0;
}
