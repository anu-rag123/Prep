class Solution {
public:
    int help(int n, vector<int> &arr, vector<int> &dp){
        if(n < 0){
            return 0;
        }
        if(dp[n] != -1){return dp[n];}
        int pick = arr[n] + help(n - 2, arr, dp);
        int not_pick = help(n - 1, arr, dp);
        return dp[n] = max(pick, not_pick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, - 1);
        return help(n - 1, nums, dp);
    }
};