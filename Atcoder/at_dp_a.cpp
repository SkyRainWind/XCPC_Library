// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;
int n,h[maxn],dp[maxn];
signed main(){
	memset(dp,0x3f,sizeof dp);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&h[i]);
	dp[1]=0;
	for(int i=1;i<=n-1;i++){
		int j=i+1,k=i+2;
		dp[j] = min(dp[j], dp[i]+abs(h[i]-h[j]));
		if(k<=n)dp[k] = min(dp[k], dp[i]+abs(h[i]-h[k]));
	}
	cout<<dp[n];

	return 0;
}

