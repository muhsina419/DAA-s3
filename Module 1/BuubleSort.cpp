#include<iostream>
using namespace std;

 void bubbleSort(int arr[] , int len){
 	for(int i=0; i<=len-1;i++){
 		for(int j=0;j<len-1;j++){
 			if(arr[j]>arr[j+1]){
 				int t= arr[j];
 				arr[j]=arr[j+1];
 				arr[j+1]=t;
			 }
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
    
    bubbleSort(a, n);
    
    cout << "Sorted array: ";
    for(int j = 0; j < n; j++) {
        cout << a[j] << " ";
    }
    cout << endl;
    
    delete[] a; // Free the dynamically allocated memory
    return 0;
}
