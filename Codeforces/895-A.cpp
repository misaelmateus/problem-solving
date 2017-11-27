//   Author : Misael Mateus 
//   Submission date: 2017-11-26 21:25:19
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
	int n;
	cin >> n;
	int v[n];
	rep(i, n){
		cin >> v[i];
	}
	int ans = 1000;
	rep(i, n)
		rep(j, n){
			int sum = 0;
			for(int l = i; l <= j; l++){
				sum += v[l];
			}
			ans = min(ans, abs(360 - 2*sum));
		}
	cout << ans << "\n";
	return 0;
}