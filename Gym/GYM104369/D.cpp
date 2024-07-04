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

int n,m,a[maxn],b[maxn],c[maxn];

void solve(){
	scanf("%d%d",&n,&m);
	ll ans = 0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		ans += a[i];
		c[i] = b[i] - a[i];
	}
	if(n == 1){
		printf("%d\n",b[1]);
		return ;
	}
	sort(c+1,c+n+1,[&](int a,int b){return a>b;});
	int rst = m-n;
	for(int i=1;i<=min(rst,n-1);i++){
		if(c[i]<=0)break;
		if(i==n-1)ans = max(ans, ans+c[i]+c[i+1]);
		else ans += c[i];
	}
	printf("%lld\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

