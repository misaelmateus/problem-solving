//   Author : Misael Mateus 
//   Submission date: 2017-10-28 20:06:22
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100100

int p[MAXN];
int mark[MAXN];
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i =1; i <= n; i++){
		cin >> p[i];
	}
	ll ans = 0;
	multiset<ll> s;
	for(int i = 1; i <= n; i++){
		if(!mark[i]){
			int t = 1, j = i;
			mark[j] = 1;
			while(p[j] != i)
				j = p[j], t++, mark[j] = 1;
			ans += (ll)t * t;
			s.insert((ll)t);
		}
	}
	if(s.size() > 1){
		auto u = s.end();
		u--;
		ll a = *u;
		u--;
		ll b = *u;
		ans += 2*a*b;
	}

	cout << ans << "\n";
}