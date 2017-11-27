#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 1000010
using namespace std;

vector<ll> dp(7, -(1LL<<60));

int main(){
	ios::sync_with_stdio(false);	
	int n;
	cin >> n;
	dp[0] = 0LL;
	rep(i, n){
		ll u;
		cin >> u;
		vector<ll> dp1(7, 0LL);
		rep(j, 7){
			dp1[j] = max(u + dp[((j - u%7 + 7) % 7)], dp[j]);
		}

		dp = dp1;
	}

	cout << dp[0] << endl;
}