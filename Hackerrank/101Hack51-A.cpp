#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111
using namespace std;

vi gr[MAXN];


int main(){
	ios::sync_with_stdio(false);	
	ll A, B, a;
	cin >> A >> B >> a;
	cout << (a*B)/A << "\n";

	dfs(1);
}