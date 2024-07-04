// by Balloons
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9,maxn=1e5+5;

int n,m;
LL a[maxn];
struct node{LL sum,mx,lazy;}se[maxn << 2];
void build(int x,int y,int num){
	if(x == y){se[num].sum = se[num].mx = a[x];return ;}
	int mid=x+y>>1;
	build(x,mid,num<<1);build(mid+1,y,num<<1|1);
	se[num].sum = se[num<<1].sum + se[num<<1|1].sum;
	se[num].mx = max(se[num<<1].mx, se[num<<1|1].mx);
}

void update(int l,int r,int x,int y,int num){
	if(se[num].mx <= 1)return ; 
	if(x == y){
		se[num].sum = se[num].mx = (LL)sqrt(se[num].sum);
		return ;
	}
	int mid=x+y>>1;
	if(r <= mid)update(l,r,x,mid,num<<1);
	else if(l>mid)update(l,r,mid+1,y,num<<1|1);
	else{update(l,r,x,mid,num<<1);update(l,r,mid+1,y,num<<1|1);}
	se[num].sum = se[num<<1].sum + se[num<<1|1].sum;
	se[num].mx = max(se[num<<1].mx, se[num<<1|1].mx);
}

LL query(int l,int r,int x,int y,int num){
	if(l <= x && y<=r)return se[num].sum;
	int mid=x+y>>1;
	if(r<=mid)return query(l,r,x,mid,num<<1);
	else if(l>mid)return query(l,r,mid+1,y,num<<1|1);
	else return query(l,r,x,mid,num<<1) + query(l,r,mid+1,y,num<<1|1);
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,n,1);
	scanf("%d",&m);
	while(m --){
		int op,l,r;scanf("%d%d%d",&op,&l,&r);
		if(op == 1)printf("%lld\n",query(l,r,1,n,1));
		else update(l,r,1,n,1);
	}

	return 0;
}


