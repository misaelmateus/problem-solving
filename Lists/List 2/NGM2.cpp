#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n, k;
	cin >> n >> k;

	ll v[20];
	for(int i = 0; i < k; i++) cin >> v[i];
	ll ans = 0;
	for(int mask = 1; mask < (1 << k); mask++){
		int cont = 0;
		ll mult = 1LL;
		for(int i = 0; i < k; i++)
			if((mask & (1 << i)))
				cont++, mult = (mult * v[i]) / __gcd(mult, v[i]);
		mult = n/mult;
		if(cont % 2) ans += mult;
		else ans -= mult;
	}

	cout << n - ans << endl;
}