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

int t;
ll test;
int n,k;
pair<int,ll> lo[maxn];

signed main(){
	scanf("%d%lld",&t,&test);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		lo[i]=mpr(x,y);
	}
	lo[++n]=mpr(t,0);
	sort(lo+1,lo+n+1,[&](pair<int,ll> a,pair<int,ll> b){
		return a.first < b.first;
	});
	
	int i;
	ll sum = 0;
	for(i=1;lo[i].first <= t;i++){
		if(i>1)sum -= min(sum, 1ll*(lo[i].first-lo[i-1].first)*k);
		sum += lo[i].second;
	}
	if(sum != test){
		puts("Wrong Record");
		return 0;
	}
	ll mn = 1e18, mnn;
	for(;i<=n;i++){
		sum -= min(sum, 1ll*(lo[i].first-lo[i-1].first)*k);
		sum += lo[i].second;
		if(mn >= (sum + 1 + k-1) / k){
			mn = (sum + 1 + k-1) / k;
			mnn = lo[i].first;
		}
	}
	cout << mnn << ' ' << mn << '\n';

	return 0;
}

