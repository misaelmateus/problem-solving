//   Author : Misael Mateus 
//   Submission date: 2015-08-26 14:26:25
#include <cstdio>
using namespace std;

int main() {
    int n, m1, m2, m3, M1, M2, M3;
    scanf("%d %d %d %d %d %d %d", &n, &m1, &M1, &m2, &M2, &m3, &M3);
    int t1 = 0, t2 = 0, t3 = 0;
    t1 = m1, t2 = m2, t3 = m3;
    int total = n - t1 - t2 - t3;
    if(total > 0)
    {
        if(total >= M1 - m1)
            t1 = M1, total -= M1 - m1;
        else
            t1 += total, total = 0;
    }
    if(total > 0)
    {
        if(total >= M2 - m2)
            t2 = M2, total -= M2 - m2;
        else
            t2 += total, total = 0;
    }
    t3 += total, total = 0;
    
    printf("%d %d %d\n", t1, t2, t3);
    return 0;
}