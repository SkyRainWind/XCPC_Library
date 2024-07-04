// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=3e5+5;
#define int ll

int n,a[maxn],vis[maxn],cnt[maxn],dp[maxn];

signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),vis[a[i]]=1,++cnt[a[i]];
	for(int i=1;i<=maxn-5;i++)cnt[i] += cnt[i-1];
	for(int i=maxn-5;i>=1;i--){
		vector<int>vb;
		for(int j=i;j<=maxn-5;j+=i)
			if(vis[j])vb.pb(j);
		int res = 0;
		for(int j=0;j<vb.size();j++){
			res += cnt[vb[j]-1]*(j)-cnt[vb[j]]*(vb.size()-j-1);
		}
		dp[i] = res;
		for(int j=2;i*j<=maxn-5;j++)
			dp[i] -= dp[i*j];
	}
	printf("%lld\n",dp[1]);

	return 0;
}

