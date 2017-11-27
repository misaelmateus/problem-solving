//   Author : Misael Mateus 
//   Submission date: 2016-05-11 21:56:22
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ax, ay, bx, by, tx, ty;
    scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &tx, &ty);
    int N;
    scanf("%d", &N);
    double distA[N], distB[N], distL[N];
    double tot = 0.;
    double menA = 3002000000., menB = 3002000000.;
    int iA = -1, iB = -1;
    double menA2 = menA, menB2 = menB;
    for(int i = 0; i < N; i++)
    {
        double cx, cy;
        scanf("%lf %lf", &cx, &cy);
        distA[i] = sqrt( (cx - ax)*(cx - ax) + (cy - ay)*(cy - ay));
        distB[i] = sqrt( (cx - bx)*(cx - bx) + (cy - by)*(cy - by));
        tot += 2.*sqrt( (cx - tx)*(cx - tx) + (cy - ty)*(cy - ty));
        distL[i] = sqrt( (cx - tx)*(cx - tx) + (cy - ty)*(cy - ty));
        distA[i] = distA[i] - distL[i];
        distB[i] = distB[i] - distL[i] ;
        if(distA[i] < menA)
            menA = distA[i], iA = i;
        if(distB[i] < menB)
            menB = distB[i], iB = i;
    }
    for(int i = 0 ; i < N; i++)
    {
        if(distA[i] < menA2 && i != iA)
            menA2 = distA[i];
        if(distB[i] < menB2 && i != iB)
            menB2 = distB[i];
    }
    bool teste = false;
    double x = min(menA, min(menB, menA+menB));
    if(iA == iB)
        x = min(min(menA, menB), min(menA + menB2, menA2 + menB));
    tot += x;
    printf("%.9lf\n", tot);


    return 0;
}
