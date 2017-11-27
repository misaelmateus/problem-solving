//   Author : Misael Mateus 
//   Submission date: 2017-10-06 19:21:03
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 5100
#define MOD 998244353LL
#define readFast ios::sync_with_stdio(false)
using namespace std;
/* This function calculates (a^b) % MOD */
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

ll comb[MAXN][MAXN];
ll fat[MAXN];
ll inv[MAXN];
ll calc(ll n, ll m){
	ll ans = 0LL;
	for(ll a = 0; a <= n && a <= m; a++){
		ll ans1 = (((comb[n][a] * comb[m][a] ) % MOD) * fat[a])%MOD;
		ans = (ans + ans1) % MOD;
	}
	return ans;
}


int main(){
	ll a, b, c;
	cin >> a >> b >> c;
	for(int i = 0; i < MAXN; i++)
		comb[i][0] = 1LL;
	for(int i = 0; i < MAXN; i++)
	    inv[i] = InverseEuler(i);
	for(ll i = 1; i < MAXN; i++){
		for(ll j = 1; j <= i; j++){
			comb[i][j] = (((i * comb[i-1][j-1]) % MOD) * inv[j]) % MOD;
		}
	}
	fat[0] = 1LL;

	for(ll i = 1; i < MAXN; i++)
		fat[i] = (fat[i-1]*i)%MOD;

	ll ans = (((calc(a, b) * calc(a, c)) % MOD) * calc(b, c)) % MOD;
	cout << ans << "\n";
	return 0;
}