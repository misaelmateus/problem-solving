//   Author : Misael Mateus 
//   Submission date: 2017-10-30 21:59:39
#include<bits/stdc++.h>

#define getcx getchar
#define pc(x) putchar_unlocked(x)
using namespace std ;
 
bool read( int &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar(); 
    if( c == EOF) { n = -1; return false; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true; 
} 
 
#define MAXN 4010
#define MAXK 810

int dp[MAXN][MAXK];
int A[MAXN][MAXN];
int pre[MAXN][MAXN];
int v[MAXN][MAXN];

int calc(int i, int j, int l_min, int l_max){
	int l_ans = -1;
	dp[i][j] = 1e8;
	l_max = min(l_max, i);
	for(int l = l_min; l <= l_max; l++){
		if(dp[i][j] > (l > 0 ? dp[l-1][j-1] : 0) + A[l][i])
			dp[i][j] = (l > 0 ? dp[l-1][j-1] : 0) + A[l][i], l_ans = l;
	}
	return l_ans;
}

void divide_conquer(int i1, int i2, int j, int l_min, int l_max){
	if(i1 > i2) return;
	int mid = (i1 + i2) >> 1;
	int l = calc(mid, j, l_min, l_max);
	if(i1 == i2) return;
	divide_conquer(i1, mid-1, j, l_min, l);
	divide_conquer(mid+1, i2, j, l, l_max);
}
int main(){
	int n, m;
	read(n);
	read(m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			read(pre[i][j]);
			if(j) pre[i][j] += pre[i][j-1];
		}

	for(int i = n-1; i >= 0; i--){
		for(int j = i; j < n; j++){
			if(i == j) A[i][j] = 0;
			else A[i][j] = A[i+1][j] + pre[i][j] - pre[i][i];
		}
	}
	for(int i = 0; i <= n; i++)
		dp[i][0] = 1e8;
	for(int j = 1; j <= m; j++)
		divide_conquer(0, n-1, j, 0, n-1);
	cout << dp[n-1][m] << "\n";
}