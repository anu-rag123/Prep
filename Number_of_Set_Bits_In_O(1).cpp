#include <bits/stdc++.h>

using namespace std;

int BitsSetTable256[256];
void initialize()
{
 
    // To initially generate the
    // table algorithmically
    BitsSetTable256[0] = 0;
    for (int i = 0; i < 256; i++)
    {
        BitsSetTable256[i] = (i & 1) +
        BitsSetTable256[i / 2];
    }
}
 
// Function to return the count
// of set bits in n
int countSetBits(int n)
{
    return (BitsSetTable256[n & 0xff] +
            BitsSetTable256[(n >> 8) & 0xff] +
            BitsSetTable256[(n >> 16) & 0xff] +
            BitsSetTable256[n >> 24]);
}
int main()
{
    int p, q, n;
    cin>>p>>q>>n;
    initialize();
    vector<int> set;
    set.push_back(1);
    int ans;
    for(int i = 1; i <= n; i++){
        ans = p * set[i - 1] + q;
        set.push_back(countSetBits(ans));
        if(set[i] == 1) {break;}
    }
    int m = set.size();
    cout<<set[n % m];
    return 0;
}
