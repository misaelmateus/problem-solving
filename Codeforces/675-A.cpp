//   Author : Misael Mateus 
//   Submission date: 2016-05-16 21:38:10
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(((c != 0 ) && (b - a) % c == 0 && (b - a)/c >= 0) || (c == 0 && b == a) )
		printf("YES\n");
	else
	printf("NO\n");
	return 0;
}
