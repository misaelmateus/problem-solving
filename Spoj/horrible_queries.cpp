#include<bits/stdc++.h>
#define MAXN 100100
#define ll long long
using namespace std;
ll tree[MAXN*3];
ll mark[MAXN * 3];
int v[MAXN];


void lazy(int l, int r, int n){
	if(!mark[n]) return ;
	tree[n] += mark[n] * (r - l + 1);

	if( (n << 1) < 3*MAXN - 1){
		mark[n << 1] += mark[n];
		mark[(n << 1) + 1] += mark[n];
	}
	mark[n] = 0;
}

void update(int l, int r, int i, int j, int n, ll val){
	lazy(i, j, n);
	if(i > r || j < l) return ;
	if(i >= l && j <= r){
		mark[n] += val;
		lazy(i, j, n);
		return ;
	}

	int mid = (i + j) >> 1;
	update(l, r, i, mid, n << 1, val);
	update(l, r, mid+1, j, (n << 1) + 1, val);
	tree[n] = tree[n << 1] + tree[(n << 1) + 1];
}

ll query(int l, int r, int i, int j, int n){
	if(i > r || j < l) return 0;
	lazy(i, j, n);
	if(i >= l && j <= r) {
		return tree[n];
	}
	int mid = (i + j) >> 1;
	return query(l, r, i, mid, n << 1) + query(l, r, mid+1, j, (n << 1) + 1);
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		memset(tree, 0, sizeof(tree));
		memset(mark, 0, sizeof(mark));
		int N, Q;
		scanf("%d %d", &N, &Q);
		
		while(Q--){
			int type, x, y;
			scanf("%d %d %d", &type, &x, &y);
			
			if(type){
				printf("%lld\n", query(x, y, 1, N, 1));
			}
			else{
				ll val;
				scanf("%lld", &val);
				update(x, y, 1, N, 1, val);
			}
		}
	}
}	