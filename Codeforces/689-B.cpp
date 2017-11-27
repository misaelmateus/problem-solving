//   Author : Misael Mateus 
//   Submission date: 2016-07-06 21:50:35
#include <bits/stdc++.h>
#define inf 0x3F3F3F3F
#define MAXN 200100
using namespace std ;
vector< pair< int, int>  >  arestas[MAXN] ;
int dist[MAXN] ;
int n, t, x  ;
void Dijkstra( int ini)
{
    priority_queue< pair< int, int>, vector< pair< int, int > >, greater<pair<int, int> > > pq;
    memset( dist, inf, sizeof( dist ) ) ;
    dist[ini] = 0 ;
    pq.push( make_pair( 0, ini ) ) ;
    while ( !pq.empty() ) 
    {
        int d = pq.top().first  ;
        int b = pq.top().second ;
        pq.pop() ;
        if( d > dist[b]) continue ;
        for( int i = 0 ; i < arestas[b].size() ; i++ )
        {
            int prox = arestas[b][i].second ;
            if( dist[ prox ] > d + arestas[b][i].first ) 
            {
                dist[ prox ]  =  d + arestas[b][i].first ;
                pq.push( make_pair( dist[ prox ] , prox ) ) ;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <n; i++)
    {
        arestas[i].push_back(make_pair(1, i+1));
        arestas[i+1].push_back(make_pair(1, i));
    }
    
    for(int i = 1; i <= n; i++)
    {
        int ai;
        scanf("%d", &ai);
        if(ai != i){
            arestas[i].push_back(make_pair(1, ai));
        }
    }
    
    Dijkstra(1);
    for(int i = 1; i <= n; i++)
    {
        if(i > 1)
            printf(" ");
        printf("%d", dist[i]);
    }
    
    printf("\n");
}