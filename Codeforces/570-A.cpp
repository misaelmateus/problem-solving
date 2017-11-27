//   Author : Misael Mateus 
//   Submission date: 2015-08-25 13:51:11
#include <cstdio>
using namespace std;

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    int cont[n];
    int cand = 0, M = 0;
    for(int i = 0; i < n; i++) cont[i] = 0;
    for(int i = 0; i < m; i++)
    {
        int maior = -1;
        int i_maior = -1;
        for(int j = 0 ; j < n; j++)
        {
            int a;
            scanf("%d", &a);
            if(a > maior)
                maior = a, i_maior = j;
                
        }
        cont[i_maior]++;
        
    }
    for(int i = 0; i < n; i++)
    {
        if(cont[i] > M)
            M = cont[i], cand = i;
    }
    printf("%d\n", cand+1);
    return 0;
}