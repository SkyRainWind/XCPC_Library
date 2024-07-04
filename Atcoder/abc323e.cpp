// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,mod=998244353,maxn=2e4+5;

int n,x,a[maxn];
int dp[maxn];

int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

signed main(){
	scanf("%d%d",&n,&x);
	int inv = pw(n, mod-2);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dp[0] = 1;
	for(int i=1;i<=x;i++)
		for(int j=1;j<=n;j++)if(i >= a[j]){
			(dp[i] += 1ll * dp[i-a[j]] * inv % mod) %= mod;
		}
	int ans = 0;
		for(int j=x;j>=0;j--)
			if(j + a[1] >= x+1)(ans += dp[j] * 1ll * inv%mod) %= mod;
			else break;
	printf("%d\n",ans);

	return 0;
}

