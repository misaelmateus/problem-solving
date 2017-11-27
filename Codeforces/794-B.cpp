//   Author : Misael Mateus 
//   Submission date: 2017-11-06 14:28:37
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111
#define readFast ios::sync_with_stdio(false)
using namespace std;




int main(){
	readFast;
	int n;
	double h;
	cin >> n >> h;
	double S = 0;
	rep(i, n-1){
		double xi = sqrt(2*h*(S + (h/n/2.0)));
		S = xi*xi/(h*2.0);
		cout << fixed << setprecision(10) << xi << " ";
	}
	cout << "\n";
}