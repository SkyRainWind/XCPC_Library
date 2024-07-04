// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;
#define int ll

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,k,m;
int a[maxn];

int check(int lim){
	vector<int>b(n+1, 0);
	for(int i=1;i<=n;i++)
		if(a[i] >= lim)b[i] = 1;
	for(int i=2;i<=n;i++)b[i] += b[i-1];
	
	int l=0;
	ll re=0;
	for(int i=1;i<=n;i++){
		while(b[i] - b[l+1] >= m)++ l;
		if(b[i] - b[l] == m)re += l+1;
	}
	return re >= k;
}

void solve(){
	int l=1e9, r=0, ans;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	
	l=0,r=1e9,ans=0;
	while(l <= r){
		int mid =l+r>>1;
		if(check(mid)){
			ans = mid;
			l = mid+1;
		}else r = mid-1;
	}
	printf("%lld\n",ans);
}

signed main(){
	int te;scanf("%lld",&te);
	while(te --)solve();

	return 0;
}

