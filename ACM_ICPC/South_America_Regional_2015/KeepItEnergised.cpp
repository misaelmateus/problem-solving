#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 100010
using namespace std;

vector<ii> gr[MAXN];
int pre[MAXN];
int v[MAXN];
int n, m;

int binary_search(int val){
	int i = 0, j = n+1;
	while(j - i > 1){
		int mid = (i + j) / 2;
		if(pre[mid] > val)
			j = mid;
		else i = mid;
	}
	return i;
}

int dist[MAXN];
int dijkstra(int a, int b){
	priority_queue< ii > q;
	rep(i, MAXN) dist[i] = 1e9 + 10;
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
	while(RII(n, m) != EOF){
		rep(i, MAXN) gr[i].clear(), pre[i] = 0;
		rep(i, n){
			RI(v[i]);
			pre[i+1] = pre[i] + v[i];
		}
		fr(i, 1, n+1) gr[i].push_back({i-1, 0});

		rep(i, m){
			int l, s, c;
			RII(l, s);
			RI(c);
			l--;
			int p = binary_search(pre[l] + s);
			gr[l].push_back({p, c});
		}

		int ans = dijkstra(0, n);
		if(ans > 1e9)
			ans = -1;
		printf("%d\n", ans);
	}
}