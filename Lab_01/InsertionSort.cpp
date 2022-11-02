#include<iostream>

using namespace std;

int main(){
    // Initialize our variables
    int size; // size of the array
    int *arr = new int[size]; // array pointer of unspecified size

    // We ask the user for the size
    cin >> size;


    // User enters numbers into the array
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    // We then use Insertion Sort to order our array
    for (int i = 1; i < size; i++){
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j-1] > key){
            arr[j] = arr[j-1];
            j = j-1;
        }
        arr[j] = key;

        // We then return our Insertion Sort for each iteration
        for(int k = 0; k < i+1; k++){
            cout << arr[k] << ";";
        }
        
        // We also create a new line for each iteration
        cout << endl;
    }
    
    // End program
    return 0;
}