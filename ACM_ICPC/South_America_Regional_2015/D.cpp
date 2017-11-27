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
	int n, m, ans = 0;
	while(cin >> n >> m){
		ans = 0;
		int v[n], B;
		rep(i, m){
			cin >> B;
			int sum = 0;
			rep(j, n) cin >> v[j];
			rep(j, n) sum += v[j];
			if(sum <= B)
				ans -= v[0];
			int a = 10000;
			while(a > 0){
				if(a + sum - v[0] <= B){
					ans += a;
					break;
				}
				a /= 10;
			}
		}
		cout << ans << "\n";
	}	
}