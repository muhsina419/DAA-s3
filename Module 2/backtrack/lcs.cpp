#include <iostream>
#include <string>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

string LCS(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    int DP[m + 1][n + 1];

    // Fill the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                DP[i][j] = 1 + DP[i - 1][j - 1];
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }

    // Backtrack to find the LCS sequence
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else if (DP[i - 1][j] > DP[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "Length of Longest Common Subsequence: " << DP[m][n] << endl;
    return lcs;
}

int main() {
    string S, SS;
    cout << "Enter the first string: ";
    cin >> S;
    cout << "Enter the second string: ";
    cin >> SS;

    string result = LCS(S, SS);
    cout << "Longest Common Subsequence: " << result << endl;

    return 0;
}

