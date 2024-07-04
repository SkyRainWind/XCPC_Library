// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;
int n,a[25][25];
int dp[(1<<20)+5][22];
void ck(int &a,int b){a = min(a, b);}
signed main(){
	memset(dp, 0x3f, sizeof dp);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	
	if(n == 1)return puts("0"), 0;

	dp[1][1] = 0;
	for(int S=1;S<=(1<<(n))-1;S+=2){
		int T = S << 1 | 1;
		for(int i=1;i<=n;i++)if(S & (1 << (i-1))){
			for(int j=2;j<=n;j++)if(i!=j && (S & (1<<(j-1))) == 0){
				ck(dp[(S ^ (1<<(j-1)))][j], dp[S][i] + a[i][j]);
			}
		}
	}
	int ans = 1e9;
	for(int i=2;i<=n;i++)
		ans = min(ans, dp[(1<<n)-1][i] + a[i][1]);
	printf("%d\n",ans);

	return 0;
}

