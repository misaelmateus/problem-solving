//   Author : Misael Mateus 
//   Submission date: 2017-09-17 19:38:01
#include<bits/stdc++.h>
#define MAXN 70010
#define P 1610612741LL
#define ll long long
using namespace std;

map<ll, int> cont;
char s[MAXN][10];
int main(){
	int n;
	scanf("%d", &n);
	for(int k = 0; k < n; k++){
		scanf(" %s", s[k]);

		for(int i = 0; i < 9; i++){
			ll num = 1LL;
			for(int j = i; j < 9; j++){
				num = num*10LL + (ll)(s[k][j] - '0');
				int val = cont[num];
				if(val != 0 && val != k+1)
					cont[num] = -1;
				else cont[num] = k+1;
			}
		}
	}

	for(int k = 0; k < n; k++){
		int me = 10, i_min = 0, j_min = 0;
		for(int i = 0; i < 9; i++){
			ll num = 1LL;
			for(int j = i; j < 9 && j - i + 1 < me; j++){
				num = num*10LL + (ll)(s[k][j] - '0');
				//cout << k <<" " << i <<" " << j << " " << num <<" " << cont[num] << endl;
				if(cont[num] == k+1)
					me = j - i + 1, i_min = i, j_min = j;
			}
		}
		for(int i = i_min; i <= j_min; i++)
			printf("%c", s[k][i]);
		printf("\n");
	}
}