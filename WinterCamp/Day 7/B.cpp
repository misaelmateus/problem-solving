#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define MAXN 10000010
using namespace std;
ll c[MAXN];
ll cS[2*MAXN];
ll qD[MAXN];
ll perm2(ll a){
	if(a < 2)
		return 0;
	return a * (a-1) / 2LL;
}

ll perm4(ll a){
	if(a < 4)
		return 0LL;
	return (a * (a-1) * (a-2) * (a-3))/24LL;
}

ll perm3(ll a){
	if(a < 3) return 0LL;
	return a * (a-1) * (a-2) / 6LL;
}

ll C(int a){
	if(a < MAXN)
		return c[a];
	return 0;
}
int main(){
	ios::sync_with_stdio(false);	
	ll n, aux;
	cin >> n;
	set<int> s;
	ll ans = 0;
	while(n--){
		cin >> aux;
		c[aux]++;

		s.insert((int)aux);
	}
	vector<int> v, v1;
	for(auto& it1 : s)
		v.push_back((int)it1);

	for(auto& it1 : s)
		v1.push_back((int)it1);

	for(auto& it1 : v)
		for(auto& it2 : v1){
			if(it1 >= it2) qD[it1-it2] += perm3(c[it1]) * c[it2];
		}
	
	for(auto& it1 : v){
		for(auto& it2 : v1){
			ll a = c[it1], b = c[it2];
			ll q = (it1 + it2 < MAXN ? qD[it1 + it2] : 0);
			if(it1 != it2){

				ans += a*b*(q - perm3(C(2*it1 + it2))*a - perm3(C(it1 + 2*it2))*b);
			}
			else {
				ans += 3*(perm2(a) * (q - perm3(C(3*it1))*a)) * 2;
				ans += 3*(perm3(a) * perm3(C(3*it1) )) * 2;
			}
		}
	}
	ans /= 3;
	for(auto& it1 : v){
		for(auto& it2 : v1){
			if(it1 < it2)
			   cS[it1 + it2] += c[it1] * c[it2] ;
		}
	}							
	for(auto &it1 : v){
		for(auto& it2 : v1){
			ll a = c[it1], b = c[it2];
			ll x = it1 + it2;
			if(it1 == it2) {
				ans += perm4(a) * (ll)(c[x] * (c[x] - 1) / 2) * 2;
				ans += perm2(a) * (ll)cS[x] * (ll)(c[x] * (c[x] - 1) / 2) * 2;
			}
			else if(it1 < it2) ans += ( (ll)(a * (a-1) / 2) * (ll)(b * (b-1) / 2) * 2 + (ll)a*b*(cS[x] - a*b)) * (ll)(c[x] * (c[x] - 1) / 2);
		}
	}
	ans /= 2;

	cout << ans << "\n";
}