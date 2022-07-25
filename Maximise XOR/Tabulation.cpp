#include <bits/stdc++.h>

using namespace std;

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
    vector<vector<int>> dp(n, vector<int> (n/2 + 1, 0));
    for(int i = 1; i <= n/2; i++) {dp[0][i] = arr[0];}
    for(int i = 0; i < n; i++) {dp[i][0] = 0;}
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= n / 2; j++){
            int pick = arr[i] ^ dp[i - 1][j - 1];
            int not_pick = dp[i - 1][j - 1];
            dp[i][j] = max(pick, not_pick);
        }
    }
    for(int i = 0; i <= n / 2; i++){
        ans = max(ans, dp[n - 1][i]);
    }
    cout<<ans;
    return 0;
}
