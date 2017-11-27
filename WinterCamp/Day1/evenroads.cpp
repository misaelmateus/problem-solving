#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 200010
#define INF 0x3f3f3f3f
using namespace std;

vector< ii > gr[MAXN];
int dist[MAXN];
int dijkstra(int a, int b){
	priority_queue< ii > q;
	memset(dist, INF, sizeof(dist));
	dist[a] = 0;

	q.emplace(0, a);
	while(!q.empty()){
		int d, node;
		tie(d, node) = q.top(); q.pop();
		d = -d;
		if(d > dist[node]) continue;

		for(ii it: gr[node])
			if(dist[it.first] > dist[node] + it.second)
				dist[it.first] = dist[node] + it.second, 
				q.emplace(-dist[it.first], it.first);
	}
	return dist[b];
}

int main(){
	ios::sync_with_stdio(false);	
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int u, v, l;
		cin >> u >> v >> l;
		u--, v--;
		gr[u].push_back({n + v, l});
		gr[n + u].push_back({v, l});
		gr[v].push_back({n + u, l});
		gr[n + v].push_back({u, l});
	}
	int ans = dijkstra(0, n-1);
	if(ans > 1e9) ans = -1;
	cout << ans << endl;
}