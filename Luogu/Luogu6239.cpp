// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 1e9+7;
int n,m,k;
int dp[32][32][(1<<9)+2][32];
void ck(int &a,int b){(a += b) %= mod;}
signed main(){
	scanf("%d%d%d",&n,&m,&k);
	dp[1][0][0][0] = 1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int S=0;S<=(1<<(k+1))-1;S++){
				for(int l=min(k, i);l>=1;l--){
					ck(dp[i][j][S][l-1], dp[i][j][S][l]);
					if(j < m)ck(dp[i][j+1][S ^ (1<<l) ^ 1][l], dp[i][j][S][l]);
				}
				if((S & (1<<k)) == 0)ck(dp[i+1][j][S << 1][min(k, i)], dp[i][j][S][0]);
			}
	printf("%d\n",dp[n][m][0][0]);

	return 0;
}

