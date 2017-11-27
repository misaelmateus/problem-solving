//   Author : Misael Mateus 
//   Submission date: 2016-11-15 22:23:25
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll Min(ll a, ll b){ if(a < b) return a; return b;}
ll Max(ll a, ll b){ if(a > b) return a; return b;}
int main(){
     ios::sync_with_stdio( false );
    ll n, m, k, x, s;
    cin >> n >> m >> k >> x >> s;
    vector<ll> a(m), b(m), c(k), d(k);
    
    for(ll i = 0; i < m; i++)  cin >> a[i];
    for(ll i = 0; i < m; i++)  cin >> b[i];
    for(ll i = 0; i < k; i++)  cin >> c[i];
    for(ll i = 0; i < k; i++)  cin >> d[i];
    
    ll custo = x*n;
    
    for(ll i = 0LL; i < m; i++){
        ll x1 = a[i], s1 = s - b[i];
        if(s1 < 0LL) continue;
        
        vector<ll>:: iterator up = upper_bound(d.begin(), d.end(), s1);
        if(up == d.begin())
            custo = Min(custo, x1*n);
        else{
            up--;
            ll i1 = (ll)( up - d.begin() );
            custo = Min(custo, x1*(Max(0LL, n - c[i1]) ));
        }
    }
    
    for(ll i = 0LL; i < k; i++){
        if(d[i] > s)
            break;
        custo = Min(custo, x*Max(0LL, n - c[i]));
    }
    
    cout << custo << endl;
}