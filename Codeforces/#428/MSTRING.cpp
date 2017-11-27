#include<bits/stdc++.h>
#define MAXN 1001
using namespace std;
int dp[MAXN][MAXN];
vector<int> pos[30];
int main(){
	string a, b;
	cin >> a >> b;
	for(int i = 0; i < b.size(); i++) pos[b[i] - 'a'].push_back(i);
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = (i > 0 ? dp[i-1][j] : 0);
			int x = -1;
			int pos = j;
			if(j > 0){
				x = s[i] - 'a';
				pos = (lower_bound(pos[x].begin(), pos[x].end(), j) - pos[x].begin());
				pos--;
			}
			dp[i][j] = max(dp[i][j], 1 + (i > 0 ?dp[i-1][pos] : 0));
		}
	}

	cout << dp[a.size()-1][b.size()] << "\n";
}