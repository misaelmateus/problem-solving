#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)

using namespace std;
int main(){
	int n;
	cin >> n;
	int m[n][n];
	rep(i, n) rep(j, n) cin >> m[i][j];

	rep(i, n)
		rep(j, n){
			if(m[i][j] == 1)
				continue;
			int ok = 0;
			rep(l, n)
				rep(r, n)
					if(m[i][l] + m[r][j] == m[i][j])
						ok = 1;
			if(!ok){
				cout << "No\n";
				return 0;
			}
		}

	cout << "Yes\n";
	return 0;
}