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
    vector<int> dp(2, 0);
    dp[0] = grid[n - 1][0] % mod;
    dp[1] = grid[n - 1][1] % mod;
    for(int i = n - 2; i >= 0; i--){
        vector<int> temp(2, 0);
        for(int j = 0; j < 2; j++){
            if(grid[i + 1][0] > grid[i][j] && grid[i + 1][1] > grid[i][j]){
                temp[j] = max(grid[i][j] + dp[0], grid[i][j] + dp[1]) % mod;
            }
            else if(grid[i + 1][0] > grid[i][j]){
                temp[j] = (grid[i][j] + dp[0]) % mod;
            }
            else if(grid[i + 1][1] > grid[i][j]){
                temp[j] = (grid[i][j] + dp[1]) % mod;
            }
            else{
                temp[j] = grid[i][j] % mod;
            }
        }
        dp = temp;
    }
    cout<<max(dp[0], dp[1]);
    return 0;
}