// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n;
int a[maxn];
struct ed{
	int nxt, to;
}ed[maxn << 1];
int head[maxn], ecnt=0;
vector<int>dp[maxn], di[maxn];
int notpm[maxn],pm[maxn],pcnt;

void work(int x){
	int tmp = a[x];
	for(int i=1;i<=pcnt;i++){
		if(pm[i]*pm[i] > tmp)break;
		if(tmp%pm[i]==0){
			dp[x].push_back(1);
			di[x].push_back(pm[i]);
			while(tmp%pm[i]==0)tmp /= pm[i];
		}
	}
	if(tmp != 1)dp[x].push_back(1), di[x].push_back(tmp);
}

void add(int x,int y){
	ed[++ecnt].to = y;ed[ecnt].nxt=head[x];head[x]=ecnt;
}

void xxs(){
	notpm[1] = 1;
	for(int i=2;i<=200000;i++){
		if(!notpm[i]){
			pm[++ pcnt] = i;
		}
		for(int j = 1;j<=pcnt && i*pm[j] <= 200000;j++){
			notpm[i*pm[j]] = 1;
			if(i%pm[j] == 0)break;
		}
	} 
}

int ans = 1;
void dfs(int x,int fat=-1){
	for(int ii=head[x];ii;ii=ed[ii].nxt){
		int u = ed[ii].to;
		if(u==fat)continue;
		dfs(u, x);
		for(int i=0;i<di[x].size();i++)
			for(int j=0;j<di[u].size();j++)if(di[x][i] == di[u][j]){
				ans = max(ans, dp[x][i] + dp[u][j]);
				dp[x][i] = max(dp[x][i], dp[u][j] + 1);
			}
	}
}

signed main(){
	xxs();
	int ok = 1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), ok &= (a[i] == 1), work(i);
	if(ok)return puts("0"), 0;
	for(int i=1;i<=n-1;i++){
		int u,v;scanf("%d%d",&u,&v);
		add(u,v), add(v,u);
	}
	dfs(1);
	printf("%d\n",ans);

	return 0;
}


