// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=305, mod=998244353;

int n,m;
int a[maxn],b[maxn],c[maxn];
ll dp[maxn][maxn][maxn];
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)c[b[i]] = a[i];
	swap(a, c);
	
	dp[0][0][n+1]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=1;k<=n+1;k++){
				if(dp[i-1][j][k]){
					if(a[i] <= k)(dp[i][j][a[i]] += dp[i-1][j][k]) %= mod;
					else (dp[i][j][k] += dp[i-1][j][k]) %= mod;
				}
				if(j && dp[i-1][j-1][k]){
					if(a[i]<k)(dp[i][j][k] += dp[i-1][j-1][k]) %= mod;
				}
			}
		}
	}
	ll ans = 0;
	for(int j=0;j<=n+1;j++)
		(ans += dp[n][m][j]) %= mod;
	cout << ans << '\n';

	return 0;
}

