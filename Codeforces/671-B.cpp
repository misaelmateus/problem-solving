//   Author : Misael Mateus 
//   Submission date: 2016-05-12 19:38:22
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int c[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	sort(c, c+n);
	ll media1 = 0LL, media2;
	for(int i = 0; i < n; i++)
		media1 += (ll)c[i];
	media2 = (media1%(ll)n) ? (media1/(ll)n + 1LL): media1/(ll)n;
	media1 /= (ll)n;
	int i  = c[0];
	int j = media1+1;
	while(j - i > 1)
	{
		int middle = (i+j) / 2;
		ll cont = 0LL;
		for(int l = 0; l < n; l++){
			if(c[l] > middle)
			break;
			cont += (ll) middle - c[l]; 
		}
		if(cont > k)
			j = middle;
		else
			i = middle;
	}
	int first = i;
	i = media2 - 1;
	j = c[n-1];
	while(j - i > 1)
	{
		int middle = (i+j) / 2;
		ll cont = 0LL;
		for(int l = n-1; l >= 0; l--){
			if(c[l] < middle)
				break;
			cont += (ll) c[l] - middle; 
		}
		if(cont > k)
			i = middle;
		else
			j = middle;
	}
	int last = j;
	printf("%d\n", last - first);
	return 0;
}
