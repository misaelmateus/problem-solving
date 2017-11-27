#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1, c2, c3;
	int t3, t1, t2;
	cin >> c1 >> c2 >> c3 >> t3 >> t1;
	if(c1 < 0 || c2 < 0 || c3 < 0 || t3 < 0 || t1 < 0 ) return 0;
	c1 *= 6, c2 *= 6, c3 *= 6, t3 *= 6, t1 *= 6;
	t2 = (c1 + c2 + c3 - 3*t3 - t1)/2;
	if(t2 < 0)
		return 0;
	for(int t12 = 0; t12 <= min(c1,c2) - t3; t12++)
		for(int t13 = 0; t13 <= min(c1, c3) - t3; t13++){
			int t23 = t2 - t12 - t13;
			if(t23 < 0 || t23 > min(c2, c3) - t3) continue;
			int a1 = c1 - t13 - t12 - t3;
			int a2 = c2 - t23 - t12 - t3;
			int a3 = c3 - t13 - t23 - t3;
			if(a1 < 0 || a2 < 0 || a3 < 0 || a1 + a2 + a3 + 2*t2 - (c1 +c2+c3)+ 3*t3 != 0) continue;
			t2 /= 3;
			if(t2 % 2 == 0) cout << t2/2 << endl;
			else cout << (int)(t2 / 2) << ".5\n";
			return 0;
		}
}