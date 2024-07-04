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

const int inf = 1e9,maxn=10005, INF = 0x3f3f3f3f;

int n,m,k;
int x[maxn],y[maxn];
struct node{int p,l,h;}st[maxn];
int dn[maxn],up[maxn];
int dp[10005][1005];

int in(int p,int q){
	return q >= 1 && q <= m && q > dn[p] && q < up[p];
}
int cmp(node a,node b){return a.p < b.p;}

signed main(){
//	freopen("P1941_3.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=k;i++){
		scanf("%d%d%d",&st[i].p,&st[i].l,&st[i].h);
		++ st[i].p;
	}
	sort(st+1,st+k+1,cmp);
	int pcnt = 1;
	for(int i=1;i<=n+1;i++){
		if(i == st[pcnt].p){
			dn[i] = st[pcnt].l, up[i] = st[pcnt].h;
			++ pcnt;
		}else dn[i]=0, up[i] = m+1;
	}
	memset(dp,0x3f,sizeof dp);
	for(int j=1;j<=m;j++)dp[1][j] = 0;
	
	int lst;
	for(int i=2;i<=n+1;i++){
		for(int j=x[i-1]+1;j<=m;j++){
				if(in(i-1,j-x[i-1]) && dp[i-1][j-x[i-1]]!=INF)dp[i][j] = min(dp[i][j], dp[i-1][j-x[i-1]]+1);
				if(dp[i][j-x[i-1]]!=INF)dp[i][j] = min(dp[i][j], dp[i][j-x[i-1]]+1);
		}
		for(int j=max(1,m-x[i-1]+1);j<=m;j++){
			if(in(i-1,j)&&dp[i-1][j]!=INF)dp[i][m] = min(dp[i][m],dp[i-1][j]+1);
			if(dp[i][j]!=INF) dp[i][m] = min(dp[i][m], dp[i][j]+1);
		}
		
		for(int j=1;j+y[i-1]<=m;j++){
			if(in(i,j) && in(i-1,j+y[i-1]) && dp[i-1][j+y[i-1]]!=INF)dp[i][j] = min(dp[i][j], dp[i-1][j+y[i-1]]);
		}
			
		for(int j=1;j<=m;j++)
			if(!in(i,j))dp[i][j] = INF;
			else if(dp[i][j] != INF){
				lst = i;
			}
	}
	int ans = INF;
	for(int j=1;j<=m;j++)if(dp[n+1][j] != INF)ans = min(ans, dp[n+1][j]);
	if(ans != INF)printf("1\n%d\n",ans);
	else{
		puts("0");
		st[pcnt+1].p = INF;
		int res=0;
		for(int i=1;i<=k;i++){
			if(st[i].p <= lst)++ res;
		}
		printf("%d\n",res);
	}

	return 0;
}


