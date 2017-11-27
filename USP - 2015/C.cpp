#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int Maxd = 3;

struct matrix {
	ld m[Maxd][Maxd];
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
					c.m[i][j] = (c.m[i][j] + (ld)(m[i][k]) * b.m[k][j]);
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
	ios::sync_with_stdio(false);	
	int T;
	cin >> T;
	while(T--){
		int n;
		ld alfa, l;
		cin >> alfa >> l >> n;
		matrix c(0);
		c.m[0][0] = c.m[1][1] = cos(M_PI * alfa / 180.0);
		c.m[0][1] = c.m[1][0] = sin(M_PI * alfa / 180.0);
		c.m[0][1] = -c.m[0][1];
		c.m[0][2] = (ld)(l);
		c.m[2][2] = 1.0;

		c = toPower(c, n);
		ld x = c.m[0][2];
		ld y = c.m[1][2];
		cout << fixed << setprecision(5) << x << " " << y << endl;
	}
}
