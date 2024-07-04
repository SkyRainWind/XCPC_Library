// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1e5+5;

ll dp[maxn];
int n,m,p[maxn],d[maxn];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	vector<int>S;
	S.pb(m);
	
	for(int i=1;i<=n;i++){
		vector<int>T;
		for(int it : S){
			if(d[i] == 1){
				dp[it] += 1ll*p[i]*it;
			}else{
				if(dp[it / d[i]] == 0){
					T.pb(it / d[i]);
				}
				dp[it / d[i]] = max(dp[it / d[i]], dp[it] + 1ll*p[i]*it);
			}
		}
		for(auto it : T)S.pb(it);
		sort(S.begin(), S.end());
	}
	ll ans = 0;
	for(auto it : S)
		ans = max(ans, dp[it]);
	printf("%lld\n",ans);

	return 0;
}

