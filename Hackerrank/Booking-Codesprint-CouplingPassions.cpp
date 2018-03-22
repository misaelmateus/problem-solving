#include<bits/stdc++.h>
#define ld long double
#define pi 3.14159265359
using namespace std;
struct point{
    ld lat, lon;
} ;
ld degree2radians(ld A){
    while(A < 0)
        A += 360.;
    while(A >= 360.0000000000000)
        A -= 360.;
    return (A*pi)/180.;
}
ld dist(point point1, point point2) {
    ld EARTH_RADIUS = 6371.;//in km
    ld point1_lat_in_radians  = degree2radians( point1.lat );
    ld point2_lat_in_radians  = degree2radians( point2.lat );
    ld point1_long_in_radians  = degree2radians( point1.lon );
    ld point2_long_in_radians  = degree2radians( point2.lon );

    return acos( sin( point1_lat_in_radians ) * sin( point2_lat_in_radians ) +
                 cos( point1_lat_in_radians ) * cos( point2_lat_in_radians ) *
                 cos( point2_long_in_radians - point1_long_in_radians) ) * EARTH_RADIUS;
}


int main(){
    ios::sync_with_stdio( false );
    int n, m, aux = 1;
    map<string, int> mapa;

    vector< vector<string> > p(n);
    cin >> n;
    for(int i = 0; i < n; i++){
        int leng;
        cin >> leng;
        p[i] = vector<string>(leng);
        for(int j = 0; j < leng; j++){
            cin >> p[i][j];
            if(!mapa[p[i][j]])
                mapa[p[i][j]] = aux++;
                
        }
    }
    
    cin >> m;
    vector< vector<string> > d(m);
    vector< string > names(m);
    vector< point >  pts(m);
    for(int i = 0; i < m; i++){
        cin >> names[i];
        ld lat, lon;
        cin >> lat >> lon;
        pts[i].lat = lat;
        pts[i].lon = lon;
        
        int leng;
        cin >> leng;
        d[i] = vector<string>(leng);
        for(int j = 0; j < leng; j++)
            cin >> d[i][j];
    }

    int max = -1;
    
    set< pair<int, int> > resp;
    for(int i = 0; i < m; i++){
        for(int j = i; j < m; j++){
            if(i == j)
                continue;
            vector<int> mark(aux, 0);
            int cont = 0;
            for(int l = 0; l < d[i].size(); l++){
                if(!mark[mapa[d[i][l]]])
                    mark[mapa[d[i][l]]] = 1, cont++;
            }
            for(int l = 0; l < d[j].size(); l++){
                if(!mark[mapa[d[j][l]]])
                    mark[mapa[d[j][l]]] = 1, cont++;
            }
            if(cont > max){
                max = cont;
                resp.clear();
                resp.insert(make_pair(i, j));
            }
            if(cont == max){
                resp.insert(make_pair(i, j));
            }
        }        
    }
    pair<ld, ld> resp1 = make_pair(1, 1);
    ld men = 100000000.;
    
    for(set< pair<int, int> > :: iterator it = resp.begin(); it != resp.end(); ++it){
        ld atual = dist(pts[(*it).first], pts[(*it).second]);
        if(atual - men < -0.0000000001){
            men = atual;
            resp1 = (*it);
        }
    }
    string name1 = names[resp1.first], name2 = names[resp1.second];
    if(name1 < name2)
        cout << name1 << " " << name2 << endl;
    else
        cout << name2 << " " << name1 << endl;
    
    
    return 0;
}