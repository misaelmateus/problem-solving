//   Author : Misael Mateus 
//   Submission date: 2016-05-05 23:28:41
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	int quant = 0;
	cin >> n >> k;
	int a[n], b[n], r[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &b[i]);
		
	for(int i = 0; i < n; i++)
	{
		r[i] = b[i] % a[i];
		b[i] = b[i] / a[i];
	}
	
	while(k >= 0)
	{
		int min = 1 << 20;
		for(int i = 0; i < n; i++)
		{
			if(b[i] < min)
				min = b[i];
		}
		quant += min;
		for(int i = 0; i < n; i++)
		{
			b[i] -= min;
			if(b[i] == 0)
			{
				int aux = r[i];
				r[i] = 0;
				k -= a[i] - aux;
				b[i] = 1;
			}
		}
	}
	cout << quant << endl;
	return 0;
}
