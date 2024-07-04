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

int n,m,a[1005][1005], c[1005*1005];
int cnt = 0;
vector<int>vx[1000005], vy[1000005];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]), c[++cnt] = a[i][j];
	sort(c+1,c+cnt+1);
	cnt = unique(c+1, c+cnt+1) - (c+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j] = lower_bound(c+1, c+cnt+1, a[i][j]) - c;
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)vx[a[i][j]].pb(i), vy[a[i][j]].pb(j);
	for(int i=1;i<=cnt;i++)
		sort(vx[i].begin(),vx[i].end()),
		sort(vy[i].begin(),vy[i].end());
		
	ll ans = 0;
	for(int i=1;i<=cnt;i++){
		ll t=0, lim=0;
		for(auto it : vx[i]){
			t += it;++ lim; 
			ans += 2ll * (1ll * lim * it - t);
//			printf("!! %d %d %d\n",it,t,ans);
		}
//		printf("? %lld\n",ans);
	}
	for(int i=1;i<=cnt;i++){
		ll t=0, lim=0;
		for(auto it : vy[i]){
			t += it;++ lim; 
			ans += 2ll * (1ll * lim * it - t);
		}
//		printf("?? %lld\n",ans);
	}
	printf("%lld\n",ans);

	return 0;
}

