// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 105, mod=998244353;

int n,k,m,v[maxn];
int C[maxn][maxn];
int dp[maxn][35][35][17];

int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

void ck(int &a,int b){(a+=b)%=mod;}

signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%d",&v[i]);
	}
	C[0][0] = 1;
	for(int i=1;i<=100;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++)(C[i][j] = C[i-1][j] + C[i-1][j-1]) %= mod;
	}

	dp[0][0][0][0] = 1;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			for(int kk=0;kk<=k;kk++){
				for(int p=0;p<=(n/2);p++){
					for(int t=0;j+t<=n;t++){
						ck(dp[i+1][j+t][kk+(p+t)%2][(p+t)/2], dp[i][j][kk][p] * 1ll * pw(v[i],t)%mod * C[n-j][t] % mod);
					}
				}
			}
		}
	}
	int ans=0;
	for(int kk=0;kk<=k;kk++)
		for(int p=0;p<=n/2;p++)
			if(kk+__builtin_popcount(p)<=k)
				ck(ans,dp[m+1][n][kk][p]);
	printf("%d\n",ans);

	return 0;
}

