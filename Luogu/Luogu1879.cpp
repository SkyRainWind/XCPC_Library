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

const int inf = 1e9,mod=1e8;

int n,m;
int f[555];
int dp[2][(1<<12)+5];

int check(int S){return (S&(S<<1)) == 0;}

signed main(){
//	freopen("P1879_2.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int t;scanf("%d",&t);
			f[i] = (f[i]<<1) | t;
		}
		
	for(int S=f[1];;S=(S-1)&f[1]){
		if(check(S))dp[1][S] = 1;
		if(S==0)break;
	}
	for(int i=2;i<=n;i++){
		for(int S=f[i];;S=(S-1)&f[i])if(check(S)){
			dp[i&1][S] = 0;
			for(int T=f[i-1];;T=(T-1)&f[i-1])if(check(T) && (S&T) == 0){
				dp[i&1][S] += dp[i&1^1][T];
				dp[i&1][S] %= mod;
				if(T==0)break;
			}if(S==0)break;
		}
	}
	int ans=0;
	for(int S=f[n];;S=(S-1)&f[n]){
		(ans += dp[n&1][S]) %= mod;
		if(S==0)break;
	}
	printf("%d\n",ans);

	return 0;
}


