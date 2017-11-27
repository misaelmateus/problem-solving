//   Author : Misael Mateus 
//   Submission date: 2017-10-28 20:05:56
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, t;
	cin >> n >> t;
	int ai;
	for(int i =0; i < n; i++){
		cin >> ai;
		t -= 86400 - ai;
		if(t <= 0){
			cout << i+1 << endl;
			return 0;
		}
	}


}