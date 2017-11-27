#include<bits/stdc++.h>
#define MAXN 200100
#define ll long long
using namespace std;
ll tree[MAXN*3];
ll mark[MAXN * 3];
int v[MAXN];


void build(int l ,int r, int n){
	if(l == r){
		tree[n] = v[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, n << 1);
	build(mid+1, r, (n << 1) | 1);
	tree[n] = min(tree[n << 1], tree[(n << 1) | 1]);
}
void lazy(int l, int r, int n){
	if(!mark[n]) return ;
	tree[n] += mark[n];

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
	tree[n] = min(tree[n << 1], tree[(n << 1) + 1]);
}

ll query(int l, int r, int i, int j, int n){
	if(i > r || j < l) return (1 << 30);
	lazy(i, j, n);
	if(i >= l && j <= r) {
		//cout << i <<" " << j <<" " << tree[n] << endl;
		return tree[n];
	}
	int mid = (i + j) >> 1;
	return min(query(l, r, i, mid, n << 1), query(l, r, mid+1, j, (n << 1) + 1));
}
int main(){
	int N, Q;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &v[i]);	
	build(1, N, 1);
	scanf("%d", &Q);
	while(Q--){
		int x, y, val;
		char c;
		scanf("%d %d%c", &x, &y, &c);
		x++, y++;
		if(c != ' '){
			ll ans = 0;
			if(x <= y)
				ans = query(x, y, 1, N, 1);
			else ans = min(query(x, N, 1, N, 1), query(1, y, 1, N, 1));
			printf("%lld\n", ans);
		}
		else{
			scanf("%d", &val);
			if(x > y) update(x, N, 1, N, 1, val), update(1, y, 1, N, 1, val);
			else update(x, y, 1, N, 1, val);
		}
	}
}	