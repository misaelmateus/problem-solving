#include<bits/stdc++.h>
#define MAXN 100010
#define ld long double
using namespace std;
vector<pair<int, int> > gr[MAXN];
int dist[MAXN];

void dijkstra(){
	for(int i  =0; i < MAXN; i++) dist[i] = 1e9;
	dist[1] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push({0, 1});
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for(auto v : gr[u]){
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;	
				pq.push({v.first, dist[v.first]});
			}
		}
	}
}
int main(){
	int T;
	cin >> T;

	while(T--){
		int N, M;
		cin >> N >> M;
		for(int i  =0; i < M; i++){
			int a, b, c;
			cin >> a >> b >> c;
			gr[a].push_back({b, c});
			gr[b].push_back({a, c});
		}
		dijkstra();
		ld ans = dist[N];
		sort(dist+1, dist+N);
		double sum = 0.0;
		for(int i = 1; i <= N && dist[i] < 1e9; i++){
			sum += dist[i];
			ans = min(ans, (N*K + sum)/l);
		}
	}

}