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

int exgcd(int a,int b,int &x,int &y){
	if(!b){x=1,y=0;return a;}
	int ret = exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
	return ret;
}

typedef double db;
namespace geo{
	#define rep(i,a,n) for(int i=(a);i<(n);i++)
	#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)
	
	const db EPS = 1e-8, pi = acos(-1);
	
	inline int sign(db a) {
		return a < -EPS ? -1 : a > EPS;
	}
	
	inline int cmp(db a, db b){
		return sign(a-b);
	}
	
	struct P {
		db x, y;
		P() {}
		P(int _x, int _y) : x(_x), y(_y) {}
		P operator+(P p) { return P(x + p.x, y + p.y); }
		P operator-(P p) { return P(x - p.x, y - p.y); }
		P operator*(db d) { return P(x * d, y * d); }
		P operator/(db d) { return P(x / d, y / d); }
		bool operator<(P p) const { 
			int c = cmp(x, p.x);
			if (c) return c == -1;
			return cmp(y, p.y) == -1;
		}
		db dot(P p) { return x * p.x + y * p.y; }
		db det(P p) { return x * p.y - y * p.x; }	// a.det(b) <=> a x b
		db distTo(P p) { return (*this-p).abs(); }
		db alpha() { return atan2(y, x); }
		void read() { cin>>x>>y; }
		db abs() { return sqrt(abs2());}
		db abs2() { return x * x + y * y; }
		P rot90() { return P(-y,x);}
		P unit() { return *this/abs(); }
	    int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }
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
	
	// if segment(not line) l1 l2 intersect(including end point) -> 1
	bool isSS(L l1, L l2){return isSS(l1[0],l1[1],l2[0],l2[1]);}
	
	bool isMiddle(db a, db m, db b) {
	    return sign(a - m) == 0 || sign(b - m) == 0 || (a < m != b < m);
	}
	 
	bool isMiddle(P a, P m, P b) {
	    return isMiddle(a.x, m.x, b.x) && isMiddle(a.y, m.y, b.y);
	}
	
	// q on segment (p1->p2)
	bool onSeg(P p1, P p2, P q){
		return crossOp(p1,p2,q) == 0 && isMiddle(p1, q, p2);
	}
	
	P proj(P p1, P p2, P q) {
	    P dir = p2 - p1;
	    return p1 + dir * (dir.dot(q - p1) / dir.abs2());
	}
	
	db distToLP(P l1,P l2,P p){
		P to = proj(l1,l2,p);
		return to.distTo(p);
	}
	
	P reflect(P p1, P p2, P q){
		return proj(p1,p2,q) * 2 - q;
	}
	
	db nearest(P p1,P p2,P q){
		P h = proj(p1,p2,q);
		if(isMiddle(p1,h,p2))
			return q.distTo(h);
		return min(p1.distTo(q),p2.distTo(q));
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
	
	db incircle(P p1, P p2, P p3){
		db A = p1.distTo(p2);
		db B = p2.distTo(p3);
		db C = p3.distTo(p1);
		return sqrtl(A*B*C/(A+B+C));
	}
	
	//polygon
	
	db area(vector<P> ps){
		db ret = 0; rep(i,0,ps.size()) ret += ps[i].det(ps[(i+1)%ps.size()]); 
		return abs(ret/2);
	}
}

void solve(){
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	if(x1 == x2){
		printf("%d %d\n",x1+1,y1);
		return ;
	}
	if(y1 == y2){
		printf("%d %d\n",x1,y1+1);
		return ;
	}
	int b = y2-y1, a = x2-x1, k, non;
	int gd = __gcd(a,b);
	b /= gd, a /= gd;
	exgcd(a,b,non,k);
	printf("%d %d\n",x1+k,y1-non);
//	int tx = x1 + k, ty = y1 - (k*b-1) / a;
//	double s1 = geo::area(vector<geo::P>{geo::P(tx,ty),geo::P(x1,y1),geo::P(x2,y2)}); 
//	
//	exgcd(b,a,non,k);
//	int ax = x1 + (k*a-1) / b, ay = y1 - k;
//	double s2 = geo::area(vector<geo::P>{geo::P(ax,ay),geo::P(x1,y1),geo::P(x2,y2)}); 
//	
//	if(geo::sign(s1-s2) < 0)printf("%d %d\n",tx,ty);
//	else printf("%d %d\n",ax,ay);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

