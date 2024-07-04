// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n;
ll down = 0;
struct ed{
	LL from,to,cap,flow,rev,cost;
	ed(){}
	ed(LL from,LL to,LL cap,LL flow,LL rev,ll cost):from(from),to(to),cap(cap),flow(flow),rev(rev),cost(cost){}
};
vector<ed>g[maxn];

struct netflow{
	vector<ed>::iterator p[maxn];
	int d[maxn],inq[maxn],a[maxn];
	int cur[maxn]; 
	int in[maxn], out[maxn];
	int s, t;	// 源 汇 
	
	netflow(){s=t=-1;}
	
	void init(int s0,int t0){
		s = s0, t = t0;
	}

	void add(int x,int y,LL w,ll v){
//		printf("%d %d %d %d\n",x,y,v,w);
		g[x].push_back(ed(x,y,v,0,g[y].size(),w));
		g[y].push_back(ed(y,x,0,0,g[x].size() - 1,-w));
	}
	
	void adde(int x,int y,int w,int l,int r){	// x->y [l,r]
		add(x, y, w, r-l);
		out[x] += l; in[y] += l;
		down += 1ll * w * l;	// 钦定流下限的流量，有费用 
	}
	
	int spfa(int &flow,int &cost){
		memset(d,0x3f,sizeof d);memset(inq,0,sizeof inq);memset(a,0,sizeof a);
		a[s]=0x3f3f3f3f;
		queue<int>Q;
		Q.push(s);inq[s]=1;d[s]=0;
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			inq[u]=0;
			for(vector<ed>::iterator it=g[u].begin();it!=g[u].end();it++){
				if(it->cap>it->flow&&d[it->to]>d[u]+it->cost){
					d[it->to]=d[u]+it->cost;
					p[it->to]=it;
					a[it->to]=min(a[u],(int)it->cap-(int)it->flow);
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
	
	LL pflow(int S0, int T0, int S, int T, int point){	// possible flow
		// S0 T0 源点汇点 ST 超源超汇 point 有多少点 
		LL lim = 0;
		for(int i=2;i<=point;i++){	// 从 2 开始，因为 1 点排除了 
			int cur = in[i] - out[i];
			if(cur > 0)add(S, i, 0, cur), lim += cur;	// 补流 
			else add(i, T, 0, -cur);
		}
		add(T0, S0, 0, inf);	// 有源汇转无源汇 
		init(S, T);
		pii res = mcmf();
		return res.second + down;
	}
}nf;
int S0, T0, S, T;

int in[maxn];
signed main(){
	scanf("%d",&n);
	S0=n+1,T0=n+2;S=S0+2,T=T0+2;
	for(int i=1;i<=n;i++){
		int m;scanf("%d",&m);
		while(m --){
			int to, w;scanf("%d%d",&to,&w);
			int ss = i;
			if(i == 1)ss = n+1;	// 源点放大一点 
			nf.adde(ss, to, w, 1, inf);
			++ in[ss];
		}
	}
	for(int i=2;i<=n;i++)nf.adde(i,T0,0,0,inf);
	ll res = nf.pflow(S0,T0,S,T,n+2);
	cout << res << '\n';

	return 0;
}

