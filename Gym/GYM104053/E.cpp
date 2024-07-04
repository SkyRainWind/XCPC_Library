// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=5e5+5;

int n,m,a[maxn];
ll b[maxn][4];
int o[maxn];

int lb(int x){return x & (-x);}
void add(int x,ll del,int id){
	for(int i=x;i<=n;i+=lb(i))b[i][id] += del;
}
ll query(int x,int id){
	ll ans = 0;
	for(int i=x;i;i-=lb(i))ans += b[i][id];
	return ans;
}
ll ans[maxn];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),o[i]=i;
	sort(o+1,o+n+1,[&](int p,int q){
		return a[p]==a[q]?p<q:a[p]<a[q];
	});
	for(int i=1;i<=n;i++){
		ll t1 = query(o[i],0), t2=query(o[i],1), t3=query(n-o[i]+1,2), t4=query(n-o[i]+1,3);
		ll t = 1ll*(t2+t4)*a[o[i]] - t1 - t3; 
		if(t > m-2)ans[o[i]] = -1;
		else ans[o[i]] = t;
		
		add(o[i],a[o[i]]-1,0), add(o[i],1,1);
		add(n-o[i]+1,a[o[i]],2), add(n-o[i]+1,1,3);
	}
	for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);

	return 0;
}

