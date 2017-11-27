//   Author : Misael Mateus 
//   Submission date: 2016-08-11 22:33:13
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string inverte(string s){
    string n = "";
    for(int i = s.size()-1; i >= 0; i--)
        n += s[i];
    return n;
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> c(n);
    for(ll i = 0; i < n; i++)
        cin >> c[i];
        
    vector<string> s(n);
    vector<string> inv(n);
    for(ll i = 0; i < n; i++){
        cin >> s[i];
        inv[i] = inverte(s[i]);
    }
    
    ll dp[n][2];
    dp[n-1][0] = 0LL;
    dp[n-1][1] = c[n-1];
    
    for(int i = n-2; i >= 0; i--){
        ll A = (1LL << 60), B = (1LL << 60);
        if(s[i] <= s[i+1])
            A = dp[i+1][0];
        if(s[i] <= inv[i+1])
            B = dp[i+1][1];
        dp[i][0] = min(A, B);
        if(dp[i][0] >= (1LL << 60)) dp[i][0] = (1LL << 60);
        
        A = (1LL << 60), B = (1LL << 60);
        
        if(inv[i] <= s[i+1])
            A = dp[i+1][0];
        if(inv[i] <= inv[i+1])
            B = dp[i+1][1];
        dp[i][1] = min(A, B) + c[i];
        if(dp[i][0] >= (1LL << 60)) dp[i][0] = (1LL << 60);
    }
    if(dp[0][0] >= (1LL << 60) && dp[0][1] >= (1LL << 60))
        cout << -1 << endl;
    else
        cout << min(dp[0][0], dp[0][1]) << endl;
        
    return 0;
}