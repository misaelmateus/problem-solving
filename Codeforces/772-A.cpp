//   Author : Misael Mateus 
//   Submission date: 2017-04-17 17:06:51
#include<bits/stdc++.h>
#define for(i, n) for(int i = 0; i < n; i++)
#define EPS 0.000000001
using namespace std;
int main(){
	int n;
	double p;
	cin >> n >> p;

	double a[n], b[n];
	for(i, n)
		cin >> a[i] >> b[i];
	double i = 0, j = (double)(1LL << 60);
	for(k, 100){
		double middle = (i+j)/2.;

		double total = 0.;
		for(l, n){
			double aux = (a[l] * middle - b[l])/p;
			if(aux < EPS)
				aux = 0;
			total += aux;
		}
		if(total < middle + EPS)
			i = middle;
		else j = middle;
	}
	if(i > (double)(1LL << 55))
		cout << -1 << endl;
	else cout << fixed << setprecision(6) << i << endl;
}