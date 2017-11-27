#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	int sum = 0;
	sum += n;
	while(k > 0){
		n *= 10;
		sum += n;
		k--;
	}

	cout << sum << endl;
}