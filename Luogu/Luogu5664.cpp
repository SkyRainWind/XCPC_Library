// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 998244353, bs = 100;

int n,m;
int a[102][2002],dp[102][202], s[105];
void upd(int &x,int y){(x += y) %= mod;}

signed main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]), upd(s[i], a[i][j]);
	int r1 = 0;
	for(int col = 1;col<=m; col ++){
		dp[0][bs] = 1;
		for(int i=1;i<=n;i++){
			for(int j=bs-i;j<=bs+i;j++){
				dp[i][j] = dp[i-1][j];
				if(j)upd(dp[i][j], 1ll * dp[i-1][j-1] * a[i][col] % mod);
				upd(dp[i][j], 1ll * dp[i-1][j+1] * (mod + s[i] - a[i][col])%mod);
			}
		}
		for(int i=bs+1;i<=200;i++)upd(r1, dp[n][i]);
	}
	LL ans = 1;
	for(int i=1;i<=n;i++)ans = 1ll * ans * (s[i] + 1) % mod;
	printf("%d\n",(mod + ans - r1 - 1) % mod);

	return 0;
}

