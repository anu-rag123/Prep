class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0], ans, fans = nums[0];
        for(int i = 1; i < n; i++){
            ans = max(nums[i], nums[i] + prev);
            prev = ans;
            fans = max(fans, ans);
            
        }
        return fans;
    }
};