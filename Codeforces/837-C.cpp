//   Author : Misael Mateus 
//   Submission date: 2017-08-07 07:05:12
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, a, b;
	cin >> n >> a >> b;
	int x[n], y[n];
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		for(int j = 0; j < i; j++){
			if(x[i] + x[j] <= a && y[i] <= b && y[j] <= b) 
				ans = max(ans, x[i]*y[i] + x[j]*y[j]);
			
			swap(x[i], y[i]);
			if(x[i] + x[j] <= a && y[i] <= b && y[j] <= b) 
				ans = max(ans, x[i]*y[i] + x[j]*y[j]);

			swap(x[j], y[j]);
			if(x[i] + x[j] <= a && y[i] <= b && y[j] <= b) 
				ans = max(ans, x[i]*y[i] + x[j]*y[j]);
			swap(x[i], y[i]);
			if(x[i] + x[j] <= a && y[i] <= b && y[j] <= b) 
				ans = max(ans, x[i]*y[i] + x[j]*y[j]);

			swap(a, b);
			if(x[i] + x[j] <= a && y[i] <= b && y[j] <= b) 
				ans = max(ans, x[i]*y[i] + x[j]*y[j]);
			
			swap(x[i], y[i]);
			if(x[i] + x[j] <= a && y[i] <= b && y[j] <= b) 
				ans = max(ans, x[i]*y[i] + x[j]*y[j]);

			swap(x[j], y[j]);
			if(x[i] + x[j] <= a && y[i] <= b && y[j] <= b) 
				ans = max(ans, x[i]*y[i] + x[j]*y[j]);
			swap(x[i], y[i]);
			if(x[i] + x[j] <= a && y[i] <= b && y[j] <= b) 
				ans = max(ans, x[i]*y[i] + x[j]*y[j]);		}
	}
	cout << ans << "\n";

	return 0;
}