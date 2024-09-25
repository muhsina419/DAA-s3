#include<iostream>
using namespace std;

int CoinChange(int coins[] , int no , int amount){
	const int INF = 10001;
	int dp[amount+1];
	
	for(int i = 0 ; i <= amount ; ++i ){
		dp[i] = INF;
	}
	
	dp[0] =0;
	
	for (int i = 0; i < no; ++i) {
        int coin = coins[i];
        for (int x = coin; x <= amount; ++x) {
            if (dp[x - coin] != INF) {
                dp[x] = (dp[x] < dp[x - coin] + 1) ? dp[x] : (dp[x - coin] + 1);
            }
        }
    }
        return dp[amount] == INF ? -1 : dp[amount];
}
			
int main() {
	int coins[] = {1, 2, 5}; 
	int numCoins = sizeof(coins) / sizeof(coins[0]);
	    
	int amount;
	cout<<"Enter amount you want to make: \n"<<endl;
	cin>>amount; 
	    
	int result = CoinChange(coins, numCoins, amount);
	    
	if (result == -1) {
		cout << "It's not possible to make the amount with the given coins." << endl;
	} else {
		cout << "The minimum number of coins needed is " << result << "." << endl;
	}
	    
	return 0;
}	
		
	
		
	 
