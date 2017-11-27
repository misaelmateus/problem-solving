#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fr(a, b, c) for(int a = (b); a < (c); a++)
#define rep(a, b) fr(a, 0, b);

using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int v[n], dp[n+1], sum[n+1];
	for(int i = 0; i < n; i++) scanf("%d", &v[i]);
	sum[n] = 0;
	dp[n] = 0;
	for(int i = n-1; i >= 0; i--) sum[i] = sum[i+1] + v[i];

	for(int i = n-1; i >= 0; i--) dp[i] = max(v[i] + sum[i+1] - dp[i+1], dp[i+1]);

	printf("%d %d\n", sum[0] - dp[0], dp[0]);

}