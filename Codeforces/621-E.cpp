//   Author : Misael Mateus 
//   Submission date: 2016-08-22 22:34:37
#include<bits/stdc++.h>
#define L 1000000007
#define MAXX 111
#define ll long long
using namespace std;
int n, b, k, x;
struct matriz{
    int m[MAXX][MAXX];
    void ini(){
        memset(m, 0, sizeof(m));
    }
};

matriz mult(matriz a, matriz b){
    matriz resp;
    resp.ini();
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            for(int l = 0; l < x; l++)
                resp.m[i][j] = (resp.m[i][j] + (int)( ( (ll)a.m[i][l]*(ll)b.m[l][j] ) % L) ) % L;
        }
    }
    
    return resp;
}

matriz exp(int a, matriz M){
    if(a == 1)
        return M;
    matriz m2 = exp(a/2, M);
    m2 = mult(m2, m2);
    if(a % 2 == 1)
        m2 = mult(m2, M);
    
    return m2;
}

int main(){
    scanf("%d %d %d %d", &n, &b, &k, &x);
    int occ[10];
    memset(occ, 0, sizeof(occ));
    
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        
        occ[aux]++;
    }
    
    matriz T;
    T.ini();
    for(int j = 0; j < x; j++){
        for(int a = 0; a < x; a++){
            for(int d = 1; d <= 9; d++){
                if((a*10 + d)%x == j)
                    T.m[j][a] += occ[d];
            }
        }
    }
    
    T = exp(b, T);
        
    cout << T.m[k][0] << endl;
    
    return 0;
}