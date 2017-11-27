#include<bits/stdc++.h>
#define MAXN 100010
#define ii pair<int, int>
#define mp(a, b) make_pair(a, b)
using namespace std;

int lca[MAXN][18];

vector<ii> gr[MAXN];
int p[MAXN];
int dist[MAXN];
int level[MAXN];

int lca(int n){
	for(int i = 1; i <= n; i++)
		lca[i][0] = p[i];
	for(int j = 2; j < 18; j++){
		for(int i = 1; i <= n; i++)
			lca[i][j] = lca[lca[i][j-1]][j-1];
	}
}

int dfs(int u, int p = -1){

	for(auto v : gr[u]){
		if(v == p) continue;
		dist[v.first] = dist[u] + v.second;
		level[v.first] = level[u] + 1;
		dfs(v.first, u);
	}

}

struct vertex {
	vertex * l, * r;
	int sum;
 
	vertex (int val)
		: l(NULL), r(NULL), sum(val)
	{ }
 
	vertex (vertex * l, vertex * r)
		: l(l), r(r), sum(0)
	{
		if (l)  sum += l->sum;
		if (r)  sum += r->sum;
	}
};
 
vertex * build (int a[], int tl, int tr) {
	if (tl == tr)
		return new vertex (0);
	int tm = (tl + tr) / 2;
	return new vertex (
		build (a, tl, tm),
		build (a, tm+1, tr)
	);
}
 
int get_sum (vertex * t, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && tr == r)
		return t->sum;
	int tm = (tl + tr) / 2;
	return get_sum (t->l, tl, tm, l, min(r,tm))
		+ get_sum (t->r, tm+1, tr, max(l,tm+1), r);
}
 
vertex * update (vertex * t, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		return new vertex (new_val);
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return new vertex (
				update (t->l, tl, tm, pos, new_val),
				t->r
			);
	else
		return new vertex (
				t->l,
				update (t->r, tm+1, tr, pos, new_val)
			);
}



int main(){
	
}