// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5005, mod = 1e9+7;

// dp[i][j] [1..i] 有 j 轮 的方案数
// dp[i][j] <- dp[t][j-1] 
int f[maxn], g[maxn], a[maxn];
int n,m,C[maxn][maxn];

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m == 1){
		puts("1");
		return ;
	}
	for(int i=1;i<=n;i++)f[i] = g[i] = 0;
	f[0] = 1;
	
	for(int i=1;i<=n;i++){
		int t=1;
		for(int s=i-1;s>=1;s--){
			if(a[s] == a[i]){
				++ t;
				if(t == m){
					g[i] = g[s-1] + 1;
				}
				if(t >= m){
					if(g[i] > g[s-1]+1)break;
					(f[i] += 1ll*f[s-1]*C[t-2][m-2]%mod) %= mod;
				}
			}
		}
		if(g[i] < g[i-1])
			f[i]=0, g[i]=g[i-1];
		if(g[i] == g[i-1])
			(f[i] += f[i-1]) %= mod;
	}
	printf("%d\n",f[n]);
}

signed main(){
	C[0][0] = 1;
	for(int i=1;i<=5000;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++)
			(C[i][j] = C[i-1][j] + C[i-1][j-1]) %= mod;
	}
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

