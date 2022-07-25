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
    vector<int> dp(n / 2 + 1, 0);
    for(int i = 1; i <= n/2; i++) {dp[i] = arr[0];}
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        vector<int> temp(n / 2 + 1, 0);
        for(int j = 1; j <= n / 2; j++){
            int pick = arr[i] ^ dp[j - 1];
            int not_pick = dp[j - 1];
            temp[j] = max(pick, not_pick);
        }
        dp = temp;
    }
    for(int i = 0; i <= n / 2; i++){
        ans = max(ans, dp[i]);
    }
    cout<<ans;
    return 0;
}
