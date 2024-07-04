// by SkyRainWind
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5 + 5;

int n, s, t;
vector<pii>g[maxn];

int idx(int p,int q){return (p-1)*(n+1) + q;}
void add(int x,int y,int v){g[x].push_back(mpr(y,v));}

void add1(int x1,int y1,int x2,int y2,int v){
	if(x1 == 0){
		add(s,idx(x2,y2),v);
		return ;
	}
	if(x2 == n+1){
		add(idx(x1,y1),t,v);
		return ;
	}
	add(idx(x1,y1), idx(x2,y2), v);
}

void add2(int x1,int y1,int x2,int y2,int v){
	if(x1 == n+1){
		add(t,idx(x2,y2),v);
		return ;
	}
	if(x2 == 0){
		add(idx(x1,y1),s,v);
		return ;
	}
	add(idx(x1,y1), idx(x2,y2), v);
}

void add3(int x1,int y1,int x2,int y2,int v){
	if(y2 == 0){
		add(idx(x1,y1),t,v);
		return ;
	}
	if(y1 == n+1){
		add(s,idx(x2,y2),v);
		return ;
	}
	add(idx(x1,y1), idx(x2,y2), v);
}

void add4(int x1,int y1,int x2,int y2,int v){
//	debug();
	if(y1 == 0){
		add(t,idx(x2,y2),v);
		return ;
	}
	if(y2 == n+1){
		add(idx(x1,y1),s,v);
		return ;
	}
	add(idx(x1,y1), idx(x2,y2), v);
}

struct iedges{int val,num;bool operator<(const iedges a)const{return a.val<val;}iedges(){}iedges(int vv,int nu):val(vv),num(nu){}};
priority_queue<iedges>pq;

int vis[maxn],dis[maxn];
void dijkstra(int be){
	int N=(n+1)*(n+1)+3;
	for(int i=1;i<=N;i++)dis[i]=inf;
	dis[be]=0;
	
	pq.push(iedges(0,be));
	while(!pq.empty()){
		int fr=pq.top().num;pq.pop();
		if(vis[fr])continue;
		vis[fr]=1; 
		for(pii now : g[fr]){
			int u=now.first,v=now.second;
			if(dis[fr]+v<dis[u]){
				dis[u]=dis[fr]+v;
				pq.push(iedges(dis[u],u));
			}
		}
	}
	
	printf("%d\n",dis[t]);
}

signed main(){
	scanf("%d",&n);
	s = (n+1) * (n+1) + 1; t = s + 1;
	for(int i=1;i<=n+1;i++){	// w -> e
		for(int j=1;j<=(n);j++){
			int v;scanf("%d",&v);
			// (i,j) -> (i,j+1)  dual (i-1,j) -> (i,j)
			add1(i-1,j,i,j,v);
		}
	}
	for(int i=1;i<=n;i++){	// n -> s
		for(int j=1;j<=n+1;j++){
			int v;scanf("%d",&v);
			// (i,j) -> (i+1,j) dual (i,j) -> (i,j-1)
			add3(i,j,i,j-1,v);
		}
	}
	for(int i=1;i<=n+1;i++){	// e -> w
		for(int j=1;j<=(n);j++){
			int v;scanf("%d",&v);
			// (i,j+1) -> (i,j)  dual (i,j) -> (i-1,j)
			add2(i,j,i-1,j,v);
		}
	}
	for(int i=1;i<=n;i++){	// s -> n
		for(int j=1;j<=n+1;j++){
			int v;scanf("%d",&v);
			// (i+1,j) -> (i,j) dual (i,j-1) -> (i,j)
			add4(i,j-1,i,j,v);
//			debug();
		}
	}
	dijkstra(s);

	return 0;
}

