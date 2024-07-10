#include<iostream>
using namespace std;

void insertionSort(int arr[] , int len){
	for(int i=1;i<len-1;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j-=1;
		}
		arr[j+1]=key;
		i+=1;
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
    
    insertionSort(a, n);
    
    cout << "Sorted array: ";
    for(int j = 0; j < n; j++) {
        cout << a[j] << " ";
    }
    cout << endl;
    
    delete[] a; // Free the dynamically allocated memory
    return 0;
}
