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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=3e5+5;

int n;
int a[maxn],dp[maxn];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans = 1;
	for(int i=1;i<=n;i++)dp[i] = 1;
	for(int i=2;i<=n;i++){
		for(int j=max(1,i-512);j<i;j++){
//			if(i == 2 && j == 1)
//				printf("%d %d %d %d\n",a[i],j-1,a[j],i-1);
			if((a[i] ^ (j-1)) > (a[j] ^ (i-1))){	//!!!
				dp[i] = max(dp[i], dp[j]+1);
				ans = max(ans, dp[i]);
			}
		}
	}
//	printf("!! %d\n",dp[3]);
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}


