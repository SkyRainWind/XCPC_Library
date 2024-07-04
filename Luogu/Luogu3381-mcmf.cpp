// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,m,s,t;
struct edges{
	int from,to;
	int cap,flow;
	int rev,cost;
	edges(){}
	edges(int from,int to,int cap,int flow,int rev,int cost):from(from),to(to),cap(cap),flow(flow),rev(rev),cost(cost){}
};
vector<edges>g[maxn];

struct mincost{
	vector<edges>::iterator p[maxn];
	int d[maxn],inq[maxn],a[maxn];
	
	void insert(int x,int y,int z,int u){
		g[x].push_back(edges(x,y,z,0,g[y].size(),u));
		g[y].push_back(edges(y,x,0,0,g[x].size()-1,-u));
	}
	
	int spfa(int &flow,int &cost){
		memset(d,0x3f,sizeof d);memset(inq,0,sizeof inq);memset(a,0,sizeof a);
		a[s]=0x3f3f3f3f;
		queue<int>Q;
		Q.push(s);inq[s]=1;d[s]=0;
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			inq[u]=0;
			for(vector<edges>::iterator it=g[u].begin();it!=g[u].end();it++){
				if(it->cap>it->flow&&d[it->to]>d[u]+it->cost){
					d[it->to]=d[u]+it->cost;
					p[it->to]=it;
					a[it->to]=min(a[u],it->cap-it->flow);
					if(!inq[it->to])inq[it->to]=1,Q.push(it->to);
				}
			}
		}
		
		if(d[t]==0x3f3f3f3f)return 0;
		int f=a[t];
		flow+=f;cost+=f*d[t];
		for(int i=t;i!=s;i=p[i]->from)p[i]->flow+=f, g[i][p[i]->rev].flow-=f;
		return 1;
	}
	
	pii mcmf(){
		int flow=0, cost=0;
		while(spfa(flow,cost));
		return mpr(flow, cost);
	}
};
mincost mcf;

signed main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++){
		int x,y,z,u;scanf("%d%d%d%d",&x,&y,&z,&u);
		mcf.insert(x,y,z,u);
	}
	pii ans = mcf.mcmf();
	printf("%d %d\n",ans.first,ans.second);

	return 0;
}

