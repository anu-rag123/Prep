class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), prev, prev2, ans;
        prev = nums[0];
        for(int i = 1; i < n ; i++){
            int pick = nums[i];
            if(i > 1) {pick += prev2;}
            int not_pick = prev;
            ans = max(pick, not_pick);
            prev2 = prev;
            prev = ans;
        }
        return prev;
    }
};