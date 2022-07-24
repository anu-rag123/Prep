#include<bits/stdc++.h>
using namespace std;

int optimised(int n, int e, vector<int> &p, vector<int> &b){
    map<int, int> myMap;
    int maxi = 0;
    for(int i = 0; i < n; i++){
        myMap[p[i]] = b[i];
    }
    for(auto i : myMap){
        if(e >= i.first) {
            maxi++;
            e += i.second;
        }
        else{
            break;
        }
    }
    return maxi;
}

int main(){
    
    int n, e, a;
    vector<int> poweri, bonusi;
    cin >> n >> e;
    for(int i = 0; i < n; i++){cin >> a; poweri.push_back(a);}
    for(int i = 0; i < n; i++){cin >> a; bonusi.push_back(a);}
    cout << optimised(n , e, poweri, bonusi);
    return 0;
}