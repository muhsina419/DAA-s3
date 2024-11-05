#include <iostream>
using namespace std;

int CoinChange(int coins[], int no, int amount, int usedCoins[]) {
    const int INF = 10001;
    int dp[amount + 1];
    int lastCoin[amount + 1]; // To store the last coin used to make each amount

    // Initialize dp array with a large value (INF)
    for (int i = 0; i <= amount; ++i) {
        dp[i] = INF;
        lastCoin[i] = -1; // Initialize lastCoin array with -1
    }

    dp[0] = 0;

    for (int i = 0; i < no; ++i) {
        int coin = coins[i];
        for (int x = coin; x <= amount; ++x) {
            if (dp[x - coin] != INF && dp[x] > dp[x - coin] + 1) {
                dp[x] = dp[x - coin] + 1;
                lastCoin[x] = coin; // Store the coin used
            }
        }
    }

    // If it's not possible to make the amount, return -1
    if (dp[amount] == INF) {
        return -1;
    }

    // Backtrack to find the coins used and store them in usedCoins array
    int tempAmount = amount;
    int count = 0; // Counter to store the number of coins used

    while (tempAmount > 0) {
        int coin = lastCoin[tempAmount];
        usedCoins[count++] = coin; // Store the coin in usedCoins array
        tempAmount -= coin;
    }

    return dp[amount];
}

int main() {
    int num, coins[num];
    cout<<"Enter the number of coins : ";
    cin>>num;

    int amount;
    cout << "Enter amount you want to make: " << endl;
    cin >> amount;
	
	cout<<"Enter the coins :";
	for( int i=0;i<=num-1 ;i++){
		cin>>coins[i];
	}
	
    int usedCoins[amount]; // Array to store the coins used

    int result = CoinChange(coins, num, amount, usedCoins);

    if (result == -1) {
        cout << "It's not possible to make the amount with the given coins." << endl;
    } else {
        cout << "The minimum number of coins needed is " << result << "." << endl;
        cout << "Coins used: ";
        for (int i = 0; i < result; ++i) {
            cout << usedCoins[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

