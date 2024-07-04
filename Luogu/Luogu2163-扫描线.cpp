// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5+5;

int n,m,x[maxn],y[maxn];
struct que{int x,y,xx,yy;}qu[maxn];
map<int,int>mpx,mpy,tox,toy;
int bit[maxn], nn, ans[maxn];
vector<int>p[maxn], lfb[maxn], rtb[maxn];

int lb(int x){return x&(-x);}
void add(int x){
	for(int i=x;i<=nn;i+=lb(i))bit[i] ++;
}
int query(int x){
	int res = 0;
	for(int i=x;i;i-=lb(i))res += bit[i];
	return res;
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]), mpx[x[i]]=mpy[y[i]]=1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&qu[i].x,&qu[i].y,&qu[i].xx,&qu[i].yy);
		-- qu[i].x, -- qu[i].y;
		mpx[qu[i].x] = mpx[qu[i].xx] = mpy[qu[i].y] = mpy[qu[i].yy] = 1;
	}
	
	int cnt = 0;
	for(auto it : mpx)tox[it.first] = ++ cnt;
	cnt = 0;
	for(auto it : mpy)toy[it.first] = ++ cnt;
	
	for(int i=1;i<=n;i++){
		x[i] = tox[x[i]], y[i] = toy[y[i]];
		p[x[i]].pb(y[i]);
	}
	for(int i=1;i<=m;i++){
		qu[i].x = tox[qu[i].x];
		qu[i].xx = tox[qu[i].xx];
		qu[i].y = toy[qu[i].y];
		qu[i].yy = toy[qu[i].yy];
		lfb[qu[i].x].pb(i);
		rtb[qu[i].xx].pb(i);
	}
	
	nn = toy.size() + 6;
	for(int i=1;i<=tox.size();i++){
		for(int j=0;j<p[i].size();j++)add(p[i][j]);
		for(int j=0;j<lfb[i].size();j++){
			int it = lfb[i][j];
			ans[it] -= query(qu[it].yy) - query(qu[it].y);
		}
		for(int j=0;j<rtb[i].size();j++){
			int it = rtb[i][j];
			ans[it] += query(qu[it].yy) - query(qu[it].y);
		}
	}
	
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);

	return 0;
}

