// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5;

int n,q,fm;
int a[maxn],p2[maxn];
ll s[maxn]; 

void build(int x,int y,int num,int d=0){
	if(x == y){
		s[x] = 2*p2[20] - p2[20-d];
		return ;
	}
	int mid=x+y>>1;
	build(x,mid,num<<1,d+1);
	build(mid+1,y,num<<1|1,d+1);
}

signed main(){
	p2[0] = 1;
	for(int i=1;i<=20;i++)p2[i] = 2*p2[i-1];

	scanf("%d%d%d",&n,&q,&fm);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,n,1);
	
	ll ans = 0;
	for(int i=1;i<=n;i++)ans += a[i] * s[i];
	for(int i=1;i<=n;i++)s[i] += s[i-1];
	int gd = __gcd(fm, p2[20]);
	fm /= gd, p2[20] /= gd;
	
	while(q --){
		int l,r,v;scanf("%d%d%d",&l,&r,&v);
		ans += v * (s[r] - s[l-1]);
		printf("%lld\n",ans * fm / p2[20]);
	}

	return 0;
}

