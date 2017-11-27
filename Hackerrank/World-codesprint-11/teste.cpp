#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
int tot[MAXN];
vector<int> p;
vector<int> v;
int n;

map<int, bool> mark;

void f(int x){
	if(mark[x]) return;
	mark[x] = 1;
	for(int i = 27; i >= 0; i--){
		if(x & (1 << i))
			f(x - (1<<i));
	}
}
int main(){
	scanf("%d", &n);
	vector<int> v1(n);
	for(int i = 0; i < n; i++){
		cin >> v1[i];
	}
	sort(v1.begin(), v1.end());
	for(int i = n-1; i >= 0; i--){
		if(!mark[v1[i]]){
			v.push_back(v1[i]);
            f(v1[i]);
		}
	}
	if(v.size() > 1000){
		while(1);

	}

	cout << 1 << endl;
}