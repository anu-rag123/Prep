#include<bits/stdc++.h>
using namespace std;

void lcs(int n, int m, int &k, int &l, string s, string t, vector<vector<int>> &dp)
{
    int ans = INT_MIN;
    // Shifting of indexes
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if(ans < dp[i][j]){
                    ans = dp[i][j];
                    k = ans;
                    l = i;
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
}
int main(){
    string s, t;
    int k = 0, l = 0;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    lcs(n, m, k, l, s, t, dp);
    string ans = "";
    if(k) {
        for(int i = l - k; i < l; i++){
            ans += s[i];
        }
    }
    cout<<ans;
    return 0;
}