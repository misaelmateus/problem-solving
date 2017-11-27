//   Author : Misael Mateus 
//   Submission date: 2016-05-07 21:41:42
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int tot[n+2][n+2];
    int maior[n+2][n+2];
    int c[n+1];
    c[0] = 0;
    memset(tot, 0, sizeof(tot));
    memset(maior, 0, sizeof(maior));
    for(int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            tot[i][j] = tot[i][j-1];
            if(c[j] == i)
                tot[i][j]++;
        }
    for(int i = n; i > 0; i--){
        for(int j = 1; j <= n; j++){
            if(i > j)
                continue;
            int a = maior[i+1][j];
            int b = maior[i][j-1];
            int A = tot[a][j] - tot[a][i-1];
            int B = tot[b][j] - tot[b][i-1];
            int d, D;
            if(tot[c[i]][j] - tot[c[i]][i-1] > tot[c[j]][j] - tot[c[j]][i-1])
                d = c[i];
            else if((tot[c[i]][j] - tot[c[i]][i-1] == tot[c[j]][j] - tot[c[j]][i-1]))
                d = min(c[i], c[j]);
            else
                d = c[j];
            D = tot[d][j] - tot[d][i-1];
            if(A > B && A > D)
                maior[i][j] = a;
            else if(A < B || A < D)
            {
                if(B > D)
                    maior[i][j] = b;
                else if(B < D)
                    maior[i][j] = d;
                else
                    maior[i][j] = min(b, d);
            }
            else if(A == B && B == D)
                maior[i][j] = min(min(a, b), d);
            else if(A == B)
                maior[i][j] = min(a, b);
            else maior[i][j] = min(a, d);
        }
    }
    int cont[n+1];
    memset(cont, 0, sizeof(cont));
    for(int i = n; i >= 1; i--)
        for(int j = i; j <= n; j++)
            cont[maior[i][j]]++;
    for(int i = 1; i <= n; i++){
        if(i > 1)
            printf(" ");
        printf("%d", cont[i]);
    }
    printf("\n");
    return 0;
}
