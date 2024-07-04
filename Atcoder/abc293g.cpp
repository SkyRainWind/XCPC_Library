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

int n,q,a[maxn],blk;
struct que{int l,r,id;}qu[maxn];
int sum[maxn];
ll res[maxn], ans;

int cmp(que a,que b){
	if(a.l / blk == b.l / blk)return a.r < b.r;
	return a.l < b.l;
}

ll c(int x){
	if(x <= 2)return 0;
	return 1ll*x*(x-1)*(x-2)/6;
}

void add(int xx){
	int x = a[xx];
	ans -= c(sum[x]);
	++ sum[x];
	ans += c(sum[x]); 
}

void del(int xx){
	int x = a[xx];
	ans -= c(sum[x]);
	-- sum[x];
	ans += c(sum[x]);
}

signed main(){
	scanf("%d%d",&n,&q);
	blk = (int)sqrt(1.0 * n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qu[i].l,&qu[i].r);
		qu[i].id = i;
	}
	sort(qu+1,qu+q+1,cmp);
	int l=0, r=0;
	for(int i=1;i<=q;i++){
		while(l > qu[i].l)add(--l);
		while(l < qu[i].l)del(l++);
		while(r < qu[i].r)add(++r);
		while(r > qu[i].r)del(r--);
		res[qu[i].id] = ans;
	}
	for(int i=1;i<=q;i++)printf("%lld\n",res[i]);

	return 0;
}

