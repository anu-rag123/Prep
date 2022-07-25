#include<bits/stdc++.h>
using namespace std;

int func(int n, vector<int> &dept, vector<int> &prev){
    int ans, fans = 0, s = 5, temp;
    unordered_map <int, int> myMap;
    for(int i = 0; i < n; i++){
        ans = 0;
        if(dept[i] == 1) {ans += 10;}
        else if(dept[i] == 2) {ans += 55;}
        else if(dept[i] == 3) {ans += 220;}
        else if(dept[i] == 4) {ans += 715;}
        else{
            int prevAns = 715;
            if(myMap.find(dept[i]) != myMap.end()){ans += myMap[dept[i]];}
            else{
                for(int j = s; j <= dept[i]; j++){
                    ans += prevAns;
                    for(int k = 0; k < 11; k++){
                        ans += prevAns - prev[k];
                        temp = prevAns;
                        prevAns = prevAns - prev[k];
                        prev[k] = temp;
                    }
                    myMap[j] = ans;
                    prevAns = ans;
                    ans = 0;
                }
                ans = prevAns;
                s = dept[i] + 1;
            }
        }
        fans += ans;
    }
    return fans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> dept(n);
    vector<int> prev = {220, 165, 120, 84, 56, 35, 20, 10, 4, 1, 0};
    for(int i = 0; i < n; i++){
        cin>>dept[i];
    }
    cout<<func(n, dept, prev);
    return 0;
}