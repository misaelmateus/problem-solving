//   Author : Misael Mateus 
//   Submission date: 2017-09-04 21:08:17
#include<bits/stdc++.h>
#define vi vector<int>
#define ld long double
using namespace std;
int is_bad(vi a, vi b, vi c){
	vector<int> v1(5), v2(5);
	for(int i = 0; i< 5; i++){
		v1[i] = b[i] - a[i];
		v2[i] = c[i] - a[i];
	}

	int x1 = 0, x2 = 0, x3 = 0;
	for(int i = 0; i < 5; i++){
		x1 += v1[i] * v2[i];
		x2 += v1[i] * v1[i];
		x3 += v2[i] * v2[i];
	}
	if(x1 == 0) return 0;
	ld ang = acos((ld)x1 / (sqrt((ld)x2) * sqrt((ld)x3)));
	if(ang < acos(-1.0L)/2.0L)
		return 1;
	return 0;
}
int n;
vector<vector<int> > v;

int test(int l){
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++){
			if(i == j || i == l || j == l) continue;
			if(is_bad(v[l], v[i], v[j])) return 0;
		}
	return 1;
}
int main(){
	scanf("%d", &n);
	if(n == 2){
		printf("2\n1\n2\n");
		return 0;
	}
	vector<int> ans(n, 0);
	v = vector<vector<int> > (n, vector<int>(5));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 5; j++){
			scanf("%d", &v[i][j]);
		}
	}

	int i = 0, j = 1, l = 2;
	while(i < n && j < n && l < n){
		while(i < n && ans[i]) i++;
		while(j < n && (i >= j || ans[j])) j++;
		while(l < n && (j >= l || ans[l])) l++;
		if(i >= n || j >= n || l >= n) break;

		if(is_bad(v[i], v[l], v[j])) ans[i] = 1;
		else ans[j] = 1, ans[l] = 1;
	}

	int a = -1, b = -1;
	for(int i  =0; i < n; i++){
		if(ans[i] == 0){
			if(a == -1) a = i;
			else b = i;
		}
	}
	int resp = -1;
	if(a != -1)
		if(test(a)) resp = a;
	if(b != -1) if(test(b)) resp = b;
	if(resp == -1){
		printf("0\n");
		return 0;
	}
	printf("1\n%d\n", resp+1);

}