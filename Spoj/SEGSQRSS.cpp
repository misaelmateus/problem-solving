#include<bits/stdc++.h>
#define MAXN 100010
#define ll long long
#define ii pair<ll, ll>
using namespace std;

ii tree[MAXN*4];

ii lazy[MAXN*4];

ll v[MAXN*4];

void build(int i, int j, int n){
	if(i == j){
		tree[n] = {v[i]*v[i], v[i]};
		return ;
	}
	int mid = (i + j) >> 1;
	build(i, mid, n << 1);
	build(mid+1, j, (n << 1) | 1);
	tree[n] = {tree[n << 1].first + tree[(n << 1) | 1].first, tree[n << 1].second + tree[(n << 1) | 1].second};
}


void propagate(int l, int r, int n){
	if(lazy[n].first == 0) return;
	if(lazy[n].first == 1){
		tree[n].first = tree[n].first + 2*tree[n].second*lazy[n].second + lazy[n].second * lazy[n].second * (ll)(r - l + 1);
		tree[n].second += (ll)(r - l + 1) * lazy[n].second;
		if(lazy[(n << 1)].first == 0) lazy[n << 1] = lazy[n];
		else lazy[n << 1].second += lazy[n].second;

		if(lazy[(n << 1) | 1].first == 0) lazy[(n << 1) | 1] = lazy[n];
		else lazy[(n << 1) | 1].second += lazy[n].second;
	}
	else{
		tree[n].first = (r - l + 1) * lazy[n].second * lazy[n].second;
		tree[n].second = (r - l + 1) * lazy[n].second;

		lazy[n << 1] = lazy[n];
		lazy[(n << 1) | 1] = lazy[n];
	}
	lazy[n].first = 0;
}
void update(int l, int r, int i, int j, int n, ii upd){
	propagate(i, j, n);
	if(j < l || i > r) return;
	if(i >= l && j <= r){
		lazy[n] = upd;
		propagate(i, j, n);
		return ;
	}
	int mid = (i + j) >> 1;
	update(l, r, i, mid, n << 1, upd);
	update(l, r, mid+1, j, (n << 1) | 1, upd);
	tree[n] = {tree[n << 1].first + tree[(n << 1) | 1].first, tree[n << 1].second + tree[(n << 1) | 1].second};
}
ll query(int l, int r, int i, int j, int n){

	if(i > r || j < l) return 0;
	propagate(i, j, n);
	if(i >= l && j <= r) {
		return tree[n].first;
	}
	int mid = (i + j) >> 1;
	return query(l, r, i, mid, n << 1) + query(l, r, mid+1, j, (n << 1) | 1);
}
int main(){
	int T;
	scanf("%d", &T);
	for(int k = 1; k <= T; k++){
		printf("Case %d:\n", k);

		memset(tree, 0, sizeof(tree));
		memset(lazy, 0, sizeof(lazy));
		int n, Q;
		scanf("%d %d", &n, &Q);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &v[i]);
		build(1, n, 1);

		int type, a, b, x;
		while(Q--){
			scanf("%d %d %d", &type, &a, &b);
			if(type == 2)
				printf("%lld\n", query(a, b, 1, n, 1));
			else if(type){
				scanf("%d", &x);
				update(a, b, 1, n, 1, {1, (ll)x});
			}
			else{
				scanf("%d", &x);
				update(a, b, 1, n, 1, {2, (ll)x});
			}

		}
	}
}