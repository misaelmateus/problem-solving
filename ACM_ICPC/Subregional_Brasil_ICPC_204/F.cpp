#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int Maxd = 101;
const int mod = 10000;

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
	int N, M, S, T;
	scanf("%d %d %d %d", &N, &M, &S, &T);
	matrix m;
	S--, T--;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 4; j++){
			int aux;
			scanf("%d", &aux);
			m.m[i][aux-1] += 1;
		}
	}

	m = toPower(m, M);
	printf("%d\n", m.m[S][T]);
	
}