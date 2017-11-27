//   Author : Misael Mateus 
//   Submission date: 2015-08-25 14:00:18
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if(n == 1)
    {
        printf("1\n");
        return 0;
    }
    int dE, dD;
    dD = n-m;
    dE = m - 1;
    if(dE >= dD)
        printf("%d\n", m-1);
    else
        printf("%d\n", m+1);
    return 0;
}