// By Misael 
// 2016-04-29

#include<bits/stdc++.h>
#define lli long long
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	lli l[n];
	for(int i = 0; i < n; i++)
		scanf("%I64d", &l[i]);
	
	sort(l, l+n);
	lli maior = l[n-1];
	lli soma = 0LL;
	for(int i = 0; i < n-1; i++)
		soma += l[i];
	lli x = maior - soma + 1;
	printf("%I64d\n", x);
	
	return 0;
}
