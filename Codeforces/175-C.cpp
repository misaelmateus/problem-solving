//   Author : Misael Mateus 
//   Submission date: 2017-09-10 19:48:59
#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
using namespace std;
int main(){
	int n, t;
	scanf("%d", &n);
	priority_queue< ii > pq;
	for(int i = 0; i < n; i++){
		ii now;
		scanf("%d %d", &now.second, &now.first);
		now.first *= -1;
		pq.push(now);
	}
	scanf("%d", &t);
	ll last = 0;
	ll ans = 0;
	for(ll i = 1; i <= t+1; i++){
		ll now = 0;
		ll q;
		if(i <= t){
			scanf("%lld", &now);
			q = now - last;
		}
		else q = (1LL << 60);
		while(!pq.empty() && q){
			ii u = pq.top();
			pq.pop();
			ll a = min((ll)u.second, q);
			ans += i*(-u.first) * a;
			u.second -= a;
			q -= a;
			if(u.second) pq.push(u);
		}
		last = now;
	}

	printf("%lld\n", ans);
	return 0;
}