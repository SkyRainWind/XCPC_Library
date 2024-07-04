// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9,maxn=2e5+ 5;

int n,q;
struct seg{
	LL sum,lazy;
	int x,y;
}se[maxn << 2];
LL a[maxn];

void build(int x,int y,int num){
	if(x == y){
		se[num].x = se[num].y = x;
		se[num].sum = a[x];
		se[num].lazy = 0;
		return ;
	}
	int mid = x+y>>1;
	build(x,mid,num<<1);
	build(mid+1,y,num<<1|1);
	se[num].x = se[num<<1].x; se[num].y = se[num<<1|1].y;
	se[num].sum = se[num<<1].sum + se[num<<1|1].sum;
	se[num].lazy = 0;
}

void pushdown(int num,int l,int r){
	if(se[num].lazy == 0)return ;
	se[num<<1].lazy += se[num].lazy; se[num<<1|1].lazy += se[num].lazy;
	int mid = l+r>>1;
	se[num<<1].sum += 1ll*(mid-l+1) * se[num].lazy; se[num<<1|1].sum += 1ll*(r-mid) * se[num].lazy;
	se[num].lazy = 0;
}

void add(int l,int r,LL to,int x,int y,int num){
	if(l <= x && y <= r){
		se[num].sum += 1ll*(y-x+1) * to;
		se[num].lazy += to;
		return ;
	}
	pushdown(num,x,y);
	int mid = x+y>>1;
	if(r <= mid)add(l,r,to,x,mid,num<<1);
	else if(l>mid)add(l,r,to,mid+1,y,num<<1|1);
	else{add(l,r,to,x,mid,num<<1);add(l,r,to,mid+1,y,num<<1|1);}
	se[num].sum = se[num<<1].sum + se[num<<1|1].sum;
}

LL query(int x,int y,int l,int r,int num){
	if(x<=l && r<=y)return se[num].sum;
	pushdown(num,l,r);
	int mid=l+r>>1;
	if(y <= mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	else return query(x,y,l,mid,num<<1) + query(x,y,mid+1,r,num<<1|1);
}

signed main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,n,1);
	while(q --){
		int op;scanf("%d",&op);
		if(op==1){
			int x,y;
			LL k;scanf("%d%d%lld",&x,&y,&k);
			add(x,y,k,1,n,1);
		}else{
			int x,y;scanf("%d%d",&x,&y);
			printf("%lld\n",query(x,y,1,n,1));
		}
	}

	return 0;
}


