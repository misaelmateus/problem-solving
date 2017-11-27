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
#define readFast ios::sync_with_stdio(false)
using namespace std;

int main(){
	readFast;
	int N;
	cin >> N;
	ll ti = 0;
	ll si, di, k;
	for(int i = 0; i < N; i++){
		cin >> si >> di;
		if(ti - si < 0)
			ti = si;
		else {
			 k = max(0LL, (ti - si)/di + 1LL);
			 ti = si + di*k;
			}
	}

	cout << ti << "\n";
}