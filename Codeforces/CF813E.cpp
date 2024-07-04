// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,k,a[maxn],rt[maxn],b[maxn];
struct segm{
	int l,r;
	int occ;
}se[maxn << 5];
int clk=0;
vector<int>g[maxn];

void build(int l,int r,int &num){
	num = ++clk;
	if(l == r)return ;
	int mid = l+r>>1;
	build(l,mid,se[num].l); build(mid+1,r,se[num].r);
}

void update(int &num,int pre,int l,int r,int to){
	num = ++clk;
	se[num] = se[pre];
	if(l == r){
		++ se[num].occ;
		return ;
	}
	int mid = l+r>>1;
	if(to <= mid)update(se[num].l,se[pre].l,l,mid,to);
	else update(se[num].r,se[pre].r,mid+1,r,to);
	se[num].occ = se[se[num].l].occ + se[se[num].r].occ;
}

int query(int rl,int rr,int l,int r,int x,int y){
	if(x<=l&&r<=y)return se[rr].occ - se[rl].occ;
	int mid = l+r>>1;
	if(y <= mid)return query(se[rl].l,se[rr].l,l,mid,x,y);
	else if(x>mid)return query(se[rl].r,se[rr].r,mid+1,r,x,y);
	else return query(se[rl].l,se[rr].l,l,mid,x,y) + query(se[rl].r,se[rr].r,mid+1,r,x,y);
}

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	build(1,n,rt[0]);
	for(int i=n;i>=1;i--){
		if(g[a[i]].size() < k)b[i] = n+1;
		else b[i] = g[a[i]][g[a[i]].size() - k];
		g[a[i]].pb(i);
	}
	for(int i=1;i<=n;i++)
		update(rt[i], rt[i-1], 1, n+1, b[i]);
	
	int lst = 0;
	int qu;scanf("%d",&qu);
	while(qu --){
		int l,r;
		scanf("%d%d",&l,&r);
		l = ((l+lst)%n) + 1;
		r = ((r+lst)%n) + 1;
		if(l > r)swap(l, r);
//		printf("qw  %d %d\n",l,r);
		printf("%d\n",lst = query(rt[l-1], rt[r], 1, n+1, r+1, n+1));
	}

	return 0;
}

