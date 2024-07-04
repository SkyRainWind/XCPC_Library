// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5+5;

int n,a[maxn];
struct que{
	int l,r,id;
}qu[maxn];

int cnt[maxn],res=0,ans[maxn];

void add(int x){
	cnt[a[x]] ^= 1;
	if(cnt[a[x]]%2 == 0)++res;
	else --res;
}
void del(int x){
	cnt[a[x]] ^= 1;
	if(cnt[a[x]]%2 == 0)++res;
	else -- res;
}
int q;
signed main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=q;i++)scanf("%d%d",&qu[i].l,&qu[i].r),qu[i].id = i;
	int blk = sqrt(n);
	sort(qu+1,qu+1+q,[&](que a,que b){
		if(a.l / blk == b.l / blk)return a.r < b.r;
		return a.l < b.l;
	});
	
	int l=1,r=0;
	for(int i=1;i<=q;i++){
		while(l < qu[i].l)del(l++);
		while(l > qu[i].l)add(--l);
		while(r < qu[i].r)add(++r);
		while(r > qu[i].r)del(r--);
		if(res==0)ans[qu[i].id] = 0;
		else ans[qu[i].id] = 1;
	}
	for(int i=1;i<=q;i++)puts(ans[i] ? "Alice" : "Bob");

	return 0;
}

