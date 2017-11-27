#include<bits/stdc++.h>
using namespace std;
int dp[10][10];
int main(){
	int T;
	cin >> T;
	while(T--){
		int ans = 1;
		int a, b;
		cin >> a >> b;
		for(int i = 0; i < a; i++ ) ans *= 26;
		for(int j = 0; j < b; j++) ans *= 10;
		if(!a && !b) ans = 0;
		cout << ans << endl;
	}

	return 0;
}