#include<bits/stdc++.h>
using namespace std;
int M[51][51][51];
int m[51][51][51][51];

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		memset(m, 0, sizeof(m));
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int l = 0; l < n; l++)
					scanf("%d", &M[i][j][l]);

		int ans = 0;
		for(int h = 0; h < n; h++){
			for(int i = n-1; i >= 0; i--)
				for(int j = n-1; j >= 0; j--)
					for(int l = n-1; l >= 0; l--){
						if(h == 0)
							m[i][j][l][h] = M[i][j][l];
						else if(i + h >= n || j + h >= n)
							m[i][j][l][h] = ( 1 << 30); 
						else{
							for(int i1 = i; i1 <= i+h; i1++)
								m[i][j][l][h] = max(m[i][j][l][h], M[i1][j][l]);
							for(int j1 = j; j1 <= j+h; j1++)
								m[i][j][l][h] = max(m[i][j][l][h], M[i][j1][l]);
							m[i][j][l][h] = max(m[i][j][l][h], m[i+1][j+1][l][h-1]);
						}
					}
		}
		for(int h = 0; h < n; h++){
			ans = 0;
			for(int i = 0; i+h < n; i++)
				for(int j = 0; j+h < n; j++)
					for(int l = 0; l+h < n; l++){
						int ma = 0;
						for(int l1 = l; l1 <= l+h; l1++){
							ma = max(ma, m[i][j][l1][h]);
						}
						ans += (ma == h+1);
					}
			printf("%d ", ans);
		}
		printf("\n");
	}
}