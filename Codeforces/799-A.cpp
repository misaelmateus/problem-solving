//   Author : Misael Mateus 
//   Submission date: 2017-05-11 21:06:53
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k, t, d;
	cin >> n >> t >> k >> d;
	int a = (n/k + (int)(n % k != 0));
	int t2 = a*t - d;
	
	if(a > 1 && (t2 > t))
		cout << "YES\n";
	else cout << "NO\n";

	return 0;
}

