// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5;

int n,a[maxn];
int stk[maxn], tp, f[maxn], g[maxn];

struct segm{
	int sum;
	int lazy;
}se[maxn << 2];

void build(int l,int r,int num){
	se[num].sum = 0;
	se[num].lazy = -1;
	if(l == r)return ;
	int mid = l+r>>1;
	build(l,mid,num << 1);build(mid+1,r,num<<1|1);
}

void pushdown(int num,int l,int r){
	if(se[num].lazy == -1)return ;
	int mid=l+r>>1;
	se[num << 1].lazy = se[num<<1|1].lazy = se[num].lazy; 
	se[num << 1].sum = (mid-l+1)*se[num << 1].lazy;
	se[num << 1|1].sum = (r-mid)*se[num << 1|1].lazy;
	se[num].lazy = -1;
}

void update(int x,int y,int to,int l,int r,int num){
	if(x<=l&&r<=y){
		se[num].lazy = to;
		se[num].sum = (r-l+1)*to;
		return ;
	}
	pushdown(num,l,r);
	int mid=l+r>>1;
	if(y<=mid)update(x,y,to,l,mid,num<<1);
	else if(x>mid)update(x,y,to,mid+1,r,num<<1|1);
	else update(x,y,to,l,mid,num<<1),update(x,y,to,mid+1,r,num<<1|1);
	se[num].sum = se[num << 1].sum + se[num << 1|1].sum;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	stk[++ tp] = 1;
	f[1] = 0;
	for(int i=2;i<=n;i++){
		while(tp && a[i] < a[stk[tp]])-- tp;
		if(tp == 0)f[i] = 0;
		else f[i] = stk[tp];
		stk[++ tp] = i;
	}
	
	tp = 0;
	stk[++ tp] = 1;
	g[1] = 0;
	for(int i=2;i<=n;i++){
		while(tp && a[i] > a[stk[tp]])-- tp;
		if(tp == 0)g[i] = 0;
		else g[i] = stk[tp];
		stk[++ tp] = i;
	}
//	for(int i=1;i<=n;i++)printf("%d%c",f[i]," \n"[i==n]);
//	for(int i=1;i<=n;i++)printf("%d%c",g[i]," \n"[i==n]);
	
	ll ans = 0;
	for(int i=2;i<=n;i++){
		if(g[i] < f[i]){
			if(g[i])update(g[i],g[i],0,1,n,1);
			update(g[i]+1,f[i],1,1,n,1);
//			printf("? %d %d\n",g[i]+1,f[i]);
		}else{
			if(f[i])update(f[i],f[i],1,1,n,1);
			update(f[i]+1,g[i],0,1,n,1);
//			printf("- %d %d\n",f[i]+1,g[i]);
		}
		ans += se[1].sum;
//		printf("%d %d\n",i,se[1].sum);
	}
	cout << ans << '\n';

	return 0;
}

