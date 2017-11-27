#include<bits/stdc++.h>
using namespace std;

int calc(int n){
	for(int i = 2; i*i <= n; i++)
		if(n % i == 0) return n/i;
	return 1;
}

map<int, int> dp;

int f(int n){
	if(n == 0) return 0;
	if(dp[n] != 0) return dp[n];
	int ans = calc(n);
	if(ans == 1) return dp[n] = ans;

	for(int i = n-2; i > 1; i--){
		int a = calc(i);
		ans = min(ans, a + f(n-i));
		if(a == 1)
			break;
	}

	return dp[n] = ans;
}
int main(){
	int n;
	cin >> n;
	if(n == 2)
		cout << 1 << endl;
	else if(n % 2 == 0) cout << 2 << endl;
	else{
		if(calc(n) == 1) cout << 1 << endl;
		else if(calc(n-2) == 1) cout << 2 << endl;
		else cout << 3 << endl;
	}

	return 0;
}