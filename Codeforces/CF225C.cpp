// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,m,x,y;
char s[1005][1005];
int col[1005],ncol[1005];
int dp[1005][2];
// dp[i][0/1] 到第 i 位，且 (i-1,i) 不同 第 i 位为 ./# 

signed main(){
	memset(dp, 0x3f, sizeof dp);
	scanf("%d%d%d%d",&n,&m,&x,&y);
	y =min(y, m);x = min(x, m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i] + 1);
	for(int j=1;j<=m;j++){
		int r=0;
		for(int i=1;i<=n;i++)
			if(s[i][j] == '.')++r;
		col[j] = r;
		ncol[j] = n-r;
	}
	for(int j=2;j<=m;j++)col[j] += col[j-1], ncol[j] += ncol[j-1];
	int ans = 1e9;
	for(int i=x+1;i<=y+1;i++){
		// []
		dp[i][0] = col[i-1], dp[i][1] = ncol[i-1];
	}
	if(y == m)ans = min(ans, min(col[m], ncol[m]));
	for(int i=x+2;i<=m;i++){
		for(int j=i-y;j<=i-x;j++)if(j >= 1){
			if(dp[j][1]!=INF)dp[i][0] = min(dp[i][0], dp[j][1] + col[i-1] - col[j-1]);
			if(dp[j][0]!=INF)dp[i][1] = min(dp[i][1], dp[j][0] + ncol[i-1] - ncol[j-1]);
		}
	}
	for(int j=m+1-y;j<=m+1-x;j++)if(j>=1)
		ans = min(ans, dp[j][0] + ncol[m] - ncol[j-1]),
		ans = min(ans, dp[j][1] + col[m] - col[j-1]);
	cout<<ans;

	return 0;
}

