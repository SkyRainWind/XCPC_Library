// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <cassert>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e18, INF = 0x3f3f3f3f, maxn = 200005;

int n,m,s,t;
struct ed{
	LL from,to,cap,flow,rev;
	ed(){}
	ed(LL from,LL to,LL cap,LL flow,LL rev):from(from),to(to),cap(cap),flow(flow),rev(rev){}
};
vector<ed>g[maxn];
char c[maxn];

struct netflow{
	int cur[maxn]; 
	int d[maxn], q[maxn], hd, tl;
	int s, t;	// 源 汇 
	
	netflow(){s=t=-1;}
	
	void init(int s0,int t0){
		s = s0, t = t0;
	}

	void add(int x,int y,int v){
		g[x].push_back(ed(x,y,v,0,g[y].size()));
		g[y].push_back(ed(y,x,0,0,g[x].size() - 1));
	}
	
	int bfs(){
		memset(d,0, sizeof d);
		hd = tl = 0;
		q[tl ++] = s;
		d[s] = 1;
		while(hd != tl){
			int now = q[hd ++];
			for(int i = 0;i<g[now].size();i++){
				ed &e = g[now][i];
				if(!d[e.to] && e.cap > e.flow)d[e.to] = d[now] + 1, q[tl ++] = e.to;
			}
		}
		return d[t];
	}
	
	LL dfs(int now,LL rem){	// rem 当前流量 
		if(now == t || !rem)return rem;
		LL flow = 0;
		for(int &i = cur[now]; i < g[now].size();i ++){
			ed &e = g[now][i];
				// 分层图 & 残量不为0 
			if(d[e.to] == d[now] + 1 && e.cap > e.flow){
				LL f = dfs(e.to, min(rem, e.cap - e.flow));
				rem -= f, flow += f, e.flow += f, g[e.to][e.rev].flow -= f;
			}
			if(!rem)break;
		}
		if(rem)d[now] = -1;
		return flow;
	}
	
	LL dinic(){
		assert(s!=-1);
		LL flow = 0;
		while(bfs()){
			memset(cur, 0, sizeof cur);
			flow += dfs(s, 1ll << 62);
		}
		return flow;
	}
}nf;

int fg = 0;
int read(){
	fg = 0;
	char ch;int r=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0' && ch <= '9')r = r * 10 + ch -'0', ch = getchar();
	if(ch == '\r')fg = 1;
	return r;
}

signed main(){
//	freopen("Luogu3410.in","r",stdin);
	scanf("%lld%lld",&m,&n);
	s = 0, t = n + m + 1;
	LL ans = 0;
//	for(int i=1;i<=m;i++){
//		int x=read();
//		int tt;
//		nf.add(s, i, x);
//		while(tt=read()){
//			nf.add(i, m+tt, 1ll << 62);
//			if(fg)break;
//		}
//		ans += x;
//	}
	for (int i=1;i<=m;i++){
        int x;scanf("%lld",&x);
        memset(c,0,sizeof(c));
        int ulen, num;
        cin.getline(c,10000);
        ulen=0;		
		nf.add(s, i, x);
        while (sscanf(c+ulen,"%lld",&num)==1){
			nf.add(i, m+num, 1ll << 62);
            if (num==0) ulen++;
            else while (num){num/=10;ulen++;}
            ulen++;
        }
        ans += x;
    }
	nf.init(s, t);
	for(int i=1;i<=n;i++){
		int x;scanf("%lld",&x);
		nf.add(m+i, t, x);
	}
	ans -= nf.dinic();
	for(int i=1;i<=m;i++)if(nf.d[i] > 0)printf("%d ",i);puts("");
	for(int i=1;i<=n;i++)if(nf.d[i+m] > 0)printf("%d ",i);puts("");
	printf("%lld\n",max(ans, 0ll));

	return 0;
}
