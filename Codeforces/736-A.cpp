//   Author : Misael Mateus 
//   Submission date: 2017-07-07 23:19:01
#include<bits/stdc++.h>
using namespace std;
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111


int main(){
	ios::sync_with_stdio(false);	
	ll n;
	cin >> n;

	ll dp[100];
	dp[0] = 1LL;
	dp[1] = 2LL;
	int i;
	int ans = 0;
	for(i = 2; dp[i-1] <= n; i++) dp[i] = dp[i-1] + dp[i-2];
	cout << i-2 << endl;


	return 0;
}