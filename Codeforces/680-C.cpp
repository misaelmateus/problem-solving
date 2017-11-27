//   Author : Misael Mateus 
//   Submission date: 2016-06-08 21:53:05
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int primos[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
	int cont = 0;
	int atual = 1;
	for(int i = 0; i < 15; i++)
	{
		if(primos[i]*atual > 100)
			break;
		printf("%d\n", primos[i]*atual);
		fflush(stdout);
		
		string resp;
		
		cin >> resp;
		if(resp == "yes")
		{
			if(cont == 0)
			{
				cont = 1;
				atual *= primos[i];
				i = -1;
			}
			else{
				cout << "composite" << endl;
				return 0;
			}
			
		}
	}
	cout << "prime" << endl;
	
	return 0;
}
