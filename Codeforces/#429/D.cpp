#include<bits/stdc++.h>
#define MAXN 300010
using namespace std;
vector<int> pos[MAXN];
int v[MAXN];
int query(int x, int l, int r){
	return (int)(lower_bound(pos[x].begin(), pos[x].end(), r+1) - lower_bound(pos[x].begin(), pos[x].end(), l));
}
int main(){
	int n, q;
	srand(time(0));
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		pos[v[i]].push_back(i+1);
	}
	while(q--){
		int l, r, k;
		int ans = -1;
		scanf("%d %d %d", &l, &r, &k);
		for(int i = 0; i < 70; i++){
			if(i > 40 && ans == -1) break;
			int x = l + rand() % (r - l + 1);
			if(ans != -1 && v[x-1] >= ans) continue;
			int cont = query(v[x-1], l, r);
			if(cont > (r - l + 1)/k)
				ans = v[x-1];
		}
		printf("%d\n", ans);
	}

	return 0;
}