// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5+5, mod=998244353;

int n,a[maxn];
struct segm{
	int ors;
	int ss;
}se[maxn << 2];

void pushup(int num,int l,int r){
	se[num].ss = (se[num << 1].ss + se[num<<1|1].ss)%mod;
	se[num].ors = se[num<<1].ors | se[num<<1|1].ors;
}

void build(int l,int r,int num){
	if(l==r){
		se[num].ss = 1ll*a[l]*a[l]%mod;
		se[num].ors = a[l];
		return ;
	}
	int mid=l+r>>1;
	build(l,mid,num<<1);build(mid+1,r,num<<1|1);
	pushup(num,l,r);
}

void update(int x,int y,int to,int l,int r,int num){
	if((se[num].ors & to) == se[num].ors)return ;
	if(l == r){
		se[num].ors &= to;
		se[num].ss = 1ll*se[num].ors*se[num].ors%mod;
		return ;
	}
	int mid = l+r>>1;
	if(y<=mid)update(x,y,to,l,mid,num<<1);
	else if(x>mid)update(x,y,to,mid+1,r,num<<1|1);
	else update(x,y,to,l,mid,num<<1),update(x,y,to,mid+1,r,num<<1|1);
	pushup(num,l,r);
}

int query(int x,int y,int l,int r,int num){
	if(x <= l && r <= y)return se[num].ss;
	
	int mid=l+r>>1;
	if(y<=mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	else return (query(x,y,l,mid,num<<1) + query(x,y,mid+1,r,num<<1|1)) % mod;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,n,1);
	int qu;scanf("%d",&qu);
	while(qu --){
		int op,l,r;scanf("%d%d%d",&op,&l,&r);
		if(op == 1){
			int x;scanf("%d",&x);
			update(l,r,x,1,n,1);
		}else{
			printf("%d\n",query(l,r,1,n,1));
		}
	}

	return 0;
}

