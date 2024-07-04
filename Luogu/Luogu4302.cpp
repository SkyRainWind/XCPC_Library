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

const int inf = 1e9,maxn=105;

char s[maxn];
int dp[maxn][maxn];
int n;

int dt(int x){int t=0;while(x){x/=10;++t;}return t;}
int getnum(int i,int k,int j){
	int tp = j-(k+1)+1,tp0=k-i+1;
	if(tp%tp0!=0)return -1;
//	puts("-1");
	int lpsz = tp / tp0;
	int cs = k;
	for(int lp=1;lp<=lpsz;lp++){
		for(int curs = i;curs<=k;curs++){
			if(s[curs] != s[++cs])return -1;
		}
	}
	return lpsz;
}

signed main(){
	scanf("%s",s+1);
	n=strlen(s + 1);
//	return 0;
	
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)dp[i][j]=j-i+1;
	for(int l=1;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			for(int k=i;k+1<=j;k++){
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j]);
				int lp = getnum(i,k,j);
				if(lp == -1)continue;
				dp[i][j] = min(dp[i][j], dp[i][k]+2+dt(lp+1));
			}
		}
	}
	printf("%d\n",dp[1][n]);

	return 0;
}


