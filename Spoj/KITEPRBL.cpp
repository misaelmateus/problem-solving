/* Geometry 2D */
#include<bits/stdc++.h>
using namespace std;
 
inline int readInt()
{
    bool minus = false;
    register int result = 0;
    register char ch = getchar_unlocked();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break ;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; 
    else result = ch-'0';
    while (true)
    {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus) return -result;
    else return result;
}

 
const double pi = acos(-1.0);
const double EPS = 1e-9;
const double INF = 1e50;
 
struct pt;
typedef pair<pt, pt> line;
typedef vector<pt> polygon;
 
//funcao de comparacao
int cmp(double a, double b = 0.0){
    if(fabs(a-b) < EPS) return 0;
    return a > b ? 1 : -1;
}
 
//estrutura que representa um ponto
// ou um vetor dependendo da necessidade
struct pt{
    double x, y;
    int id;
    pt(double x = 0.0, double y = 0.0) : x(x), y(y) {}
     
    double length() { return sqrt(x*x + y*y); }
    double length2() { return x*x + y*y; }
     
    pt normalize(){
        return (*this)/length();
    }
     
    pt operator - (pt p){ return pt(x - p.x, y - p.y); }
    pt operator + (pt p){ return pt(x + p.x, y + p.y); }
    pt operator * (double k){ return pt(x * k, y * k); }
    pt operator / (double k){ return pt(x / k, y / k); }
    bool operator < (const pt& p) const{
        if(fabs( x - p.x ) >= EPS) return x < p.x;
        return y < p.y;
    }
    bool operator == (const pt p){
        return ( fabs(x - p.x) < EPS && fabs(y - p.y) < EPS );
    }
};
 
////////////////////
// Funcoes basicas
 
double dist(pt a, pt b){ return (a - b).length(); }
double dot(pt a, pt b){ return a.x*b.x + a.y*b.y; }
double cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
double signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c))/2.0; }
 

/////////////////////
// Orientacao
 
//Determina o lado que c esta em relacao ao vetor a->b
//1  -> left
//0  -> on
//-1 -> right
int side_sign(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)); }
bool cw(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)) > 0; }
bool ccw(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)) < 0; }
bool colinear(pt a, pt b, pt c){ return !cmp(signed_area(a, b, c)); }
 
//testa se c esta na caixa limitada por a e b
bool in_box(pt a, pt b, pt c){
    return ( cmp(c.x, min(a.x, b.x)) >= 0 && cmp(c.x, max(a.x, b.x)) <= 0
        &&   cmp(c.y, min(a.y, b.y)) >= 0 && cmp(c.y, max(a.y, b.y)) <= 0 );
}
 
//////////////////////////////
// Ponto mais proximo
 
//determina o ponto mais proximo de c
//na reta ab
pt closest_point(pt a, pt b, pt c){
    //se colinares
    if( fabs( signed_area(a, b, c) ) < EPS) return c;
    pt dir = b-a;
    return a + ( dir*dot(dir, c-a)/dir.length2() );
}
 
//determina o ponto mais proximo de c
//no segmento ab
pt closest_point_seg(pt a, pt b, pt c){
    if( fabs( signed_area(a, b, c) ) < EPS) return c;
    pt close = closest_point(a, b, c);
    if( in_box(a, b, close) ) return close;
    return dist(a, c) < dist(b, c) ? a : b;
}
 
////////////////////////////////
//Angulos
 
//retorna o angulo entre os vetores a->b e a->c
//angulo com sinal
double angle(pt a, pt b, pt c){
    pt va = b-a, v = c-a;
    //va.normalize(); **nao parece ser necessario
    pt vb(-va.y, va.x);
    return atan2( dot(v, vb), dot(v, va) );
}
 
//retorna o angulo entre os vetorre a-> e a->c
//angulo sem sinal
double angle_2(pt a, pt b, pt c){
    pt va = b-a, vb = c-a;
    return acos(dot(va, vb) / (va.length() * vb.length()));
}
 
//Lei dos cossenos determina - o angulo A
double angle(double a, double b, double c){
    return acos( (b*b + c*c - a*a)/(2.0*b*c) );
}
 
//gira a em torno da origem por theta radianos
pt rotate(pt a, double theta){ return pt(cos(theta)*a.x - sin(theta)*a.y, sin(theta)*a.x + cos(theta)*a.y); }
 
//gira b em torno de a por theta radianos
pt rotate(pt a, pt b, double theta){ return a + rotate(b-a, theta); }
 
//reflete c em torno de a->b
pt reflect(pt a, pt b, pt c){
    double theta = angle(a, b, c);
    return rotate(c-a, -2.0*theta) + a;
}
 
 
///////////////////////////
// Intersecoes
 
//verifica se o ponto c se encontra no segmento ab
bool point_and_seg(pt a, pt b, pt c){
    if( !colinear(a, b, c) ) return false;
    return in_box(a, b, c); 
}
 
