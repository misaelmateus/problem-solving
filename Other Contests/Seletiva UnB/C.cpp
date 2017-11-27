#include<bits/stdc++.h>
#define fr(a, b, c) for(int (a) = (b); (a) < (c); (a)++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define mp make_pair
#define MAXN 60

using namespace std;

vector<int> gr[MAXN];
vector<int> cont, dist;
int main(){
	int T;
	scanf("%d", &T);
	for(int l = 1; l <= T; l++){
		int N, B, k, aux;
		scanf("%d %d %d", &N, &B, &k);
		rep(i, N+1) gr[i].clear();

		vector<ii> v;
		for(int i = 1; i <= N; i++){
			scanf("%d", &aux);
			if(aux <= B) 
				v.push_back(mp(i, aux));
		}
		int L;
		scanf("%d", &L);
		while(L--){
			int a, b;
			scanf("%d %d", &a, &b);
			gr[a].push_back(b);
			gr[b].push_back(a);
		}
		pair<int, ii> ans = mp(0, mp(-(1e9), -(1e9) ) );
		int t = v.size();
		for(int mask = 1; mask < (1 << t); mask++){
			cont = vector<int>(N+1, 0);
			dist = vector<int>(N+1, -1);
			int n_sites = 0;
			int max_dist = 0;
			priority_queue<ii> q;
			int w = 0;
			rep(i, t) 
				if(mask & (1 << i))
					q.push(mp(0, v[i].first)), w += v[i].second, dist[v[i].first] = 0;
			if(w > B) continue;
			while(!q.empty()){
				n_sites++;
				int u = q.top().second;
				q.pop();
				rep(i, gr[u].size()){
					int next = gr[u][i];
					if(dist[next] != -1) continue;
					cont[next]++;
					if(cont[next] >= k){
						dist[next] = dist[u] + 1;
						max_dist = max(dist[next] , max_dist);
						q.push(mp(-dist[next], next));
					}
				}
			}
			
			ans = max(ans, (pair<int, ii>)mp(n_sites, mp(-w, -max_dist )) );
		}
		if(ans.first==0) ans = mp(0, mp(0, 0));
		printf("Caso %d: %d %d %d\n",l, ans.first, -ans.second.first, -ans.second.second);

	}
}