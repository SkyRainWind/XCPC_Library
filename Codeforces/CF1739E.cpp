// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n;
char s[2][maxn];
int dp[2][maxn];
int a[2][maxn];

void ck(int &mm,int a){mm = max(mm, a);}

signed main(){
	memset(dp, -0x3f, sizeof dp);
	scanf("%d",&n);
	for(int i=0;i<=1;i++)scanf("%s", s[i] + 1);
//	s[0][n+1] = s[1][n+1] = '0';
	for(int i=0;i<=1;i++)
		for(int j=0;j<n;j++)a[i][j] = s[i][j+1] - '0';
	
	dp[0][0] = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=1;j++){
			dp[j][i+1] = max(dp[j][i+1], dp[j][i] + a[j][i+1]);
			int t = min(i+2,n);
			if(a[j^1][i]){
				dp[j^1][t] = max(dp[j^1][t], dp[j][i] + 1 + a[j^1][i+1] + a[j^1][i+2]);
			}
		}
	}
	printf("%d\n",max(dp[0][n], dp[1][n]));

	return 0;
}
