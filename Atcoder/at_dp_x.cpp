// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=20005;

int n;
struct node{int w,s,v;}a[maxn];
int cmp(node i,node j){return min(j.s,i.s-j.w) > min(i.s,j.s-i.w);}
ll dp[1005][20005];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].w,&a[i].s,&a[i].v);
	sort(a+1,a+n+1,cmp);
	
	for(int i=0;i<=10000;i++)dp[1][i] = -1e18;
	dp[1][a[1].s] = a[1].v;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=10000;j++)dp[i][j] = dp[i-1][j];
		dp[i][a[i].s] = max(dp[i][a[i].s], 1ll*a[i].v);
		for(int j=a[i].w;j<=10000;j++){
			ll &dd = dp[i][min(j-a[i].w, a[i].s)];
			dd = max(dd, dp[i-1][j] + a[i].v);
		}
	}
	ll ans=0;
	for(int i=0;i<=10000;i++)ans = max(ans, dp[n][i]);
	cout<<ans<<'\n';

	return 0;
}

