//   Author : Misael Mateus 
//   Submission date: 2016-06-08 21:49:55
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, a;
	cin >> n >> a;
	int c[n+1];
	for(int i = 1; i <= n; i++)
		cin >> c[i];
		
	int i = a, j = a;
	int tot = 0;
	while(i > 0 || j <= n)
	{
		if(i == j){
			tot += c[i];
		}
		else if(i <= 0){
			tot += c[j];
		}		
		else if(j > n){
			tot+= c[i];
		}
		else if(c[i] + c[j] == 2)
			tot += 2;	
		
		i--;
		j++;
	}
	
	cout << tot << endl;
	
	return 0;
}		
