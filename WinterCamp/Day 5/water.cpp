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
using namespace std;

string s[40];
int mark[40][40];
int k;
int dfs(int i, int j){
	if(mark[i][j] || s[i][j] != '.') return 0;
	mark[i][j] = 1;
	dfs(i+1, j);
	dfs(i+1, j-1);
	dfs(i+1, j+1);
	dfs(i, j+1);
	dfs(i, j-1);
	if(i){
		dfs(i-1, j-1);
		dfs(i-1, j);
		dfs(i-1, j+1);
	}
}

int main(){
	ios::sync_with_stdio(false);	
	int n;
	cin >> n;
	rep(i, n) cin >> s[i];
	cin >> k;
	dfs(0, 1);	
	
	for(int i = n-2; i >= 0; i--)
		for(int j = n-1; j >= 0 && k; j--){
			if(mark[i][j])
				s[i][j] = '*', k--;
		}
	rep(i, n) cout << s[i] << "\n";
	return 0;
}