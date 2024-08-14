#include<iostream>
using namespace std;

int fibonacci(int n){
	int a=0;
	int b=1;
	int c=0;
	if( n == 0 ){
		return a;
	}
	for(int i=2; i<=n; i++){
		c=a+b;
		a=b;
		b=c;
	}
	return b;
}

int main(){
	int t,result;
	cout<<"enter the n'th term : ";
	cin>>t;
        cout<<t<<" th fibonacci number is "<<fibonacci(t)<<endl;
	
	return 0;
}	
		
