// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,qu;
int s[maxn], e[maxn], p[maxn], q[maxn], cnt=0;
int rt[maxn];
struct segm{
	int ls,rs,occ;
	ll sum;
}se[maxn << 5];
int clk = 0;
ll cf[maxn];
vector<int>st[maxn], ed[maxn];

void pushup(int num){
	int ls = se[num].ls, rs = se[num].rs;
	se[num].occ = se[ls].occ + se[rs].occ;
	se[num].sum = se[ls].sum + se[rs].sum;
}

void build(int l,int r,int &num){
	num = ++ clk;
	if(l == r){
		se[num].occ = 0;
		se[num].sum = 0;
		return ;
	}
	int mid = l+r>>1;
	build(l,mid,se[num].ls); build(mid+1,r,se[num].rs);
	pushup(num);
}

void update(int l,int r,int to,int sgn, int &num,int pre){
	num = ++ clk;
	se[num] = se[pre];
	if(l == r){
		se[num].occ += sgn;
		se[num].sum += sgn * q[to];
		return ;
	}
	int mid = l+r>>1;
	if(to <= mid)update(l,mid,to,sgn,se[num].ls,se[pre].ls);
	else update(mid+1,r,to,sgn,se[num].rs,se[pre].rs);
	pushup(num);
}

ll query(int l,int r,int rst,int num){
//	printf("hh %d %d %d\n",l,r,rst);
	if(l == r)return 1ll * se[num].sum / se[num].occ * rst;
	int mid = l+r>>1;
	int ls = se[num].ls;
	if(rst <= se[ls].occ)return query(l,mid,rst,ls);
	else return se[ls].sum + query(mid+1,r,rst - se[ls].occ,se[num].rs);
}

signed main(){
//	freopen("P3168_1.in","r",stdin);
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&s[i],&e[i],&p[i]), q[++ cnt] = p[i];
	sort(q+1,q+cnt+1);
	cnt = unique(q+1,q+cnt+1) - (q+1);
	for(int i=1;i<=n;i++)
		p[i] = lower_bound(q+1,q+cnt+1,p[i]) - q;
	for(int i=1;i<=n;i++)
		st[s[i]].pb(p[i]), ed[e[i]+1].pb(p[i]);

	build(1,cnt,rt[0]);
	ll now = 0;
	for(int i=1;i<=n;i++){
		int g=0;
		for(int u : st[i])
			// 细节，只需要继承上一个位置的线段树一次 
			update(1,cnt,u,1,rt[i],g ? rt[i] : rt[i-1]), g=1;
//			printf("> %d %d\n",i,u);
		for(int u : ed[i])
			update(1,cnt,u,-1,rt[i],g ? rt[i] : rt[i-1]), g=1;
//			printf(">>> %d\n",u);
		// 如果没有增删，就只继承 
		if(g == 0)update(1,cnt,0,0,rt[i],rt[i-1]);
	}

	ll pre = 1;
	while(qu --){
		int x,a,b,c;scanf("%d%d%d%d",&x,&a,&b,&c);
		int k = 1 + (1ll*a*pre%c + b)%c;
//		int x,k;scanf("%d%d",&x,&k);
//		printf("?? %d\n",k);
		if(k > se[rt[x]].occ)printf("%lld\n",pre = se[rt[x]].sum);
		else printf("%lld\n",pre = query(1,cnt,k,rt[x]));
	}

	return 0;
}
