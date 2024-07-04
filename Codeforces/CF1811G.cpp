// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 1e9+7;

int n,m;
int a[2005];
int C[2005][2005];

void solve(){
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	vector<int>dp(n+1, -inf);
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		vector<int>ndp(n+1, -inf);
		int f = 0;
		for(int j=n;j>=1;j--){
			vector<int>buc(101, 0);
			for(int k=j-1;k>=0;k--){
				int tt = ++ buc[a[k + 1]];
				if(dp[k] == -inf)continue;
				if(tt == m){
					ndp[j] = dp[j];
					ndp[j] += dp[k]+1, ndp[j] %= mod;
					f = 1;
				}else if(tt < m){
					;
				}else{
					int v = ((C[tt][m] - C[tt-1][m])%mod + mod) % mod;
					ndp[j] += (dp[k] + v)%mod, ndp[j] %= mod;
				}
			}
		}
		dp = ndp;
		if(i == 1)printf("! %d\n",dp[3]);
		printf("!! %d\n",i);
		if(f == 0)break;
	}
	int r1 = 0;
	for(int i=1;i<=n;i++)
		if(dp[i] != -inf)
			(r1 += dp[i]) %= mod;
	printf("%d\n",r1);
}

signed main(){
	C[0][0] = 1;
	for(int i=1;i<=2000;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++)
			(C[i][j] = C[i-1][j] + C[i-1][j-1]) %= mod;
	}
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

