//   Author : Misael Mateus 
//   Submission date: 2017-04-30 01:59:16
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	if(n*n < k){
		cout << "-1\n";
		return 0;
	}

	int m[n][n];
	memset(m, 0, sizeof(m));
	rep(i, n)
		rep(j, n){
			if(m[i][j] == 1)
				continue;
			if(i == j && k > 0)
				m[i][j] = 1, k--;
			else if(k > 1)
				m[i][j] = 1, m[j][i] = 1, k-= 2;
		}

	rep(i, n){
		rep(j, n) cout << m[i][j] << " ";
		cout << "\n";
	}

}