//   Author : Misael Mateus 
//   Submission date: 2016-05-07 21:43:55
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if(k <= n || n == 4){
        printf("-1\n");
        return 0;
    }
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int pai[n+1];
    pai[1] = a;
    pai[n] = b;
    pai[2] = c;
    pai[n-1] = d;
    int K = 1;
    for(int l = 3; l < n-1; l++)
    {
        while(K == a || K == b || K == c || K == d)
        {
            K++;
        }
        pai[l] = K;
        K++;
    }

    for(int i = 1; i <= n; i++){
        if(i != 1)
            printf(" ");
        printf("%d", pai[i]);
    }
    printf("\n");
    printf("%d %d", pai[2], pai[1]);
    for(int i = 3; i <= n-2; i++)
        printf(" %d", pai[i]);
    printf(" %d %d\n", pai[n], pai[n-1]);

    return 0;
}
