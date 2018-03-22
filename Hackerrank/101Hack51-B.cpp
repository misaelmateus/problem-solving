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
int n, m, k;
int d(ii a){
	int d = 0;
	if(a.second == 0)
		d = a.first;
	else if(a.second == n)
		d = 2*n + (n - a.first);
	else if(a.first == 0){
		d = 3*n + (n - a.second);
	}
	else{
		d = n + a.second;
	}
	return d;
}

int main(){
	ios::sync_with_stdio(false);	
	cin >> n >> m >> k;
	int cont = 1, tot = 0, ans = 1e9;
	int x, y;
	vector<int> v(m);
	rep(i, m){
		cin >> x >> y;
		v[i] = d({x, y});
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < m; i++)
		v.push_back(4*n+v[i]);
	for(int i = k-1; i < v.size(); i++){
		ans = min(ans, v[i] - v[i-k+1]);
	}

	cout << ans << "\n";
}