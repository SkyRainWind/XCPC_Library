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

int n,qu,a[maxn];
struct segm{
	int l,r;
	int occ;
}se[maxn << 5];
int rt[maxn], clk = 0, vn=0;

void build(int l,int r,int &num){
	num = ++ clk;
	if(l == r)return ;
	int mid = l+r>>1;
	build(l,mid,se[num].l);
	build(mid+1,r,se[num].r);
	se[num].occ = se[num << 1].occ + se[num << 1|1].occ;
}

void update(int &num,int pre,int l,int r,int to){
	num = ++ clk;
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

int query(int num0,int num1,int x,int y,int l,int r){
	if(x <= l && r <= y)return se[num0].occ - se[num1].occ;
	int mid = l+r>>1;
	if(y <= mid)return query(se[num0].l,se[num1].l,x,y,l,mid);
	else if(x>mid)return query(se[num0].r,se[num1].r,x,y,mid+1,r);
	else return query(se[num0].l,se[num1].l,x,y,l,mid) + query(se[num0].r,se[num1].r,x,y,mid+1,r);
}

signed main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), vn = max(vn, a[i]);
	build(1,vn,rt[0]);
	for(int i=1;i<=n;i++)
		update(rt[i], rt[i-1], 1, vn, a[i]);
	while(qu --){
		int b,x,l,r;
		scanf("%d%d%d%d",&b,&x,&l,&r);
		int other = 0;
		for(int i=17;i>=0;i--){
			int lb, ub, del = 0;
			if((b>>i)&1){	// other ´ËÎ»Îª 0 
				lb = other;
				ub = other + (1<<i) - 1;
			}else{
				lb = other + (1<<i);
				ub = other + (1<<(i+1)) - 1;
				del += (1 << i);
			}
			
			lb -= x, ub -= x;
			if(ub <= 0)continue;
			if(lb > vn)continue;
			lb = max(lb, 1);
			ub = min(ub, vn);
//			printf("! %d %d\n",lb,ub);
			int oc = query(rt[r], rt[l-1], lb, ub, 1, vn);
//			printf("- %d %d\n",oc,del);
			if(oc > 0)other += del;
			else other += (1<<i) - del;
		}
//		printf("qw %d\n",other);
		printf("%d\n",b ^ other);
	}

	return 0;
}

