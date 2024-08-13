#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == key) {
            return mid; // Key found
        } else if (arr[mid] < key) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    
    return -1; // Key not found
}

int main() {
    int n, search;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int *a = new int[n]; // Dynamically allocate memory for the array
    cout << "Enter the elements of the array in sorted manner:" << endl;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << "Enter the element to search: ";
    cin >> search;

    int result = binarySearch(a, n, search);
    
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }
    
    delete[] a; // Free the dynamically allocated memory
    return 0;
}

