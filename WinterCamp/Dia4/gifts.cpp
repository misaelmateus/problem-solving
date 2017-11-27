#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007LL;
long long fat[1000005];
int main()
{

	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	fat[0] = 1LL;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long ans = 1;
	int j = n-1;
	for(int i = n; i >= 1; i--)
	{
		while(j >= 0 && v[j] >= i) j--;
		j++;
		if(i - j <= 0) ans = 0;
		else ans = ((ll)ans * (i -j)) % mod;
	}

	cout << ans << endl;
	return 0;
}