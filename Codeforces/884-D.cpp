//   Author : Misael Mateus 
//   Submission date: 2017-10-28 20:07:07
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n, aux;
	cin >> n;
	multiset<ll> s;
	ll ans = 0LL;
	while(n--){
		cin >> aux;
		s.insert(aux);
	}
	if(s.size() % 2 == 0){
		ll tot = 0;
		tot += *(s.begin());
		s.erase(s.begin());
		tot += *(s.begin());
		s.erase(s.begin());
		ans += tot;
		s.insert(tot);
	}
	while(s.size()-1){
		ll tot = 0;
		tot += *(s.begin());
		s.erase(s.begin());
		tot += *(s.begin());
		s.erase(s.begin());
		tot += *(s.begin());
		s.erase(s.begin());
		ans += tot;
		s.insert(tot);
	}
	cout << ans << "\n";
}