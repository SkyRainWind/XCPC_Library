// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 255;

int n;
struct point{
	int x,y;
}p[maxn];
struct ed{
	int l,r;
	point delp;
}e[maxn * maxn];
int f[maxn];

point operator - (point a,point b){return point{a.x - b.x, a.y - b.y};}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y);
	
	int cnt = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i == j)continue;
			e[++ cnt] = ed{i,j,p[i] - p[j]};
		}
	
	sort(e+1,e+cnt+1,[&](ed a, ed b){
		return atan2(a.delp.x,a.delp.y) < atan2(b.delp.x,b.delp.y);
	});
	
	int ans = 0;
	for(int i=1;i<=n;i++){
		memset(f,-1,sizeof f);
		f[i] = 0;
		for(int j=1;j<=cnt;j++){
			int u=e[j].l, v=e[j].r;
			if(f[v] == -1)continue;
			f[u] = max(f[u], f[v] + 1);
		}
		ans = max(ans, f[i]);
	}
	printf("%d\n",ans);

	return 0;
}

