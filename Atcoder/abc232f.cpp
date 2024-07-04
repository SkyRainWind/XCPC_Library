// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

typedef double ll;
namespace geo{
	#define rep(i,a,n) for(int i=(a);i<(n);i++)
	#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)
	
	inline int sign(db a) {
		return a < -EPS ? -1 : a > EPS;
	}
	
	inline int cmp(db a, db b){
		return sign(a-b);
	}
	
	struct P {
		ll x, y;
		P() {}
		P(ll _x, ll _y) : x(_x), y(_y) {}
	};
	
	struct L{ //ps[0] -> ps[1]
		P ps[2];
		P& operator[](int i) { return ps[i]; }
		P dir() { return ps[1] - ps[0]; }
	 	bool include(P p) { return sign((ps[1] - ps[0]).det(p - ps[0])) > 0; }
	 	L push(){ // push eps outward
	 		const double eps = 1e-6;
	 		P delta = (ps[1] - ps[0]).rot90().unit() * eps;
	 		return {ps[0] - delta, ps[1] - delta};
	 	}
	};
	
	// det value of (p1->p2) x (p1->p3)
	db cross(P p1,P p2,P p3){return ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y));}	
	#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))
	
	P rot(P now,db th){	// 逆时针旋转 th 
		db x1 = now.x*cos(th) - now.y*sin(th);
		db y1 = now.x*sin(th) + now.y*cos(th);
		return P{x1,y1};
	}
	
	P isLL(P p1, P p2, P q1, P q2) {
		db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
		return (p1 * a2 + p2 * a1) / (a1 + a2);
	}
	
	// return intersect point (l1 l2 is line not segment)
	P isLL(L l1,L l2){ return isLL(l1[0],l1[1],l2[0],l2[1]); }
	
	bool intersect(db l1,db r1,db l2,db r2){
		if(l1>r1) swap(l1,r1); if(l2>r2) swap(l2,r2); 
		return !( cmp(r1,l2) == -1 || cmp(r2,l1) == -1 );
	}
	
	// if segment (p1->p2), (q1->q2) intersect(including end point) -> 1
	bool isSS(P p1, P p2, P q1, P q2){
	    return intersect(p1.x,p2.x,q1.x,q2.x) && intersect(p1.y,p2.y,q1.y,q2.y) && 
	    crossOp(p1,p2,q1) * crossOp(p1,p2,q2) <= 0 && crossOp(q1,q2,p1)
	            * crossOp(q1,q2,p2) <= 0;
	}
	
	
	db disSS(P p1, P p2, P q1, P q2){
		if(isSS(p1,p2,q1,q2)) return 0;
		return min(min(nearest(p1,p2,q1),nearest(p1,p2,q2)), min(nearest(q1,q2,p1),nearest(q1,q2,p2)) );
	}
	
	// p1 转向 p2（右手定则）的角度，拇指向上则为 + 否则为 -
	// rad(P(1,1), P(2,0)) = -pi/4, rad(P(-1,-1),P(2,0)) = 3*pi / 4 
	db rad(P p1,P p2){
		return atan2l(p1.det(p2),p1.dot(p2));
	}
}

ll mht(geo::P p1, geo::P p2){
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

geo::P p[5];

signed main(){
	ios::sync_with_stdio(false);
	p[1].read(), p[2].read(), p[3].read();
	p[1] = p[1] - p[2], p[3] = p[3] - p[2];
	
	geo::P delt = p[3];
	p[2] = geo::P(0,0);
	
//	if(p[1].x == p[2].x && p[2].x == p[3].x){
//		
//	}
	
	int sx=1,sy=1;
	if(delt.x < 0)sx = -1;
	if(delt.y < 0)sy = -1;
	
	p[1] = geo::P(p[1].x*sx, p[1].y*sy);
	p[3] = geo::P(p[3].x*sx, p[3].y*sy);
	
	ll res = min(mht(p[1], geo::P(0,-1)), mht(p[1], geo::P(-1,0)));
	if(p[3].x == 0){
		ll r1 = mht(p[1], geo::P(0,-1));
		if(p[1].x ==0 && p[1].y > 0)r1 += 2;
		cout << r1 + p[3].y <<'\n';
		return 0;
	}
	if(p[3].y == 0){
		ll r1 = mht(p[1], geo::P(-1,0));
		if(p[1].y ==0 && p[1].x > 0)r1 += 2;
		cout << r1 + p[3].x <<'\n';
		return 0;
	}
	cout << res + p[3].x + p[3].y + 2 << '\n';

	return 0;
}

