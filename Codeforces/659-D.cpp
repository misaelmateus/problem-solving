//   Author : Misael Mateus 
//   Submission date: 2016-05-16 16:50:47
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int x[n+1], y[n+1];
	for(int i = 0; i < n+1; i++)
		scanf("%d %d", &x[i], &y[i]);
	
	
	int ini = 0;
	for(int i = 1; i < n; i++)
		if(y[i] < y[ini] || (y[i] == y[ini] && x[i] < x[ini]) )
			ini = i;
	int dir = 2;
	int cont = 0;
	for(int i = 2; i <= n; i++)
	{
		int ult = (ini + i-1) % (n);
		int atual = (ini +i) % n;
		int dir_at = 0;
		if(x[atual] - x[ult] > 0)
			dir_at += 1;
		if(x[atual] - x[ult] < 0)
			dir_at -= 1;
			
		if(y[atual] - y[ult] > 0)
			dir_at += 2;
		if(y[atual] - y[ult] < 0)
			dir_at -= 2;
		
		if( dir == 1 && dir_at == 2)
			cont++;
		if( dir == -1 && dir_at == -2)
			cont++;
		if( (dir == 2 && dir_at == -1) || (dir == -2 && dir_at == 1))
			cont++;
		
		dir = dir_at;
	}
	
	printf("%d\n", cont);
	
	
	return 0;
}
