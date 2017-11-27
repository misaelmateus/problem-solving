#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
using namespace std;
int main(){
	int n, d;
	cin >> n >> d;
	priority_queue<ii> q;
	for(int i = 0; i < n; i++){
		int ki, ai;
		cin >> ai >> ki;
		q.push({ki, ai});
	}

	while(d > 0 && !q.empty()){
		int ki, ai;
		ki = q.top().first;
		ai = q.top().second;
		q.pop();
		if(ki > ai){
			q.push({ai, ai});
			continue;
		}
		while(d > 0 && ki <= ai){
			ai -= ki;
			d--;
		}
		if(ai)
			q.push({ai, ai});
	}

	ll ans = 0LL;
	while(!q.empty()){
		int ai = q.top().second;
		q.pop();
		ans += (ll)(ai);
	}
	cout << ans << "\n";
}