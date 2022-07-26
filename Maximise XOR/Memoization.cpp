#include <bits/stdc++.h>

using namespace std;

int func(int n, vector<int> &arr, int c, vector<vector<int>> &dp){
    if(c == 0) {return 0;}
    if(n < 0){return 0;}
    if(dp[n][c] != - 1) {return dp[n][c];}
    int pick = arr[n] ^ func(n - 1, arr, c - 1, dp);
    int not_pick = func(n - 1, arr, c, dp);
    return dp[n][c] = max(pick, not_pick);
}
int main()
{
    int n, a;
    vector<int> arr;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a;
        arr.push_back(a);
    }
    int ans = INT_MIN;
    vector<vector<int>> dp(n, vector<int> (n/2 + 1, -1));
    for(int i = n/2; i>= 1; i--){
        ans = max(ans,func(n - 1, arr, i, dp));
    }
    cout<<ans;
    return 0;
}