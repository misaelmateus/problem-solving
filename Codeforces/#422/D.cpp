#include<bits/stdc++.h>
#define L 1000000007LL
#define ll long long
#define MAXN 5000005
using namespace std;

ll dp[MAXN];
ll d[MAXN];
int main(){
	for(int i = 2; i < MAXN; i++){
		if(d[i] == 0){
			for(int j = i; j < MAXN; j+= i)
				if(d[j] == 0) d[j] = (ll)i;
		}
	}

	ll t, l, r;
	cin >> t >> l >> r;
	for(int i = 2; i < MAXN; i++){
		dp[i] = (1LL << 50);
		int j = i;
		while(j > 1){
			int k = d[j];
			dp[i] = min( dp[i], (ll)i*(k - 1) / 2LL + dp[i / k] );	
			j /= k;
		}

		dp[i] %= L;
	}

	ll ans = 0LL;
	ll mult = 1LL;
	for(int i = l; i <= r; i++, mult = (mult * t) % L){
		ans = (ans + (mult * dp[i]) % L) % L;
	}

	cout << ans << "\n";
}