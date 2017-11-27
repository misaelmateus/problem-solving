//   Author : Misael Mateus 
//   Submission date: 2017-10-28 20:06:03
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, x;
	cin >> n >> x;
	int ai;
	int sum = (n-1);
	for(int i =0; i < n; i++){
		cin >> ai;
		sum += ai;
	}
	if(sum == x)
		cout << "YES\n";
	else cout << "NO\n";


}