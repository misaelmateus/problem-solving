//   Author : Misael Mateus 
//   Submission date: 2016-06-29 22:31:55
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string n;
	cin >> n;
	cout << n;
	for(int i = n.size() - 1; i >= 0; i--)
		cout << n[i];
	cout << endl;


	return 0;
}