#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, mod = 1e9 + 7;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int> (2, 0));
    dp[n - 1][0] = grid[n - 1][0] % mod;
    dp[n - 1][1] = grid[n - 1][1] % mod;
    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j < 2; j++){
            if(grid[i + 1][0] > grid[i][j] && grid[i + 1][1] > grid[i][j]){
                dp[i][j] = max(grid[i][j] + dp[i + 1][0], grid[i][j] + dp[i + 1][1]) % mod;
            }
            else if(grid[i + 1][0] > grid[i][j]){
                dp[i][j] = (grid[i][j] + dp[i + 1][0]) % mod;
            }
            else if(grid[i + 1][1] > grid[i][j]){
                dp[i][j] = (grid[i][j] + dp[i + 1][1]) % mod;
            }
            else{
                dp[i][j] = grid[i][j] % mod;
            }
        }
    }
    cout<<max(dp[0][0], dp[0][1]);
    return 0;
}
