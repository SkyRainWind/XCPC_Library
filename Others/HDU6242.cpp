// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pdd pair<double,double>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;
const double eps = 1e-3;

int id[maxn];
pdd a[maxn];
int n;
struct line{
	double a,b,c;
};

double dis(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

line get(pdd a,pdd b){
	double A = b.first - a.first;
	double B = b.second - a.second;
	double midx = 0.5 * (a.first + b.first);
	double midy = 0.5 * (a.second + b.second);
	double C = (A*midx + B*midy);
	return line{A,B,C};
}

double det(double a1,double a2,double b1,double b2){
	return a1 * b2 - a2 * b1;
}

pdd cross(line a, line b){
	// ax+by = c;
	double det0 = det(a.a,a.b,b.a,b.b);
	double det1 = det(a.c,a.b,b.c,b.b);
	double det2 = det(a.a,a.c,b.a,b.c);
	if(det0 == 0)return mpr(998244353,0);

	return mpr(det1 / det0, det2 / det0);
}

mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x + 1;}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].first,&a[i].second), id[i] = i;
	if(n == 1){
		printf("%f %f 0\n",a[1].first,a[1].second);
		return ;
	}
	if(n <= 4){
		double tx = 0.5 * (a[1].first + a[2].first);
		double ty = 0.5 * (a[1].second + a[2].second);
		double dd = dis(tx,ty,a[1].first,a[1].second);
		printf("%f %f %f\n",tx,ty,dd);
		return ;
	}
	int cnt = 0;
	while(1){
		vector<int>vis(n+1,0);
		int i1 = rnd(n);
		vis[i1] = 1;
		vector<pdd>v(4);
		v[1] = a[i1];
		for(int i=1;i<=2;){
			int ii = rnd(n);
			if(!vis[ii]){
				vis[ii] = 1;
				++ i;
				v[i] = a[ii];
			}
		}
		// random_shuffle(id+1,id+n+1);
		line l1 = get(v[1], v[2]);
		line l2 = get(v[2], v[3]);
//		for(int i=1;i<=3;i++)printf("%Lf %Lf\n",v[i].first,v[i].second);
//		puts("");

		pdd cs = cross(l1, l2);
		if(fabs(cs.first-998244353) < eps)continue;
		double R = dis(v[1].first,v[1].second,cs.first,cs.second);
		if(fabs(R) <= 1e9 && fabs(cs.first) <= 1e9 && fabs(cs.second) <= 1e9);
		else continue;

		int cnt = 0;
		for(int i=1;i<=n;i++){
			if(fabs(dis(a[i].first,a[i].second,cs.first,cs.second) - R) < eps)
				++ cnt;
		}
		if(cnt >= (n+1) / 2){
			printf("%f %f %f\n",cs.first,cs.second,R);
			return ;
		}
	}
}

signed main(){
//	while(1){
//		for(int i=1;i<=3;i++)scanf("%Lf%Lf",&a[i].first,&a[i].second);
//		line l1 = get(a[1],a[2]);
//		line l2 = get(a[2], a[3]);
//		printf("%Lfx + %Lfy = %Lf\n",l1.a,l1.b,l1.c);
//		printf("%Lfx + %Lfy = %Lf\n",l2.a,l2.b,l2.c);
//		pdd cs = cross(l1, l2);
//		if(fabs(cs.first-998244353) < eps)continue;
//		printf("(%Lf, %Lf)\n",cs.first,cs.second);
//	}
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}
