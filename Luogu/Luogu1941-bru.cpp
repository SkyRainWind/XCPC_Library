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

const int inf = 1e9,maxn=2e4+5;

int n,m,k;
int x[maxn],y[maxn],dn[maxn],up[maxn];
int dp[10005][1005];

void ck(int &a,int b,int c){if(b!=1e9)a=min(a,b+c);}
int ts(int x,int y){return dn[x]<y&&y<up[x];}

signed main(){
	freopen("1941.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n+1;i++)dn[i]=0,up[i]=1e9;
	for(int i=1;i<=k;i++){
		int p,l,h;scanf("%d%d%d",&p,&l,&h);
		++ p;
		dn[p] = l, up[p] = h;
	}
	for(int i=1;i<=n+1;i++)for(int j=0;j<=m;j++)dp[i][j] = 1e9;
	for(int i=1;i<=m;i++)dp[1][i] = 0;
	int st=-1;
	for(int i=2;i<=n+1;i++){
		for(int j=1;j<=m;j++)if(ts(i,j)){
			if(j+y[i-1]<=m&&ts(i-1,j+y[i-1]))dp[i][j] = dp[i-1][j+y[i-1]];
			for(int k=1;j-x[i-1]*k>=1;k++)
				if(ts(i-1,j-k*x[i-1]))ck(dp[i][j],dp[i-1][j-k*x[i-1]],k);
			if(dp[i][j] != 1e9)st = i;
		}
		if(ts(i,m)){
			for(int p=1;p<=m;p++){
				if(ts(i-1,p))ck(dp[i][m],dp[i-1][p],(x[i-1]==1&&m==p)?1:((m-p-1)/x[i-1]+1));
			}
			if(dp[i][m] != 1e9)st = i;
		}
	}
//	printf("%d\n",dp[10][2]);
	int ans=1e9;
	for(int i=1;i<=m;i++)ans=min(ans,dp[n+1][i]),printf("%d ",dp[n+1][i]);
	if(ans == 1e9){
		int cnt=0;
		if(st == -1){puts("0\n0\n");return 0;}
		for(int i=1;i<=st;i++)if(up[i] != 1e9)++ cnt;
		printf("0\n%d\n",cnt);
		return 0;
	}
	printf("1\n%d\n",ans);

	return 0;
}

