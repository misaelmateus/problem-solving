#include<bits/stdc++.h>
#define fr(a, b, c) for(ll a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<ll, ll>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<ll>
#define ll long long
using namespace std;


int main(){
	ios::sync_with_stdio(false);	
	ll n;
	cin >> n;
	vector<ll> v(n);
	rep(i, n)
		cin >> v[i];
	sort(v.begin(), v.end());

	ll m;
	cin >> m;
	rep(i, m){
		ll x;
		cin >> x;
		ll a = (10*x) / 11 + ((10*x) % 11 != 0);
		ll b = (10*x) / 9;

		cout << (ll)(upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a)) << "\n";
	}
	return 0;
}