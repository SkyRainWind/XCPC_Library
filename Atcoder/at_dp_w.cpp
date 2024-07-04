// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n,m;
struct node{int l,r,w;}a[maxn];
struct segm{
	ll mx,lazy;
}se[maxn << 2];
int cmp(node a,node b){return a.r<b.r;}

void build(int x,int y,int num){
	if(x==y){se[num].mx=se[num].lazy=0;return ;}
	int mid=x+y>>1;build(x,mid,num<<1);build(mid+1,y,num<<1|1);se[num].mx=se[num].lazy=0;
}

void pd(int num){
	if(!se[num].lazy)return ;

	se[num<<1].mx += se[num].lazy;
	se[num<<1].lazy += se[num].lazy;
	se[num<<1|1].mx += se[num].lazy;
	se[num<<1|1].lazy += se[num].lazy;

	se[num].lazy = 0;
}

void update(int x,int y,ll to,int l,int r,int num){
	if(x<=l&&r<=y){
		se[num].mx += to;
		se[num].lazy += to;
		return ;
	}
	pd(num);
	int mid=l+r>>1;
	if(y<=mid)update(x,y,to,l,mid,num<<1);
	else if(x>mid)update(x,y,to,mid+1,r,num<<1|1);
	else update(x,y,to,l,mid,num<<1), update(x,y,to,mid+1,r,num<<1|1);
	se[num].mx = max(se[num<<1].mx, se[num<<1|1].mx);
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].w);
	sort(a+1,a+m+1,cmp);
	build(1,n,1);
	
	int curs = 1;
	for(int i=1;i<=n;i++){
		update(i,i,max(0ll, se[1].mx), 1, n, 1);
		while(curs <= m && a[curs].r == i){
			update(a[curs].l, a[curs].r, a[curs].w, 1, n, 1);
			++ curs;
		}
	}
	printf("%lld\n",max(0ll, se[1].mx));

	return 0;
}

