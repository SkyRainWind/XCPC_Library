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

int prm[]={2,3,5,7,11,13,17,19,23,29};
int n,p;
int dp[2][(1<<10)+5][(1<<10)+5];

signed main(){
	scanf("%d%d",&n,&p);
	int mod = p;
	dp[1][0][0] = 1;
	for(int i=2;i<=n;i++){
		memset(dp[i&1],0,sizeof dp[i&1]);
		int curi = 0,tmp = i;
		for(int j=0;j<10;j++)
			while(tmp%prm[j] == 0){tmp /= prm[j];curi |= 1<<j;}
		for(int S1=0;S1<=(1<<10)-1;S1++){
			for(int S2=0;S2<=(1<<10)-1;S2++)if((S1&S2) == 0){
				if((S2&curi) == 0)(dp[i&1][S1|curi][S2] += dp[i&1^1][S1][S2])%=mod;
				if((S1&curi) == 0)(dp[i&1][S1][S2|curi] += dp[i&1^1][S1][S2])%=mod;
				( dp[i&1][S1][S2] += dp[i&1^1][S1][S2] ) %= mod;
			}
		}
	}
	int ans=0;
	for(int S1=0;S1<=(1<<10)-1;S1++){
		for(int S2=0;S2<=(1<<10)-1;S2++)if((S1&S2) == 0){
			(ans += dp[(n)&1][S1][S2])%=mod;
		}
	}
	printf("%d\n",ans);

	return 0;
}


