// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <set>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 4e5 + 5;

int n,m;
vector<int>g[maxn];
set<int>h[maxn], poi[maxn];
int x[maxn], y[maxn];
int s,t,ds,dt,vis[maxn],cnt2;
vector<pii>init_st;
int con[maxn][2], v[maxn];
// con[][0/1] 缩点之后与 s/t 连通 v[] 缩点之后第一轮是和 s/t 连边（防止连重了） 

void dfs(int x,int id){
	vis[x] = id;
	for(int u : g[x])if(!vis[u]){
		init_st.push_back(mpr(x,u));	// 每个连通块的生成森林一定在答案中 
		dfs(u, id);
	}
}

signed main(){
//	freopen("CF723F.in","r",stdin);
//	freopen("CF723F.out","w",stdout);
	int fg = 0;
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	scanf("%d%d%d%d",&s,&t,&ds,&dt);
	if(s > t)swap(s, t), swap(ds, dt);
	for(int i=1;i<=m;i++){
		if(s == x[i] || s == y[i] || t == x[i] || t == y[i]){
		}else g[x[i]].push_back(y[i]), g[y[i]].push_back(x[i]);
		// 建图 删去 和 s/t 相连的边 
	}
	int cnt = 0;
	for(int i=1;i<=n;i++)
		if(i!=s && i!=t && !vis[i]){
			dfs(i, ++cnt);
		}
		
	// x -> vis[x] 缩点 
	for(int i=1;i<=m;i++){
		if((x[i]==s&&y[i]==t) || (x[i]==t&&y[i]==s)){fg = 1;continue;}
		if(s == x[i] || s == y[i] || t == x[i] || t == y[i]){
			int fx = x[i], fy = y[i];
			if(s == x[i] || t == x[i])swap(fx, fy);
			// fx -> s/t
			poi[vis[fx]].insert(fy);
			con[vis[fx]][fy == s ? 0 : 1] = fx;
		}
	}
	// 缩点之后每个点先和 s/t 连一条边，连完之后图一定是 2 个连通块 
	// 先连只与s/t一个相连的，再连两个都相连的（只需要连一条） 
	for(int i=1;i<=cnt;i++){
		if(poi[i].size() == 1){
			int to = *poi[i].begin();
			if(to == s){
				-- ds;
				init_st.push_back(mpr(con[i][0], s));
			}
			else{
				--dt; 
				init_st.push_back(mpr(con[i][1], t));
			}
		}
	}
	
	int gg = 0;
	for(int i=1;i<=cnt;i++)
		if(poi[i].size() == 2){
			if(ds > 0){
				v[i] = 1;
				-- ds;
				init_st.push_back(mpr(con[i][0], s));
			}else if(dt > 0){
				v[i] = 2;
				-- dt;
				init_st.push_back(mpr(con[i][1], t));
			}else gg = 1;
		}
		
		// 最后再连1条，使得图连通（某个点与s/t均连 或者 s-t 直接连） 
	int ok = 0;
	if(ds+dt > 0){
		if(ds > 0 && dt > 0 && fg)init_st.push_back(mpr(s, t)), ok = 1;
		else
			for(int i=1;i<=cnt;i++){
				if(poi[i].size() == 2){
					if(ds > 0 && v[i] != 1){
						ok=1;
						-- ds;
						init_st.push_back(mpr(con[i][0], s));
					}else if(dt > 0 && v[i] != 2){
						ok=1;
						-- dt;
						init_st.push_back(mpr(con[i][1], t));
					}
					break;
				}
			}
	}

	if(!ok || gg)puts("No");
	else{
		puts("Yes");
		for(pii u : init_st)printf("%d %d\n",u.first,u.second);
	}

	return 0;
}

