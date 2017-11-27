#include<bits/stdc++.h>
#define ld long double
using namespace std;
int main(){
		ios::sync_with_stdio(false);	

	int T;
	cin >> T;
	while(T--){
		ld a, b, c, d;
		cin >> a >> b >> c >> d;
		if(a == c){
			cout << (b < d ? "<\n" : ">\n");
		}
		else if(b * (ld)log(a) < d* (ld)log(c)){
			cout << "<\n";
		}
		else cout << ">\n";
	}
}