#include <iostream>

using namespace std;

// Find Maximum Crossing Subarray Function
int Max_Cross(int arr[], int low, int mid, int high){

    // Create our counter variables
    int max_left;
    int max_right;

    // Initialize all of our sums to 0
    int left_sum = 0;
    int right_sum = 0;
    int sum = 0;

    // Find our left sum (if there is one)
    for (int i = mid; i >= low; i--){
        sum = sum + arr[i];
        
        if (sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    // Reset sum to 0
    sum = 0;

    // Find our right sum (if there is one)
    for (int j = mid + 1; j <= high; j++){
        sum = sum + arr[j];
        
        if (sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }

    // Return our left and right sum added together
    return ((left_sum + right_sum));

}

// Find Maximum Subarray Function
int Max_Sub(int arr[], int low, int high){

    // If array only has one element
    if (high == low){
        // We return the array as is
        return (arr[low]);
    }

    // Otherwise
    else{

        // Initialize our midpoint variable
       int mid = (low+high)/2;

        // We set our sub arrays as shown
        int left_low, left_high, left_sum = Max_Sub (arr, low, mid);
        int right_low, right_high, right_sum = Max_Sub (arr, mid + 1, high);
        int cross_low, cross_high, cross_sum = Max_Cross (arr, low, mid, high);

        // If the following conditions are met, we return our left subarray
       if (left_sum >= right_sum && left_sum >= cross_sum){
           return (left_sum);
       }

        // Otherwise we check for these conditions and return our right subarray
       else if (right_sum >= left_sum && right_sum >= cross_sum){
           return (right_sum);
       }

        // Otherwise, we return our cross subarray
       else{
           return (cross_sum);
       }
    }
}

// Main Function
int main(){
    // Initialize the size of our array
    int size;
    
    // User enters size of the array
    cin >> size;
    
    // Intiialize an array pointer of our now specified size
    int *arr = new int [size];
    
    // If the size is less than or equal to zero, end the program
    if (size <= 0){
        return 0;
    }

    // User enters inputs of the array
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    // Call on our Maximum Sub Function
    int max_sum = Max_Sub(arr, 0, size-1);

    // Print out our array to recieve our Maximum 
    cout << max_sum;
    
    // End program
    return 0;
}