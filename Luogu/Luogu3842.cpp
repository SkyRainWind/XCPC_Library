// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9,maxn=2e4+5;

int n;
int l[maxn],r[maxn];
int dp[maxn][2];
// dp[i][0/1] 到第i行，处于左/右端点结束时走的最短路路程 
// dp[i][0] = max{dp[i-1][0] + 1 + |r[i]-l[i-1]| + |r[i]-l[i]|, dp[i-1][1] + 1 + |r[i]-r[i-1]| + |r[i]-l[i]|}
// dp[i][1] = max{dp[i-1][1] + 1 + |l[i]-r[i-1]| + |r[i]-l[i]|, dp[i-1][0] + 1 + |r[i]-l[i-1]| + |r[i]-l[i]|}
void ck(int &a,int b){a=min(a,b);}

signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&l[i],&r[i]);
	for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=1e18;
	dp[1][0] = r[1]-1 +r[1]-l[1];
	dp[1][1] = r[1]-1;
	for(int i=2;i<=n;i++){
		if(l[i-1] <= l[i])
			dp[i][0] = dp[i-1][0] + 1 + 2*(r[i]-l[i]) + l[i]-l[i-1];
		else if(l[i-1] >= r[i])
			dp[i][0] = dp[i-1][0] + 1 + l[i-1]-l[i];
		else dp[i][0] = dp[i-1][0] + 1 + (r[i]-l[i-1]) + (r[i]-l[i]);
		
		if(r[i-1] >= r[i])ck(dp[i][0],dp[i-1][1]+1+r[i-1]-l[i]);
		else if(r[i-1] <= l[i])ck(dp[i][0],dp[i-1][1]+1+r[i]-r[i-1]+r[i]-l[i]);
		else ck(dp[i][0],dp[i-1][1]+1+(r[i]-r[i-1])+(r[i]-l[i]));
		
		if(l[i-1]<=l[i])
			dp[i][1] = dp[i-1][0] + 1 + r[i]-l[i-1];
		else if(l[i-1] >= r[i])
			dp[i][1] = dp[i-1][0] + 1 + 2*(r[i]-l[i]) + (l[i-1]-r[i]);
		else dp[i][1] = dp[i-1][0] + 1 + (l[i-1]-l[i]) + (r[i]-l[i]);
		
		if(r[i-1] >= r[i])ck(dp[i][1],dp[i-1][1] + 1 + 2*(r[i]-l[i]) + (r[i-1]-r[i]));
		else if(r[i-1] <= l[i])ck(dp[i][1],dp[i-1][1] + 1 + (r[i]-r[i-1]));
		else ck(dp[i][1],dp[i-1][1] + 1 + (r[i-1]-l[i]) + (r[i]-l[i]));
	}
	int ans0=dp[n][0] + n-l[n], ans1=dp[n][1]+n-r[n];
	printf("%lld\n",min(ans0,ans1));

	return 0;
}

