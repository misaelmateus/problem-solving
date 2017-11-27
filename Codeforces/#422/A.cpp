#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, c)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
using namespace std;


int main(){
	int a, b;
	RII(a, b);
	a = min(a, b);
	b = 1;
	for(; a > 1; a--) b*=a;

	printf("%d\n", b);
}