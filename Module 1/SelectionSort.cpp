#include<iostream>
using namespace std;

void selectionSort(int arr[], int len) {
    for(int i = 0; i < len - 1; i++) {
        int min = i;
        for(int j = i + 1; j < len; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        if(min != i) {
            int t = arr[min];
            arr[min] = arr[i];
            arr[i] = t;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int *a = new int[n]; // Dynamically allocate memory for the array
    cout << "Enter the elements of the array:" << endl;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    selectionSort(a, n);
    
    cout << "Sorted array: ";
    for(int j = 0; j < n; j++) {
        cout << a[j] << " ";
    }
    cout << endl;
    
    delete[] a; // Free the dynamically allocated memory
    return 0;
}

