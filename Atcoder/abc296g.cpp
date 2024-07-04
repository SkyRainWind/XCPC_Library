// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;
const double eps = 1e-10;

typedef long double db;
int n;
struct point{
	db x,y;
}p[maxn];

point operator - (point a,point b){return point{a.x - b.x, a.y - b.y};}
point operator + (point a,point b){return point{a.x + b.x, a.y + b.y};}

db cross(point a,point b){return a.x * b.y - a.y * b.x;}
// 右手定则拇指向上，叉积为正，否则为负 

vector<point>up,dn;
int stk[maxn];

point rot(point now,db th){	// 逆时针旋转 th 
	db x1 = now.x*cos(th) - now.y*sin(th);
	db y1 = now.x*sin(th) + now.y*cos(th);
	return point{x1,y1};
}

mt19937 mrand(random_device{}()); 
double rnd(int x) { return (mrand() % x+1) * 1.0 / x;}
map<db,db>mpx,mpn;

int sgn(double x){
	if(fabs(x) < eps)return 0;
	if(x < -eps)return -1;
	return 1;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%Lf%Lf",&p[i].x,&p[i].y);
		if(!mpx.count(p[i].x))mpx[p[i].x] = p[i].y;
		else mpx[p[i].x] = max(mpx[p[i].x], p[i].y);
		if(!mpn.count(p[i].x))mpn[p[i].x] = p[i].y;
		else mpn[p[i].x] = min(mpn[p[i].x], p[i].y);
	}
	sort(p+1,p+n+1,[&](point a,point b){return a.x==b.x?a.y<b.y:a.x<b.x;});
	
	int tp=0;
	stk[++ tp] = 1;
	for(int i=2;i<=n;i++){
		while(tp > 1 && cross(p[stk[tp-1]] - p[stk[tp]], p[stk[tp]] - p[i]) > 0)
			-- tp;
		stk[++ tp] = i;
	}
	for(int i=1;i<=tp;i++)up.pb(p[stk[i]]);
	
	tp = 0;
	stk[++ tp] = 1;
	for(int i=2;i<=n;i++){
		while(tp > 1 && cross(p[stk[tp-1]] - p[stk[tp]], p[stk[tp]] - p[i]) < 0)
			-- tp;
		stk[++ tp] = i;
	}
	for(int i=1;i<=tp;i++)dn.pb(p[stk[i]]);
	
	int qu;scanf("%d",&qu);
	while(qu --){
		db x,y;scanf("%Lf%Lf",&x,&y);
		
		int l=0, r=up.size()-1, r1 =-1;
		if(sgn(up[0].x-x)==1 || sgn(up[up.size()-1].x-x)==-1){
			puts("OUT");
			continue;
		}
		if(mpx.count(x) && sgn(mpx[x]-mpn[x])){
			if(sgn(y-mpn[x]) >=0 && sgn(mpx[x]-y) >= 0)puts("ON");
			else puts("OUT");
			continue; 
		}
		while(l <= r){
			int mid = l+r>>1;
			if(sgn(up[mid].x-x)<=0)r1 = mid, l=mid+1;
			else r=mid-1;
		}
		l=0, r=dn.size()-1;
		int r2 =-1;
		while(l <= r){
			int mid = l+r>>1;
			if(sgn(dn[mid].x-x)<=0)r2 = mid, l=mid+1;
			else r=mid-1;
		}
		
		// 找到对应的两个点 up[r1],up[r1+1], dn[r2],dn[r2+1] 
		db y1, y2;
		if(r1 == up.size()-1)y1 = up[up.size()-1].y;
		else y1 = (x - up[r1].x) * 1.0 / (up[r1+1].x - up[r1].x) * (up[r1+1].y - up[r1].y) + up[r1].y;
		
		if(r2 == dn.size()-1)y2 = dn[dn.size()-1].y;
		else y2 = (x - dn[r2].x) * 1.0 / (dn[r2+1].x - dn[r2].x) * (dn[r2+1].y - dn[r2].y) + dn[r2].y;
		if(fabs(y1-y) < eps || fabs(y2-y) < eps)puts("ON");
		else if(sgn(y1-y) == 1 && sgn(y-y2) == 1)puts("IN");
		else puts("OUT");
	}

	return 0;
}

