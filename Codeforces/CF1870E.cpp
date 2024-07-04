// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5005;

int n,a[maxn],buc[maxn],mex[maxn][maxn];
int dp[maxn][maxn];
vector<int>ar[maxn];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)ar[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j] = 0;
			
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)buc[j] = 0;
		int cnt = 0;
		for(int j=i;j<=n;j++){
			buc[a[j]] = 1;
			while(buc[cnt] == 1)++ cnt;
			mex[i][j] = cnt;
		}
	}
	
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(l==r)ar[r].pb(l);
			else{
				if(mex[l][r] == mex[l+1][r] || mex[l][r] == mex[l][r-1]);
				else ar[r].pb(l);
			}
		}
	}
	
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)dp[i][j] = dp[i-1][j];
		for(int j : ar[i])
			for(int k=0;k<=n;k++)dp[i][k ^ mex[j][i]] |= dp[j-1][k];
	}
	for(int j=n;j>=0;j--)
		if(dp[n][j])
			return printf("%d\n",j), void();
//	printf("%d\n",dp[n]);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

