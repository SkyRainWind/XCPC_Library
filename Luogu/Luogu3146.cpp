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

const int inf = 1e9;

int n;
int dp[251][251];

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)dp[i][j] = -1e9;
	for(int i=1;i<=n;i++)scanf("%d",&dp[i][i]);
	int ans=-1e9;
	for(int l=2;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			for(int k=i;k+1<=j;k++){
				if(dp[i][k] == dp[k+1][j] && dp[i][k] != -1e9){
					dp[i][j] = max(dp[i][j], dp[i][k]+1);
					ans = max(ans,dp[i][j]);
				}
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}


