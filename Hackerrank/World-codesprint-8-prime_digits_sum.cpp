#include<bits/stdc++.h>
using namespace std;
int prime[30];
int is_prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
bool test(int n){
	int dig[5];
	for(int i = 0; i < 5; i++){
		dig[4 - i] = n%10;
		n /= 10;
	}
	int soma = dig[0] + dig[1] + dig[2];
	if(!prime[soma])
		return false;
	soma += dig[3];
	if(!prime[soma])
		return false;
	soma += dig[4];
	if(!prime[soma])
		return false;
}

int mark[100000];
int main(){
	for(int i = 0; i < 9; i++) prime[is_prime[i]] = 1;
	vector<int> v;
	set<int> v1;
	for(int i = 1; i <= 99999; i++){
		if(test(i)){
			v.push_back(i);
			mark[i] = 1;
		}
	}
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i++){
		int a = v[i];
		a %= 10000;
		a *= 10;

		for(int j = 0; j <= 9; j++){
			if(mark[a + j]){
				v1.insert(v[i] % 10000);
				break;
			}
		}
	}
	cout << v1.size() << endl;
}