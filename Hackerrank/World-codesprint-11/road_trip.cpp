#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n, q;
	cin >> n >> q;
	ll w[n], g[n], p[n];
	for(int i = 0; i < n-1; i++) cin >> w[i];

	for(int i = 0; i < n; i++) cin >> g[i] >> p[i];

	while(q--){
		int x, y;
		cin >> x >> y;
		ll price = 0LL, gas = 0LL;
		ll men = (1LL<<30);
		for(int i = x-1; i < y-1; i++){
			gas += g[i];
			men = min(p[i], men);
			if(w[i] > gas)
				price += (w[i] - gas)*men, gas = 0;
			else gas -= w[i];
		}
		cout << price << "\n";
	}
}