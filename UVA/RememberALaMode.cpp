#include<bits/stdc++.h>
using namespace std;
#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
 
typedef long long int64;
 
const int
	MAXN = 105,
	MAXE = 6010,
	oo = (int)1e9;
 
int T, V, L, E;
int src, snk, sol, flow;
int cant[MAXN];
int best[MAXN];
int from[MAXN];
int head[MAXN];
int D, K;
struct edge {
	int u, v, w, cap, next;
} edges[MAXE];
 
void add_edge( int u, int v, int w, int cap) {
	edges[E++] = (edge){ u, v, +w, cap, head[u] };
	head[u] = E - 1;
	edges[E++] = (edge){ v, u, -w, 0, head[v] };
	head[v] = E - 1;
}
 
bool augment( int src, int snk ) {
 
	fill( best, best + V + 2, oo );
	
	best[src] = 0;
	
    //queue< int> Q;
	//set<pair<int,int> >Q;
	 priority_queue<pair<int, int>, vector<pair<int, int> >,
     greater<pair<int, int> > > Q;

	Q.push(make_pair(0,src));
	while(!Q.empty())
	{
		int u = Q.top().second;
		//Q.erase(Q.begin())
		Q.pop();
		for ( int e = head[u]; e != -1; e = edges[e].next ) {

			int v = edges[e].v;
		      if ( edges[e].cap && best[u] + edges[e].w < best[v] ) {
				best[v] = best[u] + edges[e].w;
				Q.push(make_pair(best[v],v));
				
				from[v] = e;
			}
		}
	}
	
	//cout << best[snk] << endl;
	if ( best[snk] == oo )
	      return false;
	sol += best[snk];
	flow++;
	for ( int x = snk; x != src; x = edges[ from[x] ].u ) {
		edges[ from[x] ].cap--;
		edges[ from[x]^1 ].cap++;
	}
	return true;
}

void clear(){
	memset(best, 0, sizeof(best));
	memset(from, 0, sizeof(from));
	memset(head, -1, sizeof(head));
	T = V = L = E = 0;
	flow = src = snk = sol = 0;

}

int main(){
	int n, m, k = 1;
	while(scanf("%d %d", &n, &m) != EOF && n && m){
		clear();
		V = n+m+1;
		int val;
		double aux;
		for(int i = 0; i < n; i++){
			scanf("%d", &val);
			add_edge(0, i+1, 0, val);
		}
		for(int i = 0; i < m; i++){
			scanf("%d", &val);
			add_edge(i+n+1, n+m+1, 0, val);
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				cin >> aux;
				if(aux < 0) continue;
				val = (int)(aux * 100 + 0.1);
				add_edge(i+1, j+n+1, val, oo);
			}
		
		printf("Problem %d: ", k++);
		while(augment(0, n+m+1));
		printf("%d.%02d ", sol/100, sol % 100);

		for(int i = 0; i < E; i += 2)
			edges[i].cap = edges[i].cap + edges[i+1].cap, edges[i+1].cap = 0;
		sol = 0;
		flow = 0;
		for(int i = 0; i < E; i++){
			if(edges[i].w != 0)
				edges[i].w = -edges[i].w;
		}
		while(augment(0, n+m+1));
		sol = -(sol);
		printf("to %d.%02d\n", sol/100, sol % 100);		
		
	}
}