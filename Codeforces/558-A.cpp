//   Author : Misael Mateus 
//   Submission date: 2015-08-25 20:54:51
#include <cstdio>
#include <algorithm>
struct dupla{
    int a, b;
};
using namespace std;
bool cresce(dupla a, dupla b){ return a.a <= b.a; }
bool decresce(dupla a, dupla b){ return a.a >= b.a; }
int main() {
    int n, dir = 0, esq = 0;
    scanf("%d", &n);
    dupla esquerda[n+1];
    dupla direita[n+1];
    esquerda[0].b = direita[0].b = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        dupla nova; nova.a = a, nova.b = b;
        if(a > 0)
            direita[dir++] = nova;
        if(a < 0)
            esquerda[esq++] = nova;
    }
    sort(direita, direita+dir, cresce);
    sort(esquerda, esquerda+esq, decresce);
    int total = 0;
    int a = 0, b = 0;
    if(dir < esq)
        total += esquerda[b++].b;
    
    while(a < dir && b < esq)
        total += esquerda[b++].b + direita[a++].b;
    
    if(a < dir)
        total += direita[a].b;
    printf("%d\n", total);  

    return 0;
}