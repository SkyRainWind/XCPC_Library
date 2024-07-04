// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1005;
int n,m,a[maxn][maxn];
int dp[maxn][2][2];
int iso(int x,int y,int t0,int t1,int t2){
	int fg = 1;
	if(y > 1)fg &= (a[x][y-1] ^ t1) != (a[x][y] ^ t1);
	if(y < m)fg &= (a[x][y+1] ^ t1) != (a[x][y] ^ t1);
	if(x > 1)fg &= (a[x-1][y] ^ t2) != (a[x][y] ^ t1);
	if(x < n)fg &= (a[x+1][y] ^ t0) != (a[x][y] ^ t1);
	return fg;
}
int iso2(int x,int y,int t0,int t1){
	int fg = 1;
	if(y > 1)fg &= (a[x][y-1] ^ t0) != (a[x][y] ^ t0);
	if(y < m)fg &= (a[x][y+1] ^ t0) != (a[x][y] ^ t0);
	if(x > 1)fg &= (a[x-1][y] ^ t1) != (a[x][y] ^ t0);
	return fg;
}
void ck(int &x,int y){x = min(x, y);}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	memset(dp,0x3f,sizeof dp);
	
	dp[1][0][0] = 0;
	dp[1][1][0] = 1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=1;j++)
			for(int k=0;k<=1;k++){
				for(int l=0;l<=1;l++)if(dp[i-1][k][l] != INF){
					int gg = 0;
					for(int col=1;col<=m;col++){
						if(iso(i-1,col,j,k,l) == 1){
							gg = 1;break;
						}
					}
					if(gg)continue;
					ck(dp[i][j][k], dp[i-1][k][l] + j);
				}
			}
	}
	int ans = INF;
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++){
			int gg = 0;
			for(int col=1;col<=m;col++)
				if(iso2(n,col,i,j)){
					gg = 1;
					break;
				}
			if(!gg)ck(ans, dp[n][i][j]);
		}
	if(ans == INF)cout<<-1;
	else cout<<ans;

	return 0;
}

