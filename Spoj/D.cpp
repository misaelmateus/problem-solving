#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n, count1 = 0, count2 = 0;

int test(int a, int b){
	int x = count1, y = count2;
	int ans = 0, bon = 0;
	for(int i = 0; i < n; i++){
		if(v[i] == 1000){
			if(x > a) ans += 10, bon += 1, x--;
			else {
				int aux = min(10, bon);
				ans += 10 - aux;
				bon -= aux;
			}
		}
		if(v[i] == 2000){
			if(y > b) ans += 20, bon += 2, y--;
			else{
				int aux = min(20, bon);
				ans += 20 - aux;
				bon -= aux;
			}
		}
	}
	
	//printf("%d %d = %d\n", a, b, ans);
	return ans;
}
int binary_search2(int a){
	int i = 1, j = count2;
	while(j - i > 1){
		int mid = (i+j) >> 1;
		int ans1 = test(a, mid);
		int ans2 = test(a, mid-1);
		if(ans1 - ans2 <= 0)
			i = mid;
		else j = mid;
	}
	int ans = 1e9;
	for(int l = i-1; l <= j; l++)
		ans = min(ans, test(a, l));
	return ans;
}
int binary_search(){
	int i = 1, j = count1;
	while(j - i > 1){
		int mid = (i+j) >> 1;
		int ans1 = binary_search2(mid);
		int ans2 = binary_search2(mid-1);
		if(ans1 - ans2 <= 0)
			i = mid;
		else j = mid;
	}
	int ans = 1e9;
	for(int l = i-1; l <= j; l++)
		ans = min(ans, binary_search2(l));
	return ans;
}
int main(){
	scanf("%d", &n);
	v = vector<int>(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		if(v[i] == 1000) count1++;
		else count2++;
	}

	int ans = binary_search();

	printf("%lld\n", ans*100LL);
}