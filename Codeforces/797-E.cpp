//   Author : Misael Mateus 
//   Submission date: 2017-04-16 22:42:26
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int v[n+1];

	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	int n1 = (int)(sqrt(n) + 0.000000001);

	int dp[n1][n+1];

	for(int i = 1; i < n1; i++){
		for(int j = n; j > 0; j--){
			if(j + v[j] + i > n)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + dp[i][j+v[j] + i];
		}
	}

	int q;
	scanf("%d", &q);
	while(q--){
		int p, k;
		scanf("%d %d", &p, &k);

		if(k < n1){
			printf("%d\n", dp[k][p]);
		}
		else{
			int cont = 0;
			while(p <= n){
				p = p+v[p] + k;
				cont++;
			}
			printf("%d\n", cont);
		}
	}

	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int v[n+1];

	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	int n1 = (int)(sqrt(n) + 0.000000001);

	int dp[n1][n+1];

	for(int i = 1; i < n1; i++){
		for(int j = n; j > 0; j--){
			if(j + v[j] + i > n)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + dp[i][j+v[j] + i];
		}
	}

	int q;
	scanf("%d", &q);
	while(q--){
		int p, k;
		scanf("%d %d", &p, &k);

		if(k < n1){
			printf("%d\n", dp[k][p]);
		}
		else{
			int cont = 0;
			while(p <= n){
				p = p+v[p] + k;
				cont++;
			}
			printf("%d\n", cont);
		}
	}

	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int v[n+1];

	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	int n1 = (int)(sqrt(n) + 0.000000001);

	int dp[n1][n+1];

	for(int i = 1; i < n1; i++){
		for(int j = n; j > 0; j--){
			if(j + v[j] + i > n)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + dp[i][j+v[j] + i];
		}
	}

	int q;
	scanf("%d", &q);
	while(q--){
		int p, k;
		scanf("%d %d", &p, &k);

		if(k < n1){
			printf("%d\n", dp[k][p]);
		}
		else{
			int cont = 0;
			while(p <= n){
				p = p+v[p] + k;
				cont++;
			}
			printf("%d\n", cont);
		}
	}

	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int v[n+1];

	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	int n1 = (int)(sqrt(n) + 0.000000001);

	int dp[n1][n+1];

	for(int i = 1; i < n1; i++){
		for(int j = n; j > 0; j--){
			if(j + v[j] + i > n)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + dp[i][j+v[j] + i];
		}
	}

	int q;
	scanf("%d", &q);
	while(q--){
		int p, k;
		scanf("%d %d", &p, &k);

		if(k < n1){
			printf("%d\n", dp[k][p]);
		}
		else{
			int cont = 0;
			while(p <= n){
				p = p+v[p] + k;
				cont++;
			}
			printf("%d\n", cont);
		}
	}

	return 0;
}