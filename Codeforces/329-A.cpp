//   Author : Misael Mateus 
//   Submission date: 2016-07-26 21:46:53
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    
    char m[N][N];
    int l[N], c[N];
    
    memset(l, 0, sizeof(l));
    memset(c, 0, sizeof(c));
    
    
    for(int i = 0; i < N; i++){
        scanf(" %s", m[i]);
        for(int j = 0; j < N; j++){
            if(m[i][j] == '.')
                l[i] = 1, c[j] = 1;
        }
    }
    
    int linha = 1, coluna = 1;
    
    for(int i = 0; i < N; i++)
    {
        if(!l[i])
            linha = 0;
        if(!c[i])
            coluna = 0;
    }
    
    if(!linha && !coluna)
        printf("-1\n");
    else if(linha){
         for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                if(m[i][j] == '.'){
                    printf("%d %d\n", i+1, j+1);
                    break;
                }
            }
    }
    else{
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                if(m[j][i] == '.'){
                    printf("%d %d\n", j+1, i+1);
                    break;
                }
            }
    }
    
    
    return 0;
}