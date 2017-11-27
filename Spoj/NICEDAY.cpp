#include<bits/stdc++.h>
#define MAXN 100100
#define vi vector<int>
#define ii pair<int, int>
using namespace std;

int tree[MAXN];
pair<int, ii > Q[MAXN];

void update(int k, int val){
	while(k < MAXN){
		tree[k] = min(tree[k], val);
		k += (k & -k);
	}
}

int query(int k){
	int ans = 1e9;
	while(k > 0){
		ans = min(ans, tree[k]);
		k -= (k & -k);
	}
	return ans;
}

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int n;
		scanf("%d", &n);
		for(int i = 0; i <= n; i++)
			tree[i] = 1e9;
		int cont = n;
		for(int i = 0; i < n; i++){
			scanf("%d %d %d", &Q[i].first, &Q[i].second.first, &Q[i].second.second);
		}

		sort(Q, Q+n);

		for(int i = 0; i < n; i++){
			if(query(Q[i].second.first-1) < Q[i].second.second)
				cont--;
			update(Q[i].second.first, Q[i].second.second);
		}
		printf("%d\n", cont);
	}
}