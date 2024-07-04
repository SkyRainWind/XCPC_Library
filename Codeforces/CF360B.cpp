// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,k,a[maxn],dp[2005];

int check(int lim){
	for(int i=1;i<=n;i++){
		dp[i] = i-1;
		for(int j=1;j<i;j++)
			if(1ll*(i-j)*lim >= abs(a[i] - a[j])){
				dp[i] = min(dp[j]+i-j-1, dp[i]);
			}
	}
//	cout<<dp[1]<<'\n';
	for(int i=1;i<=n;i++)
		if(dp[i] + n-i <= k)return 1;
	return 0;
}

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=0,r = 2e9+1, ans;
	while(l <= r){
		int mid=(int)((1ll*l+1ll*r)/2);
		if(check(mid))r = mid-1, ans = mid;
		else l = mid+1;
	}
	cout<<ans;

	return 0;
}

