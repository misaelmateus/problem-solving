//   Author : Misael Mateus 
//   Submission date: 2016-05-02 15:27:59
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int tot = (n/3)*2;
	n %= 3;
	if(n > 0)
		tot++;
	printf("%d\n", tot);
	return 0;
}
