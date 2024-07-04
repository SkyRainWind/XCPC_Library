// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

ll dp[305][305];
signed main(){
	int n,h;
	scanf("%d%d",&n,&h);
	vector<int>a(n+1);
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), dp[i][i] = h;
	for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n;i++){
			int j = i+len-1;
			for(int k=i;k<j;k++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] - max(0, h + 1 - (a[j] - a[i] + 1)/2));
			}
		}
	cout << dp[1][n];

	return 0;
}

