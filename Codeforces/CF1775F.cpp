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

int n,mod;

void solve1(){
	int a = max((int)sqrt(1.0 * n) - 2, 0), b = a;
	while(1){
		if(a*b >= n)break;
		++ a;
		if(a*b >= n)break;
		++ b; 
	}
	printf("%d %d\n",a,b);
	for(int i=1;i<=a;i++,puts(""))
		for(int j=1;j<=b;j++)
			printf("%c", ".#"[(i-1) * b + j <= n]);
}

int dp[1005];
void solve2(){
	int a = sqrt(n), b = a;
	ll ans=0;
	while(1){
		if(a*b >= n)break;
		++ a;
		if(a*b >= n)break;
		++ b; 
	}
	while(a * b >= n){
		int de = a*b - n;
		ans += 1ll*dp[de] * (1 + (a != b))%mod;
		ans %= mod;
		++ a, -- b;
	}
	printf("%d %d\n",2*(a+b),ans);
}

int dd[1005][1005][6];
signed main(){
	int te,ty;
	scanf("%d%d",&te,&ty);
	if(ty == 2){
		scanf("%d",&mod);
		dp[0] = 1;
		for(int t=1;t<=1000;t++)
			for(int j=1;j<=4;j++) 
			for(int i=t;i<=1000;i++)
				(dp[i] += dp[i-t]) %= mod;
		
		dd[0][0][4] = 1;
		for(int t=1;t<=1000;t++)
			for(int j=1;j<=4;j++){
				for(int i=t;i<=1000;i++)
					dd[i][t][1] = dd[i][t-1][4],
					dd[i][t][2] = dd[i][t-1][2],
					dd[i][t][3] = dd[i][t-1][3],
					dd[i][t][4] = dd[i][t-1][4];
				for(int i=t;i<=1000;i++){
					dd[i][t][j] += dd[i-t][t][j];
				}
			}
//					if(j == 1)dd[i][t][j] = dd[i][t-1][4];
//					else (dd[i][t][j] += dd[i-t][t-1][4] + dd[i][t][j-1]) %= mod;
		for(int i=1;i<=10;i++)printf("%d\n",dp[i]);
		for(int i=1;i<=10;i++)printf("%d\n",dd[i][1000][4]);
		printf("- %d\n",dd[1][1]);
	}
	while(te --){
		scanf("%d",&n);
		if(ty == 1)solve1();
		else solve2();
	}

	return 0;
}

