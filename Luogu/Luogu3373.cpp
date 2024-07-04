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

int n,q,mod;
struct seg{
	LL sum,lazyadd,lazymul;
}se[maxn << 2];
LL a[maxn];

void build(int x,int y,int num){
	if(x == y){
		se[num].sum = a[x];
		se[num].lazyadd = 0;
		se[num].lazymul = 1;
		return ;
	}
	int mid = x+y>>1;
	build(x,mid,num<<1);
	build(mid+1,y,num<<1|1);
	se[num].sum = (se[num<<1].sum + se[num<<1|1].sum)%mod;
	se[num].lazyadd = 0;se[num].lazymul = 1;
}

void pushdown(int num,int l,int r){
	if(se[num].lazymul != 1){
		(se[num<<1].lazyadd *= se[num].lazymul)%=mod; (se[num<<1|1].lazyadd *= se[num].lazymul)%=mod;
		(se[num<<1].sum *= se[num].lazymul)%=mod;
		(se[num<<1|1].sum *= se[num].lazymul)%=mod;
		(se[num<<1].lazymul *= se[num].lazymul)%=mod;
		(se[num<<1|1].lazymul *= se[num].lazymul)%=mod;
		se[num].lazymul = 1;
	}
	if(se[num].lazyadd != 0){
		(se[num<<1].lazyadd += se[num].lazyadd)%=mod;
		(se[num<<1|1].lazyadd += se[num].lazyadd)%=mod;	
		int mid=l+r>>1;
		(se[num<<1].sum += (mid-l+1)*se[num].lazyadd%mod)%=mod;
		(se[num<<1|1].sum += (r-mid)*se[num].lazyadd%mod)%=mod;
		se[num].lazyadd = 0;
	}
}

void add(int l,int r,LL to,int x,int y,int num){
	if(l <= x && y <= r){
		(se[num].sum += 1ll*(y-x+1) * to%mod)%=mod;
		(se[num].lazyadd += to)%=mod;
		return ;
	}
	pushdown(num,x,y);
	int mid = x+y>>1;
	if(r <= mid)add(l,r,to,x,mid,num<<1);
	else if(l>mid)add(l,r,to,mid+1,y,num<<1|1);
	else{add(l,r,to,x,mid,num<<1);add(l,r,to,mid+1,y,num<<1|1);}
	(se[num].sum = se[num<<1].sum + se[num<<1|1].sum)%=mod;
}

void mul(int l,int r,LL to,int x,int y,int num){
	if(l <= x && y <= r){
		(se[num].lazyadd *= to)%=mod;
		(se[num].lazymul *= to)%=mod;
		(se[num].sum *= to)%=mod;
		return ;
	}
	pushdown(num,x,y);
	int mid = x+y>>1;
	if(r <= mid)mul(l,r,to,x,mid,num<<1);
	else if(l>mid)mul(l,r,to,mid+1,y,num<<1|1);
	else{mul(l,r,to,x,mid,num<<1);mul(l,r,to,mid+1,y,num<<1|1);}
	se[num].sum = (se[num<<1].sum + se[num<<1|1].sum)%mod;
}

LL query(int x,int y,int l,int r,int num){
	if(x<=l && r<=y)return se[num].sum;
	pushdown(num,l,r);
	int mid=l+r>>1;
	if(y <= mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	else return (query(x,y,l,mid,num<<1) + query(x,y,mid+1,r,num<<1|1))%mod;
}

signed main(){
	scanf("%d%d%d",&n,&q,&mod);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,n,1);
	while(q --){
		int op;scanf("%d",&op);
		if(op==2){
			int x,y;
			LL k;scanf("%d%d%lld",&x,&y,&k);
			add(x,y,k,1,n,1);
		}else if(op==1){
			int x,y;
			LL k;scanf("%d%d%lld",&x,&y,&k);
			mul(x,y,k,1,n,1);
		}else if(op==3){
			int x,y;scanf("%d%d",&x,&y);
			printf("%lld\n",query(x,y,1,n,1));
		}
	}

	return 0;
}


