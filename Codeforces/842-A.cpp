//   Author : Misael Mateus 
//   Submission date: 2017-08-29 20:25:01
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l, r, x, y, p;
	scanf("%d %d %d %d %d", &l, &r, &x, &y, &p);
	for(int k = l; k <= r; k++){
		if(k % p ) continue;
		int b = k / p;
		if(b >= x && b <= y) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}