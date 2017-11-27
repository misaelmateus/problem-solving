#include<bits/stdc++.h>
#define MAXN 1001
#define EPS 0.0000001
using namespace std;
int w, n;
double dist[MAXN][MAXN];
int x[MAXN], y[MAXN];
int ans_x, ans_y;
int dfs(double ans){
	vector<int> mark(2*MAXN, 0);
	vector< pair<int, int> > mark1(2*MAXN, {1, 1});
	queue< int  > q;
	for(int i = 0; i < n; i++){
		if(ans - x[i] > -EPS)
			q.push(i), mark[i] = 1, mark[i+MAXN] = 1;
		else if(2*ans - x[i] > -EPS)
			q.push(i+MAXN), mark[i+MAXN] = 1, mark1[i+MAXN] = {x[i], 2*y[i]};
	}

	while(!q.empty()){
		int u = q.front();
		pair<int, int> p = mark1[u];
		q.pop();
		if(u < MAXN){
			for(int i = 0; i < n; i++)
				if(!mark[i] && i != u && ans - dist[u][i] > -EPS) 
					q.push(i), mark[i] = 1, mark[i+MAXN] = 1, mark1[i] = p, mark1[i+MAXN] = p;
				else if(!mark[i] && i != u && 2*ans - dist[u][i] > -EPS) 
					q.push(i + MAXN), mark[i+MAXN] = 1, mark1[i+MAXN] = {x[i] + x[u], y[i] + y[u]};
		}
		else{
			for(int i = 0; i < n; i++)
				if(!mark[i + MAXN] && i != u && ans - dist[u-MAXN][i] > -EPS) 
					q.push(i+MAXN), mark[i+MAXN] = 1, mark1[i+MAXN] = p;
		}
	}

	for(int i = 0; i < n; i++){
		if(mark[i] && 2*ans - (w - x[i]) > -EPS){
			ans_x = w + x[i], ans_y = 2*y[i];
			return 1;
		}
	}
	for(int i = 0; i < n; i++){
		if(mark[i+MAXN] && ans - (w - x[i]) > -EPS){
			ans_x = mark1[i+MAXN].first, ans_y = mark1[i+MAXN].second;
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("froggy.in", "r", stdin);
    freopen("froggy.out", "w", stdout);
	scanf("%d %d", &w, &n);
	ans_x = 1;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		for(int j = 0; j < i; j++){
			dist[i][j] = dist[j][i] = sqrt((long long)(x[i] - x[j]) * (x[i] - x[j]) + (long long)(y[i] - y[j])*(y[i] - y[j]));
		}
	}

	double i = 0, j = 1e9;
	for(int a = 0; a < 50; a++){
		double m = (i + j) / 2;
		if(dfs(m))
			j = m;
		else i = m;
	}
	printf("%.3lf %.3lf", (double)ans_x/2, (double)ans_y/2);
	return 0;
}	