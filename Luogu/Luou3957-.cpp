// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;
//#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5 + 5;

int n,d,k;
int x[maxn], s[maxn];
LL dp[maxn];
LL qu[maxn], qu3[maxn];
int qu2[maxn], qu4[maxn];

int check(int lim){
	int mn = max(d-lim, 1), mx = d + lim;
	
	int hd=1, tl=0;
	for(int i=1;i<=n;i++)qu[i] = qu2[i] = 0;
	int l=0, r=0;
	for(int i=1;i<=n;i++){
		while(x[i] - x[r] >= mn){
			while(hd <= tl && qu[tl] <= dp[r])-- tl;
			qu[++ tl] = dp[r];qu2[tl] = r;
			++ r;
		}
		while(x[i] - x[l] > mx){	// 放在后面以排除 距离 > mx 且 > mn的不合法情况 
			if(qu[hd] == dp[l] && qu2[hd] == l)++ hd;
			++ l;
		}
		if(hd > tl)dp[i] = -1e18;
		else dp[i] = qu[hd] + s[i];
		if(dp[i] >= k)return 1;
//		printf("%d %d %d %d\n",i,dp[i], hd,tl);
	}
	return 0;
}

signed main(){
//	freopen("3957_6.in","r",stdin);
	scanf("%d%d%d",&n,&d,&k);
	LL r1 = 0;
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&s[i]), r1 += s[i] >= 0 ? s[i] : 0;
	if(r1 < k){
		puts("-1");
		return 0;
	}
//	printf("%d\n",check(235));return 0;
	int l=1, r=1e9, ans;
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid))r = mid-1, ans = mid;
		else l = mid+1;
	}
	printf("%d\n",ans);

	return 0;
}
