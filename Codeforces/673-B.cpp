//   Author : Misael Mateus 
//   Submission date: 2016-05-07 21:37:58
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int x[n+1];
    memset(x, 0, sizeof(x));
    x[1] = 2;
    x[n] = 1;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a < b){
            int aux = a;
            a = b;
            b = aux;
        }
        if(x[a] == 2 || x[b] == 1)
        {
            printf("0\n");
            return 0;
        }
        x[a] = 1;
        x[b] = 2;
    }
    int aux = 2;
    int resp = -1;
    int muda = n+1;
    for(int i = 1; i <= n; i++)
    {
        if(x[i]!=0 && x[i] < aux)
        {
            aux = x[i];
            muda = i;
        }
        if(x[i]!=0 && x[i] > aux)
        {
            resp = 0;
            break;
        }
    }
    int cont = 0;
    if(!resp)
    {
        printf("0\n");
        return 0;
    }

    for(int i = muda-1; i > 0; i--)
    {
        if(x[i] == 2)
            break;
        cont++;
    }
    int total = 0;
    total += cont + 1;
    printf("%d\n", total);
    return 0;
}
