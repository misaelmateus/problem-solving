#include<bits/stdc++.h>
#define MAXN 100010
#define MAXK 51
#define MOD 5000000
using namespace std;
int tree[MAXN][MAXK];
int v[MAXN];
int sum(int i, int k){
	int ans = 0;
	while(i > 0){
		ans += tree[i][k];
		if(ans >= MOD)
			ans -= MOD;
		i -= (i & -i);
	}
	return ans;
}

void update(int i, int k, int val){
	while(i < MAXN){
		tree[i][k] += val;
		if(tree[i][k] >= MOD)
			tree[i][k] -= MOD;
		i += (i & -i);
	}
}


int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		v[i]+=2;
	}

	update(1, 0, 1);
	for(int i = 1; i <= n; i++){
		for(int l = 1; l <= k; l++){
			update(v[i], l, sum(v[i]-1, l-1));
		}
	}

	int ans = sum(MAXN-1, k);
	cout << ans << endl;
}