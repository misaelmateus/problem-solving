#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int main(){
	int a, b;
	cin >> a >> b;
	int ans = b / (b-a) + (b % (b-a) != 0 ? 1 : 0);
	cout << ans << endl;
}