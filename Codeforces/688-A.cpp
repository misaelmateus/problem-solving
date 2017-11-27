//   Author : Misael Mateus 
//   Submission date: 2016-06-29 22:30:53
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, d;
	scanf("%d %d", &n, &d);
	int maior = 0;
	int atual = 0;
	for (int i = 0; i < d; ++i)
	{
		int flag = 0;
		for (int j = 0; j < n; ++j)
		{
			char aux;
			scanf(" %c", &aux);
			if(aux == '0')
				flag = 1;
		}
		if(flag)
			atual++;
		else
			atual = 0;
		if(atual > maior)
			maior = atual;
	}

	cout << maior << endl;
}