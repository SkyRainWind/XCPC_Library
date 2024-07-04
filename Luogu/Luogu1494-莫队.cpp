// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 50005;

int n,q;
ll ci=0;
int a[maxn],b[maxn];
struct que{
	int l,r,id;
}qu[maxn];

struct rr{
	int l,r;
	ll res;
}ans[maxn];
int blk;

void add(int x){
	ci+=b[x];
	++b[x];
}
void del(int x){
	--b[x];
	ci-=b[x];
}

signed main(){
	scanf("%d%d",&n,&q);
	blk = sqrt(1.0 * n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=q;i++){
		int l,r;scanf("%d%d",&l,&r);
		qu[i] =que{l,r,i};
	}
	sort(qu+1,qu+q+1,[&](que a,que b){return a.l/blk==b.l/blk?a.r<b.r:a.l<b.l;});
	int l=1,r=0;
	for(int i=1;i<=q;i++){
		int ql=qu[i].l,qr=qu[i].r;
		while(l<ql)del(a[l++]);
		while(l>ql)add(a[--l]);
		while(r<qr)add(a[++r]);
		while(r>qr)del(a[r--]);
		ans[qu[i].id]={ql,qr,ci};
	}
	for(int i=1;i<=q;i++){
		if(ans[i].l==ans[i].r)puts("0/1");
		else{
			ll fm = (ans[i].r-ans[i].l+1);
			fm = fm*(fm-1)/2;
			ll fz = ans[i].res;
			ll gd = __gcd(fm, fz);
			printf("%lld/%lld\n",fz/gd, fm/gd);
		}
	}

	return 0;
}

