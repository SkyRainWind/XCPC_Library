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
LL qu1[maxn], qu3[maxn];
int qu2[maxn], qu4[maxn];

int in(int x,int y,int mn,int mx){
	int t1 = y-x;
	return mn <= t1 && t1 <= mx;
}

int check(int lim){
	int mn = max(d-lim, 1), mx = d + lim;
	
	int st = -1;
	for(int i=1;i<=n;i++){
		if(x[i]<mn)dp[i] = -1e18;
		else{st = i;break;}
	}
	if(st == -1 || x[st] > mx)return 0;
	int fm = 0;
	dp[0] = 0;
	dp[st] = s[st];if(dp[st] >= k)return 1;
	++ st;
	int hd1=1, tl1=0;
	int hd2=1, tl2=0;
	for(int i=1;i<=st-1;i++){
		qu3[++ tl2] = dp[i]; qu4[tl2] = x[i];
	}
	while(hd2 <= tl2 && !in(qu4[hd2], x[st], mn ,mx))++ hd2;
	
	for(int i=st;i<=n;i++){
		int t1 = lower_bound(x+fm, x+i, x[i] - mx) - x;
		int t2 = upper_bound(x+fm, x+i, x[i] - mn) - x - 1;
		LL rmx = -1e18;
		for(int j=t1;j<=t2;j++)rmx = max(rmx, dp[j]);
		dp[i] = rmx + s[i];
		if(dp[i] >= 1ll * k)return 1;
		fm = t1;
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
//	printf("%d\n",check(578));return 0;
	int l=1, r=1e9, ans;
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid))r = mid-1, ans = mid;
		else l = mid+1;
	}
	printf("%d\n",ans);

	return 0;
}

