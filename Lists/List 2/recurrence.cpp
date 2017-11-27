// http://www.spoj.com/problems/REC/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int Maxd = 2;
int mod = 1000000007;

struct matrix {
	int m[Maxd][Maxd];
	matrix(int diag = 0) {
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				m[i][j] = diag * (i == j);
	}
	matrix operator*(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				for (int k = 0; k < Maxd; k++)
					c.m[i][j] = (c.m[i][j] + (ll)(m[i][k]) * b.m[k][j]) % mod;
		return c;
	}
};

matrix toPower(matrix A, ll p)
{
	matrix R(1);
	while (p) {
		if (p & 1ll) R = R * A;
		p >>= 1ll; A = A * A;
	}
	return R;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int a, b, N;
		cin >> a >> b >> N >> mod;

		matrix A(0);
		A.m[0][0] = a % mod;
		A.m[1][0] = b % mod;
		A.m[1][1] = 1 % mod;
		A = toPower(A, N);
		cout << (A.m[0][0] + A.m[1][0]) % mod << "\n";
	}	
}