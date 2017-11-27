#include<bits/stdc++.h>
#define ii pair<int, int>
#define ff first
#define ss second
#define MAXV 2100
#define MAXN 110
using namespace std;

int dp[MAXN][MAXV];
int main(){
	int n;
	scanf("%d", &n);
	pair<ii, ii> v[n];
	for(int i = 0; i < n; i++)
		scanf("%d %d %d", &v[i].ff.ss, &v[i].ff.ff, &v[i].ss.ff), v[i].ss.ss = i+1;
	sort(v, v+n);
	for(int tg = MAXV-30; tg >= 0; tg--){
		for(int i = n-1; i >= 0; i--){
			if(tg + v[i].ff.ss >= v[i].ff.ff)		
				dp[i][tg] = dp[i+1][tg];
			else dp[i][tg] = max(dp[i+1][tg], dp[i+1][tg + v[i].ff.ss] + v[i].ss.ff);
		}
	}
	printf("%d\n", dp[0][0]);
	vector<int> ans;

	int tg = 0;
	for(int i = 0; i < n; i++){
		if(tg + v[i].ff.ss >= v[i].ff.ff)		
				continue;
		if(dp[i][tg] == dp[i+1][tg + v[i].ff.ss] + v[i].ss.ff)
			ans.push_back(v[i].ss.ss), tg += v[i].ff.ss;
	}

	printf("%d\n", (int)ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}