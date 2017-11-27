#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int i = 0;
	int sum = 0;
	for(; i < n-1; i++){
		sum += v[i];
		if(sum > v[n-1])
			break;
	}
	cout << i+1 << "\n";
}