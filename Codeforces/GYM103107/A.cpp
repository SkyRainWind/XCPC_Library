// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 4e5+5;

int n,m,a[maxn];
struct segm{
	int mx,orval;
}se[maxn << 2];

void upd(int num){
	se[num].mx = max(se[num << 1].mx, se[num << 1|1].mx);
	se[num].orval = se[num << 1].orval | se[num << 1|1].orval;
}

void build(int x,int y,int num){
	if(x == y){
		se[num].orval = se[num].mx = a[x];
		return ;
	}
	int mid=x+y>>1;
	build(x,mid,num<<1); build(mid+1,y,num<<1|1);
	upd(num);
}

int check(int num,int to){
	return (se[num].orval & to) == se[num].orval;
}

void update(int x,int y,int to,int l,int r,int num){
	if(check(num, to))return ;
	if(l == r){
		se[num].orval &= to;
		se[num].mx &= to;
		return ;
	}
	
	if(x <= l && r <= y){
		if(check(num, to))return ;
		int mid = l+r>>1;
		if(!check(num << 1, to))update(x,y,to,l,mid,num<<1);
		if(!check(num << 1|1, to))update(x,y,to,mid+1,r,num<<1|1);
		upd(num);
		return ;
	}
	int mid = l+r>>1;
	if(y <= mid)update(x,y,to,l,mid,num << 1);
	else if(x>mid)update(x,y,to,mid+1,r,num<<1|1);
	else update(x,y,to,l,mid,num<<1), update(x,y,to,mid+1,r,num<<1|1);
	upd(num);
}

void update(int k,int to,int l,int r,int num){
	if(l == r){
		se[num].mx = se[num].orval = to;
		return ;
	}
	int mid = l+r>>1;
	if(k <= mid)update(k,to,l,mid,num<<1);
	else update(k,to,mid+1,r,num<<1|1);
	upd(num); 
}

ll query(int x,int y,int l,int r,int num){
	if(x <= l && r<=y)return se[num].mx;
	int mid=l+r>>1;
	if(y<=mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	else return max(query(x,y,l,mid,num<<1), query(x,y,mid+1,r,num<<1|1));
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,n,1);
	while(m --){
		char s[6];
		scanf("%s",s +1);
		if(s[1] == 'Q'){
			int l,r;scanf("%d%d",&l,&r);
			printf("%d\n",query(l,r,1,n,1));
		}else if(s[1] == 'A'){
			int l,r,v;scanf("%d%d%d",&l,&r,&v);
			update(l,r,v,1,n,1);
		}else{
			int x,v;scanf("%d%d",&x,&v);
			update(x,v,1,n,1);
		}
	}

	return 0;
}

