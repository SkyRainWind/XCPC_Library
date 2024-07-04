// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 505;

// dp[i][j][k] 考虑到第 i 个位置，当前位置为 a[j]，当前换了 k 次的答案
// dp[i][j][k] <- dp[i-1][j][k-1] + a[j]
// dp[i][j][k] <- dp[i-1][t][k-(j-i)] + a[j], t<j, j>=i

int n,a[maxn],dp[maxn][maxn][maxn],pre[maxn][maxn];
void upd(int &x,int y){x = max(x, y);}
 
signed main(){
	memset(dp, -0x3f, sizeof dp);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dp[1][1][0] = a[1], dp[1][2][1] = a[2];
	memset(pre,-0x3f,sizeof pre);
	for(int j=1;j<=n;j++)
		for(int k=0;k<=1;k++)
			pre[j+1][k] = max(pre[j][k], dp[1][j][k]);
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=i;k++){
				if(dp[i-1][j][k-1] != -INF)
					upd(dp[i][j][k], dp[i-1][j][k-1] + a[j]);
			}
			for(int k=0;k<=i;k++){
				int r;
//				for(int t=0;t<j;t++){
//					if(k - (j-i) >= 0)r = max(r, dp[i-1][t][k - (j-i)]);
//				}
				if(j >= i && k - (j-i) >= 0){
					r = pre[j][k - (j-i)];
					if(r != -INF)upd(dp[i][j][k], r + a[j]);
				}
			}
		}
		memset(pre,-0x3f,sizeof pre);
		for(int j=1;j<=n;j++)
			for(int k=0;k<=i;k++)
				pre[j+1][k] = max(pre[j][k], dp[i][j][k]);
	}
	int ans = 0;
	for(int j=1;j<=n;j++)
		for(int k=0;k<=n;k++)
			upd(ans, dp[n][j][k]);
	cout << ans << '\n';

	return 0;
}

