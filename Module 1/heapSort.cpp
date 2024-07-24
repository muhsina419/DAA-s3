#include<iostream>
using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void heapify (int arr[] , int len , int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left < len && arr[left] > arr[largest]){
        largest = left ;
    }

    if(right < len && arr[right] > arr[largest]){
        largest = right ;
    }

    if(largest != i ){
        swap(arr[i],arr[largest]);

    	heapify(arr, len ,largest);

    }
}

void heapSort(int arr[] ,int len){
    int startIndex= (len / 2) - 1;

    for(int i = startIndex ; i>=0 ; i--){
        heapify(arr,len,i);
    }
    
    for(int i = len -1 ; i > 0; i--){
    	swap(arr[0],arr[i]);
    	
    	heapify(arr,i,0);
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
    
    heapSort(a, n);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n ; i++) {
        cout << a[i ] << " ";
    }
    cout << endl;
    
    delete[] a; // Free the dynamically allocated memory
    return 0;
}

