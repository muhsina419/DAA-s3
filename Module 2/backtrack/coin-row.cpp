#include <iostream>
#include <algorithm>
using namespace std;

int CoinRow(int coins[], int n, int dp[]) {
    if (n == 0) return 0;
    if (n == 1) return coins[0];
    
    dp[0] = coins[0];
    dp[1] = max(coins[0], coins[1]);
    
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], coins[i] + dp[i - 2]);
    }
    
    return dp[n - 1];
}

void backtrackCoins(int coins[], int n, int dp[], int selectedCoins[], int &count) {
    int i = n - 1;
    count = 0;
    
    while (i >= 0) {
        if (i == 0 || dp[i] == coins[i] + (i >= 2 ? dp[i - 2] : 0)) {
            selectedCoins[count++] = coins[i];
            i -= 2; // Move to the non-adjacent element
        } else {
            i -= 1; // Skip the current coin
        }
    }
}

int main() {
    int no;
    cout << "Enter the number of coins you have: ";
    cin >> no;
    
    int coins[no];
    cout << "Enter the values of coins you have: ";
    for (int i = 0; i < no; i++) {
        cin >> coins[i];
    }
    
    int dp[no]; // DP array to store maximum values up to each index
    int maxSum = CoinRow(coins, no, dp);
    
    int selectedCoins[no]; // Array to store the selected coins for max sum
    int count = 0; // To keep track of the number of selected coins
    
    backtrackCoins(coins, no, dp, selectedCoins, count);
    
    cout << "The maximum sum that can be obtained is " << maxSum << "." << endl;
    cout << "Coins selected for maximum sum are: ";
    for (int i = 0; i < count; i++) {
        cout << selectedCoins[i] << " ";
    }
    cout << endl;
    
    return 0;
}

