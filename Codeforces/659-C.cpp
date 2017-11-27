//   Author : Misael Mateus 
//   Submission date: 2016-05-13 19:47:11
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int ult = 1;
	int num = 0;
	int brinc[n+1];
	for(int i = 0; i < n; i++)
		scanf("%d", &brinc[i]);
	brinc[n] = 1000000000;
	sort(brinc, brinc+n);
	vector <int> resp;
	for(int i = 0; i <= n; i++)
		for( ; ult <= brinc[i] && num + ult <= m; ult++)
		{
			if(ult == brinc[i])
				continue;
			num += ult;
			resp.push_back(ult);
		}
	printf("%d\n", resp.size());
	for(int i = 0; i < resp.size(); i++)
	{
		if(i)
			printf(" ");
		printf("%d", resp[i]);
		
		
	}
	printf("\n");
	
	
	return 0;
		
	
		
	
	
	
}
