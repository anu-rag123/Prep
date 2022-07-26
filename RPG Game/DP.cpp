#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.first >= b.first;
}

//DP Solution
int dynamic(int n, int e, vector<pair<int,int>> p, vector<vector<int>> &dp){
    if(n == 0){
        if(e >= p[0].first) {return 1;}
        else {return 0;}
    }
    if(dp[n][e] != - 1) {return dp[n][e];}
    int pick = 0;
    if(e >= p[n].first) {
        pick = 1 + dynamic(n - 1, e + p[n].second, p, dp);
    }
    int not_pick = dynamic(n - 1, e, p, dp);
    return  dp[n][e] = max(pick, not_pick);
}

int main(){
    int n, e, a;
    vector<int> poweri, bonusi;
    cin >> n >> e;
    for(int i = 0; i < n; i++){cin >> a; poweri.push_back(a);}
    for(int i = 0; i < n; i++){cin >> a; bonusi.push_back(a);}
    vector<pair<int,int>> myPair;
    for(int i = 0; i < n; i++){
        myPair.push_back(make_pair(poweri[i], bonusi[i]));
    }
    sort(myPair.begin(), myPair.end(), compare);

    //Declare a dp vector of size (n * maximum_experience_points)
    vector<vector<int>> dp(n, vector<int>(500, -1));

    cout << dynamic(n - 1, e, myPair, dp);
    return 0;
}