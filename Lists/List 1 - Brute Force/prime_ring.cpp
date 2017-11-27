#include<bits/stdc++.h>
using namespace std;
int n;
int isPrime[100];
void f(int mask, vector<int> &v){
	if(mask == (1 << n)-1 ){
		
		if(v.size() > 1 && !isPrime[v.back() + 1]) 
			return;
		for(int i = 0; i < v.size(); i++){
			if(i) printf(" ");
			printf("%d", v[i]);
		}
		printf("\n");
		return ;
	}

	for(int i = 1; i < n; i++){
		if(!(mask & (1 << i)) && isPrime[v.back() + i+1]){
			v.push_back(i+1);
			f(mask | (1 << i), v);
			v.pop_back();
		}
	}
}
int main(){
	for(int i = 2; i < 100; i++){
		isPrime[i] = 1;
		for(int j = 2; j < i; j++)
			if(i%j == 0) isPrime[i] = 0;
	}
	int k = 1;
	while( scanf("%d", &n) != EOF ){
		if(k-1) printf("\n");
		printf("Case %d:\n", k++);
		vector<int> v = {1};
		f(1, v);
		
	}

}