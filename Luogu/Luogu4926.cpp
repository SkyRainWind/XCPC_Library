// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pid pair<int,double>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;
const double eps = 1e-6;

int n,m,t;
int opt[maxn], A[maxn], B[maxn], k[maxn];
struct ed{
	int to;
	double v;
	int ty;
};
vector<ed>g[maxn];
double dis[maxn];
int vis[maxn];

int spfa(double s){
	for(int i=0;i<=n;i++)dis[i]=1e9,vis[i]=0;dis[n+1]=0;
	vector<int>len(n+3, 0);
	queue<int>Q;
	Q.push(n+1);
	while(!Q.empty()){
		int u = Q.front();Q.pop();vis[u] = 0;
		for(auto it : g[u]){
			int v = it.to;
			double w = it.v;
			if(it.ty == 1)w = -log(w-s);
			if(it.ty == 2)w = log(w+s);
			
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				if(!vis[v]){
					vis[v] = 1;
					++ len[v];
					if(len[v] == n+2)return 1;
					Q.push(v);
				}
			}
		}
	}
	return 0;
}

signed main(){
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&opt[i],&A[i],&B[i],&k[i]);
		g[A[i]].pb(ed{B[i],1.0*k[i],opt[i]});
	}
	g[n+1].pb(ed{0,0,3});
	for(int i=1;i<=t;i++){
		int C,x;scanf("%d%d",&C,&x); 
		g[0].pb(ed{C,log(x),3});
		g[C].pb(ed{0,-log(x),3});
	}
	double l=0,r=1e9,ans;
	if(!spfa(0))return puts("-1"),0;
	while(r-l > eps){
		double mid = (l+r)/2;
		if(spfa(mid))l=mid,ans=mid;
		else r=mid;
	}
	printf("%.9f\n",ans);

	return 0;
}

