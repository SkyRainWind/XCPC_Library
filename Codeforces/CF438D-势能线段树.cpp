// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5+5;

int n,m,a[maxn];

struct segm{
	ll sum;
	int mx;
	int lazy;
}se[maxn << 2];

void upd(int num){
	se[num].mx = max(se[num << 1].mx, se[num << 1|1].mx);
	se[num].sum = se[num << 1].sum + se[num << 1|1].sum;
}

void build(int x,int y,int num){
	if(x == y){
		se[num].sum = se[num].mx = a[x];
		return ;
	}
	int mid=x+y>>1;
	build(x,mid,num<<1); build(mid+1,y,num<<1|1);
	upd(num);
}

void update(int x,int y,int to,int l,int r,int num){
	if(se[num].mx < to)return ;
	if(l == r){
		se[num].sum %= to;
		se[num].mx %= to;
		return ;
	}
	
	if(x <= l && r <= y){
		if(se[num].mx < to)return ;
		int mid = l+r>>1;
		if(se[num << 1].mx >= to)update(x,y,to,l,mid,num<<1);
		if(se[num << 1|1].mx >= to)update(x,y,to,mid+1,r,num<<1|1);
		upd(num);
		return ;
	}
	if(se[num].mx < to)return ;
	
	int mid = l+r>>1;
	if(y <= mid)update(x,y,to,l,mid,num << 1);
	else if(x>mid)update(x,y,to,mid+1,r,num<<1|1);
	else update(x,y,to,l,mid,num<<1), update(x,y,to,mid+1,r,num<<1|1);
	upd(num);
}

void update(int k,int to,int l,int r,int num){
	if(l == r){
		se[num].mx = se[num].sum = to;
		return ;
	}
	int mid = l+r>>1;
	if(k <= mid)update(k,to,l,mid,num<<1);
	else update(k,to,mid+1,r,num<<1|1);
	upd(num); 
}

ll query(int x,int y,int l,int r,int num){
	if(x <= l && r<=y)return se[num].sum;
	int mid=l+r>>1;
	if(y<=mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	else return query(x,y,l,mid,num<<1) + query(x,y,mid+1,r,num<<1|1);
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,n,1);
	while(m --){
		int op;scanf("%d",&op);
		if(op==1){
			int l,r;scanf("%d%d",&l,&r);
			printf("%lld\n",query(l,r,1,n,1));
		}else if(op == 2){
			int l,r,x;scanf("%d%d%d",&l,&r,&x);
			update(l,r,x,1,n,1);
		}else{
			int k,x;scanf("%d%d",&k,&x);
			update(k,x,1,n,1);
		}
	}

	return 0;
}

