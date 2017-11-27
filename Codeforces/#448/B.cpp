#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 100100
#define readFast ios::sync_with_stdio(false)
using namespace std;
ll tree[MAXN];
int main(){
	readFast;
	int n;
	ll k;
	ll x;
	ll ans = 0LL;
	cin >> n >> x >> k;
	ll v[n];
	rep(i, n) 
		cin >> v[i];

	sort(v, v+n);
	for(int i = 0; i < n; i++){
		ll a = ((v[i] + x-1)/x) * x + x*(k-1);
		ll b = a + x;
		if(k == 0){
			ans += (ll)(lower_bound(v, v+n, b) - lower_bound(v, v+n, v[i]));
			continue;
		}
		//cout << v[i] << " " << a << " " << b << endl;
		ans += (ll)(lower_bound(v, v+n, b) - lower_bound(v, v+n, a));
	}
	cout << ans << "\n";
}