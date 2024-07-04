// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;
const double eps = 1e-7;

int n;
struct po{double x,y;}p[maxn];
int stk[maxn];

double slope(int x1,int y1,int op){
	po x = p[x1], y = p[y1];
	if(fabs(x.x-y.x) < eps)return op==1?0:1e13;
	return (x.y - y.y) / (x.x - y.x);
}

double dist(int x1,int y1){
	po x=p[x1], y=p[y1];
	return sqrt((x.x-y.x)*(x.x-y.x) + (x.y-y.y) * (x.y-y.y));
}

po rot(po now,double th){
	double x1 = now.x*cos(th) - now.y*sin(th);
	double y1 = now.x*sin(th) + now.y*cos(th);
	return po{x1,y1};
}

mt19937 mrand(random_device{}()); 
double rnd(int x) { return mrand() % x * 1.0 / x;}

signed main(){
//	freopen("2742.in","r",stdin);
	scanf("%d",&n);
	double ang = rnd(360);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&p[i].x,&p[i].y), p[i] = rot(p[i], ang);
	sort(p+1,p+n+1,[&](po a,po b){return a.x==b.x?a.y>b.y:a.x<b.x;});
	
	int tp=0;
	stk[++tp] = 1;
	for(int i=2;i<=n;i++){
		while(tp>1 && slope(stk[tp-1], stk[tp], 1) - slope(stk[tp], i, 1) > eps)-- tp;
		stk[++ tp] = i;
	}
	double ans=0.0;
	for(int i=1;i<tp;i++)ans += dist(stk[i],stk[i+1]);
	
	sort(p+1,p+n+1,[&](po a,po b){return a.x==b.x?a.y<b.y:a.x<b.x;});
	tp=0;
	stk[++tp] = 1;
	for(int i=2;i<=n;i++){
		while(tp>1 && slope(stk[tp-1], stk[tp], -1) - slope(stk[tp], i, -1) < -eps)-- tp;
		stk[++ tp] = i;
	}
	for(int i=1;i<tp;i++)ans += dist(stk[i],stk[i+1]);
	printf("%.2f\n",ans);

	return 0;
}

