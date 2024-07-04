// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=5005, mod = 1e9+7;

int n,k,a[maxn];
int dp[5005][(1<<10)+5];
vector<int>all,ri[5005];
int ban[1005][1005],mn[1005];

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)mn[i]=i;
	for(int i=1;i<=k;i++){
		int c,r;scanf("%d%d",&c,&r);
		a[c-r] = 1, a[c+r] = 2;
		ban[c-r][c+r] = 1;
		ri[c+r].pb(c-r);
		mn[c+r] = min(mn[c+r], c-r);
	}
	dp[0][1] = 1;
	for(int i=1;i<=n;i++){
		for(int S=0;S<=(1<<10)-1;S++){
			if(ri[i].size() == 0)(dp[i][(S<<1|1)&1023] += dp[i-1][S]) %= mod;
			
			int now=1;
			for(int k=2;k<=10 && i-k>=0;k+=2){
				if((S&(1<<(k-1))) == 0 && ban[i-k][i])break;
//				int T = S & (~((1<<(k-1))-1));
				int T = (S>>(k-1))<<(k-1);
				if(i-k<=mn[i] && ((S>>(k-1))&1) == 1)(dp[i][(T<<1|1)&1023] += 1ll*dp[i-1][S]*now%mod) %= mod;
				if(((S>>(k-1))&1) == 1 && !ban[i-k][i])now = 2ll*now%mod;
			}
		}
	}
	int ans = 0;
	for(int S=0;S<=(1<<10)-1;S++)
		ans += dp[n][S], ans %= mod;
	printf("%d\n",ans);

	return 0;
}

