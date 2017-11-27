//   Author : Misael Mateus 
//   Submission date: 2015-08-24 19:28:01
#include <cstdio>
#include <algorithm>
using namespace std;
int funcao(int a, int b){ return a >= b; }
int main() {
    int Na, Nb;
    scanf("%d %d", &Na, &Nb);
    int K, M;
    scanf("%d %d", &K, &M);
    int l1[Na];
    int l2[Nb];
    for(int i = 0; i < Na; i++)
        scanf("%d", &l1[i]);
    for(int i = 0; i < Nb; i++)
        scanf("%d", &l2[i]);
    if(l1[K-1] < l2[Nb - M])
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}