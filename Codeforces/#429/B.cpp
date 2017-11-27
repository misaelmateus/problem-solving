#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio( false );
	int n;
	cin >> n;
	if(n % 2 == 0){
		if(n % 4 != 0)
			cout << -1;
		else while(n != 0){
			cout << "-++-";
			n-= 4;
		}
		cout << endl;
	}
	else{
		if((n / 2) % 2 == 0)
			cout << -1 << endl;
		else{
			cout << "--+";
			n -= 3;
			while(n != 0){
				cout << "-++-";
				n -= 4;
			}
			cout << endl;
		}
	}

	return 0;
}