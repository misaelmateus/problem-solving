#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a = n/3, b = n/3, c = (n - a - b);
		int ba = a, bb = b, bc = c, ans = a&b&c;
		for(int i = 0; i < 10000; i++, a--, b--){
			c = n - a - b;
			if(ans < a&b&c)
				ans = (a&b&c), ba =a, bb = b, bc = c;
		}
		cout << ba << " " << bb << " " << bc << endl;

	}
}