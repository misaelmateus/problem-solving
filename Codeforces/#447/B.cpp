#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000007LL

ll fast_pow(ll a, ll b){
	if(b == 0) return 1LL;
	if(b == 1LL) return a % P;
	ll x = 1LL;
	if(b & 1LL)
		x = a % P;
	ll y  = fast_pow(a, b >> 1);
	x = (((x * y) % P) * y) % P;
	return x;
}

int main(){
	ll n, m, k;
	ll ans;
	cin >> n >> m >> k;
	if(m < n)
		swap(n, m);
	ans = fast_pow(2, n-1);
	ans = fast_pow(ans, m-1);
	ll a = fast_pow(k, m - n + 1);
	if(a == k)
		cout << ans << "\n";
	else cout << "0\n";
	return 0;
}