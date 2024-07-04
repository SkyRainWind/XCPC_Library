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

int n,a[maxn],dp[maxn],k;

int check(int lim){
	int rst = n-lim, rem = k-1;
	if(rst >= rem){
		int lst = rst - rem;
		if(lim+lst >= a[lim])return 1;
		return 0;
	}
	rem -= rst;
	if(lim < a[lim])return 0;
	if(dp[lim - a[lim]] >= rem)return 1;
	return 0;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dp[i] = dp[i-1];
		if(i-a[i] >= 0)dp[i] = max(dp[i], dp[i-a[i]] + 1);
	}
	int qu;scanf("%d",&qu);
	while(qu --){
		scanf("%d",&k);
		int l=1, r=n, ans = 0;
		while(l <= r){
			int mid = l+r>>1;
			if(check(mid))l = mid+1, ans = mid;
			else r = mid-1;
		}
		printf("%d\n",ans);
	}

	return 0;
}

