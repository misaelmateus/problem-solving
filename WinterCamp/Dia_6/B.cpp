#include<bits/stdc++.h>
#define ld long double
#define EPS (ld)(0.0000000001)
using namespace std;

ld pot4(ld a){
	return a*a*a*a;
}
int main(){
	ld a, b, c;
	while(cin >> a >> b >> c){
		ld S2 = (a * a + b*b + c*c);
		ld S4 = (pot4(a)  + pot4(b) + pot4(c));
		ld delta = 12.0 * S2 * S2 - 24.0 * S4;
		if(delta < -EPS) {
			cout << "-1.000\n";
			continue;
		}
	
		ld l = sqrt(S2 + (ld)sqrt(delta)/2.0);
		ld area = l*l *(ld)0.43301270189;
		cout << fixed << setprecision(3) << area << "\n";
	}
}
