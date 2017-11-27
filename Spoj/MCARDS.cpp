#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

int sort_cards(vi v){
	if(v.size() <= 1) return 0;
	int dp[v.size()+1][401];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= v.size(); i++){
		for(int j = 1; j <= 400; j++) {
			if(v[i-1] == j){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return v.size() - dp[v.size()][400];
}

int f(vector<int> &p, int mask, vector<pair<int, int> > &cards){
	if(p.size() == 4){
		vi v;
		for(int i = 0; i < cards.size(); i++){
			for(int j = 0, aux = 0; j < 4; j++, aux += 100){
				if(cards[i].first == p[j])
					v.push_back(cards[i].second+aux);
			}
		}
		return sort_cards(v);
	}
	else{
		int ans = 1e9;
		for(int i = 1; i <= 4; i++){
			if(mask & (1 << i)) continue;
			p.push_back(i);
			ans = min(ans, f(p, mask | (1 << i), cards));
			p.pop_back();
		}
		return ans;
	}
}
int main(){
	ios::sync_with_stdio(false);	
	int C, N;
	cin >> C >> N;
	vector<pair<int, int> > cards;
	for(int i = 0; i < C*N; i++){
		int x, y;
		cin >> x >> y;
		cards.push_back({x, y});
	}
	vi v;
	cout <<	f(v , 0, cards) << endl;

}