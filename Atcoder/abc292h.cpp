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

int n,b,q;
int a[maxn];
struct segm{
	ll sum, mxsum;
}se[maxn << 2];

void build(int x,int y,int num){
	if(x == y){
		se[num].sum = se[num].mxsum = a[x] - b;
		return ;
	}
	int mid = x+y>>1;
	build(x,mid,num<<1);build(mid+1,y,num<<1|1);
	se[num].sum = se[num<<1].sum + se[num<<1|1].sum;
	se[num].mxsum = max(se[num << 1].mxsum, se[num<<1].sum + se[num<<1|1].mxsum);
}

void update(int x,int to,int l,int r,int num){
	if(l == r){
		se[num].sum = se[num].mxsum = to - b;
		return ;
	}
	int mid = l+r>>1;
	if(x <= mid)update(x,to,l,mid,num<<1);
	else update(x,to,mid+1,r,num<<1|1);
	se[num].sum = se[num<<1].sum + se[num<<1|1].sum;
	se[num].mxsum = max(se[num << 1].mxsum, se[num<<1].sum + se[num<<1|1].mxsum);
}

int query(ll cur,int l,int r,int num){
	if(l == r)return l;
	int mid = l+r>>1;
	if(cur+se[num << 1].mxsum >= 0)return query(cur,l,mid,num << 1);
	return query(cur + se[num << 1].sum,mid+1,r,num << 1|1);
}

ll q2(int x,int y,int l,int r,int num){
	if(x <= l && r <= y)return se[num].sum;
	int mid = l+r>>1;
	if(y <= mid)return q2(x,y,l,mid,num<<1);
	else if(x > mid)return q2(x,y,mid+1,r,num << 1|1);
	else return q2(x,y,l,mid,num<<1) + q2(x,y,mid+1,r,num<<1|1);
}

signed main(){
	scanf("%d%d%d",&n,&b,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,n,1);
	while(q --){
		int c,x;scanf("%d%d",&c,&x);
		update(c,x,1,n,1);
		int id = query(0,1,n,1);
		ll sum = q2(1,id,1,n,1);
		printf("%.12f\n",1.0 * sum / id + 1.0 * b);
	}

	return 0;
}

