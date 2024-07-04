// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e6+5;

int n,k,a[maxn],b[maxn],w[maxn],S[maxn*2],sc;
map<int,int>mp;
int xo[maxn], cf[maxn];

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i],&b[i],&w[i]), S[++sc]=a[i], S[++sc]=b[i]+1;
	sort(S+1,S+sc+1);
	sc = unique(S+1,S+sc+1) - (S+1); 
	int cnt = 0;
	for(int i=1;i<=sc;i++)mp[S[i]] = ++cnt;
	for(int i=1;i<=n;i++)a[i] = mp[a[i]], b[i] = mp[b[i]+1];
	
	for(int i=1;i<=n;i++){
		xo[a[i]] ^= w[i];
		xo[b[i]] ^= w[i];
		++ cf[a[i]];
		-- cf[b[i]];
	}
	int cc = 0, xx = 0, ans=-1;
	for(int i=1;i<=cnt+1;i++){
		cc += cf[i];
		xx ^= xo[i];
		if(cc >= k)ans = max(ans, xx);
	}
	printf("%d\n",ans);

	return 0;
}

