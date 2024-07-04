// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=5e5+5;

int n;
char s[maxn];
vector<int>g[maxn];
int stk[maxn],tp;
ll pd[maxn],f[maxn],fa[maxn],to[maxn];

void dfs(int x,int fat=0){
	int ntp=tp;
	for(int u:g[x]){
		int qw=-1;
		if(s[u]=='(')stk[++tp]=u,to[u]=-1;
		else{
			if(tp){
				qw=stk[tp];
				to[u]=fa[stk[tp--]];
			}
			else to[u]=-1;
		}
		dfs(u,x);
		if(s[u]=='(')--tp;
		else if(~qw)stk[++tp]=qw;
	}
}

void dfs2(int x,int fat=0){
	for(int u:g[x]){
		if(~to[u])pd[u]=pd[to[u]]+1;
		f[u]=f[x]+pd[u];
		dfs2(u,x);
	}
}

signed main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=2;i<=n;i++){
		int x;scanf("%d",&x);
		g[x].pb(i);
		fa[i]=x;
	}
	if(s[1]=='(')stk[++tp]=1,to[1]=-1;
	else to[1]=-1;
	dfs(1);
	pd[1]=0,f[1]=0;
	dfs2(1);
	ll ans=0;
	for(int i=1;i<=n;i++)ans ^= (1ll*i*f[i]);
	cout<<ans<<'\n';

	return 0;
}

