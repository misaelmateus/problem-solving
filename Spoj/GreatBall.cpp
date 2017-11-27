#include<bits/stdc++.h>
#define MAXN 211
using namespace std;

int tree[2*MAXN];

int update(int k, int val){
	while(k < 2*MAXN)
		tree[k] += val, k += (k & -k);
}

int sum(int k){
	int ans = 0;
	while(k > 0)
		ans += tree[k], k -= (k & -k);
	return ans;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		memset(tree, 0, sizeof(tree));
		map<int, int> compressed_values;
		int n;
		scanf("%d", &n);
		set<int> s;
		int v1[n], v2[n];
		for(int i = 0; i < n; i++){
			scanf("%d %d", &v1[i], &v2[i]);
			s.insert(v1[i]);
			s.insert(v2[i]);
		}
		int k = 2;
		for(auto u : s){
			compressed_values[u] = k;
			k+=2;
		}

		for(int i = 0; i < n; i++){
			update(compressed_values[v1[i]], 1);
			update(compressed_values[v2[i]], -1);
		}
		int ans = 0;
		for(int i = 1; i < 2*MAXN; i++)
			ans = max(ans, sum(i));
		printf("%d\n", ans);
	}
}