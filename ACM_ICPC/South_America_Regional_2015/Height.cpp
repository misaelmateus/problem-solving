#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111
#define vi vector<int>
using namespace std;

int f(vector<vi> v){
	int n = v.size();
	int m = v[0].size();
	int ans = 0;
	int flag = 0;
	fr(i, 1, n){
		flag = 0;
		rep(j, m){
			if(v[i][j] - v[i-1][j] > 0){
				if(!flag) ans++;
				flag = 1;
			}
			else flag = 0;
		}
	}
	return ans;
}

vector<vi> gira(vector<vi> v){
	int n = v.size();
	int m = v[0].size();
	vector<vi> ans(m, vi(n));
	rep(i, m)
		rep(j, n) ans[i][j] = v[j][m - i - 1];

	return ans;
}

int mark[MAXN][MAXN];
int r, c;
vector<vi> v;
int m_x[] = {1, -1, 0, 0};
int m_y[] = {0, 0, 1, -1};
void dfs(int i, int j){
	mark[i][j] = 1;
	rep(l, 4){
		int i1 = i + m_x[l];
		int j1 = j + m_y[l];
		if(i1 < 0 || i1 >= r || j1 < 0 || j1 >= c || mark[i1][j1] || v[i1][j1] != v[i][j]) continue;
		dfs(i1, j1);
	}
}
int main(){
	ios::sync_with_stdio(false);	
	cin >> r >> c;
	v = vector<vi> (r, vi(c));
	rep(i, r)
		rep(j, c) cin >> v[i][j];
	int ans = 5;

	rep(i, 4){
		ans += f(v);
		v = gira(v);
	}
	rep(i, r) rep(j, c)
			if(!mark[i][j])
				dfs(i, j), ans++;

	cout << ans << endl;

}