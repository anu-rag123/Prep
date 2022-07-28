#include<bits/stdc++.h>
using namespace std;

void lcs(int n, int m, string s, string t, vector<vector<int>> &dp)
{
	// Shifting of indexes
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}
int main(){
    string s, t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    lcs(n, m, s, t, dp);
    int i = n, j = m, k = dp[n][m] - 1;
    string ans = "";
    for(int i = 1; i <= dp[n][m]; i++) {ans += "$";}
    while(i > 0 && j > 0){
        if(s[i - 1] == t[j - 1]) {
            ans[k] = s[i - 1];
            k--;
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else if(dp[i - 1][j] < dp[i][j - 1]){
            j--;
        }
    }
    cout<<ans;
    return 0;
}