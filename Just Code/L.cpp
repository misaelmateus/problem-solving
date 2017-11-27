#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 10010
#define INF 0x3f3f3f3f
#define mt make_tuple
#define eb emplace_back
#define fr(a, b, c) for(ll a = (b); (a) < (c); (a)++ )
#define rep(a, b) fr(a, 0, b)
typedef tuple<ll,ll,ll> State;

#define ii pair<ll, ll>
#define iii pair<ll, ii>

vector<iii> gr[MAXN];
ii dist[MAXN];
ii sum(ii a, ii b){
	return {a.first + b.first, a.second + b.second};
}

ii mult(int k, ii b){
	return {k*b.first, k*b.second};
}
ii dijkstra(ll a, ll b){
	priority_queue< pair<ii, int> > q;
	for(int i = 0; i < MAXN; i++) dist[i] = {-1, -1};
	dist[a] = {0, 0};

	q.emplace(0, a);
	while(!q.empty()){
		ii d;
		ll node;
		tie(d, node) = q.top(); q.pop();
		d = mult(-1, d);
		if(dist[node] == (ii){-1, -1} || d > dist[node]) continue;
		for(iii it: gr[node])
			if(dist[it.first] == (ii){-1, -1} || dist[it.first] > sum(dist[node], it.second) )
				dist[it.first] = sum(dist[node], it.second), 
				q.emplace(mult(-1, dist[it.first]), it.first);
	}
	return dist[b];
}
int main(){
	int n_t;
	scanf("%d", &n_t);
	while(n_t--){
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				ii c = {0, 0};
				scanf("%lld", &c.first);
				gr[i*m + j].push_back({(i+1) * m + j, (ii)c});
			}
		for(int i = 0; i <= n; i++)
			for(int j = 0; j < m-1; j++){
				ii c = {0, 0};
				if(i < n)
					scanf("%lld", &c.second);
				gr[i*m + j].push_back({i*m + j + 1, (ii)c });
				gr[i*m + j + 1].push_back({i*m + j, (ii)c });
			}
		ii ans = dijkstra(0, n*m);
		printf("%lld %lld\n", ans.first, ans.second);
	}

}