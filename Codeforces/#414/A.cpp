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
	int n, a, b, p;
	cin >> p >> a >> b >> n;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	sort(v.begin(), v.end());
	int ans = 0;
	rep(i, n){
		if(v[i] > a && v[i] < b){
			ans++;
		}
	}
	cout << ans << "\n";
}