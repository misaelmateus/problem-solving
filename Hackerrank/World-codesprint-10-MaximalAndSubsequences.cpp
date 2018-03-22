#include <bits/stdc++.h>
#define ll long long
#define P 1000000007LL
using namespace std;
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
 
  if(x<0){
    x = x+P;
  }
 
  return x;
 
 
}
ll comb(ll n, ll k){
    if(k == 1)
        return n;
    return ((n*(comb(n-1, k-1)%P))%P*inv(k))%P;
}
ll resp;
vector < ll > solve(int n, int k, vector < ll > a, int bit){
    if(bit < 0 || a.size() == k){
        resp = comb((ll)a.size(), (ll)k);
        return a;
    }
    vector< ll > b;
    for(int i = 0; i < a.size(); i++)
        if(a[i] & (1L << bit))
            b.push_back(a[i] );
    if(b.size() >= k)
        return solve(n, k, b, bit-1);
    else return solve(n, k, a, bit-1);
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector < ll > result = solve(n, k, a, 62);
    ll ma = result[0];
    for (ssize_t i = 1; i < k; i++) {
        ma &= result[i];
    }
    cout << ma << endl << resp << endl;

    return 0;
}
