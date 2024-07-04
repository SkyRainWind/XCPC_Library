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

int sgn(long double x){
	if(fabs(x) < 1e-12)return 0;
	if(x < 0)return -1;
	return 1;
}

// 感谢板子 
struct Point {
    double x,y;
    Point (){}
    Point (double _x,double _y):x(_x),y(_y){}
    double distance(const Point &b) const{
        return hypot(x-b.x,y-b.y);
    }
    double len(){return hypot(x,y);}
    Point operator +(const Point &b) const{return Point (x+b.x,y+b.y);}
    Point operator -(const Point &b) const{return Point (x-b.x,y-b.y);}
    double operator *(const Point &b)const{return x*b.x+y*b.y;}
    Point operator *(const double &k) const{return Point (x*k,y*k);}
    Point operator /(const double &k) const{return Point (x/k,y/k);}
    double operator ^(const Point &b)const {return x*b.y-y*b.x;}
    double len2(){return x*x+y*y;}	// hypot
    Point trunc(double r){
        double l=len();
        if (!sgn(l)) return *this;
        r/=l;
        return Point(x*r,y*r);
    }
    // 向左/右转 90 
    Point rotleft() {return Point(-y,x);}
    Point rotright(){return Point(y,-x);}
}s,e,p[200005];
vector<Point>v1,v2; 
ll ans = 0;
int bit[200005];

double cross(Point a,Point b){return a^b;}

int lb(int x){return x & (-x);}
void add(int x,int n){
	for(int i=x;i<=n;i+=lb(i))
		bit[i] ++;
}
int query(int x,int n){
	int r=0;
	for(int i=x;i;i-=lb(i))
		r += bit[i];
	return r;
}

int idx[200005],n;

void solve(vector<Point>p){
//	printf("? %d\n",v.size());
	int v1s=p.size();
	for(int i=1;i<=v1s;i++)idx[i] = i;
	
	sort(idx+1,idx+v1s+1,[&](int a,int b){
		return sgn(cross(p[a-1]-s, p[b-1]-s)) > 0;
	});
	
	vector<int>x(n+1),y(n+1);
	
	x[idx[1]] = 1;
	for(int i=2;i<=v1s;i++){
		x[idx[i]] = x[idx[i-1]] + (sgn(cross(p[idx[i-1]-1] - s, p[idx[i]-1] - s)) > 0);
	}
	
	sort(idx+1,idx+v1s+1,[&](int a,int b){
		return sgn(cross(p[a-1]-e, p[b-1]-e)) < 0;
	});
	
	y[idx[1]] = 1;
	for(int i=2;i<=v1s;i++){
		y[idx[i]] = y[idx[i-1]] + (sgn(cross(p[idx[i-1]-1] - e, p[idx[i]-1] - e)) < 0);
	}
	
	sort(idx+1,idx+v1s+1,[&](int a,int b){
		return x[a] == x[b] ? y[a] < y[b] : x[a] < x[b];
	});
	
	for(int i=1;i<=v1s;i++){
		ans += query(y[idx[i]], v1s);
		add(y[idx[i]], v1s);
	}
	
	for(int i=0;i<=v1s;i++)bit[i]=0;
}

signed main(){
	scanf("%lf%lf%lf%lf",&s.x,&s.y,&e.x,&e.y);
	scanf("%d",&n);
	int c2=0,c1=0;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&p[i].x,&p[i].y);
		if(sgn((p[i]-s) ^ (e-s)) == 0){
			if(sgn((p[i]-s) * (e-s)) < 0)++c1;
			else ++ c2;
		}else{
			if(sgn((p[i]-s) ^ (e-s)) < 0)v1.pb(p[i]);
			else v2.pb(p[i]);
		}
	} 
	ans = 0;
	ans += 1ll * c1 * (c1-1)/2;
	ans += 1ll * c2 * (c2-1)/2;
//	printf("he %d %d\n",c1,c2);
	solve(v1);
	swap(s, e);
	solve(v2);
	cout << ans << '\n'; 

	return 0;
}

