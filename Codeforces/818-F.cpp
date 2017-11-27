//   Author : Misael Mateus 
//   Submission date: 2017-07-05 22:28:37
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(false);	
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		
		ll l = 0, r = n+1;
		while(r - l > 1){
			ll k = (l+r) >> 1;
			if((ll)(n - k)*(n - k - 1) >= 2LL*k)
				l = k;
			else r = k;
		}
		ll ans = 2*l;
		for(int i = l+1; i < n && (ll)i + (ll)(n - i) * (n - i - 1) / 2 > ans; i++) ans = (ll)i + (ll)(n - i) * (n - i - 1)/2;
		cout << ans << endl;
	}

	return 0;
}