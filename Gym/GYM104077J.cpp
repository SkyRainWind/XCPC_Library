#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define INF 21473647

const int maxn=255*255+5;
 
bool st[255][255];
std::string str;
int sumr[255], sumc[255];
 
struct ed{
	ll from,to,cap,flow,rev;
	ed(){}
	ed(ll from,ll to,ll cap,ll flow,ll rev):from(from),to(to),cap(cap),flow(flow),rev(rev){}
};
vector<ed>g[maxn];

int cur[maxn];
int d[maxn],q[maxn],hd,tl;
int s,t;

void add(int x,int y,int v){
	g[x].pb(ed(x,y,v,0,g[y].size()));
	g[y].pb(ed(y,x,0,0,g[x].size()-1));
}

void link(int a, int b, int v){
	add(a,b,v);
}

int bfs(){
	memset(d,0,sizeof d);
	hd=tl=0;
	q[tl ++]=s;
	d[s]=1;
	while(hd != tl){
		int now = q[hd++];
		for(int i=0;i<g[now].size();i++){
			ed &e = g[now][i];
			if(!d[e.to] && e.cap > e.flow)d[e.to] = d[now] + 1, q[tl++] = e.to;
		}
	}
	return d[t];
}

ll dfs(int now,ll rem){
	if(now==t||!rem)return rem;
	ll flow=0;
	for(int &i=cur[now];i<g[now].size();i++){
		ed &e=g[now][i];
		if(d[e.to] == d[now]+1 && e.cap > e.flow){
			ll f = dfs(e.to, min(rem, e.cap - e.flow));
			rem -= f, flow += f, e.flow += f, g[e.to][e.rev].flow -= f;
		}
		if(!rem)break;
	}
	if(rem)d[now] = -1;
	return flow;
}
 
int dinic(int st, int ed){
    int ans = 0;
    s=st,t=ed;
    while(bfs()){
    	memset(cur,0,sizeof cur);
        ans += dfs(s, INF);
    }
    return ans;
}
 
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
    int n, m;
    ll c, d;
    std::cin >> n >> m >> c >> d;
    for(int i = 1; i <= n; i++){
        std::cin >> str;
        for(int j = 1; j <= m; j++){
            st[i][j] = str[j - 1] == '.' ? 1 : 0;
            sumr[i] += st[i][j];
            sumc[j] += st[i][j];
            if(st[i][j])
                link(i, n + j, 1);
        }
    }
    ll ans = 1e18;
    int s = 0;
    int e = n + m + 1;
    ll cc = 0;
    for(int i = std::max(n, m); i >= 0; i--){
        for(int j = 1; j <= n; j++)
            if(sumr[j] > i){
                link(s, j, 1);
                cc++;
            }
        for(int j = 1; j <= m; j++)
            if(sumc[j] > i){
                link(n + j, e, 1);
                cc++;
            }
        // printf("cc before flow = %d\n", cc);
        cc -= dinic(s, e);
        // for(int j = 1; j <= m; j++)
        // printf("i = %d, ans = %lld, cc = %lld\n", i, ans, cc);
        ans = std::min(ans, c * i + d * cc);
    }
    std::cout<<ans<<'\n';
}