//interseccao entre as retas a->b e c->d e guarda em inter
bool intersect(pt a, pt b, pt c, pt d, pt& inter){
    double det = cross(b-a, d-c);
    if(fabs(det) < EPS){
        if( fabs(signed_area(a, b, c) ) < EPS){
            inter = pt(INF, INF); 
            return true; //retas coincidentes
        }
        return false; //retas paralelas
    }
    //retas concorrentes
    double ua = ( cross(d-c, a-c) )/det; //parametros (pode ser importante)
//  double ub = ( cross(b-a, a-c) )/det;
    inter = a + (b-a)*ua;
    return true;
}
 
//testa se exsite interseccao entre os dois segmentos
bool intersect_seg(pt a, pt b, pt c, pt d, pt& inter){
    if( !intersect(a, b, c, d, inter) ) return false; //segmentos paralelos
     
    if( inter == pt(INF, INF) )
        return in_box(a, b, min(c, d)) || in_box(c, d, min(a, b)); //segmentos sobrepostos
         
    return in_box(a, b, inter) && in_box(c, d, inter); //segmentos concorrentes
}
 
//intersecao entre reta e circunferencia
bool intersect(pt center, double r, pt a, pt b, pt& r1, pt& r2){
    pt close = closest_point(a, b, center);
    double x = dist(center, close);
     
    if( cmp(x, r) > 0 ) return false;
     
    double d = sqrt(r*r - x*x);
     
    pt v = (b - a);
    r1 = close - (v*d/v.length());
    r2 = close + (v*d/v.length());
    return true;
}
 
//intersecao de ciucunferencias
bool intersect(pt c1, double r1, pt c2, double r2, pt& p1, pt& p2){
    double d = dist(c1, c2);
    if(r1 < r2) { swap(c1, c2); swap(r1, r2); }
    if( cmp(d, r1+r2) > 0 || cmp(d, r1-r2) < 0) return false; //nao tem intersecao
    if( !cmp(d) && !cmp(r1, r2) ) return true; //sao iguais
     
    pt v = c2 - c1;
    p1 = c1 + v*r1/v.length();
    if( !cmp(d-r1-r2) || !cmp(d+r2-r1) ){ p2 = p1; return true; } //tengencia interna/externa
     
    double theta = angle(r2, d, r1);
    p2 = rotate(c1, p1, theta);
    p1 = rotate(c1, p1, -theta);
    return true;
}
 
///////////////////////////////////
// Areas, perimetros e convexidade
 
double trap(pt& a, pt& b){ return 0.5*(b.x - a.x)*(b.y + a.y); }
 
double area(polygon& poly){
    double ret = 0.0;
    for(int i = 0; i < poly.size(); i++){
        ret += trap(poly[i], poly[(i+1)%poly.size()]);
    }
    return fabs(ret);
}
 
//Determina se o poligono simples eh convexo
bool is_convex(polygon& p){
    int left = 0, right = 0, side;
    for(int i = 0; i < p.size(); i++){
        side = side_sign(p[i], p[(i+1)%p.size()], p[(i+2)%p.size()]);
        if(side < 0) right++;
        if(side > 0) left++;
    }
    return !(left && right);
 }

//testa se o ponto esta dentro de um poligono (nao necessariamente convexo)
bool inside_poly(pt p, polygon poly){
    poly.push_back(poly[0]);
     
    for(int i = 0; i < poly.size()-1; i++)
        if(point_and_seg(poly[i], poly[i+1], p)) return false; //na borda
     
    for(int i = 0; i < poly.size()-1; i++) poly[i] = poly[i] - p;
    p = pt(0, 0);
     
    double theta, y;
     
    while(true){
        theta = (double)rand()/10000.0;
         
        bool inter = false;
        //evita que um ponto fique no eixo x
        for(int i = 0; i < poly.size()-1; i++){
            poly[i] = rotate(poly[i], theta);
            if( !cmp(poly[i].x) ) inter = true;
        }
         
        if( !inter ){
            poly[poly.size()-1] = poly[0];
            //testa as possiveis intersecoes
            for(int i = 0; i < poly.size()-1; i++){
                if( cmp( poly[i].x * poly[i+1].x ) < 0 ){
                    y = poly[i+1].y - poly[i+1].x * (poly[i].y - poly[i+1].y) / (poly[i].x - poly[i+1].x);
                    if( cmp(y) > 0 ) inter = !inter; //se interecao valida
                }
            }
            return inter; //testa a paridade da semi-reta vertical partindo de p
        }
    }
    return true;
}

 int main(){
    srand(time(NULL));
    int T;
    T = readInt();
    while(T--){
        int n;
        scanf("%d", &n);
        polygon p(n);
        for(int i = 0; i < n; i++){
            p[i].x = readInt();
            p[i].y = readInt();
        }
        double area1 = area(p)*2;
        printf("%.3lf ", area1);
        bool convex = is_convex(p);
        int m;
        scanf("%d", &m);
        double x, y;
        for(int i = 1; i<= m; i++){
            x = readInt();
            y = readInt();
            if(inside_poly(pt(x, y), p))
                printf("%d ", i);
        }
        printf("%d\n", convex);
    }
 }