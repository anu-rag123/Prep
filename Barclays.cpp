#include<bits/stdc++.h>
using namespace std;
int func(int n, int x, vector<int> &arr, vector<int> &dp){
    if(n == 0){
        if(arr[n] * 1.0 / x < 0){
            int change = ceil(arr[n] * 1.0/ x) * x;
            return min(change, arr[n]);
        }
        else{
            int change = floor(arr[n] * 1.0/ x) * x;
            return dp[0] =  min(change, arr[n]);
        }
    }
    if(dp[n] != -1) {return dp[n];}
    int pick;
    if(arr[n]* 1.0 / x < 0){
        pick = ceil(arr[n]* 1.0 / x) * x + func(n - 1, x, arr, dp); 
    }
    else if(arr[n]* 1.0 / x >= 0){
        pick = floor(arr[n]* 1.0 / x) * x + func(n - 1, x, arr, dp);
    }
    int not_pick = arr[n] + func(n - 1, x, arr, dp);
    return dp[n] = min(pick, not_pick);
}
int main() {
	int n, x;
	cin>>n>>x;
	vector<int> arr(n);
	vector<int> dp(n, -1);
	for(int i = 0; i < n; i++){
	    cin>>arr[i];
	}
	
	cout<<func(n - 1, x, arr, dp);
	
}