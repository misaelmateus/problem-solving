#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, m, a, d;
		cin >> n >> m >> a >> d;

		ll v[5];
		v[0] = a;
		for(ll i = 1; i < 5; i++)
			v[i] = v[i-1] + d;
		ll ans = 0;
		for(int mask = 1; mask < (1 << 5); mask++){
			int cont = 0;
			ll mult = 1LL;
			for(int i = 0; i < 5; i++)
				if((mask & (1 << i)))
					cont++, mult = (mult * v[i]) / __gcd(mult, v[i]);
			mult = m/mult - (n-1)/mult;
			if(cont % 2) ans += mult;
			else ans -= mult;
		}

		cout << (m - n + 1) - ans << endl;
	}
}