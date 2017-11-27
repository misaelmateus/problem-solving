#include<bits/stdc++.h>
#define MAXN 10010
#define ii pair<int, int>
#define INF 0x3f3f3f3f
using namespace std;

vector<pair<int, int> > gr[MAXN];

int mark[MAXN];
int t[MAXN];
int dist[MAXN];
int x;
int dfs(int u, int p, int d, vector<int> &v){
	v.push_back(u);
	mark[u] = d+1;
	for(auto next: gr[u]){
		if(next.first == p || t[next.first]) continue;
		if(mark[next.first]) {
			t[u] = mark[u] - mark[next.first] + next.second;
			for(int j = v.size()-1; 1 ; j--){
				t[v[j]] = t[u];
				if(v[j] == next.first) break;
			}
		}
		else dfs(next.first, u, d+next.second, v);
	}
	v.pop_back();
}


int dijkstra(int a){
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
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	while(m--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		gr[a].push_back({b, c});
		gr[b].push_back({a, c});
	}
	memset(mark, 0, sizeof(mark));
	for(int i = 1; i <= n; i++){
		vector<int> v;
		if(!mark[i]) dfs(i, -1, 0, v);
	}

	int q;
	scanf("%d", &q);
	while(q--){
		int s;
		scanf("%d %d", &s, &x);
		int ans = 1e9;
		dijkstra(s);
		for(int i = 1; i <= n; i++){
			if(dist[i] < 1e8 && t[i] >= x)
				ans = min(ans, 2*dist[i] + t[i]);
		}
		if(ans == 1e9) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}