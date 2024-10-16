#include<iostream>
using namespace std;

#define N 100

int collectMaxCoins(int coins[N][N], int n, int m){
	int dp[N][N]={0};
	
	dp[0][0]=coins[0][0];
	
	for(int j = 1; j<m;j++){
		dp[0][j]=dp[0][j-1]+coins[0][j];
	}
	
	for(int i =1; i<n;i++){
		dp[i][0]=dp[i-1][0]+coins[i][0];
	}
	
	for (int i =1; i<n;++i){
		for (int j =1;j<m;++j){
			dp[i][j] = coins[i][j]+max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n-1][m-1];
}

int main(){
	int coins[N][N]={
		{0,1,1,0},
		{1,0,1,1},
		{0,0,0,1},
		{1,1,0,0}
	};
	int n =4;
	int m =4;
	int maxCoins = collectMaxCoins(coins,n,m);
	cout<<"Maximum coins collected: "<<maxCoins<<endl;
}











