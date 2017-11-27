#include<bits/stdc++.h>
using namespace std;
#define ld long double 

int main(){
	ios::sync_with_stdio(false);	
	int n;
	cin >> n;
	while(n--){
		int a, v1, v2;
		cin >> a >> v1 >> v2;
		if(sqrt(2.0L)/v1 > 2.0L/v2)
			cout << "Elevator\n";
		else cout << "Stairs\n";
	}
}