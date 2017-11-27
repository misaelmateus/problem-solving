#include<bits/stdc++.h>
#define MAXN 100010
#define MAXVAL MAXN-1
using namespace std;
struct node{
	int le, ri, cnt;
};
node tree[MAXN*21];
int id[MAXN];
int sz;
void build(int &n, int l, int r){
	n = sz++;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(tree[n].le, l, mid);
	build(tree[n].ri, mid+1, r);
}

void update(int &no, int prev, int l, int r, int pos, int val){
	no = sz++;
	tree[no] = tree[prev];
	if(l == r && l == pos){
		tree[no].cnt = val;
		return ;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid)
		update(tree[no].le, tree[prev].le, l, mid, pos, val);
	else update(tree[no].ri, tree[prev].ri, mid+1, r, pos, val);
	tree[no].cnt = tree[tree[no].le].cnt + tree[tree[no].ri].cnt;
}

int query(int no1, int no2, int l, int r, int k){
	if(tree[no2].cnt - tree[no1].cnt < k) return -1;
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(tree[tree[no2].le].cnt - tree[tree[no1].le].cnt >= k)
		return query(tree[no1].le, tree[no2].le, l, mid, k);
	else return query(tree[no1].ri, tree[no2].ri, mid+1, r, k - (tree[tree[no2].le].cnt - tree[tree[no1].le].cnt));
}
int main(){
	int n, r;
	scanf("%d %d", &n, &r);
	map<int, int> compressed_val;
	map<int, int> inv_compr;
	set<int> aux;
	int v[n];
	build(id[0], 1, MAXVAL);
	for(int i = 1; i <= n; i++){
		scanf("%d", v+i);
		aux.insert(v[i]);
	}
	int k = 1;
	int a, b;
	for(auto u : aux){
		inv_compr[k] = u;
		compressed_val[u] = k++;
	}
	for(int i = 1; i <= n; i++)
		update(id[i], id[i-1], 1, MAXVAL, compressed_val[v[i]], 1);

	while(r--){
		scanf("%d %d %d", &a, &b, &k);
		printf("%d\n", inv_compr[query(id[a-1], id[b], 1, MAXVAL, k)]);
	}
	return 0;
}

