#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
vi perm(vi a, vi b){
	vi c(a.size());
	for(int i = 0; i < a.size(); i++) c[i] = a[b[i]-1];
	return c;
}
vi exp(vi v, int m){
	vi a(v.size());
	for(int i = 0; i < v.size(); i++) a[i] = i+1;
	while(m > 0){
		if(m & 1) a = perm(a, v);
		m >>= 1;
		v = perm(v, v);
	}
	return a;
}
int main(){
	int n, m;
	while(scanf("%d %d", &n, &m) && n){
		vi v(n);
		char s[n], s1[n];
		for(int i = 0; i < n; i++) scanf("%d", &v[i]);
		scanf(" %[^\n]", s);

		v = exp(v, m);
		for(int i = 0; i < n; i++)
			printf("%d\n", v[i]);
		printf("\n");
	}
		
	return 0;
}	