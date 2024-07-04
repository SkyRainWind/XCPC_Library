// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 4e5+5;

int n,m;
int fa[maxn],dep[maxn],v[maxn],cf[maxn];
int sz[maxn],heavy[maxn],top[maxn],dfn[maxn],dfs_clock,seq[maxn];
int qx[maxn], qy[maxn];
struct segm{
	int sum;
}se[maxn << 2];

struct edges{
	int to,v,nxt;
}ed[maxn << 1];
int head[maxn],ecnt=0;
int dis[maxn];

void add(int x,int y,int z){
	ed[++ecnt].to = y;ed[ecnt].v = z;ed[ecnt].nxt=head[x];head[x]=ecnt;
}

void dfs1(int x,int fat,int ds=0){
	fa[x] = fat;
	sz[x] = 1;
	dep[x] = dep[fat] + 1;
	dis[x] = ds;
	
	for(int i=head[x];i;i=ed[i].nxt){
		int u = ed[i].to,w=ed[i].v;
		if(u == fat)continue;
		dfs1(u, x, ds+w);
		v[u] = w;
		sz[x] += sz[u];
		if(!heavy[x] || sz[u] > sz[heavy[x]])
			heavy[x] = u;
	}
}

void dfs2(int x,int now){
	top[x] = now;
	dfn[x] = ++ dfs_clock;
	seq[dfs_clock] = x;
	
	if(!heavy[x])return ;
	dfs2(heavy[x], now);
	for(int i=head[x];i;i=ed[i].nxt){
		int u = ed[i].to;
		if(u == heavy[x] || u == fa[x])continue;
		dfs2(u,u);
	}
}

int getlca(int u,int v){
	int lc;
	while(top[u] != top[v]){
		if(dep[top[u]] > dep[top[v]]){
			u = fa[top[u]];
		}else{
			v = fa[top[v]];
		}
	}
	if(dep[u] > dep[v])swap(u, v);
	return u;
}

int ecc = 0;
int mxe = 0;
pair<pii,int> _gt[maxn];
void dfs3(int x,int fat=0){
	for(int i=head[x];i;i=ed[i].nxt){
		int u=ed[i].to, w=ed[i].v;
		if(u == fat)continue;
		dfs3(u, x);
		cf[x] += cf[u];
		if(cf[u] == ecc)mxe = max(mxe, w);
		cf[u] = 0;
	}
}

int check(int lim){
	ecc = mxe = 0;
	int mxd = 0;
	int l=1,r=m,rr=m+1;
	while(l<=r){
		int mid=l+r>>1;
		if(_gt[mid].first.second>lim)r=mid-1,rr=mid;
		else l=mid+1;
	}
	for(int i=rr;i<=m;i++){
		int x = qx[_gt[i].second], y = qy[_gt[i].second]; 
		pii lcd = _gt[i].first;
		int lc = lcd.first;
		int lcv = lcd.second;
		cf[x] ++, cf[y] ++, cf[lc] -= 2;
		++ ecc;
		mxd = max(mxd, lcv);
	}
	
	dfs3(1);cf[1] = 0;
	if(mxd - mxe <= lim)return 1;
	return 0;
}

namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline ll read()
	{
        bool sign=0; char ch=nc();ll x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return 0;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
        return x;
    }
    #undef BUF_SIZE
};
using namespace fastIO;
#define qr() read()

signed main(){
//	freopen("2680.in","r",stdin);
	n=qr(),m=qr();
	for(int i=1;i<=n-1;i++){
		int x=qr(),y=qr(),z=qr();
		add(x,y,z);add(y,x,z);
	}
	dfs1(1,0);dfs2(1,1);
	
	for(int i=1;i<=m;i++){
		qx[i]=qr(),qy[i]=qr();
		int lc = getlca(qx[i], qy[i]);
		int lcv = dis[qx[i]] + dis[qy[i]] - 2 * dis[lc];
		_gt[i] = mpr(mpr(lc, lcv),i);
	}
	sort(_gt+1,_gt+m+1,[&](pair<pii,int> a,pair<pii,int> b){return a.first.second<b.first.second;});
	int l=0,r=1e9,ans;
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid))r = mid-1,ans = mid;
		else l = mid+1;
	}
	cout << ans << '\n';

	return 0;
}

