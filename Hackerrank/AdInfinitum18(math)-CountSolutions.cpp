#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define ld long double
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define MAXN 100100
using namespace std;

map<ll, ll> root;


int main()
{
	for(ll i = 1; i < MAXN; i++) root[i*i] = i;
	int q;
	cin >> q;
	while(q--){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		int cnt = 0;

		fr(x, 1, c+1){
			ll k = (ll)x*(ll)x - (ll)x * a;

			ll delta = b*b - 4LL*k;
			if(delta != 0 && root[delta] == 0) continue;
			ll r1 = (b + root[delta])/2LL, r2 = (b - root[delta])/2LL;
			if(r1*2LL != b + root[delta]) continue;
			if(r1 >= 1LL && r1 <= d) cnt++;
			if(r1 != r2 && r2 >= 1LL && r2 <= d) cnt++;

		}

		cout << cnt << endl;
	}

	return 0;
}

