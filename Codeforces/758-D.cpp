//   Author : Misael Mateus 
//   Submission date: 2017-01-19 21:10:37
#include<bits/stdc++.h>
#define ll unsigned long long
#define INF 10000000000000000000ULL
using namespace std;
ll dp[100];
int main(){
    ll n;
    string s;
    
    cin >> n;
    cin >> s;
    int t = s.size();
    vector<ll> v(t);
    for(int i = 0; i < t; i++){
        v[i] = (ll)(s[i] - '0');
    }
    
    dp[0] = v[0];
    
    for(int i = 1; i < t; i++){
        dp[i] = v[i] + dp[i-1]*n;
        if(dp[i] < 0ULL)
            dp[i] = INF;
        ll sum = v[i];
        ll ult = (ll)(10);
        for(int j = i-1; j >= 0; j--){
            sum += ult*v[j];
            ult *= (ll)(10);
            if(v[j] == 0)
                continue;
            
            ll oth = sum;
            if(oth >= n)
                break;
            
            if(j > 0){
                oth = oth + dp[j-1]*n;
            }
            if(oth >= 0 && oth < dp[i])
                dp[i] = oth;
            
            
        }
    }
    
    cout << dp[t-1] << endl;
}