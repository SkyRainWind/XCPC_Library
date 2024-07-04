// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;

int n,m;
int gr[15][15];
int dp[(1<<12) +5],low[13][(1<<12)+5];

signed main(){
//	freopen("3959.in","r",stdin);
	for(int i=1;i<=12;i++)for(int j=1;j<=12;j++)gr[i][j] = gr[j][i] = inf;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,v;scanf("%d%d%d",&x,&y,&v);
		gr[x][y] = gr[y][x] = min(gr[x][y],v);
	}
	int ans=inf;
	for(int i=1;i<=n;i++){
		for(int S=0;S<=(1<<n)-1;S++)dp[S] = inf, low[i][S] = 1;
		dp[(1<<(i-1))] = 0;
		for(int S=0;S<=(1<<n) - 1;S++)if((S&(1<<(i-1)))){
			for(int j=1;j<=n;j++)if((S&(1<<(j-1))) == 0){
				for(int k=1;k<=n;k++)if(gr[j][k]!=inf && (S&(1<<(k-1)))){
					if(dp[S|(1<<(j-1))] > dp[S]+low[k][S] * gr[j][k]){
						dp[S|(1<<(j-1))] = dp[S] + low[k][S] * gr[j][k];
						for(int pp=1;pp<=n;pp++)low[pp][S|(1<<(j-1))] = low[pp][S];
						low[j][S|(1<<(j-1))] = low[k][S] + 1;
					}
				}
			}
		}
		ans = min(ans, dp[(1<<n)-1]);
	}
	printf("%d\n",ans);

	return 0;
}


