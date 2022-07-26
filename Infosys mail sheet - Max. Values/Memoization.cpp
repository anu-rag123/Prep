#include<bits/stdc++.h>
using namespace std;

int func(int n, int m, int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    int mod = 1e9 + 7;
    if(i == n - 1){return dp[i][j] = grid[i][j] % mod;}
    if(dp[i][j] != -1) {return dp[i][j];}
    if(grid[i+1][0] > grid[i][j] && grid[i+1][1] > grid[i][j]){
        return dp[i][j] = max(grid[i][j] + func(n, m , i + 1, 0, grid, dp), grid[i][j] + func(n, m, i + 1, 1, grid, dp)) % mod;
    }
    if(grid[i+1][0] > grid[i][j]){
        return dp[i][j] = (grid[i][j] + func(n, m, i + 1, 0, grid, dp)) % mod;
    }
    if(grid[i+1][1] > grid[i][j]){
        return dp[i][j] = (grid[i][j] + func(n, m, i + 1, 1, grid, dp)) % mod;
    }
    else{
        return dp[i][j] = grid[i][j] % mod;
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int> (2, -1));
    int j0 = func(n, m, 0, 0, grid, dp);
    int j1 = func(n, m, 0, 1, grid, dp);
    cout<<max(j0, j1);
    return 0;
}