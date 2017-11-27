#include<bits/stdc++.h>
#define ld long double
using namespace std;

ld pc[8][70][70], pg[70][70];

int id[8][70];
int ind[8][70];
int main()
{
	int n;
	cin >> n;
	int t = (1 << n);
	for(int i = 1; i <= t; i++)
		for(int j = 1; j <= t; j++){
			cin >> pg[i][j];
			pg[i][j] /= (ld)100.0;
		}

	for(int i = 1; i <= t; i++)
		pc[1][i][(i+1)/2] = (ld)1.0, ind[1][i] = (i + 1)/2, ind[0][i] = i;

	for(int k = 1; k < n; k++)
		for(int i = 1; i <= t; i++){
			for(int l = 1; l<= (1 << (n - k)); l++){
				ind[k+1][i] = (ind[k][i]+1)/2;
				ld a = 0.0;
				for(int j = 1; j <= t; j++)
					a += pc[k][j][l] * pg[i][j] * (ind[k-1][i] != ind[k-1][j]);
				pc[k+1][i][(l+1)/2] += a * pc[k][i][l];
			}
		}
	
	
	for(int k = n; k >= 1; k--){
		for(int l = 1; l <= (1 << (n - k)); l++){
			if(!id[k][l]){
				int p = -1;
				ld ma = -1;
				for(int i = 1; i <= t; i++){
					ld a = 0;
					for(int j  =1; j <= t; j++)
						a+= pc[k][j][l] * pg[i][j] * (ind[k-1][i] != ind[k-1][j]);
					a *= pc[k][i][l];
					if(a > ma)
						ma = a , p = i;
				}
				id[k][l] = p;
			}

			if(k > 1){
				if(ind[k-1][id[k][l]] == 2*l)
					id[k-1][2*l] = id[k][l];
				else id[k-1][2*l - 1] = id[k][l];
			}
		}
		
	}

	ld ans = 0;
	for(int k = 1; k <= n; k++)
		for(int l = 1; l <= (1 << (n -k)); l++){
			ld a = (ld)0.0;
			for(int j  =1; j <= t; j++){
				a += pc[k][j][l] * pg[id[k][l]][j] * (ind[k-1][id[k][l]] != ind[k-1][j]);
			}
			ans += a*(1 << (k-1)) * pc[k][id[k][l] ][l];
		}

	cout << fixed << setprecision(12) << ans << endl;
}