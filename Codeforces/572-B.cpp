//   Author : Misael Mateus 
//   Submission date: 2015-08-24 20:16:40
#include <cstdio>
#include <map>
using namespace std;
#define li long int
int main() {
    int n,s, vend = 0;
    scanf("%d %d", &n, &s);
    map <li, li> venda;
    map <li, li> compra;
    for(int i = 0; i < n; i++)
    {
        char c;
        li p, q;
        scanf(" %c %d %d", &c, &p, &q);
        
        if(c == 'B')
            compra[p] += q;
        if(c == 'S'){
            if(venda[p] == 0)
                vend++;
            venda[p] += q;
            
        }
            
    }
    map<li,li>::reverse_iterator rit;
    int i = 0;
    rit = venda.rbegin();
    for(i = 0; i < vend - s; i++)
        ++rit;
    for(i = 0; i < s && rit != venda.rend(); ++rit)
    {
        i++;
        li a = rit->first;
        li b = rit->second;
        printf("S %d %d\n", a, b);
    }
    for(rit = compra.rbegin(), i = 0; i < s && rit != compra.rend(); ++rit)
    {
        i++;
        li a = rit->first;
        li b = rit->second;
        printf("B %ld %ld\n", a, b);
    }
    
    return 0;
}