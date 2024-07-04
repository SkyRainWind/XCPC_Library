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

typedef int db;
namespace geo{
	#define rep(i,a,n) for(int i=(a);i<(n);i++)
	#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)
	
	const db EPS = 1e-8;
	
	inline int sign(db a) {
		return a < -EPS ? -1 : a > EPS;
	}
	
	inline int cmp(db a, db b){
		return sign(a-b);
	}
	
	struct P {
		db x, y;
		P() {}
		P(db _x, db _y) : x(_x), y(_y) {}
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
	
	int contain(vector<P> ps, P p){ //2:inside,1:on_seg,0:outside
		int n = ps.size(), ret = 0;	
		rep(i,0,n){
			P u=ps[i],v=ps[(i+1)%n];
			if(onSeg(u,v,p)) return 1;
			if(cmp(u.y,v.y)<=0) swap(u,v);
			if(cmp(p.y,u.y) >0 || cmp(p.y,v.y) <= 0) continue;
			ret ^= crossOp(p,u,v) > 0;
		}
		return ret*2;
	}
	
	vector<P> convexHull(vector<P> ps) {
	    int n = ps.size(); if(n <= 1) return ps;
	    sort(ps.begin(), ps.end());
	    vector<P> qs(n * 2); int k = 0;
	    for (int i = 0; i < n; qs[k++] = ps[i++]) 
	        while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
	    for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
	       	while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
	    qs.resize(k - 1);
	    return qs;
	}
	
	vector<P> convexHullNonStrict(vector<P> ps) {
		//caution: need to unique the Ps first
	    int n = ps.size(); if(n <= 1) return ps;
	    sort(ps.begin(), ps.end());
	    vector<P> qs(n * 2); int k = 0;
	    for (int i = 0; i < n; qs[k++] = ps[i++]) 
	        while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) < 0) --k;
	    for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
	       	while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) < 0) --k;
	    qs.resize(k - 1);
	    return qs;
	}
	
	db convexDiameter(vector<P> ps){
		int n = ps.size(); if(n <= 1) return 0;
		int is = 0, js = 0; rep(k,1,n) is = ps[k]<ps[is]?k:is, js = ps[js] < ps[k]?k:js;
		int i = is, j = js;
		db ret = ps[i].distTo(ps[j]);
		do{
			if((ps[(i+1)%n]-ps[i]).det(ps[(j+1)%n]-ps[j]) >= 0)
				(++j)%=n;
			else
				(++i)%=n;
			ret = max(ret,ps[i].distTo(ps[j]));
		}while(i!=is || j!=js);
		return ret;
	}
	
	// left part of segment (q1->q2)
	vector<P> convexCut(const vector<P>&ps, P q1, P q2) {
		vector<P> qs;
		int n = ps.size();
		rep(i,0,n){
			P p1 = ps[i], p2 = ps[(i+1)%n];
			int d1 = crossOp(q1,q2,p1), d2 = crossOp(q1,q2,p2);
			if(d1 >= 0) qs.pb(p1);
			if(d1 * d2 < 0) qs.pb(isLL(p1,p2,q1,q2));
		}
		return qs;
	}
	
	//min_dist
	// 最近点对，需要先对 ps 按 x 坐标排序 
}

vector<geo::P>a;

struct node{
	geo::P p;
	int id, st;
	// 1 下 2 左 3 右 4 上 
}all[200005];
geo::L se[200005];
int n; 

signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++){
		geo::L ls;
		ls[0].read(); ls[1].read();
		if(ls[0].x==ls[1].x){
			if(ls[0].y > ls[1].y)swap(ls[0], ls[1]);
		}else if(ls[0].x > ls[1].x)swap(ls[0], ls[1]);
		
		if(ls[0].y==ls[1].y)all[i*2-1] = node{ls[0],i,2}, all[i*2]=node{ls[1],i,3};
		else all[i*2-1]=node{ls[0],i,1}, all[i*2]=node{ls[1],i,4};
		se[i] = ls;
	}
	sort(all+1,all+n*2+1,[&](node a,node b){
		if(a.p.y == b.p.y)return a.st < b.st;
		return a.p.y < b.p.y;
	});
	set<int> S;
	S.insert(-1e9-1);S.insert(1e9+1);
	ll ans = 0;
	for(int i=1;i<=n*2;i++){
		if(all[i].st == 1){
			S.insert(all[i].p.x);
		}else if(all[i].st == 4)S.erase(all[i].p.x);
		else if(all[i].st == 2){
			geo::P p = se[all[i].id][0], q = se[all[i].id][1];
			set<int>::iterator pit = lower_bound(S.begin(),S.end(),p.x);
			set<int>::iterator qit = upper_bound(S.begin(),S.end(),q.x);
			ans += distance(pit,qit);
		}
	}
	cout << ans << '\n';

	return 0;
}

