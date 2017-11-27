#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f1(int a, int b, int c, int i){
	if( (b & (1LL << i)) && (c & (1LL << i)) && (!(a & (1LL << (i+1) )) && ) )
}
int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll a = 0LL, b = 0LL, c = 0LL;
		while(n >= 0){
			int i = 60;
			while(i >= 0 && !(n & (1LL << i)) ) i--;
			i--;
			while(i >= 0 && !(n & (1LL << i)) ) i--;
			if(i < 0) break;
			a += (1LL << i);
			b += (1LL << i);
			c += (1LL << i);
			n -= 3*(1LL << i);	
		}
		if(a & n){
			a+= n;
			int i = 60;
			for(; i >= 0; i--){
				if((a & (1LL << i) && (( ((b & (1LL << i) ^ (c & (1LL << i)) ))
					&& !(a & (1LL << (i+1)) ) ){
						a -= (1LL << i);
						a += (1LL << (i+1));
						if(b & (1LL << i))
						
					}
			}

		}
		else a += n;
		if(!(a & 1)) a -= 1, b += 1;
		cout << a << " " << b << " " << c << "\n";
	}
}