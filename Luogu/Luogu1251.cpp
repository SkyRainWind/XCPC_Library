// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 4005;

int n, r[maxn];
struct edges{
	int from,to;
	int cap;ll flow;
	int rev;ll cost;
	edges(){}
	edges(int from,int to,int cap,int flow,int rev,int cost):from(from),to(to),cap(cap),flow(flow),rev(rev),cost(cost){}
};
vector<edges>g[maxn];

struct mincost{
	vector<edges>::iterator p[maxn];
	int d[maxn],inq[maxn];
	ll a[maxn];
	int s = -1, t;
	
	void init(int ss,int tt){s = ss, t = tt;}
	
	void insert(int x,int y,ll z,ll u){
		g[x].push_back(edges(x,y,z,0,g[y].size(),u));
		g[y].push_back(edges(y,x,0,0,g[x].size()-1,-u));
	}
	
	ll spfa(ll &flow,ll &cost){
		memset(d,0x3f,sizeof d);memset(inq,0,sizeof inq);memset(a,0,sizeof a);
		a[s]=1e18;
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
		ll f=a[t];
		flow+=f;cost+=f*d[t];
		for(int i=t;i!=s;i=p[i]->from)p[i]->flow+=f, g[i][p[i]->rev].flow-=f;
		return 1;
	}
	
	pair<ll,ll> mcmf(){
		assert(s != -1);
		ll flow=0, cost=0;
		while(spfa(flow,cost));
		return mpr(flow, cost);
	}
};
mincost mcf;
// 拆点，一天拆成早 晚
// S 向晚上连 cap=r_i,w=0 的边 代表强制给早上 r[i] 个干净纸巾
// 早上向 T 连 cap=r_i,w=0 的边，代表脏纸巾
// 晚上向下一个晚上连 cap=inf,w=0 的边，代表延迟洗
// 晚上向 某个早上连 cap=inf,w=qc/sc 的边，代表快慢洗
// S 向早上 连 cap=inf,w=p 的边，代表买纸巾 

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&r[i]);
	int p,qd,qc,sd,sc;
	scanf("%d%d%d%d%d",&p,&qd,&qc,&sd,&sc);
	int s = n*2+1, t = n*2+2;
	mcf.init(s, t);
	
	for(int i=1;i<=n;i++){
		int mor=i*2-1, nig=i*2;
		mcf.insert(s,nig,r[i],0);
		mcf.insert(mor,t,r[i],0);
		mcf.insert(s,mor,inf,p);
		if(nig+2<=2*n)mcf.insert(nig,nig+2,inf,0);
		if(mor+2*qd<=2*n)mcf.insert(nig,mor+2*qd,inf,qc);
		if(nig+2*sd<=2*n)mcf.insert(nig,mor+2*sd,inf,sc);
	}
	cout << mcf.mcmf().second << '\n'; 

	return 0;
}

