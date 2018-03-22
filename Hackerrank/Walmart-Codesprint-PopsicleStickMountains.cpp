#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define MOD 1000000007LL
using namespace std;

ll resto(ll a){
    ll r = a%MOD;
    while(r < 0LL)
        r+= MOD;
   return r;
}
ll fastPow(ll a, ll b)
{
    ll res = 1LL;
    while (b > 0LL)
    {
        if (b & 1LL)
        {
            res *= a; res %= MOD;
        }
        a *= a; a %= MOD;
        b >>= 1;
    }
    return res;
}
 
/*
    Modular Multiplicative Inverse
    Using Euler's Theorem
*/
 
long long InverseEuler(ll n)
{
    return fastPow(n, MOD-2LL);
}
int main() {
    ll t;
    cin >> t;
    ll r[4010];
    r[0] = 0LL;
    for(ll n = 2LL; n < 4010LL; n+=2LL){
        
        ll resp = 1LL;
        for(ll i = 2LL; i <= n; i++)
            resp = resto(resp * i);
        for(ll i = 2LL; i <= (n/2); i++)
            resp = resto(resp*InverseEuler(i));
        for(ll i = 2LL; i <= (n/2); i++)
            resp = resto(resp*InverseEuler(i));
        
        ll resp1 = 1LL;
        for(ll i = 2LL; i <= n; i++)
            resp1 = resto(resp1 * i)%MOD;
        for(ll i = 2LL; i <= (n/2LL) + 1LL; i++)
            resp1 = resto(resp1*InverseEuler(i));
        for(ll i = 2LL; i <= (n/2LL) - 1LL; i++)
            resp1 = resto(resp1*InverseEuler(i));
        r[n] = resto(r[n-2LL] + resp - resp1);
        
    }
    while(t--){
        ll n;
        cin >> n;
        cout << r[n] << endl;
    }
    return 0;
}
