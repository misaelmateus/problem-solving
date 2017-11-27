//   Author : Misael Mateus 
//   Submission date: 2017-07-05 18:37:58
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)

#define L 1000000007LL
#define MAXN 100010
using namespace std;
ll hS[MAXN], hT[MAXN]; // hash
ll pow29[MAXN];
int n, m, x;
string s, t;


int dp[MAXN][40];

int lcp(int i, int j){
	int l = 0, r = 1 + min(n - i, m - j);
	while(r - l > 1){
		int middle = (l + r) >> 1;

		ll a = hS[i+middle-1];
		if(i > 0) a -= hS[i-1];
		a = ((a+L) * pow29[max(0, j - i)]) % L;

		ll b = hT[j+middle-1];
		if(j > 0) b -= hT[j-1];
		b = ((b+L) * pow29[max(0, i - j)]) % L;

		if(a == b)
			l = middle;
		else r = middle;
	}
	return l;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> s >> m >> t >> x;

	pow29[0] = 1LL;
	fr(i, 1, MAXN) pow29[i] = (pow29[i-1] * 29LL) % L;

	rep(i, n)
		hS[i] = ((i > 0 ? hS[i-1] : 0) + pow29[i] * (ll)(s[i] - 'a')) % L;
	rep(i, m)
		hT[i] = ((i > 0 ? hT[i-1] : 0) + pow29[i] * (ll)(t[i] - 'a')) % L;
	
	dp[0][1] = lcp(0, 0)-1;
	
	rep(i, n){
		rep(cnt, x+1){
			dp[i+1][cnt] = max(dp[i+1][cnt], dp[i][cnt]);
			int l = lcp(i+1, dp[i][cnt]+1);
			dp[i+l][cnt+1] = max(dp[i+l][cnt+1], dp[i][cnt]+l);
		}
	}
	int ans = 0;
	rep(cnt, x+1){
		ans |= (dp[n-1][cnt] == m-1);
	}

	cout << (ans == 1 ? "YES\n" : "NO\n");
	return 0;	
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)

#define L 1000000007LL
#define MAXN 100010
using namespace std;
ll hS[MAXN], hT[MAXN]; // hash
ll pow29[MAXN];
int n, m, x;
string s, t;


int dp[MAXN][40];

int lcp(int i, int j){
	int l = 0, r = 1 + min(n - i, m - j);
	while(r - l > 1){
		int middle = (l + r) >> 1;

		ll a = hS[i+middle-1];
		if(i > 0) a -= hS[i-1];
		a = ((a+L) * pow29[max(0, j - i)]) % L;

		ll b = hT[j+middle-1];
		if(j > 0) b -= hT[j-1];
		b = ((b+L) * pow29[max(0, i - j)]) % L;

		if(a == b)
			l = middle;
		else r = middle;
	}
	return l;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> s >> m >> t >> x;

	pow29[0] = 1LL;
	fr(i, 1, MAXN) pow29[i] = (pow29[i-1] * 29LL) % L;

	rep(i, n)
		hS[i] = ((i > 0 ? hS[i-1] : 0) + pow29[i] * (ll)(s[i] - 'a')) % L;
	rep(i, m)
		hT[i] = ((i > 0 ? hT[i-1] : 0) + pow29[i] * (ll)(t[i] - 'a')) % L;
	
	dp[0][1] = lcp(0, 0)-1;
	
	rep(i, n){
		rep(cnt, x+1){
			dp[i+1][cnt] = max(dp[i+1][cnt], dp[i][cnt]);
			int l = lcp(i+1, dp[i][cnt]+1);
			dp[i+l][cnt+1] = max(dp[i+l][cnt+1], dp[i][cnt]+l);
		}
	}
	int ans = 0;
	rep(cnt, x+1){
		ans |= (dp[n-1][cnt] == m-1);
	}

	cout << (ans == 1 ? "YES\n" : "NO\n");
	return 0;	
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)

#define L 1000000007LL
#define MAXN 100010
using namespace std;
ll hS[MAXN], hT[MAXN]; // hash
ll pow29[MAXN];
int n, m, x;
string s, t;


int dp[MAXN][40];

int lcp(int i, int j){
	int l = 0, r = 1 + min(n - i, m - j);
	while(r - l > 1){
		int middle = (l + r) >> 1;

		ll a = hS[i+middle-1];
		if(i > 0) a -= hS[i-1];
		a = ((a+L) * pow29[max(0, j - i)]) % L;

		ll b = hT[j+middle-1];
		if(j > 0) b -= hT[j-1];
		b = ((b+L) * pow29[max(0, i - j)]) % L;

		if(a == b)
			l = middle;
		else r = middle;
	}
	return l;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> s >> m >> t >> x;

	pow29[0] = 1LL;
	fr(i, 1, MAXN) pow29[i] = (pow29[i-1] * 29LL) % L;

	rep(i, n)
		hS[i] = ((i > 0 ? hS[i-1] : 0) + pow29[i] * (ll)(s[i] - 'a')) % L;
	rep(i, m)
		hT[i] = ((i > 0 ? hT[i-1] : 0) + pow29[i] * (ll)(t[i] - 'a')) % L;
	
	dp[0][1] = lcp(0, 0)-1;
	
	rep(i, n){
		rep(cnt, x+1){
			dp[i+1][cnt] = max(dp[i+1][cnt], dp[i][cnt]);
			int l = lcp(i+1, dp[i][cnt]+1);
			dp[i+l][cnt+1] = max(dp[i+l][cnt+1], dp[i][cnt]+l);
		}
	}
	int ans = 0;
	rep(cnt, x+1){
		ans |= (dp[n-1][cnt] == m-1);
	}

	cout << (ans == 1 ? "YES\n" : "NO\n");
	return 0;	
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)

#define L 1000000007LL
#define MAXN 100010
using namespace std;
ll hS[MAXN], hT[MAXN]; // hash
ll pow29[MAXN];
int n, m, x;
string s, t;


int dp[MAXN][40];

int lcp(int i, int j){
	int l = 0, r = 1 + min(n - i, m - j);
	while(r - l > 1){
		int middle = (l + r) >> 1;

		ll a = hS[i+middle-1];
		if(i > 0) a -= hS[i-1];
		a = ((a+L) * pow29[max(0, j - i)]) % L;

		ll b = hT[j+middle-1];
		if(j > 0) b -= hT[j-1];
		b = ((b+L) * pow29[max(0, i - j)]) % L;

		if(a == b)
			l = middle;
		else r = middle;
	}
	return l;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> s >> m >> t >> x;

	pow29[0] = 1LL;
	fr(i, 1, MAXN) pow29[i] = (pow29[i-1] * 29LL) % L;

	rep(i, n)
		hS[i] = ((i > 0 ? hS[i-1] : 0) + pow29[i] * (ll)(s[i] - 'a')) % L;
	rep(i, m)
		hT[i] = ((i > 0 ? hT[i-1] : 0) + pow29[i] * (ll)(t[i] - 'a')) % L;
	
	dp[0][1] = lcp(0, 0)-1;
	
	rep(i, n){
		rep(cnt, x+1){
			dp[i+1][cnt] = max(dp[i+1][cnt], dp[i][cnt]);
			int l = lcp(i+1, dp[i][cnt]+1);
			dp[i+l][cnt+1] = max(dp[i+l][cnt+1], dp[i][cnt]+l);
		}
	}
	int ans = 0;
	rep(cnt, x+1){
		ans |= (dp[n-1][cnt] == m-1);
	}

	cout << (ans == 1 ? "YES\n" : "NO\n");
	return 0;	
}