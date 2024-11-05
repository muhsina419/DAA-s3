#include <iostream>
using namespace std;

#define N 100

int collectMaxCoins(int coins[N][N], int n, int m, int dp[N][N]) {
    dp[0][0] = coins[0][0];

    // Initialize the first row
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + coins[0][j];
    }

    // Initialize the first column
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + coins[i][0];
    }

    // Fill the dp table
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = coins[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n - 1][m - 1];
}

void printPath(int dp[N][N], int coins[N][N], int n, int m) {
    int i = n - 1, j = m - 1;
    cout << "Path to collect maximum coins: " << endl;

    while (i > 0 || j > 0) {
        cout << "(" << i << ", " << j << ") ";
        if (i == 0) {
            j--;
        } else if (j == 0) {
            i--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << "(0, 0)" << endl; // Starting point
}

int main() {
    int coins[N][N] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 0, 0}
    };
    int n = 4;
    int m = 4;
    int dp[N][N] = {0};

    int maxCoins = collectMaxCoins(coins, n, m, dp);
    cout << "Maximum coins collected: " << maxCoins << endl;

    printPath(dp, coins, n, m);
    
    return 0;
}

