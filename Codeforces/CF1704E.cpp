// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9,maxn=1005;

int n,m;
vector<int>g[maxn];
int in[maxn],out[maxn];
LL tmp[maxn],a[maxn];

void solve(){
	scanf("%d%d",&n,&m);
	int first=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), g[i].clear(), in[i] = out[i] = 0, first |= a[i];
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y);
		++ in[y];++ out[x];
	}
	if(!first){puts("0");return ;}
	int pos;
	for(int i=1;i<=n;i++)if(!out[i])pos = i;
	for(int t=1;t<=n;t++){
		memset(tmp,0,sizeof tmp);
		for(int i=1;i<=n;i++){
			if(a[i]){
				for(int j=0;j<g[i].size();j++){
					int u=g[i][j];
					++ tmp[u];
				}
				-- a[i];
			}
		}
		int isover=0;
		for(int i=1;i<=n;i++){
			a[i] = a[i]+tmp[i];
			isover |= (a[i]!=0);
		} 
		if(!isover){
			printf("%d\n",t);
			return ;
		}
	}
	queue<int>Q;
	for(int i=1;i<=n;i++)if(!in[i])Q.push(i);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		if(u == pos)continue;
		for(int i=0;i<g[u].size();i++){
			int v = g[u][i];
			a[v] += a[u];a[v]%=998244353;
			--in[v];
			if(in[v] == 0)Q.push(v);
		}
		a[u] = 0;
	}
	printf("%lld\n",(a[pos] + n)%998244353);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}


