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
int W;
int a[101];
int dp[(1<<18) + 5];
int lft[(1<<18) + 5]; 

signed main(){
	scanf("%d%d",&n,&W);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int S=0;S<=(1<<n)-1;S++)dp[S] = inf;
	int bs = (1<<n)-1;
	dp[0] = 0;
	lft[0] = 0;
	for(int S=0;S<=(1<<n)-1;S++){
		for(int i=1;i<=n;i++)if((S&(1<<(i-1))) == 0){
			if(lft[S] >= a[i]){
				if(dp[S|(1<<(i-1))] > dp[S]){
					dp[S|(1<<(i-1))] = dp[S];
					lft[S|(1<<(i-1))] = lft[S]-a[i];
				}else if((lft[S|(1<<(i-1))] < lft[S]-a[i]) && dp[S|(1<<(i-1))] == dp[S]) lft[S|(1<<(i-1))] = lft[S]-a[i];
			}else{
				if(dp[S|(1<<(i-1))] > dp[S]+1){
					dp[S|(1<<(i-1))] = dp[S]+1;
					lft[S|(1<<(i-1))] = W - a[i];
				}else if((lft[S|(1<<(i-1))] < W-a[i]) && dp[S|(1<<(i-1))] == dp[S]+1) lft[S|(1<<(i-1))] = W-a[i];
			}
		}
	}
	printf("%d\n",dp[(1<<n)-1]);

	return 0;
}


