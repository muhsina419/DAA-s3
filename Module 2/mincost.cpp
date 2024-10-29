
#include<iostream>
#include <cstdlib> 
using namespace std;

int min(int a, int b, int c){
    if(a < b && a < c) return a;
    else if(b < c) return b;
    else return c;
}

int mincost(int cost[3][3], int m, int n, int memo[3][3]){
    if (m == 0 && n == 0){
        return cost[0][0];
    }
    if (memo[m][n] != -1){
        return memo[m][n];
    }
    if(m == 0){
        memo[m][n] = cost[0][n] + mincost(cost, 0, n-1, memo); 
    }
    else if(n == 0){
        memo[m][n] = cost[m][0] + mincost(cost, m-1, 0, memo);
    }
    else{
        memo[m][n] = cost[m][n] + min(mincost(cost, m-1, n, memo), mincost(cost, m, n-1, memo), mincost(cost, m-1, n-1, memo));
    }
    return memo[m][n];
}

int main(){
    int m = 3, n = 3;
    int cost[3][3];
    int memo[3][3];
    
    int N = 10; 
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cost[i][j] = rand() % N;
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            memo[i][j] = -1;
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    
    int result = mincost(cost, m-1, n-1, memo);
    cout << "The minimum cost is: " << result << endl;
}

