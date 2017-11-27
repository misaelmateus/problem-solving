#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		ll a, b, c;
		cin >> a >> b >> c;
		if(a > b)
			swap(a, b);
		int flag = 1;
		if(a*b == c) {
			cout << "0\n";
			continue;
		}
		if(c % a == 0 || c % b == 0 ){
			cout << "1\n";
			continue;
		}
		for(ll i = 1; i * i<= c; i++){
			if(c % i == 0 && i <= a && c/i <= b){
				cout << "2\n";
				flag = 0;
				break;
			}
		}
		ll d = a*b - c;
		for(ll i = 1; i * i <= d && flag; i++){
			if(d % i == 0 && i <= a && d/i <= b)
			{
				cout << "2\n";
				flag = 0;
				break;
			}
		}
		if(flag)
			cout << "3\n";
	}
}