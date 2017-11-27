#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[100][10][2][2];
string s;
ll f(int i, int ult, int flag1, int flag2){
	if(i == s.size()) return 1LL;
	if(dp[i][ult][flag1][flag2] != -1) return dp[i][ult][flag1][flag2];
	ll ans = 0LL;
	if(!flag1){
		for(int j = 0; j <= (int)(s[i] - '0'); j++){
			if(j == s[i] - '0') ans += f(i+1, j, 0, flag2 | (j < ult));
			else{
				ans += f(i+1, j, 1, flag2 | (j < ult));
			}
		}
	}
	else{
		for(int j = 0; j < 10; j++){
			if(flag2 && j > ult) continue;

			ans += f(i+1, j, 1, flag2 | (j < ult));
		}
	}
	return dp[i][ult][flag1][flag2] = ans;
}

int check(string s){
	int flag = 0;
	for(int i = 1; i < s.size(); i++){
		if(s[i] < s[i-1]) flag = 1;
		if(s[i] > s[i-1] && flag) return 0;
	}
	return 1;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		memset(dp, -1, sizeof(dp));
		if(!check(s))
			cout << -1 << "\n";
		else cout << f(0, 0, 0, 0) - 1 << "\n";
	}
	return 0;
}