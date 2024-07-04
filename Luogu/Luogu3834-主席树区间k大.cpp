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

int n,qu,a[maxn],b[maxn],buc[maxn];

struct segm{
	int l,r;
	int sum;
}se[maxn << 5];
int rt[maxn];
int clk=0;

void build(int l,int r,int &num){
	num = ++ clk;
	if(l == r){
		se[num].sum = 0;
		return ;
	}
	int mid = l+r>>1;
	build(l,mid,se[num].l);
	build(mid+1,r,se[num].r);
	se[num].sum = se[se[num].l].sum + se[se[num].r].sum;
}

void update(int x,int l,int r,int &num,int pre){
	num = ++ clk;
	se[num] = se[pre];
//	printf("up %d %d %d\n",x,l,r);
	if(l == r){
		se[num].sum ++;
		return ;
	}
	int mid = l+r>>1;
	if(x <= mid)update(x,l,mid,se[num].l,se[pre].l);
	else update(x,mid+1,r,se[num].r,se[pre].r);
	se[num].sum = se[se[num].l].sum + se[se[num].r].sum;
}

int query(int l,int r,int k,int num1,int num2){
	if(l == r)return l;
	int mid = l+r>>1;
	int dv = se[se[num1].l].sum - se[se[num2].l].sum;
//	printf("- %d %d %d\n",l,r,dv);
	if(k <= dv)return query(l,mid,k,se[num1].l,se[num2].l);
	else return query(mid+1,r,k-dv,se[num1].r,se[num2].r);
}

signed main(){
//	freopen("P3834_3.in","r",stdin);
	scanf("%d%d",&n,&qu);
	int cnt = 0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), b[++ cnt] = a[i]; 
	sort(b+1,b+cnt+1);
	cnt = unique(b+1,b+cnt+1) - (b+1);
	for(int i=1;i<=n;i++)a[i] = lower_bound(b+1,b+cnt+1,a[i]) - b, buc[a[i]] ++;
//	for(int i=1;i<=n;i++)printf("- %d\n",a[i]);
	build(1,cnt,rt[0]);
	for(int i=1;i<=n;i++){
		update(a[i],1,cnt,rt[i],rt[i-1]);
	}
	while(qu --){
		int l,r,k;scanf("%d%d%d",&l,&r,&k);
		int id = query(1,cnt,k,rt[r],rt[l-1]);
		printf("%d\n",b[id]);
	}

	return 0;
}

