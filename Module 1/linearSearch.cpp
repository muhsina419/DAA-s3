#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i; // Return the index of the target element
        }
    }
    return -1; // Return -1 if the target element is not found
}

int main() {
    int arr[] = {4, 2, 7, 1, 9, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int search;
    
    cout<<"Enter the element to search :";
    cin>>search;

    int result = linearSearch(arr, size, search);

    if(result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}

