#include<bits/stdc++.h>

typedef double T;
struct pt {
	T x,y;
	pt operator+(pt p) {return {x+p.x, y+p.y};}
	pt operator-(pt p) {return {x-p.x, y-p.y};}
	pt operator*(T d) {return {x*d, y*d};}
	pt operator/(T d) {return {x/d, y/d};} // only for floatingpoint
	
	bool operator==(pt a, pt b) {return a.x == b.x && a.y == b.y;}
	bool operator!=(pt a, pt b) {return !(a == b);}


	ostream& operator<<(ostream& os, pt p) {
		return os << "("<< p.x << "," << p.y << ")";
	}
};
T sq(pt p) {return p.x*p.x + p.y*p.y;}
double abs(pt p) {return sqrt(sq(p));}

// rotate 90º
pt perp(pt p) {return {-p.y, p.x};}

pt rot(pt p, double a) {
	return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)};
}

T dot(pt v, pt w) {return v.x*w.x + v.y*w.y;}
T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}

// anti-horario: > 0
// horario : < 0
// colinear: = 0
T orient(pt a, pt b, pt c) {return cross(b-a,c-a);}

pt scale(pt c, double factor, pt p) {
	return c + (p-c)*factor;
}

// angle in [0, PI]
double angle(pt v, pt w) {
	double cosTheta = dot(v,w) / abs(v) / abs(w);
	return acos(max(-1.0, min(1.0, cosTheta)));
}

bool isConvex(vector<pt> p) {
	bool hasPos=false, hasNeg=false;
	for (int i=0, n=p.size(); i<n; i++) {
		int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
		if (o > 0) hasPos = true;
		if (o < 0) hasNeg = true;
	}
	return !(hasPos && hasNeg);
}

bool half(pt p) { // true if in blue half
	assert(p.x != 0 || p.y != 0); // the argument of (0,0) is undefined
	return p.y > 0 || (p.y == 0 && p.x < 0);
}

// use when want to do polar starting in point v, v is the first in the polar sort
bool half(pt p, pt v){
	return cross(v,p) < 0 || (cross(v,p) == 0 && dot(v,p) < 0);

}
void polarSort(vector<pt> &v) {
	sort(v.begin(), v.end(), [](pt v, pt w) {
		return make_tuple(half(v), 0, sq(v)) <
	    	   make_tuple(half(w), cross(v,w), sq(w)); 
	});

	/* if want to do polar around point O do 
		return make_tuple(half(v-o), 0)) <
			   make_tuple(half(w-o), cross(v-o, w-o));
	*/
}


// Line
struct line {
	pt v; T c;
	// From direction vector v and offset c
	line(pt v, T c) : v(v), c(c) {}
	// From equation ax+by=c
	line(T a, T b, T c) : v({b,-a}), c(c) {}
	// From points P and Q
	line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
	
	// - these work with T = int
	
	
	// positive if in the left side and negative if in the right side
	T side(pt p) {return cross(v,p)-c;}
	double dist(pt p) {return abs(side(p)) / abs(v);}
	double sqDist(pt p) {return side(p)*side(p) / (double)sq(v);}
	// line perpendicular to this line passes in point P
	line perpThrough(pt p) {return {p, p + perp(v)};}
	// compare two projections on a line, what comes before in direction v
	bool cmpProj(pt p, pt q) {
		return dot(v,p) < dot(v,q);
	}
	line translate(pt t) {return {v, c + cross(v,t)};}
	
	// - these require T = double
	line shiftLeft(double dist) {return {v, c + dist*abs(v)};}
	// project of point in v
	pt proj(pt p) {return p - perp(v)*side(p)/sq(v)};

	// reflection on point by a line
	pt refl(pt p) {return p - perp(v)*2*side(p)/sq(v);}
};

bool inter(line l1, line l2, pt &out) {
	T d = cross(l1.v, l2.v);
	if (d == 0) return false;
	out = (l2.v*l1.c - l1.v*l2.c) / d; // requires floating-point coordinates
	return true;
}

// return the intern or extern bissector
line bisector(line l1, line l2, bool interior) { 
	assert(cross(l1.v, l2.v) != 0); // l1 and l2 cannot be parallel!
	double sign = interior ? 1 : -1;
	return {l2.v/abs(l2.v) + l1.v/abs(l1.v) * sign,
			l2.c/abs(l2.v) + l1.c/abs(l1.v) * sign};
}

// return if point is in a disk of diameter a,b ( p != a, b)
bool inDisk(pt a, pt b, pt p) {
	return dot(a-p, b-p) <= 0;
}

// if p is in segment (a, b)
bool onSegment(pt a, pt b, pt p) {
	return (p == a || p == b) || orient(a,b,p) == 0 && inDisk(a,b,p);
}

// if has intersection with only one point
bool properInter(pt a, pt b, pt c, pt d, pt &out) {
	double oa = orient(c,d,a),
	ob = orient(c,d,b),
	oc = orient(a,b,c),
	od = orient(a,b,d);
	// Proper intersection exists iff opposite signs
	if (oa*ob < 0 && oc*od < 0) {
		out = (a*ob - b*oa) / (ob-oa);
		return true;
	}
	return false;
}

// To create sets of points we need a comparison function
struct cmpX {
	bool operator()(pt a, pt b) {
		return make_pair(a.x, a.y) < make_pair(b.x, b.y);
	}
};
// create set with intersection : 1 point if has one intersection, 2 points if there is a segment
set<pt,cmpX> inters(pt a, pt b, pt c, pt d) {
	pt out;
	if (properInter(a,b,c,d,out)) return {out};
	set<pt,cmpX> s;
	if (onSegment(c,d,a)) s.insert(a);
	if (onSegment(c,d,b)) s.insert(b);
	if (onSegment(a,b,c)) s.insert(c);
	if (onSegment(a,b,d)) s.insert(d);
	return s;
}

// dist seg to point
double segPoint(pt a, pt b, pt p) {
	if (a != b) {
		line l(a,b);
		if (l.cmpProj(a,p) && l.cmpProj(p,b)) // if closest to projection
			return l.dist(p); // output distance toline
	}
	return min(abs(p-a), abs(p-b)); // otherwise distance to A or B
}

// dist segment to segment
double segSeg(pt a, pt b, pt c, pt d) {
	pt dummy;
	if (properInter(a,b,c,d,dummy))
		return 0;
	return min({segPoint(a,b,c), segPoint(a,b,d), segPoint(c,d,a), segPoint(c,d,b)});
}


double areaTriangle(pt a, pt b, pt c) {
	return abs(cross(b-a, c-a)) / 2.0;
}
double areaPolygon(vector<pt> p) {
	double area = 0.0;
	for (int i = 0, n = p.size(); i < n; i++) {
		area += cross(p[i], p[(i+1)%n]); // wrap back to 0 if i == n-1
	}
	return abs(area) / 2.0;
}


// true if P at least as high as A (blue part)
bool above(pt a, pt p) {
	return p.y >= a.y;
}
// check if [PQ] crosses ray from A
bool crossesRay(pt a, pt p, pt q) {
	return (above(a,q) - above(a,p)) * orient(a,p,q) > 0;
}
// if strict, returns false when A is on the boundary
bool inPolygon(vector<pt> p, pt a, bool strict = true) {
	int numCrossings = 0;
	for (int i = 0, n = p.size(); i < n; i++) {
		if (onSegment(p[i], p[(i+1)%n], a))
			return !strict;
		numCrossings += crossesRay(a, p[i], p[(i+1)%n]);
	}
	return numCrossings & 1; // inside if odd number of crossings
}
int main(){

	return 0;
}