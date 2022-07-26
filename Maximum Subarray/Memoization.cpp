class Solution {
public:
    int help(int n, vector<int> &arr, vector<int> &dp){
        if(n == 0) {return dp[0] = arr[0];}
        if(dp[n] != -1) {return dp[n];}
        return dp[n] = max(arr[n], arr[n] + help(n - 1, arr, dp));
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        help(n - 1,nums, dp);
        return *max_element(dp.begin(), dp.end());
    }
};