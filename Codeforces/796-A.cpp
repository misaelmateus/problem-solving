//   Author : Misael Mateus 
//   Submission date: 2017-04-10 22:08:40
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	m--;
	int v[n];

	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	int D = n;
	for(int i = m-1; i >= 0; i--)
		if(v[i] && v[i] <= k)
			D = min(D, m - i);

	for(int i = m+1; i < n; i++)
		if(v[i] && v[i] <= k)
			D = min(D, i - m);

	printf("%d\n", D*10);
	return 0;
}