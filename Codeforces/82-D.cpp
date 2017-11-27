//   Author : Misael Mateus 
//   Submission date: 2017-09-10 21:24:11
#include<bits/stdc++.h>
#define MAXN 1010
using namespace std;
int dp[MAXN][MAXN];
int v[MAXN];
int Min(int a, int b, int c){
	return min(a, min(b, c));
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &v[i]);

	for(int i = 0; i < n; i++) dp[n][i] = dp[n+1][i] = v[i];
	for(int i = n-1; i > 0; i--)
		for(int j = 0; j < i; j++){
			dp[i][j] = Min(dp[i+2][j] + max(v[i], v[i+1]),
						   dp[i+2][i] + max(v[j], v[i+1]),
						   dp[i+2][i+1] + max(v[j], v[i]));
		}
	printf("%d\n", dp[1][0]);
	int j = 0;
	int i = 1;
	while(i < n){
		if(dp[i][j] == dp[i+2][i+1] + max(v[j], v[i])){
			printf("%d %d\n", j+1, i+1);
			j = i+1;
		}
		else if(dp[i][j] == dp[i+2][i] + max(v[j], v[i+1])){
			printf("%d ", j+1);
			if(i+1 < n) printf("%d", i+2);
			printf("\n");
			j = i;
		}
		else if(dp[i][j] == dp[i+2][j] + max(v[i], v[i+1])){
			printf("%d ", i+1);
			if(i+1 < n) printf("%d", i+2);
			printf("\n");
		}
		i+=2;
	}
	if(j < n)
		printf("%d\n", j+1);

}
#include<bits/stdc++.h>
#define MAXN 1010
using namespace std;
int dp[MAXN][MAXN];
int v[MAXN];
int Min(int a, int b, int c){
	return min(a, min(b, c));
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &v[i]);

	for(int i = 0; i < n; i++) dp[n][i] = dp[n+1][i] = v[i];
	for(int i = n-1; i > 0; i--)
		for(int j = 0; j < i; j++){
			dp[i][j] = Min(dp[i+2][j] + max(v[i], v[i+1]),
						   dp[i+2][i] + max(v[j], v[i+1]),
						   dp[i+2][i+1] + max(v[j], v[i]));
		}
	printf("%d\n", dp[1][0]);
	int j = 0;
	int i = 1;
	while(i < n){
		if(dp[i][j] == dp[i+2][i+1] + max(v[j], v[i])){
			printf("%d %d\n", j+1, i+1);
			j = i+1;
		}
		else if(dp[i][j] == dp[i+2][i] + max(v[j], v[i+1])){
			printf("%d ", j+1);
			if(i+1 < n) printf("%d", i+2);
			printf("\n");
			j = i;
		}
		else if(dp[i][j] == dp[i+2][j] + max(v[i], v[i+1])){
			printf("%d ", i+1);
			if(i+1 < n) printf("%d", i+2);
			printf("\n");
		}
		i+=2;
	}
	if(j < n)
		printf("%d\n", j+1);

}
#include<bits/stdc++.h>
#define MAXN 1010
using namespace std;
int dp[MAXN][MAXN];
int v[MAXN];
int Min(int a, int b, int c){
	return min(a, min(b, c));
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &v[i]);

	for(int i = 0; i < n; i++) dp[n][i] = dp[n+1][i] = v[i];
	for(int i = n-1; i > 0; i--)
		for(int j = 0; j < i; j++){
			dp[i][j] = Min(dp[i+2][j] + max(v[i], v[i+1]),
						   dp[i+2][i] + max(v[j], v[i+1]),
						   dp[i+2][i+1] + max(v[j], v[i]));
		}
	printf("%d\n", dp[1][0]);
	int j = 0;
	int i = 1;
	while(i < n){
		if(dp[i][j] == dp[i+2][i+1] + max(v[j], v[i])){
			printf("%d %d\n", j+1, i+1);
			j = i+1;
		}
		else if(dp[i][j] == dp[i+2][i] + max(v[j], v[i+1])){
			printf("%d ", j+1);
			if(i+1 < n) printf("%d", i+2);
			printf("\n");
			j = i;
		}
		else if(dp[i][j] == dp[i+2][j] + max(v[i], v[i+1])){
			printf("%d ", i+1);
			if(i+1 < n) printf("%d", i+2);
			printf("\n");
		}
		i+=2;
	}
	if(j < n)
		printf("%d\n", j+1);

}
#include<bits/stdc++.h>
#define MAXN 1010
using namespace std;
int dp[MAXN][MAXN];
int v[MAXN];
int Min(int a, int b, int c){
	return min(a, min(b, c));
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &v[i]);

	for(int i = 0; i < n; i++) dp[n][i] = dp[n+1][i] = v[i];
	for(int i = n-1; i > 0; i--)
		for(int j = 0; j < i; j++){
			dp[i][j] = Min(dp[i+2][j] + max(v[i], v[i+1]),
						   dp[i+2][i] + max(v[j], v[i+1]),
						   dp[i+2][i+1] + max(v[j], v[i]));
		}
	printf("%d\n", dp[1][0]);
	int j = 0;
	int i = 1;
	while(i < n){
		if(dp[i][j] == dp[i+2][i+1] + max(v[j], v[i])){
			printf("%d %d\n", j+1, i+1);
			j = i+1;
		}
		else if(dp[i][j] == dp[i+2][i] + max(v[j], v[i+1])){
			printf("%d ", j+1);
			if(i+1 < n) printf("%d", i+2);
			printf("\n");
			j = i;
		}
		else if(dp[i][j] == dp[i+2][j] + max(v[i], v[i+1])){
			printf("%d ", i+1);
			if(i+1 < n) printf("%d", i+2);
			printf("\n");
		}
		i+=2;
	}
	if(j < n)
		printf("%d\n", j+1);

}
