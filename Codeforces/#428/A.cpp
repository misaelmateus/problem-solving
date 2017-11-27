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



int main(){
	ios::sync_with_stdio(false);	
	int n, tot = 0, k;
	cin >> n >> k;

	rep(i, n){
		int u;
		cin >> u;
		tot += u;
		int a = min(8, tot);
		k -= a;
		tot -= a;
		if(k <= 0){
			cout << i+1 << endl;
			return 0;
		}

	}
	cout << -1 << endl;
	return 0;

}