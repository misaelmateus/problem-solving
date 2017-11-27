#include<bits/stdc++.h>
#define EPS 0.000000001
using namespace std;
int main(){
	int n;
	cin >> n;
	double t, d[n], s[n];
	cin >> t;
	double i = -(1<<30), j = (double)(1 << 30);
	for(int k = 0; k < n; k++) {
		cin >> d[k] >> s[k]; 
		i = max(i, -s[k]);
	}

	for(int l = 0; l < 200; l++){
		double middle = (i + j)/2.;

		double sum = -t;
		for(int k = 0; k < n; k++){
			sum += (d[k])/(s[k] + middle);
		}

		if(sum > EPS)
			i = middle;
		else
			j = middle;
	}

	cout << fixed << setprecision(8) << j << "\n";
}