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

int n,m;
int mt[105];
int dp[2][(1<<11)+5][(1<<11) +5];

int check(int S){	// 技巧，判断S是否有两个1，它们的距离<=2 ：(S&(S<<1)) != 0 || (S&(S<<2)) != 0 
	return (S&(S<<1)) == 0 && (S&(S<<2)) == 0; 
}

int ct(int S){int t=0;while(S){if(S&1)++t;S>>=1;}return t;}

signed main(){
//	freopen("2704.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char s[15];scanf("%s",s+1);
		for(int j=1;j<=m;j++){
			mt[i] = (mt[i] << 1) | (s[j] == 'P'?1:0);
		}
	}
	if(n == 1){
		int ans=0;
		for(int S=mt[1];S;S=(S-1)&mt[1])if(check(S))ans=max(ans,ct(S));
		printf("%d\n",ans);
		return 0;
	}
	if(n == 2){
		int ans=0;
		for(int S=mt[1];;S=(S-1)&mt[1])if(check(S))
			for(int T=mt[2];;T=(T-1)&mt[2]){
				if(check(T) && (S&T) == 0)ans = max(ans,ct(S)+ct(T));
				if(T==0)break; 
			}
		printf("%d\n",ans);
		return 0;
	}		
	for(int S=mt[1];;S=(S-1)&mt[1])if(check(S)){
		for(int T=mt[2];;T=(T-1)&mt[2])if(check(T) && (S&T) == 0){
			dp[0][T][S] = max(dp[0][T][S],ct(S)+ct(T));
			if(T==0)break;
		}if(S==0)break;
	}
	for(int i=3;i<=n;i++){
		int curS = mt[i];
		for(int S=curS;;S=(S-1)&curS)if(check(S)){
			for(int T=mt[i-1];;T=(T-1)&mt[i-1])if(check(T) && (S&T)==0){
				for(int U=mt[i-2];;U=(U-1)&mt[i-2])if(check(U) && (S&U) == (U&T) && (S&U) == 0){
					dp[i&1][S][T] = max(dp[i&1][S][T],dp[i&1^1][T][U]+ct(S));
					if(U==0)break;
				}if(T==0)break;
			}if(S==0)break;
		}
	}
	int ans=0;
	for(int S=mt[n];;S=(S-1)&mt[n])if(check(S)){
		for(int T=mt[n-1];;T=(T-1)&mt[n-1]){
			if(check(T) && (S&T) == 0)ans=max(ans,dp[n&1][S][T]);
			if(T==0)break;
		}if(S==0)break;
	}
	printf("%d\n",ans);

	return 0;
}


