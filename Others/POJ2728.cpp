// by Balloons
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1 << 30;
const int maxn=5005;
const double eps=1e-6;

struct data{double x,y,h;}a[maxn];
double dis[maxn][maxn], h[maxn][maxn],p[maxn][maxn],line[maxn];
int vis[maxn];
int n;

double getdis(int x,int y){
	return sqrt((a[x].x-a[y].x)*(a[x].x-a[y].x) + (a[x].y-a[y].y)*(a[x].y-a[y].y));
}

double prim(double num){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			p[i][j] = h[i][j] - dis[i][j]*num;
	memset(vis,0,sizeof vis);
	memset(line,127,sizeof line);
	line[1] = 0;
	for(int i=1;i<=n;i++){
		int u = 0;
		for(int j=1;j<=n;j++)
			if(!vis[j] && line[j]<line[u]) u = j;
		vis[u] = 1;
		for(int j=1;j<=n;j++)
			if(!vis[j])line[j] = min(line[j],p[u][j]);
	}
	double sum=0;
	for(int i=1;i<=n;i++)sum += line[i];
	return sum;
}

int main(){
	while(scanf("%d",&n),n){
		for(int i=1;i<=n;i++)scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].h);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				dis[i][j] = getdis(i,j);
				h[i][j] = fabs(a[i].h-a[j].h);
			}
		double l=0.0, r=100.0;
		while(r-l >= eps){
			double mid=(l+r)/2.0;
			if(prim(mid) >= 0)l=mid;
			else r=mid;
		}
		printf("%.3f\n",l);
	}

	return 0;
}
