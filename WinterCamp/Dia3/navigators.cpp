#include<bits/stdc++.h>
#define vi vector<int>
#define INF 0x3f3f3f3f
#define ii pair<int, int>
using namespace std;
#define MAXN 200010

vi v[MAXN], v2[MAXN];
int p[MAXN], r[MAXN], N;
vector<ii> p1, r1;
vector<ii> gr[MAXN];

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
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> p[i] >> r[i];
		p1.push_back({p[i], i});
		r1.push_back({r[i], i});
	}

	sort(p1.begin(), p1.end());
	sort(r1.begin(), r1.end());
	
	for(int i = 0; i < N; i++){
		if(i > 0) gr[p1[i].second].push_back({p1[i-1].second, p1[i].first - p1[i-1].first });
		if(i < N-1) gr[p1[i].second].push_back({p1[i+1].second, p1[i+1].first - p1[i].first});

		if(i > 0) gr[r1[i].second].push_back({r1[i-1].second, r1[i].first - r1[i-1].first});
		if(i < N-1) gr[r1[i].second].push_back({r1[i+1].second, r1[i+1].first - r1[i].first});
	}
	
	cout << dijkstra(0, N-1) << endl;
	return 0;
}