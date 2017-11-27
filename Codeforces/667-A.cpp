//   Author : Misael Mateus 
//   Submission date: 2016-04-29 22:01:23
#include<bits/stdc++.h>
#define pi 3.14159265359
using namespace std;
int main()
{
	double d, h, v, e;
	scanf("%lf %lf %lf %lf", &d, &h, &v, &e);
	d /= 2;
	double A = pi * d * d;
	e *= A;
	if(v - e < 10e-8 ){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	double x = v - e;
	
	double V = A * h;
	double t = V / x;
	printf("%.6lf\n", t);
	
	return 0;
}

