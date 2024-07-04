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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=6005;

int n,a[maxn];
int dp[maxn][2];
struct ed{
	int to, nxt;
}ed[maxn << 1];
int head[maxn],ecnt=0;

void add(int x,int y){
	ed[++ ecnt].to = y;
	ed[ecnt].nxt = head[x];
	head[x] = ecnt;
}
int de[maxn],dd[maxn];

void dfs(int x){
	if(dd[x] == 0){
		dp[x][0] = 0;
		dp[x][1] = a[x];
		return ;
	}
	for(int i=head[x];i;i=ed[i].nxt){
		int u = ed[i].to;
		dfs(u);
		dp[x][0] += max(dp[u][0], dp[u][1]);
		dp[x][1] += dp[u][0]; 
	}
	dp[x][1] += a[x];
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]); 
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);swap(x,y);
		add(x,y);++ de[y];++ dd[x];
	}
	for(int i=1;i<=n;i++)if(!de[i]){dfs(i);printf("%d\n",max(dp[i][0], dp[i][1]));}

	return 0;
}


