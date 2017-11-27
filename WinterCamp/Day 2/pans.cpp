#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int now = 1;
	if(n == 1){
		cout << "2\n1A 0X\n1B 0X\n";
		return 0;
	}
	cout << n << endl;
	while(n > 3){
		cout << now << "A " << now+1 << "B\n";
		cout << now << "B " << now+1 << "A\n";
		n-=2;
		now+=2;
	}

	if(n == 2){
		cout << now << "A " << now+1 << "B\n";
		cout << now << "B " << now+1 << "A\n";
	}
	else{
		cout << now << "A " << now+1 << "A\n";
		cout << now << "B " << now+2 << "A\n";
		cout << now+1 << "B " << now+2 << "B\n";
	}

	return 0;
}