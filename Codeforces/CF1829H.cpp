// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod=1e9+7;

int n,k;
int dp[200005][(1<<6)+5];

void solve(){
	scanf("%d%d",&n,&k);
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(k == 6){
		int s=1,ans=1;
		for(int i=1;i<=n;i++)
			if(a[i] == 63)ans = 2ll*ans%mod;
		printf("%d\n",ans-1);
		return ;
	}
	dp[0][(1<<6)-1] = 1;
	for(int i=1;i<=n;i++){
		for(int S=0;S<=(1<<6)-1;S++){
			dp[i][S] = dp[i-1][S];
		}
		for(int S=0;S<=(1<<6)-1;S++){
			(dp[i][S & a[i]] += dp[i-1][S] )%= mod; 
		}
	}
	int ans = 0;
	for(int S=0;S<=(1<<6)-1;S++)
		if(__builtin_popcount(S) == k)(ans += dp[n][S]) %= mod;
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

