class Solution {
public:
    bool help(int n, vector<int> &arr, vector<int> &dp){
        if(n == arr.size() - 1) {return true;}
        if(dp[n] != -1) {return dp[n];}
        for(int i = arr[n]; i >= 1; i--){
            if(n + i < arr.size()){
                if(help(n + i, arr, dp)){
                    return dp[n] = true;
                }
            }
        }
        return dp[n] = false;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return help(0, nums, dp);
    }
};