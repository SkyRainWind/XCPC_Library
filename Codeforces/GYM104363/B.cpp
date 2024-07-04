// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6 + 5;

int n,qu;
char s[maxn];

struct segm{
	int lf, ri;
	int s0, s1;
	int lazy;
}se[maxn << 2];

void pushup(int num){
	se[num].s0 = se[num << 1].s0 + se[num << 1 | 1].s0;
	se[num].s1 = se[num << 1].s1 + se[num << 1 | 1].s1;
	if(se[num << 1].ri == se[num << 1|1].lf && se[num << 1].ri == 0)
		se[num].s0 ++;
	if(se[num << 1].ri == se[num << 1|1].lf && se[num << 1].ri == 1)
		se[num].s1 ++;
	se[num].lf = se[num << 1].lf;
	se[num].ri = se[num << 1 | 1].ri;
	se[num].lazy = 0;
}

void build(int l,int r,int num){
	if(l == r){
		se[num].lf = se[num].ri = s[l] - '0';
		se[num].s0 = se[num].s1 = se[num].lazy = 0;
		return ;
	}
	int mid = l+r>>1;
	build(l,mid,num << 1);build(mid+1,r,num << 1|1);
	pushup(num);
}

void pushdown(int num){
	if(!se[num].lazy)return ;
	swap(se[num << 1].s0, se[num << 1].s1);
	se[num << 1].lazy ^= 1, se[num << 1].lf ^= 1, se[num << 1].ri ^= 1;
	swap(se[num << 1|1].s0, se[num << 1|1].s1);
	se[num << 1 | 1].lazy ^= 1, se[num << 1 | 1].lf ^= 1, se[num << 1 | 1].ri ^= 1;
	se[num].lazy = 0;
}

void update(int x,int y,int l,int r,int num){
	if(x <= l && r <= y){
		se[num].lazy ^= 1;
		se[num].lf ^= 1, se[num].ri ^= 1;
		swap(se[num].s0, se[num].s1);
		return ;
	}
	pushdown(num);
	int mid = l+r>>1;
	if(y <= mid){
		update(x,y,l,mid,num << 1);
	}
	else if(x > mid)update(x,y,mid+1,r,num << 1 | 1);
	else update(x,y,l,mid,num<<1),update(x,y,mid+1,r,num<<1|1);
	pushup(num);
}

segm operator + (segm a,segm b){
	segm c;
	c.s0 = a.s0 + b.s0;
	c.s1 = a.s1 + b.s1;
	if(a.ri == b.lf && a.ri == 0)
		c.s0 ++;
	if(a.ri == b.lf && a.ri == 1)
		c.s1 ++;
	c.lf = a.lf;
	c.ri = b.ri;
	return c;
}

segm query(int x,int y,int l,int r,int num){
	if(x <= l && r <= y)
		return se[num];
	pushdown(num);
	int mid = l+r>>1;
	if(y <= mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	segm q1 = query(x,y,l,mid,num<<1);
	segm q2 = query(x,y,mid+1,r,num<<1|1);
	return q1 + q2;
}

signed main(){
	scanf("%d%d",&n,&qu);
	scanf("%s",s + 1);
	build(1,n,1);

	while(qu --){
		char t[5];
		int l,r;
		scanf("%s",t+1);scanf("%d%d",&l,&r);
		if(t[1] == 'M'){
			update(l,r,1,n,1);
		}else{
			segm now = query(l,r,1,n,1);
			printf("%d\n",max(now.s0,now.s1) + 1);
		}
	}

	return 0;
}
