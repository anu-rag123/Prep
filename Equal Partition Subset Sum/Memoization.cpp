class Solution {
public:
    bool help(int n, int k, vector<int> &arr, vector<vector<int>> &dp){
        if(k == 0) {return true;}
        if(n == 0){
            return arr[0] == k;
        }
        if(dp[n][k] != -1) {return dp[n][k];}
        bool pick = false;
        if(k >= arr[n]) {pick = help(n - 1, k - arr[n], arr, dp);}
        bool not_pick = help(n - 1, k, arr, dp);
        return dp[n][k] = pick || not_pick;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i = 0; i < n; i++){
            s += nums[i];
        }
        if(s % 2){return false;}
        vector<vector<int>> dp(n, vector<int>(s/2 + 1, -1));
        return help(n - 1, s / 2, nums, dp);
    }
};