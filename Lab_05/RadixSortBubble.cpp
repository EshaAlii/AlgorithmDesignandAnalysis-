#include <iostream>
#include <vector>

using namespace std;

// Bubble_Sort Function
void Bubble_Sort(vector< vector<int> > &vect, int size, int k){
    // Double for loop to traverse through our matrix/2D Vectors
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1; j++){
            // If second column is less than our first
            if ( vect[j][k] > vect[j+1][k]){
                // We swap thier places 
                vect[j].swap(vect[j+1]);
            }
        }
    }
}

// Radix_Sort Function
void Radix_Sort(vector< vector<int> > &vect, int size){
    // We iterate down to 0 for columns...
    for(int k = 9; k >= 0; k--){
        // And utilize Bubble Sort...
        Bubble_Sort(vect, size, k);
    }
}

// Print_Array prints out our 2D Vector
void Print_Vect(vector< vector<int> > vect, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < 10; j++){
            cout << vect[i][j] << ";";
        }    
        cout << endl;
    }
}

// Main Function
int main(){
    // Initialize our variables
    int size; // Size of our 2D vector
    
    // User enters size of the 2D vector (for Columns)
    cin >> size;

    // Initialize our 2D vector
    vector< vector<int> > vect;

    // The value the user will input
    int val;

    // Take in user input for our 2D vector
    for (int i = 0; i < size; i++){
        vector<int> temp;
        for (int j = 0; j < 10; j++){
            cin >> val;
            temp.push_back(val);
        }
        vect.push_back(temp);
        temp.clear();
    }

    // Sort our 2D vector
    Radix_Sort(vect, size);
    Print_Vect(vect, size);

    // End Program
    return 0;
}