//   Author : Misael Mateus 
//   Submission date: 2016-08-24 22:08:59
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, a;
	scanf("%d %d", &n, &a);
	int v[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	if( n == 1 ){
		printf("0\n");
		return 0;
	}
	if(n == 2 ){
		int resp = min( abs(a - v[0]), abs(a - v[1]) );
		printf("%d\n", resp);
		return 0;
	}
	
	sort(v, v+n);
	int resp = min( min( abs(a - v[0]) + v[n-2] - v[0], abs(a - v[n-2]) + v[n-2] - v[0]), min( abs(a - v[1]) + v[n-1] - v[1], abs(a - v[n-1]) + v[n-1] - v[1]) );
	printf("%d\n", resp);
	return 0;
}
