#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int sum = 0;
	int v[n];
	for(int i = 0; i < n; i++) cin >> v[i], sum += v[i];
	sort(v, v+n);
	reverse(v, v+n);
	if(v[0]*100 >= 45*sum || (v[0]*100 >= 40*sum && (v[0] - v[1])*10 >= sum))
		cout << "1\n";
	else cout << "2\n";
}