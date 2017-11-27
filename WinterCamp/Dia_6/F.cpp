#include<bits/stdc++.h>
#define ll long long
#define vvi vector<vector<int> >
#define vi vector<int>
const int Maxd = 16;
const int mod = 1000000009;
using namespace std;
int v[4][3];
int x[] = {1, 1, -1, -1, 2, 2, -2, -2};
int y[] = {2, -2, 2, -2, 1, -1, 1, -1};

map< vvi , int > mapa;


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
					c.m[i][j] = (c.m[i][j] + ll(m[i][k]) * b.m[k][j]) % mod;
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

	int cont = 0;

	for(int mask = 0; mask < (1 << 12); mask++){
		int flag = 1;
		for(int i =0; i < 4; i++)
			for(int j = 0; j < 3; j++){
				if(!(mask & (1 << (3*i + j)) )) continue;

				for(int l = 0; l < 8; l++){
					int i1 = i + x[l], j1 = j + y[l];
					if(i1 < 0 || j1 < 0 || i1 >= 4 || j1 >= 3)
						continue;
					int p = (1 << (3*i1 + j1));
					if(mask & p) flag = 0;
				}
			}
		cont += flag;
	}
	
	cout << cont << endl;
}