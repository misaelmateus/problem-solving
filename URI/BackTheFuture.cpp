#include<bits/stdc++.h>
using namespace std;
#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
 
typedef long long int64;
 
const int
	MAXN = 102,
	MAXE = 10010,
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
	while(scanf("%d %d", &n, &m) != EOF){
		int a, b, c;
		clear();
		V = n;
		while(m--){
			scanf("%d %d %d", &a, &b, &c);
			add_edge(a, b, c, 1);
			add_edge(b, a, c, 1);
		}
		
		scanf("%d %d", &D, &K);
		for(int i = 0; i < E; i++)
			edges[i].cap *= K;
		add_edge(0, 1, 0, D);
		while(augment(0, n));
		printf("Instancia %d\n", k++);
		if(flow != D)
			printf("impossivel\n\n");
		else printf("%d\n\n", sol);
	}
}