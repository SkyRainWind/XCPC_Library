// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, maxn = 105;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k;
int c[maxn],p[maxn][maxn];
ll dp[105][105][105];

void ck(ll &a, ll b){a = min(a, b);}

signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&p[i][j]);
	
	memset(dp,0x3f,sizeof dp);
	dp[0][0][0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			ll mn=INF, mnid, smn=INF, smnid;
			for(int t=0;t<=m;t++)
				if(dp[i-1][j-1][t] <= mn){
					smn = mn, smnid =mnid;
					mn = dp[i-1][j-1][t], mnid = t;
				}else if(dp[i-1][j-1][t] <= smn){
					smn = dp[i-1][j-1][t], smnid = t;
				}
				
			for(int k=1;k<=m;k++){
				if(c[i] == 0){
					ck(dp[i][j][k],dp[i-1][j][k] + p[i][k]);
//					printf(">  %d %d %d %d\n",i,j,k,mnid); 
					if(k == mnid)
						ck(dp[i][j][k], smn + p[i][k]);
					else ck(dp[i][j][k], mn + p[i][k]);
				}else{
					if(k != c[i]){
						dp[i][j][k] = INF;
						continue;
					}
					ck(dp[i][j][k], dp[i-1][j][k]);
					for(int t=0;t<=m;t++)
						if(t != k)
							ck(dp[i][j][k], dp[i-1][j-1][t]);
				}
			}
		}
	}
	ll ans = INF;
//	for(int j=1;j<=n;j++)
//	for(int jj=1;jj<=k;jj++)
	for(int i=1;i<=m;i++){
		ans = min(ans, dp[n][k][i]);
//		printf("%d %d %d %d\n",j,jj,i,dp[j][jj][i]);
	}
	if(ans == INF)puts("-1");
	else cout << ans << '\n';

	return 0;
}

