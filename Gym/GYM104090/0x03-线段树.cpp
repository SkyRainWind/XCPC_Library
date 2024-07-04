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

int n,m,a[maxn];
struct segm{
	ll sum;
	int lazy;
}se[maxn << 2];

void build(int l,int r,int num){
	se[num].lazy=0;
	if(l == r){
		se[num].sum = a[l];
		return ;
	}
	int mid = l+r>>1;
	build(l,mid,num << 1);build(mid+1,r, num<<1|1);
	se[num].sum = se[num << 1].sum + se[num << 1|1].sum;
}

void pushdown(int num,int l,int r){
	if(!se[num].lazy)return ;
	
	int mid=l+r>>1;
	se[num<<1].sum += 1ll*(mid-l+1)*se[num].lazy;
	se[num<<1|1].sum += 1ll*(r-mid)*se[num].lazy;
	
	se[num << 1].lazy += se[num].lazy;
	se[num << 1|1].lazy += se[num].lazy;
	
	se[num].lazy=0;
}

void update(int x,int y,int to,int l,int r,int num){
	if(x<=l&&r<=y){
		se[num].lazy += to;
		se[num].sum += 1ll * (r-l+1) * to;
		return ;
	}
	pushdown(num,l,r);
	int mid = l+r>>1;
	if(y <= mid)update(x,y,to,l,mid,num<<1);
	else if(x>mid) update(x,y,to,mid+1,r,num<<1|1);
	else update(x,y,to,l,mid,num<<1), update(x,y,to,mid+1,r,num<<1|1);
	se[num].sum = se[num << 1].sum + se[num << 1|1].sum;
}

ll query(int x,int y,int l,int r,int num){
	if(x<=l && r<=y)return se[num].sum;
	int mid = l+r>>1;
	pushdown(num,l,r);
	if(y <= mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	else return query(x,y,l,mid,num<<1) + query(x,y,mid+1,r,num<<1|1);
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,n,1);
	while(m --){
		int op,x,y,k;scanf("%d%d%d",&op,&x,&y);
		if(op == 1){
			scanf("%d",&k);
			update(x,y,k,1,n,1);
		}
		else printf("%lld\n",query(x,y,1,n,1));
	}

	return 0;
}

