//   Author : Misael Mateus 
//   Submission date: 2016-05-18 14:38:22
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    int cont = 0;
    scanf("%d", &N);
    for(int j = 5; j > 0; j--)
    {
        cont += N/j;
        N %= j;
    }

    printf("%d\n", cont);

    return 0;
}
