//   Author : Misael Mateus 
//   Submission date: 2016-05-11 21:51:41
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    char s[n];
    scanf(" %s", &s);
    if(n > 26){
        printf("-1\n");
        return 0;
    }
    int mapa[26];
    memset(mapa, 0, sizeof(mapa));
    int cont = 0;
    for(int i = 0; i < n; i++)
    {
        int atual = (int)(s[i] - 'a');
        if(mapa[atual] == 0)
            mapa[atual] = 1;
        else
            cont++;
    }
    printf("%d\n", cont);
}
