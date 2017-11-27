#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<ld, int>
#define ll long long
#define ld double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 1010
using namespace std;

vector<pair<int, ii > > gr[MAXN];
int n, m;

ld dist[MAXN];
ld dijkstra(int a, int b, ld t){
	priority_queue< ii > q;
	rep(i, MAXN) dist[i] = (ld)2e9;
	dist[a] = 0.0;
	ld aux;
	q.emplace(0.0, a);
	while(!q.empty()){
		int d, node;
		tie(d, node) = q.top(); q.pop();
		d = -d;
		if(d > dist[node]) continue;
		for(pair<int, ii> it: gr[node]){
			aux = it.second.first*t + (ld)it.second.second;
			if(dist[it.first] > dist[node] + aux)
				dist[it.first] = dist[node] + aux, 
				q.emplace(-dist[it.first], it.first);
		}
	}
	return dist[b];
}


int main(){
	while(scanf("%d %d", &n, &m) != EOF){
		rep(i, MAXN) gr[i].clear();

		int x, y, A, B;
		rep(i, m){
			scanf("%d %d %d %d", &x, &y, &A, &B);
			gr[x].push_back({y, {A, B}});
			gr[y].push_back({x, {A, B}});
		}

		ld i = 0, j = 1440.0;
		rep(l, 300){
			ld i1 = i + (j - i) / 3.0;
			ld j1 = j - (j - i) / 3.0;
			if(dijkstra(1, n, i1) > dijkstra(1, n, j1))
				j = j1;
			else i = i1;
		}
		double ans = dijkstra(1, n, i);
		printf("%.5lf\n", ans);
	}
	
}