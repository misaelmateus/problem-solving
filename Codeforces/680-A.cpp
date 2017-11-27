//   Author : Misael Mateus 
//   Submission date: 2016-06-08 21:47:34
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int c[5];
	for(int i = 0; i < 5; i++)
		cin >> c[i];
		
	sort(c, c+5);
	int maior = 0, atual = 0, soma = 0, cont = 0;
	for(int i = 0; i < 5; i++)
	{
		soma += c[i];
		if(i == 0 || c[i] != c[i-1])
		{
			atual = c[i];
			cont = 1;
			continue;
		}
		atual += c[i];
		cont++;
		if(cont <= 3 && cont > 1 && atual > maior)
				maior = atual;
	}
	
	cout << soma - maior;
	return 0;
}

