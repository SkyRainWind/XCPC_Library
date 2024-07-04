// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n;
char s[300050];
double now, dp[300005];

signed main(){
	scanf("%d",&n);scanf("%s",s + 1);
	for(int i=1;i<=n;i++){
		if(s[i] == 'o')dp[i] = dp[i-1] + 2*now + 1, ++ now;
		else if(s[i] == 'x')now=0, dp[i] = dp[i-1];
		else dp[i] = dp[i-1] +now + 0.5, now = (now+1)/2;
	}
	printf("%.4f\n",dp[n]);

	return 0;
}


