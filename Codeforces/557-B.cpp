//   Author : Misael Mateus 
//   Submission date: 2015-08-26 14:53:50
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n,w;
    scanf("%d %d", &n, &w);
    int Mmen, Mwoman;
    int vetor[2*n];
    for(int i = 0; i < 2*n; i++)
    {
        int a;
        scanf("%d", &vetor[i]);
    }
    sort(vetor, vetor+(2*n));
    Mwoman = vetor[0];
    Mmen = vetor[n];
    double x = 0;
    x = (double) w / (3*n);
    if(2*x > Mmen)
        x =(double) Mmen/2;
    if(x > Mwoman)
        x =(double) Mwoman;
    
    x *= (double) 3 * n;
    printf("%.7lf\n", x);
    return 0;
}