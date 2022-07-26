class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0, k;
        for(int i = 0; i < n; i++){
            s += nums[i];
        }
        k = s / 2;
        if(s % 2){return false;}
        vector<vector<bool>> dp(n, vector<bool>(s/2 + 1, false));
        if(k == nums[0]){dp[0][k] = true;}
        for(int i = 0; i < n; i++) {dp[i][0] = true;}
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= k; j++){
                bool pick = false;
                if(j >= nums[i]) {pick = dp[i - 1][j - nums[i]];}
                bool not_pick = dp[i - 1][j];
                dp[i][j] = pick || not_pick;
            }
        }
        return dp[n - 1][k];
    }
};