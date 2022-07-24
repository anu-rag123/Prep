#include<bits/stdc++.h>
using namespace std;

int greedy(int n, int e, vector<int> &p, vector<int> &b){
    int maxi = 0;
    vector<pair<int,int>> myPair;
    for(int i = 0; i < n; i++){
        myPair.push_back(make_pair(p[i], b[i]));
    }
    sort(myPair.begin(), myPair.end());
    for(int i = 0; i < n; i++){
        if(e >= myPair[i].first){maxi++; e += myPair[i].second;}
        else {break;}
    }
    return maxi;
}

int main(){
    
    int n, e, a;
    vector<int> poweri, bonusi;
    cin >> n >> e;
    for(int i = 0; i < n; i++){cin >> a; poweri.push_back(a);}
    for(int i = 0; i < n; i++){cin >> a; bonusi.push_back(a);}
    
    cout << greedy(n , e, poweri, bonusi);
    return 0;
}