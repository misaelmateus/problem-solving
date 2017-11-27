#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;

using ordered_set = tree<
  pair<int,int>,
  null_type,
  less<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>;

#define MAXN 100010

ordered_set tree[4*MAXN];
vector<int> gr[MAXN];
int val[MAXN];
int beg[MAXN], end[MAXN], dfs_num = 0;

void dfs(int u){
	beg[u] = ++dfs_num;
	for(auto &v : gr[u])
		dfs(v);
	end[u] = dfs[num];
}

void build(int i, int j, int N){
	if(i == j) {
		tree[N].insert(val[i]);
		return ;
	}
	int middle = (i+j) >> 1;
	build(i, middle, 2*N);
	build(middle+1, j, 2*N+1);
	tree[N] = tree[2*N];
	for(auto &v : tree[2*N+1]) tree[N].insert(v);
}