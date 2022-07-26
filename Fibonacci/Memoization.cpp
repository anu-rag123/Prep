class Solution {
public:
    int help(int n, vector<int> &dp){
        if(n == 0 || n == 1) {return n;}
        if(dp[n] != -1) {return dp[n];}
        return dp[n] = help(n - 1, dp) + help(n - 2, dp);
    }
    int fib(int n) {
        vector<int> dp(n  + 1, -1);
        return help(n, dp);
    }
};