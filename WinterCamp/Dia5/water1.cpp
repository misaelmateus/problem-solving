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
int k, n;
int dfs(int i, int j){
	if(mark[i][j] || s[i][j] != '.') return 0;
	mark[i][j] = 1;
    if( i >= n)  return 0;
	
	if ( k ) dfs(i+1, j);
if (( s[i+1][j] == '#' )  || (s[i+1][j] =='*') ) if (   s[i][j] =='.' && k) s[i][j] = '*',k--;
   if((s[i+1][j] == '*'  || (s[i+1][j] =='#'))  && j-1 >= 0 && (s[i][j-1] =='#') && k)
	dfs(i, j-1);
if((s[i+1][j] == '*'  || (s[i+1][j] =='#'))   && j+1 < n && (s[i][j+1] =='#') && k)
	dfs(i, j+1);
	return 0;
}

int main(){
	ios::sync_with_stdio(false);	
	
	cin >> n;
	rep(i, n) cin >> s[i];
	cin >> k;
	for(int i = n-1; i > 0 && k > 0; i--)
			dfs(0, i);
		
	rep(i, n) cout << s[i] << "\n";
	return 0;
}
