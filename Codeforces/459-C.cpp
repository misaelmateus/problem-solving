//   Author : Misael Mateus 
//   Submission date: 2017-03-11 03:36:28
#include<bits/stdc++.h>
#define MAXN 1010
using namespace std;
int ans[MAXN][MAXN];
int k, D, flag;
void f(int i, int j, int d){
	if(i == j)
		return;
	if(d == D){
		flag = 1;
		return;
	}

	int x = max(1, (j - i + 1)/k + ((j - i + 1) % k != 0));

	for(int a = i; a <= j; a += x){
		for(int b = 0; b < x && a + b <= j; b++)
			ans[a+b][d] = (a - i)/x + 1;
		f(a, min(a+x-1, j), d+1);
	}
}


int main(){
	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXN; j++)
			ans[i][j] = 1;
	int n;
	cin >> n >> k >> D;

	f(0, n-1, 0);
	if(flag)
		cout << -1 << endl;
	else 
	for(int i = 0; i < D; i++){
		for(int j = 0; j < n; j++)
			cout << ans[j][i] << " ";
		cout << endl;
	}
}