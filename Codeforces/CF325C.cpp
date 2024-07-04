// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5 + 5, mod = 314000000;

int m,n;
int cnt[maxn], to[maxn], v[maxn];
set<int>S[maxn]; 	// 用于存当前点对应哪些反向边（爆出的怪物 -> 原来的怪物） 

struct pt{
	int to, dis;
	pt(int to,int dis):to(to),dis(dis){}
};
bool operator < (pt a, pt b){
	return a.dis > b.dis;
}
priority_queue<pt>pq;
int dis[maxn];
// dijkstra

vector<int>edge[maxn];	// 正向边（和S[]像） 
int op_edge[maxn], cnt_edge[maxn];	
// op_edge[] 当前反向边最优的情况下由（已经松弛过了的）爆出怪物所产生的钻石数，就是用每次松弛过的点来更新保证最优 
// cnt_edge[] 来判断对于某条边，是否已经凑齐了爆出的怪物（来更新原来的） 
map<int,int>num[maxn];	// 当前正向边某个怪物出现了几次 
int ans[maxn][2];

void upd(int &x){x = x >= mod ? mod : x;}

void solve1(){
	for(int i=1;i<=m;i++){
		if(num[i].size() == 0)pq.push(pt(to[i], cnt[i])), dis[to[i]] = min(dis[to[i]], cnt[i]);
	}
	while(!pq.empty()){
		pt tp = pq.top();pq.pop();
		int curv = tp.to;if(v[curv])continue;
		v[curv] = 1;
		
		for(int u : S[curv]){
			op_edge[u] += 1ll * dis[curv] * num[u][curv] >= mod ? mod : dis[curv] * num[u][curv];
			upd(op_edge[u]);
			
 			cnt_edge[u] ++;
			if(cnt_edge[u] == num[u].size()){
				if(op_edge[u] + cnt[u] < dis[to[u]]){
					dis[to[u]] = op_edge[u] + cnt[u];
					upd(dis[to[u]]);
					
					pq.push(pt(to[u], dis[to[u]]));
				}
			}
		}
	}
	for(int i=1;i<=n;i++)ans[i][0] = dis[i] == INF ? -1 : dis[i];
}

int vis[maxn], instk[maxn];	// instk[] 判环 vis[] 记忆化 

int dfs(int x){
	vis[x] = 1;
	instk[x] = 1;
	if(ans[x][0] == -1)return ans[x][1] = -1;
	for(int u : edge[x]){
		int fg = 0, rr = 0;
		for(pii v : num[u]){
			int vf = v.first, vs = v.second;
			// (x -> vf) vs次 
			if(ans[vf][0] == -1){fg = 1;break;}
			if(instk[vf]){fg = 2;continue;}	// 优先级 先 -1 再 -2 
			
			int val = vis[vf] ? ans[vf][1] : dfs(vf);
			
			if(val == -2){fg = 2;continue;}
			rr += 1ll * val * vs >= mod ? mod : val * vs; 
			upd(rr);
		}
		if(fg == 1){continue;}
		if(fg == 2){instk[x] = 0;return ans[x][1] = -2;}
		ans[x][1] = max(ans[x][1], rr + cnt[u]);
		upd(ans[x][1]);
	}
	instk[x] = 0;
	return ans[x][1];
}

void solve2(){
	for(int i=1;i<=n;i++)
		if(!vis[i])dfs(i);
}

signed main(){
	scanf("%d%d",&m,&n);
	memset(dis, 0x3f, sizeof dis);
	for(int i=1;i<=m;i++){
		int cur;
		int t;scanf("%d%d",&cur,&t);
		to[i] = cur;
		edge[cur].push_back(i);
		while(t--){
			int tmp;scanf("%d",&tmp);
			if(tmp == -1){
				++ cnt[i];
			}else{
				S[tmp].insert(i);
				++ num[i][tmp];
			}
		}
	}
	solve1();
	solve2();
	for(int i=1;i<=n;i++)printf("%d %d\n",ans[i][0],ans[i][1]);

	return 0;
}

