class Solution {
public:

    int fib(int n) {
        int prev2 = 0, prev = 1, ans;
        if(n == 0) {return 0;}
        for(int i = 2; i <= n; i++){
            ans = prev + prev2;
            prev2 = prev;
            prev = ans;
        }
        return prev;
    }
};