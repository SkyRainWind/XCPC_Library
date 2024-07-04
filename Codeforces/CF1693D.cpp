// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,a[maxn];
int dp[maxn][2];
int lst;
ll ans = 0;

void solve(int l){
	dp[l][0] = inf, dp[l][1] = -inf;
	for(int i=l+1;i<=n;i++){
		int w0 = -inf, w1 = inf;
		if(dp[i-1][0] != -inf){
			if(a[i]>a[i-1])w0 = max(w0, dp[i-1][0]);
			if(a[i]<dp[i-1][0])w1 = min(w1, a[i-1]);
		}
		if(dp[i-1][1] != inf){
			if(a[i]<a[i-1])w1 = min(w1, dp[i-1][1]);
			if(a[i]>dp[i-1][1])w0 = max(w0, a[i-1]);
		}
		
//		printf("%d %d %d %d\n",dp[i][0],w0,dp[i][1],w1);
		if(dp[i][0]==w0&&dp[i][1]==w1)break;
		dp[i][0]=w0, dp[i][1]=w1;
		if(dp[i][0]==-inf && dp[i][1] == inf){lst = i-1;break;}
	}
//	printf("! %d %d\n",l,lst);
	ans += lst - l +1;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	lst = n;
	for(int i=n;i>=1;i--)solve(i);
	cout << ans << '\n';

	return 0;
}

