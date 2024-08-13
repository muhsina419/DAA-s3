#include<iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int a1 = mid - left + 1;
    int a2 = right - mid;

    int L[a1], R[a2];

    for(int i = 0; i < a1; i++) {
        L[i] = arr[left + i];
    }
    for(int j = 0; j < a2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i < a1 && j < a2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];  // Use '=' instead of '=='
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < a1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < a2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    mergeSort(a, 0, n - 1); // Corrected this to sort the entire array

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a; // Free the dynamically allocated memory
    return 0;
}

