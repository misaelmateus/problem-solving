//   Author : Misael Mateus 
//   Submission date: 2015-08-25 17:21:35
#include <cstdio>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    int n = (a + b + c)*(a + b + c) - a*a - c*c - e*e;
    printf("%d\n", n);
    return 0;
}