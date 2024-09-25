#include<iostream>
using namespace std;

int CoinRow(int coins[] , int n) {
	if (n == 0) return 0;
	if (n == 1 ) return coins[0];
	if (n == 2 ) return max(coins[0] , coins[1]);
	
	int dp[n];
	
	dp[0]=coins[0];
	dp[1]= max(coins[0] , coins[1]);
	
	for(int i =2 ; i < n ; ++i){
		dp[i]=max(dp[i-1] ,coins[i]+dp[i-2]);
	}
	
	return dp[n-1];
	
}

int main(){
	int no;
	cout<<"Enter the number of coins you have : ";
	cin>>no;
	
	int coin[no];
	cout<<"Enter the values of coins you have : ";
	for (int i=0; i<no; i++){
		cin>>coin[i];
	}
	
	int result = CoinRow (coin , no);
	cout<<"The maximum can be obtained using this is "<<result<<"."<<endl;
	
	return 0;
}
	
