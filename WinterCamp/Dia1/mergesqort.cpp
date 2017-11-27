#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
using namespace std;
ll tot = 0LL;
map<int, ll> dp;
ll f(int a){
	if(a <= 1) return 0LL;
	if(dp[a]) return dp[a];

	int b = (int)sqrt(a)-1;
	while(b*b <= a) b++;
	b--;
	dp[a] = (ll)a + f(b) + f(a - b);
	return dp[a];
}
int main(){
	ios::sync_with_stdio(false);	
	int n;
	cin >> n;

	cout << f(n) << "\n";
}