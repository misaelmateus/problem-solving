//   Author : Misael Mateus 
//   Submission date: 2016-08-03 23:52:04
#include<bits/stdc++.h>
#define ll long long
#define P 1000000007

using namespace std;
ll n, m, k;
ll escolhe[10011];
ll F(ll i){
    return 1LL + (((m - i - 1LL)/n));
}

ll mdc(ll  a, ll b, ll *x, ll *y) {
    ll xx, yy, d;
    if(b==0) {
        *x=1LL; *y=0LL;
        return a;
    }
    
    d = mdc(b, a%b, &xx, &yy);
    *x = yy;
    *y = xx - a/b*yy;
    return d;
}


ll inv(ll a){
    ll x,y,d;
    d = mdc(a,P,&x,&y);
    
    if(x<0)
      x = x+P;
    
    return x;


}

ll comb(ll a, ll b){
    if(escolhe[b] != 0)
        return escolhe[b];
    if(b < a - b)
        b = a - b;
    ll res = 1LL;
    for(ll i = a; i > b; i--)
        res = (res * i) % P;
    for(ll i = (a-b); i > 1; i--)
        res = (res * inv(i)) % P;
    
    return escolhe[b] = escolhe[a-b] = res;
}

ll eleva(ll a, ll b){
    
    ll res = 1LL;
    if(b == 1LL)
        return a;
    ll aux = eleva(a, b/2LL);
    if(b % 2LL == 1)
        res *= a;
    res = (( (aux * aux)%P )* res)%P;
    return res;
}

ll m2[10011][111];
ll f2(ll i, ll j){
    if(m2[i][j] != 0)
        return m2[i][j];
    ll res = eleva(comb(n, i), F(j));
    
    return m2[i][j] = res;
}
ll dp[111][10011];
ll solve(ll i, ll j){
    if(i == n)
        return (ll)(j == 0);
    if(dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = 0;
    for(ll x = 0; x <= min(j, n); x++){
        dp[i][j] = (dp[i][j] + solve(i+1, j-x) * f2(x, i) )%P;
    }
    return dp[i][j];
}
int main(){
    cin >> n >> m >> k;
    
    memset(dp, -1, sizeof(dp));
    dp[n][0] = 1LL;
        
    
    
    cout << solve(0, k) << endl;
}