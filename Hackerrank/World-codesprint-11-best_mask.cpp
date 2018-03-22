#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
int tot[MAXN];
int tot1[MAXN];
int n;

int main(){
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	int ans = 0, len = 50;
	for(int i = 0; i < (1 << 19); i++){
		int l = 0;
		for(int j = 0; j <= 26; j++){
			if(i &(1 << j))
				l++;
		}
		if(l >= len)
			continue;
		int j;
		for(j = 0; j < n; j++)
			if(!(v[j] & i))
				break;
		if(j == n)
			ans = i, len = l;
	}
	for(int i1 = 0; i1 < (1 << 17); i1++){
		int i = (i1 << 9);
		int l = 0;
		for(int j = 0; j <= 26; j++){
			if(i &(1 << j))
				l++;
		}
		if(l >= len)
			continue;
		int j;
		for(j = 0; j < n; j++)
			if(!(v[j] & i))
				break;
		if(j == n)
			ans = i, len = l;
	}

	cout << ans << endl;
}