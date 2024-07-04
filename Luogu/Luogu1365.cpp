// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cmath> 
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5 +5;

int n;
char s[maxn];
int lft[maxn];
double dp[maxn];

signed main(){
	scanf("%d",&n);
	scanf("%s", s+1);
	int lst = 0;
	for(int i=1;i<=n;i++){
		if(s[i] == 'x')lst = i, lft[i] = i + 1;
		else lft[i] = lst + 1;
	}
	for(int i=1;i<=n;i++)if(s[i] != 'x'){
		int t1 = 0;
		for(int j = i;j>=max(lft[i], i-30);j--){
			if(s[j] == '?')++ t1;
			dp[i] = dp[j-1] + 
		}
		dp[i] = dp[max(lft[i], i-30) - 1] + 0.5 * (t1*t1) / pow(2, t1) + 0.5 * ((t1-1)*(t1-1)) / pow(2, t1-1);
	}else dp[i] = dp[i-1];
	printf("%.4f %.4f\n",dp[1],dp[2]);
	printf("%.4f\n",dp[n]);

	return 0;
}


