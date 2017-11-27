//   Author : Misael Mateus 
//   Submission date: 2016-05-05 21:51:16
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int n_s = 2 * (n / 7), resto = n%7;
	int resp1 = n_s, resp2 = n_s;
	if(resto == 1)
		resp2 += 1;
	if(resto >= 2)
		resp2 += 2;
	if(resto == 6)
		resp1 += 1;
	printf("%d %d\n", resp1, resp2);
	return 0;
}
