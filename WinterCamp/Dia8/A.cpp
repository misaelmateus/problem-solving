#include<bits/stdc++.h>

using namespace std;


int main(){
	int a1, b1, c1, a2, b2, c2;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	int p1 = (a1 > a2) + (b1 > b2) + (c1 > c2);
	int p2 = (a1 < a2) + (b1 < b2) + (c1 < c2);
	cout << p1 << " " << p2 << "\n";
	return 0;
}