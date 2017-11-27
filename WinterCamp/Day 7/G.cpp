#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n;
	cin >> n;
	set<ll> s;
	ll ans = (1LL << 60);
	while(n--){
		ll aux;
		cin >> aux;
		auto it = s.upper_bound(aux);
		if(it != s.end()){
			ans = min(ans, (*it) - aux);
		}
		s.insert(aux);
	}

	cout << ans << "\n";
	return 0;
}