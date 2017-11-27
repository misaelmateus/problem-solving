//   Author : Misael Mateus 
//   Submission date: 2016-05-05 23:46:35
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n, k;
	cin >> n >> k;
	ll x = 1;
	for(x = 1; ( (x*(x+1))/2LL ) < k; x++);
	x--;
	k -= (x*(x+1))/2LL ;
	
	for(int i = 1LL; i <= n; i++)
	{
		ll aux;
		cin >> aux;
		if(i == k)
			cout << aux << endl;
	}
	
	return 0;
}
