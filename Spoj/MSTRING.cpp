#include<bits/stdc++.h>
#define MAXN 1001
using namespace std;
int dp[MAXN][MAXN];
vector<int> pos[30];
int main(){
	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXN; j++)
			dp[i][j] = -1e5;
	string a, b;
	cin >> a >> b;
	for(int i = 0; i < b.size(); i++) pos[b[i] - 'a'].push_back(i);
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j <= b.size(); j++){
			dp[i][j] = (i > 0 ? dp[i-1][j] : 1e5);
			if(j == 0) {
				dp[i][j] = 1;
				continue;
			}
			if(i == 0)
				continue;
			int l = 0, aux = 1;
			int x = (int)a[i] - 'a';
			auto it = lower_bound(pos[x].begin(), pos[x].end(), j);
			it--;
			if(it >= pos[x].begin()) l = *(it);
			else aux = 0;
			dp[i][j] = min(dp[i][j], aux + dp[i-1][l]);
			
		}
	}

	cout << dp[a.size()-1][b.size()] << "\n";
}