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
        vector<bool> dp(s / 2 + 1, false);
        if(k == nums[0]){dp[k] = true;}
        dp[0] = true;
        for(int i = 1; i < n; i++){
            for(int j = k; j >= 1; j--){
                bool pick = false;
                if(j >= nums[i]) {pick = dp[j - nums[i]];}
                bool not_pick = dp[j];
                dp[j] = pick || not_pick;
            }
        }
        return dp[k];
    }
};