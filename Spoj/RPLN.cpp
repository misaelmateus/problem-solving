#include<bits/stdc++.h>
#define MAXN 100100
#define ll long long
using namespace std;
int tree[MAXN*3];
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

int query(int l, int r, int i, int j, int n){
	if(i > r || j < l) return (1e9);
	if(i >= l && j <= r) {
		//cout << i <<" " << j <<" " << tree[n] << endl;
		return tree[n];
	}
	int mid = (i + j) >> 1;
	return min(query(l, r, i, mid, n << 1), query(l, r, mid+1, j, (n << 1) + 1));
}
int main(){
	int T;
	scanf("%d", &T);
	for(int k = 1; k <= T; k++){
		printf("Scenario #%d:\n", k);
		int N, Q;
		scanf("%d %d", &N, &Q);
		for(int i = 1; i <= N; i++)
			scanf("%d", &v[i]);	
		build(1, N, 1);
		
		while(Q--){
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%d\n", query(x, y, 1, N, 1));	
		}
	}
}	