#include<bits/stdc++.h>
#define MAXN 1000010
#define ll long long
using namespace std;
ll v[MAXN];
int main(){
	int n;
	cin >> n;
	set<pair<ll, int> > s;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		s.insert({v[i], i});
	}
	ll ans = 0LL;
	int i = 0;
	while(i != n){
		auto it = s.begin();
		int p = (*it).second;
		ans += (ll)(p - i) * v[p]; 
		for(i++; i <= p; i++){
			s.erase({v[i], i});
		}
		i--;
	}

	cout << ans << endl;
}