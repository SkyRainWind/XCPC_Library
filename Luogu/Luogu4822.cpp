// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 50 * 50 + 5;

int n,m,k;
vector<pii>g[maxn];
int vis[maxn][55];
int dis[maxn][55];

void spfa(){
	memset(dis,0x3f,sizeof dis);
	queue<int>Q,qst;
	Q.push(1), qst.push(0);
	vis[1][0] = 1;
	dis[1][0] = 0;
	
	while(!Q.empty()){
		int now = Q.front(), nst = qst.front();
		Q.pop(), qst.pop();
		vis[now][nst] = 0;
		for(auto it : g[now]){
			int u = it.first, v = it.second;
			if(dis[u][nst] > dis[now][nst] + v){
				dis[u][nst] = dis[now][nst] + v;
				if(!vis[u][nst])vis[u][nst]=1, Q.push(u), qst.push(nst);
			}
			if(nst < k && dis[u][nst+1] > dis[now][nst] + v/2){
				dis[u][nst+1] = dis[now][nst] + v/2;
				if(!vis[u][nst+1])vis[u][nst+1]=1, Q.push(u), qst.push(nst+1);
			}
		}
	}
}

signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		g[x].pb(mpr(y,z)), g[y].pb(mpr(x,z));
	}
	spfa();
	int ans = 1e9;
	for(int i=0;i<=k;i++)
		ans = min(ans, dis[n][i]);
	cout << ans << '\n';

	return 0;
}

