// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 1e9+7;

char s[10005];
int num[10005], d, n;
ll dp[10005][2][2][105];

ll dfs(int x,int up,int is0,int rem){
	ll &dd = dp[x][up][is0][rem];
	if(x == n+1){
		if(is0 || rem)return dd = 0;
		else return dd = 1;
	}
	if(~dd)return dd;
	
	dd = 0;
	int lim = up ? num[x] : 9;
	for(int i=0;i<=lim;i++){
		(dd += dfs(x+1, up && i == lim, is0 && i == 0, (rem + i) % d)) %= mod;
	}
	return dd;
}

signed main(){
	memset(dp, -1, sizeof dp);
	scanf("%s",s + 1);
	scanf("%d",&d);
	n = strlen(s + 1);
	for(int i=1;i<=n;i++)num[i] = s[i] - '0';
	printf("%d\n",dfs(1,1,1,0));

	return 0;
}

